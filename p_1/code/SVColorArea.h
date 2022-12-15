#ifndef SVCOLORAREA_H
#define SVCOLORAREA_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QtMath>
#include "colorchange.h"

// ���ܣ������еı��Ͷ�(S)������(V)����
class SVColorArea : public QWidget,ColorChange
{
    Q_OBJECT

public:
    SVColorArea(QWidget *parent = nullptr);
    void setHue(int);
    void setSaturation(int);
    void setBrightness(int);
    void setHsv(int, int, int);
    void setColor(const QColor &);

protected:
    void paintEvent(QPaintEvent *);			// ��ͼ�¼�
    void mousePressEvent(QMouseEvent *);	// ��갴���¼�
    void mouseMoveEvent(QMouseEvent *);		// ����ƶ��¼�

public slots:
    void slotHueChanged(int); // ɫ���ı�Ĳۺ���

signals:
    void sigSvChanged(int, int, int);

private:
    void drawSVPixmap();
    void createVPixmap();	// �������Ƚ����pixmap
    void createSVPixmap();	// ���������������pixmap
    void updateSVPixmap();	// ���������������pixmap

    int m_iHue;
    int m_iSaturation;
    int m_iBrightness;
    const int m_iAreaWidth;	// ����������Ŀ��
    QPixmap m_svPixmap;	// �����������pixmap
    QPixmap m_vPixmap;	// ���Ƚ����pixmap
};

#endif // SVCOLORAREA_H
