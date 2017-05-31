#ifndef VIDEOROUTE_H
#define VIDEOROUTE_H

#include <QtWidgets/QWidget>
#include <QLabel>
#include <QLayout>
#include <QGroupBox>
#include "ui_videoroute.h"
#include "ImageLabel.h"
class VideoRoute : public QWidget
{
	Q_OBJECT

public:
	VideoRoute(QWidget *parent = 0);
	void CreateWidgets();
	void displayImage(int,int);
	~VideoRoute();
public:

	QVector<ImageLabel*> *ilabels;
private slots:
	void update_video(int frame,int k);
	void update_route(int start,int end, int k);
	void update_cursor(int start,int end, int k);
	void update_route_data(int start, int end, int k);
	void update_route_reset(int number);
	void save();
	void play();
public:
	Ui::VideoRouteClass ui;
};

#endif // VIDEOROUTE_H
