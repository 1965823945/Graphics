#ifndef PREVIEWCOLORAREA_H
#define PREVIEWCOLORAREA_H

#include <QWidget>
#include <QStylePainter>

// ��ɫԤ������
class PreviewColorArea : public QWidget
{
    Q_OBJECT

public:
    PreviewColorArea(QWidget *parent = nullptr);

    void setNewColor(const QColor &); // �����µ���ɫ

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

public slots:
    void slotSvChanged(int, int, int);

signals:
    void sigSvChanged(int, int, int);

private:
    void paint(QPainter &painter, QRect) const;

    QColor m_newColor;
};

#endif // PREVIEWCOLORAREA_H
