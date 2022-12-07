#include "colorchange.h"

ColorChange::ColorChange()
{
}

int ColorChange::GetRed(const QColor &c)
{
    mRed=c.red();
    return mRed;
}
int ColorChange::GetGreen(const QColor &c)
{
    mGreen=c.green();
    return mGreen;
}
int ColorChange::GetBlue(const QColor &c)
{
    mBlue=c.blue();
    return mBlue;
}

double ColorChange::GetXYZ_X(const QColor& c)
{
    float var_R = (c.red() / 255.0f); //R from 0 to 255
    float var_G = (c.green() / 255.0f); //G from 0 to 255
    float var_B = (c.blue() / 255.0f); //B from 0 to 255

    if (var_R > 0.04045f) {
        var_R = powf(( (var_R + 0.055f) / 1.055f), 2.4f);
    } else {
        var_R = var_R / 12.92f;
    }

    if (var_G > 0.04045) {
        var_G = powf(( (var_G + 0.055f) / 1.055f), 2.4f);
    } else {
        var_G = var_G / 12.92f;
    }

    if (var_B > 0.04045f) {
        var_B = powf(( (var_B + 0.055f) / 1.055f), 2.4f);
    } else {
        var_B = var_B / 12.92f;
    }

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;

    mXYZ_X = var_R * 0.4124f + var_G * 0.3576f + var_B * 0.1805f;
    return mXYZ_X;
}
double ColorChange::GetXYZ_Y(const QColor& c)
{
    float var_R = (c.red() / 255.0f); //R from 0 to 255
    float var_G = (c.green() / 255.0f); //G from 0 to 255
    float var_B = (c.blue() / 255.0f); //B from 0 to 255

    if (var_R > 0.04045f) {
        var_R = powf(( (var_R + 0.055f) / 1.055f), 2.4f);
    } else {
        var_R = var_R / 12.92f;
    }

    if (var_G > 0.04045) {
        var_G = powf(( (var_G + 0.055f) / 1.055f), 2.4f);
    } else {
        var_G = var_G / 12.92f;
    }

    if (var_B > 0.04045f) {
        var_B = powf(( (var_B + 0.055f) / 1.055f), 2.4f);
    } else {
        var_B = var_B / 12.92f;
    }

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;
    mXYZ_Y = var_R * 0.2126f + var_G * 0.7152f + var_B * 0.0722f;
    return mXYZ_Y;
}
double ColorChange::GetXYZ_Z(const QColor& c)
{
    float var_R = (c.red() / 255.0f); //R from 0 to 255
    float var_G = (c.green() / 255.0f); //G from 0 to 255
    float var_B = (c.blue() / 255.0f); //B from 0 to 255

    if (var_R > 0.04045f) {
        var_R = powf(( (var_R + 0.055f) / 1.055f), 2.4f);
    } else {
        var_R = var_R / 12.92f;
    }

    if (var_G > 0.04045) {
        var_G = powf(( (var_G + 0.055f) / 1.055f), 2.4f);
    } else {
        var_G = var_G / 12.92f;
    }

    if (var_B > 0.04045f) {
        var_B = powf(( (var_B + 0.055f) / 1.055f), 2.4f);
    } else {
        var_B = var_B / 12.92f;
    }

    var_R = var_R * 100;
    var_G = var_G * 100;
    var_B = var_B * 100;
    mXYZ_Z = var_R * 0.0193f + var_G * 0.1192f + var_B * 0.9505f;
    return mXYZ_Z;
}

double ColorChange::GetCMYK_C(const QColor &c)
{
    mCMYK_K=qMin(qMin(1-(double)GetRed(c)/255,1-(double)GetGreen(c)/255),1-(double)GetBlue(c)/255);
    if(mCMYK_K==1)
    {
        mCMYK_C=0.00;
    }
    else
    {
        mCMYK_C=(1-(double)mRed/255-mCMYK_K)/(1-mCMYK_K);
    }
    return mCMYK_C;
}
double ColorChange::GetCMYK_M(const QColor &c)
{
    mCMYK_K=qMin(qMin(1-(double)GetRed(c)/255,1-(double)GetGreen(c)/255),1-(double)GetBlue(c)/255);
    if(mCMYK_K==1)
    {
        mCMYK_M=0.00;
    }
    else
    {
        mCMYK_M=(1-(double)mGreen/255-mCMYK_K)/(1-mCMYK_K);
    }
    return mCMYK_M;
}
double ColorChange::GetCMYK_Y(const QColor &c)
{
    mCMYK_K=qMin(qMin(1-(double)GetRed(c)/255,1-(double)GetGreen(c)/255),1-(double)GetBlue(c)/255);
    if(mCMYK_K==1)
    {
        mCMYK_Y=0.00;
    }
    else
    {
        mCMYK_Y=(1-(double)mBlue/255-mCMYK_K)/(1-mCMYK_K);
    }
    return mCMYK_Y;
}
double ColorChange::GetCMYK_K(const QColor &c)
{
    mCMYK_K=qMin(qMin(1-(double)GetRed(c)/255,1-(double)GetGreen(c)/255),1-(double)GetBlue(c)/255);
    return mCMYK_K;
}
double fXYZ_LAB(double x)
{
    double y;
    if(x>/*powf((double)6/29,3)*/(double)216/24389)
    {
        y=powf(x,((double)1/3));
    }else
    {
        //        y=((double)1/3)*powf((double)29/6,3)*x+((double)16/116);
        y=(double)((double)24389/27*x+16)/116;
    }
    return y;
}
double ColorChange::GetLAB_L(const QColor &c)
{
    double var_L=GetXYZ_Y(c)/100;
    mLAB_L=116*fXYZ_LAB(var_L)-16;
    return mLAB_L;
}
double ColorChange::GetLAB_A(const QColor &c)
{
    double var_A=GetXYZ_X(c)/95.047;
    double var_L=GetXYZ_Y(c)/100;
    mLAB_A=500*(fXYZ_LAB(var_A)-fXYZ_LAB(var_L));
    return mLAB_A;
}
double ColorChange::GetLAB_B(const QColor &c)
{
    double var_L=GetXYZ_Y(c)/100;
    double var_B=GetXYZ_Z(c)/108.883;
    mLAB_B=200*(fXYZ_LAB(var_L)-fXYZ_LAB(var_B));
    return mLAB_B;
}

int ColorChange::GetHue(const QColor& c)
{
    double max=qMax(c.red(),qMax(c.green(),c.blue()));
    double min=qMin(c.red(),qMin(c.green(),c.blue()));
    if(max==min)
    {
        mHue=0.00;
    }
    else
    {
        if(max==c.red()&&c.green()>=c.blue())
        {
            mHue=60*((c.green()-c.blue())/(max-min));
        }
        if(max==c.red()&&c.green()<c.blue())
        {
            mHue=60*((c.green()-c.blue())/(max-min))+360;
        }
        if(max==c.green())
        {
            mHue=60*((c.blue()-c.red())/(max-min))+120;
        }
        if(max==c.blue())
        {
            mHue=60*((c.red()-c.green())/(max-min))+240;
        }
    }
    return (int)mHue;
}
double ColorChange::GetHSV_S(const QColor &c)
{
    double max=qMax(c.red(),qMax(c.green(),c.blue()));
    double min=qMin(c.red(),qMin(c.green(),c.blue()));
    if(max==0)
    {
        mHSV_S=0.00;
    }
    else
    {
        mHSV_S=((max-min)/max);
    }
    return mHSV_S;
}
double ColorChange::GetHSV_V(const QColor &c)
{
    double max=qMax(c.red(),qMax(c.green(),c.blue()));
    mHSV_V=max/255;
    return mHSV_V;
}
double ColorChange::GetHSL_S(const QColor &c)
{
    double max=qMax(c.red(),qMax(c.green(),c.blue()));
    double min=qMin(c.red(),qMin(c.green(),c.blue()));
    if(GetHSL_L(c)==0||max==min)
    {
        mHSL_S=0.00;
    }
    if(GetHSL_L(c)>0&&GetHSL_L(c)<=0.5)
    {
        mHSL_S=((max-min)/(max+min));
    }
    if(GetHSL_L(c)>0.5)
    {
        mHSL_S=((max-min)/(2-(max+min)));
    }
    return mHSL_S;
}
double ColorChange::GetHSL_L(const QColor &c)
{
    double max=qMax(c.red(),qMax(c.green(),c.blue()));
    double min=qMin(c.red(),qMin(c.green(),c.blue()));
    mHSL_L=((max+min)/2)/255;
    return mHSL_L;
}

QColor ColorChange::XYZ_RGB(double x,double y,double z)
{
    double var_X=3.2406*(x/100)-1.5375*(y/100)-0.4986*(z/100);
    double var_Y=-0.9689*(x/100)+1.8758*(y/100)+0.0415*(z/100);
    double var_Z=0.0557*(x/100)-0.2040*(y/100)+1.0570*(z/100);
    if(var_X>=0.0031308)
    {
        var_X=1.055*powf(var_X,(1/2.4))-0.055;
    }else
    {
        var_X=12.92*var_X;
    }
    if(var_Y>=0.0031308)
    {
        var_Y=1.055*powf(var_Y,(1/2.4))-0.055;
    }else
    {
        var_Y=12.92*var_Y;
    }
    if(var_Z>=0.0031308)
    {
        var_Z=1.055*powf(var_Z,(1/2.4))-0.055;
    }else
    {
        var_Z=12.92*var_Z;
    }
    double iRed=var_X*255;
    double iGreen=var_Y*255;
    double iBlue=var_Z*255;
    QColor color;
    color.setRgb((int)iRed,(int)iGreen,(int)iBlue);
    return color;
}
QColor ColorChange::CMYK_RGB(double c,double m,double y,double k)
{
    double iRed=255*(1-c)*(1-k);
    double iGreen=255*(1-m)*(1-k);
    double iBlue=255*(1-y)*(1-k);
    QColor color;
    color.setRgb((int)iRed,(int)iGreen,(int)iBlue);
    return color;
}
double fLAB_XYZ(double x)
{
    double y;
    if(powf(x,3)>(double)216/24389)
    {
        y=powf(x,3);
    }else
    {
        y=(double)(116*x-16)/((double)24389/27);
    }
    return y;
}
QColor ColorChange::LAB_RGB(double l,double a,double b)
{
    if(l>(((double)24389/27)*((double)216/24389)))
    {
        mXYZ_X=powf((double)(l+16)/116,3)*95.047;
    }else
    {
        mXYZ_X=l/((double)24389/27)*95.047;
    }
    //mXYZ_X=fLAB_XYZ((l+16)/116)*95.047;
    mXYZ_Y=fLAB_XYZ(a/500+(double)(l+16)/116)*100;
    mXYZ_Z=fLAB_XYZ((double)(l+16)/116-(double)b/200)*108.883;
    QColor color;
    color=XYZ_RGB(mXYZ_X,mXYZ_Y,mXYZ_Z);
    return color;
}
QColor ColorChange::HSV_RGB(int h, double s, double v)
{
    if(h==360)
    {
        h=0;
    }
    double c=v*s;
    double x=c*(1-(abs(fmod((double)h/60.00,2.00)-1)));
    double m=v-c;
    double R,G,B;
    if(0<=h&&h<60)
    {
        R=c;
        G=x;
        B=0;
    }
    if(60<=h&&h<120)
    {
        R=x;
        G=c;
        B=0;
    }
    if(120<=h&&h<180)
    {
        R=0;
        G=c;
        B=x;
    }
    if(180<=h&&h<240)
    {
        R=0;
        G=x;
        B=c;
    }
    if(240<=h&&h<300)
    {
        R=x;
        G=0;
        B=c;
    }
    if(300<=h&&h<360)
    {
        R=c;
        G=0;
        B=x;
    }
    double iRed=(R+m)*255;
    double iGreen=(G+m)*255;
    double iBlue=(B+m)*255;
    QColor color;
    color.setRgb((int)iRed,(int)iGreen,(int)iBlue);
    return color;
}

QColor ColorChange::HSL_RGB(int h, double s, double l)
{
    double c=(1-abs(2*l-1))*s;
    double x=c*(1-(abs(fmod((double)h/60.00,2.00)-1)));
    double m=l-c/2;
    double R,G,B;
    if(0<=h&&h<60)
    {
        R=c;
        G=x;
        B=0;
    }
    if(60<=h&&h<120)
    {
        R=x;
        G=c;
        B=0;
    }
    if(120<=h&&h<180)
    {
        R=0;
        G=c;
        B=x;
    }
    if(180<=h&&h<240)
    {
        R=0;
        G=x;
        B=c;
    }
    if(240<=h&&h<300)
    {
        R=x;
        G=0;
        B=c;
    }
    if(300<=h&&h<360)
    {
        R=c;
        G=0;
        B=x;
    }
    double iRed=(R+m)*255;
    double iGreen=(G+m)*255;
    double iBlue=(B+m)*255;
    QColor color;
    color.setRgb((int)iRed,(int)iGreen,(int)iBlue);
    return color;
}
