#include "ui_form.h"

class MyForm : public QWidget
{
	Q_OBJECT

	public: 
		MyForm(QWidget *parent = 0);

	private:
		Ui::form ui;
};
