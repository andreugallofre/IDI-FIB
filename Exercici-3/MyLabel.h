#include <QLabel>
#include <stdio.h>

class MyLabel: public QLabel
{

	Q_OBJECT
public:
	MyLabel(QWidget *parent);

	int hora = 0;
	int minut = 0;
	bool alarma = false;

public slots:
	
	void AlarmaOff();
	void AlarmaOn();
	void setHour(int hour);
	void setMin(int hour);
	void reset();

signals:
	
	void reseta(int);
};