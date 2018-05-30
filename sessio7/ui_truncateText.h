/********************************************************************************
** Form generated from reading UI file 'truncateText.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRUNCATETEXT_H
#define UI_TRUNCATETEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyLineEdit.h"
#include "MyTagEdit.h"

QT_BEGIN_NAMESPACE

class Ui_TruncateText
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    MyTagEdit *label_3;
    QSlider *horizontalSlider;
    MyLineEdit *lineEdit;

    void setupUi(QWidget *TruncateText)
    {
        if (TruncateText->objectName().isEmpty())
            TruncateText->setObjectName(QStringLiteral("TruncateText"));
        TruncateText->resize(651, 557);
        verticalLayoutWidget = new QWidget(TruncateText);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 130, 171, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new MyTagEdit(TruncateText);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 180, 311, 18));
        horizontalSlider = new QSlider(TruncateText);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(90, 230, 491, 20));
        horizontalSlider->setMaximum(20);
        horizontalSlider->setOrientation(Qt::Horizontal);
        lineEdit = new MyLineEdit(TruncateText);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(280, 140, 281, 32));

        retranslateUi(TruncateText);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), label_3, SLOT(AyLmao(int)));
        QObject::connect(lineEdit, SIGNAL(textEdited(QString)), label_3, SLOT(setText(QString)));

        QMetaObject::connectSlotsByName(TruncateText);
    } // setupUi

    void retranslateUi(QWidget *TruncateText)
    {
        TruncateText->setWindowTitle(QApplication::translate("TruncateText", "Form", 0));
        label->setText(QApplication::translate("TruncateText", "Text:", 0));
        label_2->setText(QApplication::translate("TruncateText", "RealText", 0));
        label_3->setText(QApplication::translate("TruncateText", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class TruncateText: public Ui_TruncateText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUNCATETEXT_H
