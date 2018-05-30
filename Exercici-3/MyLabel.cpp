#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0): QLabel(parent){}


void MyLabel::AlarmaOff(){
	setStyleSheet("background-color : rgb(255,0,0); color : rgb(255, 255, 255);");
	setText("Alarma Desactivada");
	alarma = false;
}

void MyLabel::AlarmaOn(){
	alarma = true;
	setStyleSheet("background-color : rgb(0,255,0); color : rgb(255, 255, 255);");
	char buffer [256];
	if (hora < 10){
		if (minut < 10) sprintf (buffer, "Alarma -- 0%d:0%d", hora, minut);
		else sprintf (buffer, "Alarma -- 0%d:%d", hora, minut);
	}
	else{
		if (minut < 10) sprintf (buffer, "Alarma -- %d:0%d", hora, minut);
		else sprintf (buffer, "Alarma -- %d:%d", hora, minut);
	}

	QString str;

	str = buffer;
	setText(str);
}

void MyLabel::setMin(int min){
	minut = min;
	if (alarma) AlarmaOn();
}
void MyLabel::setHour(int hour){
	hora = hour;
	if (alarma) AlarmaOn();
}

void MyLabel::reset(){
	emit reseta(0);
    hora = 0;
    minut = 0;
}
