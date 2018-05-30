#include <QApplication>
#include "MyForm.h"

int main( int argc, char ** argv )
{
	QApplication app( argc, argv );
	MyForm Rellotge;
	Rellotge.show();
	return app.exec();
}

