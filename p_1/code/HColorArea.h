#ifndef HCOLORAREA_H
#define HCOLORAREA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QLinearGradient>
#include <QtMath>
#include <QDebug>

// ���ܣ������е�ɫ������
class HColorArea : public QWidget
{
    Q_OBJECT

public:
    HColorArea(QWidget *parent = nullptr);
    void setHue(int);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

private:
    void createHuePixmap(); // ����ɫ��pixmap

signals:
    void sigHueChanged(int); // ɫ��ֵ�ı䷢���ź�

private:
    QPixmap m_huePixmap;
    double m_hue;
    int m_iHue;
    const int m_iColorHeight; // ��ɫ����ĸ߶�
    const int m_iColorWidth; // ��ɫ����Ŀ��
    const int topMargin = 7;
    const int rightMargin = 9;
};

#endif // HCOLORAREA_H
