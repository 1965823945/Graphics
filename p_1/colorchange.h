#ifndef COLORCHANGE_H
#define COLORCHANGE_H
#include <QColor>
#include <QtMath>

class ColorChange
{
private:

    int mRed,mBlue,mGreen;
    double mXYZ_X,mXYZ_Y,mXYZ_Z;
    double mCMYK_C,mCMYK_M,mCMYK_Y,mCMYK_K;
    double mLAB_L,mLAB_A,mLAB_B;
    double mHue;
    double mHSV_S,mHSV_V,mHSL_S,mHSL_L;

public:
    ColorChange();
    int GetRed(const QColor& );
    int GetGreen(const QColor& );
    int GetBlue(const QColor& );

    double GetXYZ_X(const QColor& );
    double GetXYZ_Y(const QColor& );
    double GetXYZ_Z(const QColor& );

    double GetCMYK_C(const QColor& );
    double GetCMYK_M(const QColor& );
    double GetCMYK_Y(const QColor& );
    double GetCMYK_K(const QColor& );

    double GetLAB_L(const QColor& );
    double GetLAB_A(const QColor& );
    double GetLAB_B(const QColor& );

    int GetHue(const QColor& );
    double GetHSV_S(const QColor& );
    double GetHSV_V(const QColor& );
    double GetHSL_S(const QColor& );
    double GetHSL_L(const QColor& );

    QColor XYZ_RGB(double,double,double);
    QColor CMYK_RGB(double,double,double,double);
    QColor LAB_RGB(double,double,double);
    QColor HSV_RGB(int,double,double);
    QColor HSL_RGB(int,double,double);

};

#endif // COLORCHANGE_H
