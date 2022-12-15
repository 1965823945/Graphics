/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "hcolorarea.h"
#include "previewcolorarea.h"
#include "svcolorarea.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label_4;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_3;
    SVColorArea *m_pSVColorArea;
    HColorArea *m_pHColorArea;
    PreviewColorArea *m_pPreviewColorArea;
    QDoubleSpinBox *m_pDoubleSpinBoxS;
    QSpinBox *m_pSpinBoxG;
    QSpinBox *m_pSpinBoxH;
    QSpinBox *m_pSpinBoxB;
    QSpinBox *m_pSpinBoxR;
    QDoubleSpinBox *m_pDoubleSpinBoxV;
    QDoubleSpinBox *m_pDoubleSpinBoxXYZ_Y;
    QDoubleSpinBox *m_pDoubleSpinBoxXYZ_Z;
    QDoubleSpinBox *m_pDoubleSpinBoxXYZ_X;
    QDoubleSpinBox *m_pDoubleSpinBoxCMYK_M;
    QDoubleSpinBox *m_pDoubleSpinBoxCMYK_Y;
    QDoubleSpinBox *m_pDoubleSpinBoxCMYK_C;
    QDoubleSpinBox *m_pDoubleSpinBoxLAB_A;
    QDoubleSpinBox *m_pDoubleSpinBoxLAB_B;
    QDoubleSpinBox *m_pDoubleSpinBoxLAB_L;
    QDoubleSpinBox *m_pDoubleSpinBoxHSL_S;
    QDoubleSpinBox *m_pDoubleSpinBoxHSL_L;
    QSpinBox *m_pSpinBoxHSL_H;
    QDoubleSpinBox *m_pDoubleSpinBoxCMYK_K;
    QLineEdit *m_pEditColor;
    QLabel *label_7;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(720, 400);
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(360, 190, 61, 20));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(360, 40, 61, 20));
        label->setFont(font);
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setEnabled(true);
        label_6->setGeometry(QRect(360, 290, 61, 20));
        label_6->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(360, 90, 61, 20));
        label_2->setFont(font);
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setEnabled(true);
        label_5->setGeometry(QRect(360, 240, 61, 20));
        label_5->setFont(font);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(360, 140, 61, 20));
        label_3->setFont(font);
        m_pSVColorArea = new SVColorArea(Widget);
        m_pSVColorArea->setObjectName(QString::fromUtf8("m_pSVColorArea"));
        m_pSVColorArea->setGeometry(QRect(30, 40, 256, 256));
        m_pHColorArea = new HColorArea(Widget);
        m_pHColorArea->setObjectName(QString::fromUtf8("m_pHColorArea"));
        m_pHColorArea->setGeometry(QRect(300, 33, 50, 334));
        m_pPreviewColorArea = new PreviewColorArea(Widget);
        m_pPreviewColorArea->setObjectName(QString::fromUtf8("m_pPreviewColorArea"));
        m_pPreviewColorArea->setGeometry(QRect(30, 310, 256, 50));
        m_pDoubleSpinBoxS = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxS->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxS"));
        m_pDoubleSpinBoxS->setGeometry(QRect(503, 240, 72, 28));
        m_pDoubleSpinBoxS->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxS->setMaximumSize(QSize(70, 26));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setWeight(50);
        m_pDoubleSpinBoxS->setFont(font1);
        m_pDoubleSpinBoxS->setAccelerated(true);
        m_pDoubleSpinBoxS->setMaximum(1.000000000000000);
        m_pDoubleSpinBoxS->setSingleStep(0.010000000000000);
        m_pSpinBoxG = new QSpinBox(Widget);
        m_pSpinBoxG->setObjectName(QString::fromUtf8("m_pSpinBoxG"));
        m_pSpinBoxG->setGeometry(QRect(503, 40, 72, 28));
        m_pSpinBoxG->setMinimumSize(QSize(72, 28));
        m_pSpinBoxG->setMaximumSize(QSize(70, 26));
        m_pSpinBoxG->setFont(font1);
        m_pSpinBoxG->setAccelerated(true);
        m_pSpinBoxG->setMaximum(255);
        m_pSpinBoxH = new QSpinBox(Widget);
        m_pSpinBoxH->setObjectName(QString::fromUtf8("m_pSpinBoxH"));
        m_pSpinBoxH->setGeometry(QRect(430, 240, 72, 28));
        m_pSpinBoxH->setMinimumSize(QSize(72, 28));
        m_pSpinBoxH->setMaximumSize(QSize(70, 26));
        m_pSpinBoxH->setFont(font1);
        m_pSpinBoxH->setAccelerated(true);
        m_pSpinBoxH->setMaximum(360);
        m_pSpinBoxB = new QSpinBox(Widget);
        m_pSpinBoxB->setObjectName(QString::fromUtf8("m_pSpinBoxB"));
        m_pSpinBoxB->setGeometry(QRect(576, 40, 72, 28));
        m_pSpinBoxB->setMinimumSize(QSize(72, 28));
        m_pSpinBoxB->setMaximumSize(QSize(70, 26));
        m_pSpinBoxB->setFont(font1);
        m_pSpinBoxB->setAccelerated(true);
        m_pSpinBoxB->setMaximum(255);
        m_pSpinBoxR = new QSpinBox(Widget);
        m_pSpinBoxR->setObjectName(QString::fromUtf8("m_pSpinBoxR"));
        m_pSpinBoxR->setGeometry(QRect(430, 40, 72, 28));
        m_pSpinBoxR->setMinimumSize(QSize(72, 28));
        m_pSpinBoxR->setMaximumSize(QSize(70, 26));
        m_pSpinBoxR->setFont(font1);
        m_pSpinBoxR->setAccelerated(true);
        m_pSpinBoxR->setMaximum(255);
        m_pDoubleSpinBoxV = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxV->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxV"));
        m_pDoubleSpinBoxV->setGeometry(QRect(576, 240, 72, 28));
        m_pDoubleSpinBoxV->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxV->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxV->setFont(font1);
        m_pDoubleSpinBoxV->setAccelerated(true);
        m_pDoubleSpinBoxV->setMaximum(1.000000000000000);
        m_pDoubleSpinBoxV->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxXYZ_Y = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxXYZ_Y->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxXYZ_Y"));
        m_pDoubleSpinBoxXYZ_Y->setEnabled(true);
        m_pDoubleSpinBoxXYZ_Y->setGeometry(QRect(503, 90, 72, 28));
        m_pDoubleSpinBoxXYZ_Y->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxXYZ_Y->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxXYZ_Y->setFont(font1);
        m_pDoubleSpinBoxXYZ_Y->setAccelerated(true);
        m_pDoubleSpinBoxXYZ_Y->setMaximum(100.000000000000000);
        m_pDoubleSpinBoxXYZ_Y->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxXYZ_Z = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxXYZ_Z->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxXYZ_Z"));
        m_pDoubleSpinBoxXYZ_Z->setEnabled(true);
        m_pDoubleSpinBoxXYZ_Z->setGeometry(QRect(576, 90, 72, 28));
        m_pDoubleSpinBoxXYZ_Z->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxXYZ_Z->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxXYZ_Z->setFont(font1);
        m_pDoubleSpinBoxXYZ_Z->setAccelerated(true);
        m_pDoubleSpinBoxXYZ_Z->setMaximum(109.000000000000000);
        m_pDoubleSpinBoxXYZ_Z->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxXYZ_X = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxXYZ_X->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxXYZ_X"));
        m_pDoubleSpinBoxXYZ_X->setEnabled(true);
        m_pDoubleSpinBoxXYZ_X->setGeometry(QRect(430, 90, 72, 28));
        m_pDoubleSpinBoxXYZ_X->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxXYZ_X->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxXYZ_X->setFont(font1);
        m_pDoubleSpinBoxXYZ_X->setAccelerated(true);
        m_pDoubleSpinBoxXYZ_X->setMaximum(96.000000000000000);
        m_pDoubleSpinBoxXYZ_X->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxCMYK_M = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxCMYK_M->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxCMYK_M"));
        m_pDoubleSpinBoxCMYK_M->setEnabled(true);
        m_pDoubleSpinBoxCMYK_M->setGeometry(QRect(503, 140, 72, 28));
        m_pDoubleSpinBoxCMYK_M->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxCMYK_M->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxCMYK_M->setFont(font1);
        m_pDoubleSpinBoxCMYK_M->setAccelerated(true);
        m_pDoubleSpinBoxCMYK_M->setMaximum(1.000000000000000);
        m_pDoubleSpinBoxCMYK_M->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxCMYK_Y = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxCMYK_Y->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxCMYK_Y"));
        m_pDoubleSpinBoxCMYK_Y->setEnabled(true);
        m_pDoubleSpinBoxCMYK_Y->setGeometry(QRect(576, 140, 72, 28));
        m_pDoubleSpinBoxCMYK_Y->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxCMYK_Y->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxCMYK_Y->setFont(font1);
        m_pDoubleSpinBoxCMYK_Y->setAccelerated(true);
        m_pDoubleSpinBoxCMYK_Y->setMaximum(1.000000000000000);
        m_pDoubleSpinBoxCMYK_Y->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxCMYK_C = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxCMYK_C->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxCMYK_C"));
        m_pDoubleSpinBoxCMYK_C->setEnabled(true);
        m_pDoubleSpinBoxCMYK_C->setGeometry(QRect(430, 140, 72, 28));
        m_pDoubleSpinBoxCMYK_C->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxCMYK_C->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxCMYK_C->setFont(font1);
        m_pDoubleSpinBoxCMYK_C->setAccelerated(true);
        m_pDoubleSpinBoxCMYK_C->setMaximum(1.000000000000000);
        m_pDoubleSpinBoxCMYK_C->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxLAB_A = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxLAB_A->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxLAB_A"));
        m_pDoubleSpinBoxLAB_A->setEnabled(true);
        m_pDoubleSpinBoxLAB_A->setGeometry(QRect(503, 190, 72, 28));
        m_pDoubleSpinBoxLAB_A->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxLAB_A->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxLAB_A->setFont(font1);
        m_pDoubleSpinBoxLAB_A->setAccelerated(true);
        m_pDoubleSpinBoxLAB_A->setMinimum(-128.000000000000000);
        m_pDoubleSpinBoxLAB_A->setMaximum(127.000000000000000);
        m_pDoubleSpinBoxLAB_A->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxLAB_B = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxLAB_B->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxLAB_B"));
        m_pDoubleSpinBoxLAB_B->setEnabled(true);
        m_pDoubleSpinBoxLAB_B->setGeometry(QRect(576, 190, 72, 28));
        m_pDoubleSpinBoxLAB_B->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxLAB_B->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxLAB_B->setFont(font1);
        m_pDoubleSpinBoxLAB_B->setAccelerated(true);
        m_pDoubleSpinBoxLAB_B->setMinimum(-128.000000000000000);
        m_pDoubleSpinBoxLAB_B->setMaximum(127.000000000000000);
        m_pDoubleSpinBoxLAB_B->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxLAB_L = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxLAB_L->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxLAB_L"));
        m_pDoubleSpinBoxLAB_L->setEnabled(true);
        m_pDoubleSpinBoxLAB_L->setGeometry(QRect(430, 190, 72, 28));
        m_pDoubleSpinBoxLAB_L->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxLAB_L->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxLAB_L->setFont(font1);
        m_pDoubleSpinBoxLAB_L->setAccelerated(true);
        m_pDoubleSpinBoxLAB_L->setMinimum(0.000000000000000);
        m_pDoubleSpinBoxLAB_L->setMaximum(100.000000000000000);
        m_pDoubleSpinBoxLAB_L->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxHSL_S = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxHSL_S->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxHSL_S"));
        m_pDoubleSpinBoxHSL_S->setEnabled(true);
        m_pDoubleSpinBoxHSL_S->setGeometry(QRect(503, 290, 72, 28));
        m_pDoubleSpinBoxHSL_S->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxHSL_S->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxHSL_S->setFont(font1);
        m_pDoubleSpinBoxHSL_S->setAccelerated(true);
        m_pDoubleSpinBoxHSL_S->setMaximum(1.000000000000000);
        m_pDoubleSpinBoxHSL_S->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxHSL_L = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxHSL_L->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxHSL_L"));
        m_pDoubleSpinBoxHSL_L->setEnabled(true);
        m_pDoubleSpinBoxHSL_L->setGeometry(QRect(576, 290, 72, 28));
        m_pDoubleSpinBoxHSL_L->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxHSL_L->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxHSL_L->setFont(font1);
        m_pDoubleSpinBoxHSL_L->setAccelerated(true);
        m_pDoubleSpinBoxHSL_L->setMaximum(1.000000000000000);
        m_pDoubleSpinBoxHSL_L->setSingleStep(0.010000000000000);
        m_pSpinBoxHSL_H = new QSpinBox(Widget);
        m_pSpinBoxHSL_H->setObjectName(QString::fromUtf8("m_pSpinBoxHSL_H"));
        m_pSpinBoxHSL_H->setEnabled(true);
        m_pSpinBoxHSL_H->setGeometry(QRect(430, 290, 72, 28));
        m_pSpinBoxHSL_H->setMinimumSize(QSize(72, 28));
        m_pSpinBoxHSL_H->setMaximumSize(QSize(70, 26));
        m_pSpinBoxHSL_H->setFont(font1);
        m_pSpinBoxHSL_H->setAccelerated(true);
        m_pSpinBoxHSL_H->setMaximum(360);
        m_pDoubleSpinBoxCMYK_K = new QDoubleSpinBox(Widget);
        m_pDoubleSpinBoxCMYK_K->setObjectName(QString::fromUtf8("m_pDoubleSpinBoxCMYK_K"));
        m_pDoubleSpinBoxCMYK_K->setEnabled(true);
        m_pDoubleSpinBoxCMYK_K->setGeometry(QRect(649, 140, 72, 28));
        m_pDoubleSpinBoxCMYK_K->setMinimumSize(QSize(72, 28));
        m_pDoubleSpinBoxCMYK_K->setMaximumSize(QSize(70, 26));
        m_pDoubleSpinBoxCMYK_K->setFont(font1);
        m_pDoubleSpinBoxCMYK_K->setAccelerated(true);
        m_pDoubleSpinBoxCMYK_K->setMinimum(0.000000000000000);
        m_pDoubleSpinBoxCMYK_K->setMaximum(1.000000000000000);
        m_pDoubleSpinBoxCMYK_K->setSingleStep(0.010000000000000);
        m_pDoubleSpinBoxCMYK_K->setValue(0.000000000000000);
        m_pEditColor = new QLineEdit(Widget);
        m_pEditColor->setObjectName(QString::fromUtf8("m_pEditColor"));
        m_pEditColor->setGeometry(QRect(430, 340, 71, 20));
        m_pEditColor->setFont(font1);
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setEnabled(true);
        label_7->setGeometry(QRect(360, 340, 61, 20));
        label_7->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "LAB", nullptr));
        label->setText(QCoreApplication::translate("Widget", "RGB", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "HSL", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "XYZ", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "HSV", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "CMYK", nullptr));
        m_pSpinBoxH->setSuffix(QCoreApplication::translate("Widget", "\302\260", nullptr));
        m_pSpinBoxHSL_H->setSuffix(QCoreApplication::translate("Widget", "\302\260", nullptr));
        m_pEditColor->setText(QCoreApplication::translate("Widget", "000000", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "H  #", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
