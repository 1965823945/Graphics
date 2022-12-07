#ifndef Widget_H
#define Widget_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include "SVColorArea.h"
#include "HColorArea.h"
#include "PreviewColorArea.h"
#include "colorchange.h"

namespace Ui
{
class Widget;
}

class Widget : public QWidget,ColorChange
{
    Q_OBJECT
public:

    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void slotColorItemSel(const QColor &); // 同步饱和度与亮度区域、色调区域的颜色值

    void slotUpdateEditData(int, int, int); // 更新颜色编辑框的值
    void slotEditChanged(const QString &); // 编辑框文本改变
    void slotEditFinished(); // 编辑框编辑完成

    // HSV/RGB值改变触发的槽函数
    void slotValueChangedH(int);
    void slotValueChangedS(double);
    void slotValueChangedV(double);

    void slotValueChangedR(int);
    void slotValueChangedG(int);
    void slotValueChangedB(int);

    void slotValueChangedXYZ_X(double);
    void slotValueChangedXYZ_Y(double);
    void slotValueChangedXYZ_Z(double);

    void slotValueChangedCMYK_C(double);
    void slotValueChangedCMYK_M(double);
    void slotValueChangedCMYK_Y(double);
    void slotValueChangedCMYK_K(double);

    void slotValueChangedLAB_L(double);
    void slotValueChangedLAB_A(double);
    void slotValueChangedLAB_B(double);

    void slotValueChangedHSL_S(double);
    void slotValueChangedHSL_L(double);

private:
    Ui::Widget *ui;
    void updateRGB(const QColor &);
    void updateXYZ(const QColor &);
    void updateCMYK(const QColor &);
    void updateLAB(const QColor &);
    void updateHSV(const QColor &);
    void updateSL(const QColor &);
    void updateH16(const QColor &);

    QColor m_iColor;
    int m_iRed;
    int m_iGreen;
    int m_iBlue;
    int m_iHue; // 色调
    double m_iSaturation; // 饱和度
    double m_iBrightness; //亮度
    bool m_bNotEdit;


    int m_iRGB_R,m_iRGB_G,m_iRGB_B;
  //  int m_iHue;
    double m_iHSV_S,m_iHSV_V,m_iHSL_S,m_iHSL_L;

    double m_iCMYK_C,m_iCMYK_M,m_iCMYK_Y,m_iCMYK_K;


};
#endif // Widget_H
