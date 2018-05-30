#include "MyLineEdit.h"

void MyLineEdit::AyLmao(int slider) {
	QString test = text().left(slider);
	emit enviaText (test);
}
