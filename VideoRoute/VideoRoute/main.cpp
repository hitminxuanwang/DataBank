#include "videoroute.h"
#include <QtWidgets/QWidget>
#include <QLayout>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VideoRoute w;
	w.show();
	return a.exec();
}
