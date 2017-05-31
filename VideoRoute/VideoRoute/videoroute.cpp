#include "videoroute.h"
#include "QPainter"
#include "QPixMap"
#include "iostream"
#include "fstream"
#include "stdlib.h"
#include <QLayout>
#include <QFormLayout>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#ifdef _DEBUG
#pragma comment(lib, "opencv_core2411d.lib")
#pragma comment(lib, "opencv_imgproc2411d.lib")
#pragma comment(lib, "opencv_highgui2411d.lib")

#else
#pragma comment(lib, "opencv_core2411.lib")
#pragma comment(lib, "opencv_imgproc2411.lib")
#pragma comment(lib, "opencv_highgui2411.lib")
#endif // _DEBUG

using namespace std;
using namespace cv;
#define N 7
#define M 250
vector<vector<Mat>> videos;
vector<vector<Point>> routes;
vector <vector <int> > flags;
vector<vector<pair<int, int>>> route_record;
vector<pair<int, int>> sequence;
Mat srcroute;
Mat combine1;
class Sleeper : public QThread
{
public:
	static void usleep(unsigned long usecs){ QThread::usleep(usecs); }
	static void msleep(unsigned long msecs){ QThread::msleep(msecs); }
	static void sleep(unsigned long secs){ QThread::sleep(secs); }
};
void ReadVideos(int number){
	for (int i = 0; i < number; i++)
	{

		stringstream ss;
		ss << i;
		string str = ss.str();
		VideoCapture capture(str+".mp4");
		int totalFrameNumber = capture.get(CV_CAP_PROP_FRAME_COUNT);
		int start = 0;
		int end = totalFrameNumber - 1;
		int rate = capture.get(CV_CAP_PROP_FPS);//frame rate
		bool stop = false;
		int currentframe = start;
		vector<Mat> video;
		while (!stop)
		{
			Mat frame;
			capture >> frame;

			video.push_back(frame);
			currentframe++;
			if (currentframe == totalFrameNumber)
			{
				stop = true;
			}

		}
		videos.push_back(video);
	}

};
void IniteRoutes(int number)
{
	srcroute= imread("blank.jpg", CV_LOAD_IMAGE_COLOR);
	int offset = 30;
	for (int i = 0; i < number; i++)
	{
		vector<Point> route;
		vector<int> flag;
		vector<pair<int, int>> record;
		for (int j = 0; j < M; j++)
		{
			Point p(offset + i * 20, offset + j);
			pair<int, int> pr(i,j);
			srcroute.at<Vec3b>(offset+i*20, offset+j) = 0;
			route.push_back(p);
			flag.push_back(0);
		}
		route_record.push_back(record);
		flags.push_back(flag);
		routes.push_back(route);
	}

	//hypothesis
	for (int i = 0; i < 100; i++)
	{
		int a = i%N;
		int b = (rand() % (249 - 0)) + 0;
		sequence.push_back(pair<int, int>(a, b));
	}



}
void DrawRoute(Mat src,Ui_VideoRouteClass *ui){
	int x = ui->label->width();
	int y = ui->label->height();
	QImage srcimage(src.data, src.cols, src.rows, src.step, QImage::Format_RGB888);
	srcimage = srcimage.rgbSwapped();
	QPixmap p_1(QPixmap::fromImage(srcimage).scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

	ui->label->setPixmap(p_1);
	ui->label->show();
}
VideoRoute::VideoRoute(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ReadVideos(N);
	IniteRoutes(N);
	CreateWidgets();
	displayImage(0,0);

}
void VideoRoute::displayImage(int vi,int frame){
	Mat pic = videos[vi][frame];
	int x = ui.label_2->width();
	int y= ui.label_2->height();
	QSize size= ui.groupBox_2->frameSize();

	QImage image(pic.data, pic.cols, pic.rows, pic.step, QImage::Format_RGB888);
	image = image.rgbSwapped();
	QPixmap p_2(QPixmap::fromImage(image).scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

	QImage srcimage(srcroute.data, srcroute.cols, srcroute.rows, srcroute.step, QImage::Format_RGB888);
	srcimage = srcimage.rgbSwapped();
	QPixmap p_1(QPixmap::fromImage(srcimage).scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

	ui.label->setPixmap(p_1);
	ui.label_2->setPixmap(p_2);

	combine1 = imread("combine1.jpg");
	QImage image_1(combine1.data, combine1.cols, combine1.rows, combine1.step, QImage::Format_RGB888);
	image_1 = image_1.rgbSwapped();
	QPixmap p(QPixmap::fromImage(image_1).scaled(size.width(),size.height()/N,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	for (int i = 0; i < N; i++)
	{
		ilabels->at(i)->setPixmap(p);
		ilabels->at(i)->repaint();
	}
}
void VideoRoute::CreateWidgets(){
	ui.label->setStyleSheet("border: 1px solid  yellow");
	ui.label_2->setStyleSheet("border: 1px solid  yellow");
	QRect rect= ui.groupBox_2->geometry();

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(ui.label);
	layout->addWidget(ui.label_2);

	ui.groupBox->setLayout(layout);
	int offset = (rect.height()-N)/ N;
	ilabels = new QVector<ImageLabel*>;
	for (int i = 0; i < N; i++)
	{
		ImageLabel* ilabel = new ImageLabel(ui.groupBox_2,i);
		int frames = videos[i].size(); ilabel->frames = frames;
		ilabel->setGeometry(rect.x(),rect.y()+offset*i+1,rect.width(),rect.height()/N);
		connect(ilabel, SIGNAL(videoChanged(int,int)), this, SLOT(update_video(int,int)));
		connect(ilabel, SIGNAL(routeChanged(int, int,int)), this, SLOT(update_route(int, int,int)));
		connect(ilabel, SIGNAL(cursorChanged(int,int, int)), this, SLOT(update_cursor(int, int,int)));
		connect(ilabel, SIGNAL(saveVector(int, int, int)), this, SLOT(update_route_data(int, int, int)));
		connect(ilabel, SIGNAL(routeReset(int)), this, SLOT(update_route_reset(int)));
		ilabels->append(ilabel);
	}
	QVBoxLayout *l = new QVBoxLayout;
	for (int i = 0; i < N; i++)
	{
		l->addWidget(ilabels->at(i));
	}
	ui.groupBox_2->setLayout(l);



}
void VideoRoute::update_video(int frame,int k){
	int x = ui.label_2->width();
	int y = ui.label_2->height();
	Mat pic = videos[k][frame];
	QImage image(pic.data, pic.cols, pic.rows, pic.step, QImage::Format_RGB888);
	image = image.rgbSwapped();
	QPixmap pixmap(QPixmap::fromImage(image).scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	ui.label_2->setPixmap(pixmap);
	ui.label_2->show();
}
void VideoRoute::update_route(int start,int end, int k){

	Mat dis = srcroute.clone();

	if (start != -1)
	{

		for (int w = start; w < end; w++){
			Point p = routes[k][w];
			flags[k][w] = 1;
			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; i <= 1; i++)
				{
					dis.at<Vec3b>(p.x + i, p.y + j)[0] = 0;
					dis.at<Vec3b>(p.x + i, p.y + j)[1] = 0;
					dis.at<Vec3b>(p.x + i, p.y + j)[2] = 255;
				}
			}
		}
	}

	for (int i = 0; i < flags.size(); i++)
	{
		for (int j = 0; j < flags[i].size(); j++)
		{
			if (flags[i][j]==1)
			{
				Point pr = routes[i][j];
				for (int m = -1; m <= 1 ; m++)
				{
					for (int n = -1; n <= 1 ; n++)
					{
						dis.at<Vec3b>(pr.x + m, pr.y + n)[0] = 0;
						dis.at<Vec3b>(pr.x + m, pr.y + n)[1] = 0;
						dis.at<Vec3b>(pr.x + m, pr.y + n)[2] = 255;
					}
				}

			}

		}

	}

	DrawRoute(dis,&ui);
}
void VideoRoute::update_cursor(int start,int end,int k){
	if (start==-1)
	{
		QSize size = ui.groupBox_2->frameSize();
		QImage image_1(combine1.data, combine1.cols, combine1.rows, combine1.step, QImage::Format_RGB888);
		image_1 = image_1.rgbSwapped();
		QPixmap p(QPixmap::fromImage(image_1).scaled(size.width(), size.height() / N, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		ilabels->at(k)->setPixmap(p);
		ilabels->at(k)->repaint();
		return;
	}
	QPixmap qpx = ilabels->at(k)->pix;
	QImage qim = qpx.toImage();
	QImage   swapped = qim.rgbSwapped();
	Mat tmp = Mat(swapped.height(), swapped.width(), CV_8UC4, const_cast<uchar*>(swapped.bits()), swapped.bytesPerLine()).clone();
	Mat result;
	cvtColor(tmp, result, CV_BGR2RGB);
	vector<Mat> channels;
	for (int i = start; i <= end; i++){
		split(result, channels);
		channels[2].col(i) = 255;
		merge(channels, result);
	}
	QImage image_1(result.data, result.cols, result.rows, result.step, QImage::Format_RGB888);
	image_1 = image_1.rgbSwapped();
	ilabels->at(k)->setPixmap(QPixmap::fromImage(image_1));
	ilabels->at(k)->repaint();
	ilabels->at(k)->show();

}
void VideoRoute::update_route_data(int start, int end, int k){
	route_record[k].push_back(pair<int,int>(start,end));
}
void VideoRoute::update_route_reset(int number){
	for (int i = 0; i < flags[number].size(); i++)
	{
		flags[number][i] = 0;
	}
	route_record[number].clear();
	update_route(-1, 0, number);
	update_cursor(-1, 0, number);
	ilabels->at(number)->startCursor = 0;
	ilabels->at(number)->endCursor = 0;
}
void VideoRoute::save(){
	QString qs = ui.lineEdit->text();

	// or this if you on Windows :-)
	string speed = qs.toLocal8Bit().constData();
	qs = ui.lineEdit_2->text();
	string startVideo = qs.toLocal8Bit().constData();
	qs = ui.lineEdit_3->text();
	string endVideo = qs.toLocal8Bit().constData();
	ofstream fout("data.txt");
	fout << speed<< endl;
	fout <<startVideo << endl;
	fout << endVideo << endl;
	for (int i = 0; i < N; i++)
	{
		fout << i<<":\t";
		for (int j = 0; j < route_record[i].size(); j++)
		{
			fout << route_record[i][j].first << "\t" << route_record[i][j].second<<"\t";
		}
		fout << endl;
	}

}
void VideoRoute::play(){
	for (int i = 0; i < sequence.size(); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int x = ui.label_2->width();
			int y = ui.label_2->height();
			Mat pic = videos[sequence[i].first][sequence[i].second];
			//imshow("figure", pic); waitKey();
			QImage image(pic.data, pic.cols, pic.rows, pic.step, QImage::Format_RGB888);
			image = image.rgbSwapped();
			QPixmap pixmap(QPixmap::fromImage(image).scaled(x, y, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
			ui.label_2->setPixmap(pixmap);
			ui.label_2->show();
			Sleeper::msleep(100);


			Mat result=combine1.clone();
			vector<Mat> channels;
			split(result, channels);
			//channels[2].col(sequence[i].second) = 255;
			for (int m = -2; m <=2; m++)
			{
				if (int(sequence[i].second *4.8)+ m >= 0 && int(sequence[i].second*4.8) + m<=combine1.cols)
				{
					channels[2].col(sequence[i].second*4.8+m) = 255;
				}
			}
			merge(channels, result);
			QSize size = ui.groupBox_2->frameSize();
			QImage image_1(result.data, result.cols, result.rows, result.step, QImage::Format_RGB888);
			image_1 = image_1.rgbSwapped();
			QPixmap p(QPixmap::fromImage(image_1).scaled(size.width(), size.height() / N, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

			QImage img(combine1.data, combine1.cols, combine1.rows, combine1.step, QImage::Format_RGB888);
			img = img.rgbSwapped();
			QPixmap pr(QPixmap::fromImage(img).scaled(size.width(), size.height() / N, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
			for (int k = 0; k <N; k++)
			{
				ilabels->at(k)->setPixmap(pr);
				ilabels->at(k)->repaint();
			}
			ilabels->at(sequence[i].first)->setPixmap(p);
			ilabels->at(sequence[i].first)->repaint();

			qApp->processEvents();

			
		}
	}





}
VideoRoute::~VideoRoute()
{
	
}
