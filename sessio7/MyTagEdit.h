#include <QSlider>
class MyTagEdit: public QSlider
{
	Q_OBJECT

	public:
		MyTagEdit (QWidget *parent);
	public slots:
		void AyLmao (int slider);
	signals:
		void enviaText (const QString &);
	private:
		int size;
};
