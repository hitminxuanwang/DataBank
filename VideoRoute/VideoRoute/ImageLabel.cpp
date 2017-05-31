#include <ImageLabel.h>
#include "QMessageBox"
#include <sstream>
#include <iostream> 
using namespace std;

ImageLabel::ImageLabel(QWidget *parent,int flag)
	: QWidget(parent){
	this->setMouseTracking(true);
	number = flag;

}void ImageLabel::paintEvent(QPaintEvent *event) {
	QWidget::paintEvent(event);

	if (pix.isNull())
		return;

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	QSize pixSize = pix.size();
	//pixSize.scale(event->rect().size(), Qt::IgnoreAspectRatio);

	QPixmap scaledPix = pix.scaled(pixSize,
		Qt::KeepAspectRatio,
		Qt::SmoothTransformation
		);

	painter.drawPixmap(QPoint(), scaledPix);


}

void ImageLabel::setPixmap(const QPixmap &pixmap){
	pix = pixmap;
}


void ImageLabel::mousePressEvent(QMouseEvent *ev){
	QPoint start = mapFromGlobal(QCursor::pos());
	if (ev->buttons() & Qt::RightButton)
	{
		emit videoChanged(max(0, (min((start.x()), (width())) - 1)) / ((float)width() / frames), number);
		emit routeReset(number);
	}
	else
	{
		startCursor = start.x();
		endCursor = start.x();
		emit videoChanged(max(0, (min((start.x()), (width())) - 1)) / ((float)width() / frames), number);
		emit routeChanged(max(0, startCursor) / ((float)width() / frames), min(endCursor, width() - 1) / ((float)width() / frames), number);
	}


}
void ImageLabel::mouseMoveEvent(QMouseEvent *ev){
	QPoint current = mapFromGlobal(QCursor::pos());
	if (ev->buttons() & (Qt::LeftButton))
	{
		if (current.x() <= startCursor)
		{
			startCursor = current.x();
		}
		if (current.x() >= endCursor)
		{
			endCursor = current.x();
		}
		emit videoChanged((float)max(0, (min((current.x()), (width())) - 1)) / ((float)width() / frames), number);
		emit cursorChanged(max(0,startCursor),min(endCursor,width()-1), number);
		emit routeChanged(max(0, startCursor) / ((float)width() / frames), min(endCursor, width() - 1) / ((float)width() / frames), number);
	}
	else
	{

		emit videoChanged((float)max(0, (min((current.x()), (width())) - 1)) / ((float)width() / frames),number);
	}
}
void ImageLabel::mouseReleaseEvent(QMouseEvent *ev){
	QPoint current = mapFromGlobal(QCursor::pos());
	if (/*ev->buttons() &*/ (Qt::LeftButton))
	{
		emit saveVector(max(0, startCursor) / ((float)width() / frames), min(endCursor, width() - 1) / ((float)width() / frames), number);
	}
}


ImageLabel::~ImageLabel(){




}