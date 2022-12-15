#include "widget.h"
#include "ui_widget.h"
#include <QtGlobal>
#include "colorchange.h"

Widget::Widget(QWidget *parent)
    :QWidget(parent)
    ,ColorChange()
    ,ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 正则表达式应用在颜色编辑栏
    QRegExp rx("(\\d?[a-f]?){0,6}");
    ui->m_pEditColor->setValidator(new QRegExpValidator(rx, this));
    ui->m_pEditColor->setText("000000");


    // 各个界面的信号槽连接
    connect(ui->m_pSVColorArea, &SVColorArea::sigSvChanged, ui->m_pPreviewColorArea, &PreviewColorArea::slotSvChanged);
    connect(ui->m_pPreviewColorArea, &PreviewColorArea::sigSvChanged, this, &Widget::slotUpdateEditData);
    connect(ui->m_pHColorArea, &HColorArea::sigHueChanged, ui->m_pSVColorArea, &SVColorArea::slotHueChanged);

    // 颜色编辑框改变
    connect(ui->m_pEditColor, &QLineEdit::textEdited, this, &Widget::slotEditChanged);
    connect(ui->m_pEditColor, &QLineEdit::editingFinished, this, &Widget::slotEditFinished);

    // 计数器控件
    connect(ui->m_pSpinBoxR, SIGNAL(valueChanged(int)), this, SLOT(slotValueChangedR(int)));
    connect(ui->m_pSpinBoxG, SIGNAL(valueChanged(int)), this, SLOT(slotValueChangedG(int)));
    connect(ui->m_pSpinBoxB, SIGNAL(valueChanged(int)), this, SLOT(slotValueChangedB(int)));

    connect(ui->m_pDoubleSpinBoxXYZ_X, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedXYZ_X(double)));
    connect(ui->m_pDoubleSpinBoxXYZ_Y, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedXYZ_Y(double)));
    connect(ui->m_pDoubleSpinBoxXYZ_Z, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedXYZ_Z(double)));

    connect(ui->m_pDoubleSpinBoxCMYK_C, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedCMYK_C(double)));
    connect(ui->m_pDoubleSpinBoxCMYK_M, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedCMYK_M(double)));
    connect(ui->m_pDoubleSpinBoxCMYK_Y, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedCMYK_Y(double)));
    connect(ui->m_pDoubleSpinBoxCMYK_K, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedCMYK_K(double)));

    connect(ui->m_pDoubleSpinBoxLAB_L, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedLAB_L(double)));
    connect(ui->m_pDoubleSpinBoxLAB_A, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedLAB_A(double)));
    connect(ui->m_pDoubleSpinBoxLAB_B, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedLAB_B(double)));

    connect(ui->m_pSpinBoxH, SIGNAL(valueChanged(int)), this, SLOT(slotValueChangedH(int)));
    connect(ui->m_pDoubleSpinBoxS, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedS(double)));
    connect(ui->m_pDoubleSpinBoxV, SIGNAL(valueChanged(double)), this, SLOT(slotValueChangedV(double)));

    connect(ui->m_pSpinBoxHSL_H, SIGNAL(valueChanged(int)), this, SLOT(slotValueChangedH(int)));
    connect(ui->m_pDoubleSpinBoxHSL_L,SIGNAL(valueChanged(double)),this,SLOT(slotValueChangedHSL_L(double)));
    connect(ui->m_pDoubleSpinBoxHSL_S,SIGNAL(valueChanged(double)),this,SLOT(slotValueChangedHSL_S(double)));
}

Widget::~Widget()
{
    m_bNotEdit = false;
}


// 同步饱和度与亮度区域、色调区域的颜色值
void Widget::slotColorItemSel(const QColor &c)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    // 同步饱和度与亮度区域、色调区域的颜色值
    ui->m_pHColorArea->setHue(c.hue());
    ui->m_pSVColorArea->setColor(c);

    m_bNotEdit = false;
}

// 值改变触发的槽函数

void Widget::slotValueChangedR(int r)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    int iGreen = ui->m_pSpinBoxG->value();
    int iBlue = ui->m_pSpinBoxB->value();
    QColor color;
    color.setRgb(r, iGreen, iBlue);

    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pSpinBoxR->setValue(r);
//    ui->m_pSpinBoxG->setValue(GetGreen(color));
//    ui->m_pSpinBoxB->setValue(GetBlue(color));

    m_bNotEdit = false;
}

void Widget::slotValueChangedG(int g)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    int iRed = ui->m_pSpinBoxR->value();
    int iBlue = ui->m_pSpinBoxB->value();
    QColor color;
    color.setRgb(iRed, g, iBlue);

    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pSpinBoxR->setValue(GetRed(color));
//    ui->m_pSpinBoxG->setValue(g);
//    ui->m_pSpinBoxB->setValue(GetBlue(color));

    m_bNotEdit = false;
}

void Widget::slotValueChangedB(int b)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    int iRed = ui->m_pSpinBoxR->value();
    int iGreen = ui->m_pSpinBoxG->value();
    QColor color;
    color.setRgb(iRed, iGreen, b);

    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pSpinBoxR->setValue(GetRed(color));
//    ui->m_pSpinBoxG->setValue(GetGreen(color));
//    ui->m_pSpinBoxB->setValue(b);

    m_bNotEdit = false;
}
void Widget::slotValueChangedXYZ_X(double x)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;
    double Y=ui->m_pDoubleSpinBoxXYZ_Y->value();
    double Z=ui->m_pDoubleSpinBoxXYZ_Z->value();

    QColor color;
    color=XYZ_RGB(x,Y,Z);

    updateRGB(color);
    updateH16(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxXYZ_X->setValue(x);
//    ui->m_pDoubleSpinBoxXYZ_Y->setValue(GetXYZ_Y(color));
//    ui->m_pDoubleSpinBoxXYZ_Z->setValue(GetXYZ_Z(color));

    m_bNotEdit = false;
}
void Widget::slotValueChangedXYZ_Y(double y)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;
    double X=ui->m_pDoubleSpinBoxXYZ_X->value();
    double Z=ui->m_pDoubleSpinBoxXYZ_Z->value();

    QColor color;
    color=XYZ_RGB(X,y,Z);

    updateRGB(color);
    updateH16(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxXYZ_X->setValue(GetXYZ_X(color));
//    ui->m_pDoubleSpinBoxXYZ_Y->setValue(y);
//    ui->m_pDoubleSpinBoxXYZ_Z->setValue(GetXYZ_Z(color));

    m_bNotEdit = false;
}
void Widget::slotValueChangedXYZ_Z(double z)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;
    double X=ui->m_pDoubleSpinBoxXYZ_X->value();
    double Y=ui->m_pDoubleSpinBoxXYZ_Y->value();

    QColor color;
    color=XYZ_RGB(X,Y,z);

    updateRGB(color);
    updateH16(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxXYZ_X->setValue(GetXYZ_X(color));
//    ui->m_pDoubleSpinBoxXYZ_Y->setValue(GetXYZ_Y(color));
//    ui->m_pDoubleSpinBoxXYZ_Z->setValue(z);

    m_bNotEdit = false;
}
void Widget::slotValueChangedCMYK_C(double c)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double M=ui->m_pDoubleSpinBoxCMYK_M->value();
    double Y=ui->m_pDoubleSpinBoxCMYK_Y->value();
    double K=ui->m_pDoubleSpinBoxCMYK_K->value();
    QColor color;
    color=CMYK_RGB(c,M,Y,K);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxCMYK_C->setValue(c);
//    ui->m_pDoubleSpinBoxCMYK_M->setValue(GetCMYK_M(color));
//    ui->m_pDoubleSpinBoxCMYK_Y->setValue(GetCMYK_Y(color));
//    ui->m_pDoubleSpinBoxCMYK_K->setValue(GetCMYK_K(color));

    m_bNotEdit = false;
}

void Widget::slotValueChangedCMYK_M(double m)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double C=ui->m_pDoubleSpinBoxCMYK_C->value();
    double Y=ui->m_pDoubleSpinBoxCMYK_Y->value();
    double K=ui->m_pDoubleSpinBoxCMYK_K->value();
    QColor color;
    color=CMYK_RGB(C,m,Y,K);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxCMYK_C->setValue(GetCMYK_C(color));
//    ui->m_pDoubleSpinBoxCMYK_M->setValue(m);
//    ui->m_pDoubleSpinBoxCMYK_Y->setValue(GetCMYK_Y(color));
//    ui->m_pDoubleSpinBoxCMYK_K->setValue(GetCMYK_K(color));


    m_bNotEdit = false;
}

void Widget::slotValueChangedCMYK_Y(double y)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double C=ui->m_pDoubleSpinBoxCMYK_C->value();
    double M=ui->m_pDoubleSpinBoxCMYK_M->value();
    double K=ui->m_pDoubleSpinBoxCMYK_K->value();
    QColor color;
    color=CMYK_RGB(C,M,y,K);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxCMYK_C->setValue(GetCMYK_C(color));
//    ui->m_pDoubleSpinBoxCMYK_M->setValue(GetCMYK_M(color));
//    ui->m_pDoubleSpinBoxCMYK_Y->setValue(y);
//    ui->m_pDoubleSpinBoxCMYK_K->setValue(GetCMYK_K(color));

    m_bNotEdit = false;
}
void Widget::slotValueChangedCMYK_K(double k)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double C=ui->m_pDoubleSpinBoxCMYK_C->value();
    double M=ui->m_pDoubleSpinBoxCMYK_M->value();
    double Y=ui->m_pDoubleSpinBoxCMYK_Y->value();
    QColor color;
    color=CMYK_RGB(C,M,Y,k);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxCMYK_C->setValue(GetCMYK_C(color));
//    ui->m_pDoubleSpinBoxCMYK_M->setValue(GetCMYK_M(color));
//    ui->m_pDoubleSpinBoxCMYK_Y->setValue(GetCMYK_Y(color));
//    ui->m_pDoubleSpinBoxCMYK_K->setValue(k);

    m_bNotEdit = false;
}
void Widget::slotValueChangedLAB_L(double l)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double A=ui->m_pDoubleSpinBoxLAB_A->value();
    double B=ui->m_pDoubleSpinBoxLAB_B->value();
    QColor color;
    color=LAB_RGB(l,A,B);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxLAB_L->setValue(l);
//    ui->m_pDoubleSpinBoxLAB_A->setValue(GetLAB_A(color));
//    ui->m_pDoubleSpinBoxLAB_B->setValue(GetLAB_B(color));

    m_bNotEdit = false;
}
void Widget::slotValueChangedLAB_A(double a)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double L=ui->m_pDoubleSpinBoxLAB_L->value();
    double B=ui->m_pDoubleSpinBoxLAB_B->value();
    QColor color;
    color=LAB_RGB(L,a,B);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxLAB_L->setValue(GetLAB_L(color));
//    ui->m_pDoubleSpinBoxLAB_A->setValue(a);
//    ui->m_pDoubleSpinBoxLAB_B->setValue(GetLAB_B(color));

    m_bNotEdit = false;
}
void Widget::slotValueChangedLAB_B(double b)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double L=ui->m_pDoubleSpinBoxLAB_L->value();
    double A=ui->m_pDoubleSpinBoxLAB_A->value();

    QColor color;
    color=LAB_RGB(L,A,b);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateHSV(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxLAB_L->setValue(GetLAB_L(color));
//    ui->m_pDoubleSpinBoxLAB_A->setValue(GetLAB_A(color));
//    ui->m_pDoubleSpinBoxLAB_B->setValue(b);

    m_bNotEdit = false;
}
void Widget::slotValueChangedH(int h)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double s = ui->m_pDoubleSpinBoxS->value();
    double v = ui->m_pDoubleSpinBoxV->value();
    QColor color;
    color =HSV_RGB(h,s,v);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateSL(color);

//    ui->m_pSpinBoxH->setValue(h);
//    ui->m_pSpinBoxHSL_H->setValue(h);

    ui->m_pHColorArea->setHue(h);
    ui->m_pSVColorArea->setHue(h);
    ui->m_pPreviewColorArea->setNewColor(color);

    m_bNotEdit = false;
}

void Widget::slotValueChangedS(double s)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    int h=ui->m_pSpinBoxH->value();
    double v = ui->m_pDoubleSpinBoxV->value();

    QColor color;
    color =HSV_RGB(h,s,v);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxS->setValue(s);

    ui->m_pSVColorArea->setSaturation(s*255);

    ui->m_pPreviewColorArea->setNewColor(color);

    m_bNotEdit = false;
}

void Widget::slotValueChangedV(double v)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    int h=ui->m_pSpinBoxH->value();
    double s = ui->m_pDoubleSpinBoxS->value();

    QColor color;
    color =HSV_RGB(h,s,v);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateSL(color);

//    ui->m_pDoubleSpinBoxV->setValue(v);

    ui->m_pSVColorArea->setBrightness(v*255);

    ui->m_pPreviewColorArea->setNewColor(color);

    m_bNotEdit = false;
}

void Widget::slotValueChangedHSL_S(double Hs)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double iHSL_L=ui->m_pDoubleSpinBoxHSL_L->value();
    double iHSL_H=ui->m_pSpinBoxHSL_H->value();
    QColor color;
    color=HSL_RGB(iHSL_H,Hs,iHSL_L);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);

//    ui->m_pDoubleSpinBoxHSL_S->setValue(Hs);
//    ui->m_pDoubleSpinBoxHSL_L->setValue(GetHSL_L(color));

    m_bNotEdit = false;
}
void Widget::slotValueChangedHSL_L(double Hl)
{
    if (m_bNotEdit)
    {
        return;
    }
    m_bNotEdit = true;

    double iHSL_S=ui->m_pDoubleSpinBoxHSL_S->value();
    double iHSL_H=ui->m_pSpinBoxHSL_H->value();
    QColor color;
    color=HSL_RGB(iHSL_H,iHSL_S,Hl);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);

//    ui->m_pDoubleSpinBoxHSL_S->setValue(GetHSL_S(color));
//    ui->m_pDoubleSpinBoxHSL_L->setValue(Hl);

    m_bNotEdit = false;
}
void Widget::updateRGB(const QColor &color)
{
    ui->m_pSpinBoxR->setValue(GetRed(color));
    ui->m_pSpinBoxG->setValue(GetGreen(color));
    ui->m_pSpinBoxB->setValue(GetBlue(color));

//    QString strR = QString::number(GetRed(color), 16);
//    QString strG = QString::number(GetGreen(color), 16);
//    QString strB = QString::number(GetBlue(color), 16);
//    QString strRgb = QString("%1%2%3").arg(QString("%1").arg(strR.size() == 1 ? strR.prepend("0") : strR),
//                                           QString("%1").arg(strG.size() == 1 ? strG.prepend("0") : strG),
//                                           QString("%1").arg(strB.size() == 1 ? strB.prepend("0") : strB));
//    ui->m_pEditColor->setText(strRgb);
}
void Widget::updateH16(const QColor &color)
{
    QString strR = QString::number(GetRed(color), 16);
    QString strG = QString::number(GetGreen(color), 16);
    QString strB = QString::number(GetBlue(color), 16);
    QString strRgb = QString("%1%2%3").arg(QString("%1").arg(strR.size() == 1 ? strR.prepend("0") : strR),
                                           QString("%1").arg(strG.size() == 1 ? strG.prepend("0") : strG),
                                           QString("%1").arg(strB.size() == 1 ? strB.prepend("0") : strB));
    ui->m_pEditColor->setText(strRgb);
}

void Widget::updateXYZ(const QColor &color)
{
    ui->m_pDoubleSpinBoxXYZ_X->setValue(GetXYZ_X(color));
    ui->m_pDoubleSpinBoxXYZ_Y->setValue(GetXYZ_Y(color));
    ui->m_pDoubleSpinBoxXYZ_Z->setValue(GetXYZ_Z(color));
}
void Widget::updateCMYK(const QColor &color)
{
    ui->m_pDoubleSpinBoxCMYK_C->setValue(GetCMYK_C(color));
    ui->m_pDoubleSpinBoxCMYK_M->setValue(GetCMYK_M(color));
    ui->m_pDoubleSpinBoxCMYK_Y->setValue(GetCMYK_Y(color));
    ui->m_pDoubleSpinBoxCMYK_K->setValue(GetCMYK_K(color));
}
void Widget::updateLAB(const QColor &color)
{
    ui->m_pDoubleSpinBoxLAB_L->setValue(GetLAB_L(color));
    ui->m_pDoubleSpinBoxLAB_A->setValue(GetLAB_A(color));
    ui->m_pDoubleSpinBoxLAB_B->setValue(GetLAB_B(color));
}

void Widget::updateHSV(const QColor &color)
{
    ui->m_pSpinBoxH->setValue(GetHue(color));
    ui->m_pSpinBoxHSL_H->setValue(GetHue(color));

    ui->m_pDoubleSpinBoxS->setValue(GetHSV_S(color));
    ui->m_pDoubleSpinBoxV->setValue(GetHSV_V(color));

    ui->m_pHColorArea->setHue(GetHue(color));

    ui->m_pSVColorArea->setHue(GetHue(color));
    ui->m_pSVColorArea->setSaturation(GetHSV_S(color)*255);
    ui->m_pSVColorArea->setBrightness(GetHSV_V(color)*255);

    ui->m_pPreviewColorArea->setNewColor(color);
}
void Widget::updateSL(const QColor &color)
{
    ui->m_pDoubleSpinBoxHSL_S->setValue(GetHSL_S(color));
    ui->m_pDoubleSpinBoxHSL_L->setValue(GetHSL_L(color));
}

// 更新颜色编辑框的值
void Widget::slotUpdateEditData(int h, int s, int v)
{
    m_bNotEdit = true;

    m_iHue = h;
    m_iSaturation = s;
    m_iBrightness = v;
    QColor color;
    color.setHsv(h, s, v);

    updateRGB(color);
    updateH16(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateSL(color);

    ui->m_pSpinBoxH->setValue(h);
    ui->m_pSpinBoxHSL_H->setValue(h);

    ui->m_pDoubleSpinBoxS->setValue((double)s/255);

    ui->m_pDoubleSpinBoxV->setValue((double)v/255);

    m_bNotEdit = false;
}

// 编辑框文本改变
void Widget::slotEditChanged(const QString &strColor)
{
    m_bNotEdit = true;

    int r = 0, g = 0, b = 0;
    switch (strColor.length())
    {
    case 0:
    {
        r = g = b = 0;
    }
        break;
    case 1:
    case 2:
    {
        r = g = 0;
        bool ok;
        b = strColor.toInt(&ok, 16);
    }
        break;
    case 3:
    {
        QString strR = QString("%1%2").arg(strColor.left(1), strColor.left(1));
        QString strG = QString("%1%2").arg(strColor.mid(1, 1), strColor.mid(1, 1));
        QString strB = QString("%1%2").arg(strColor.right(1), strColor.right(1));
        bool ok;
        r = strR.toInt(&ok, 16);
        g = strG.toInt(&ok, 16);
        b = strB.toInt(&ok, 16);
    }
        break;
    case 4:
    {
        r = 0;
        QString strG = QString("%1").arg(strColor.left(2));
        QString strB = QString("%1").arg(strColor.right(2));
        bool ok;
        g = strG.toInt(&ok, 16);
        b = strB.toInt(&ok, 16);
    }
        break;
    case 5:
    {
        QString strR = QString("%1").arg(strColor.left(1));
        QString strG = QString("%1").arg(strColor.mid(1, 2));
        QString strB = QString("%1").arg(strColor.right(2));
        bool ok;
        r = strR.toInt(&ok, 16);
        g = strG.toInt(&ok, 16);
        b = strB.toInt(&ok, 16);
    }
        break;
    case 6:
    {
        QString strR = QString("%1").arg(strColor.left(2));
        QString strG = QString("%1").arg(strColor.mid(2, 2));
        QString strB = QString("%1").arg(strColor.right(2));
        bool ok;
        r = strR.toInt(&ok, 16);
        g = strG.toInt(&ok, 16);
        b = strB.toInt(&ok, 16);
    }
        break;
    default:
        break;
    }

    QColor color;
    color.setRgb(r, g, b);
    updateRGB(color);
    updateXYZ(color);
    updateCMYK(color);
    updateLAB(color);
    updateHSV(color);
    updateSL(color);

    m_bNotEdit = false;
}

// 编辑框编辑完成
void Widget::slotEditFinished()
{
    QString strColor = ui->m_pEditColor->text();
    switch (strColor.length())
    {
    case 0:
    {
        ui->m_pEditColor->setText("000000");
    }
        break;
    case 1:
    {
        ui->m_pEditColor->setText(strColor.prepend("00000"));
    }
        break;
    case 2:
    {
        ui->m_pEditColor->setText(strColor.prepend("0000"));
    }
        break;
    case 3:
    {
        QString strR = QString("%1%2").arg(strColor.left(1), strColor.left(1));
        QString strG = QString("%1%2").arg(strColor.mid(1, 1), strColor.mid(1, 1));
        QString strB = QString("%1%2").arg(strColor.right(1), strColor.right(1));
        ui->m_pEditColor->setText(strR.append(strG).append(strB));
    }
        break;
    case 4:
    {
        QString strG = QString("%1").arg(strColor.left(2));
        QString strB = QString("%1").arg(strColor.right(2));
        ui->m_pEditColor->setText(strG.append(strB).prepend("00"));
    }
        break;
    case 5:
    {
        QString strR = QString("%1").arg(strColor.left(1));
        QString strG = QString("%1").arg(strColor.mid(1, 2));
        QString strB = QString("%1").arg(strColor.right(2));
        ui->m_pEditColor->setText(strR.append(strG).append(strB).prepend("0"));
    }
        break;
    case 6:
    {
        return;
    }
        break;
    default:
        break;
    }
}
