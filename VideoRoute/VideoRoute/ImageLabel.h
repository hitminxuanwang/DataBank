

#include <QWidget>
#include <QFrame>
#include <QtGui>
//#include <videoroute.h>
#include <ui_videoroute.h>

class ImageLabel :public QWidget
{
	Q_OBJECT
public:
	ImageLabel(QWidget *parent/*,Ui::VideoRouteClass* p*/,int flag);
	~ImageLabel();
	int number;
	int frames;
	QPixmap pix;
	int startCursor; 
	int endCursor;
public slots:
	void setPixmap(const QPixmap&);
protected:
	void paintEvent(QPaintEvent *);
signals:
	void videoChanged(int,int);
	void routeReset(int);
	void routeChanged(int,int,int);
	void cursorChanged(int,int, int);
	void saveVector(int, int, int);
protected:
	void mousePressEvent(QMouseEvent *ev);
	void mouseMoveEvent(QMouseEvent *ev);
	void mouseReleaseEvent(QMouseEvent *ev);
private:

};