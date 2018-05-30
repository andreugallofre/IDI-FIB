#include <QLineEdit>
class MyLineEdit: public QLineEdit
{
	Q_OBJECT

	public:
		MyLineEdit (QWidget *parent);
	public slots:
		void AyLmao (int slider);
	signals:
		void enviaText (const QString &);
};
