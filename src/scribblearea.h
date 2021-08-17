#ifndef SCRIBBLEAREA_H
#define SCRIBBLEAREA_H

#include <QImage>
#include <QPoint>
#include <QWidget>
#include <QColor>
#include <QPainter>

class ScribbleArea : public QWidget
{
    // Declares our class as a QObject which is the base class
    // for all Qt objects
    // QObjects handle events
    Q_OBJECT

public:
    ScribbleArea(QWidget *parent = 0);
    QImage getImage();

public slots:

    // Events to handle
    void clearImage();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    // Updates the scribble area where we are painting
    void paintEvent(QPaintEvent *event) override;

private:
    void initScribbleImage(QImage *image);
    void drawLineTo(const QPoint &endPoint);
    void resizeImage(QImage *image, const QSize &newSize);


    // Marked true or false depending on if the user
    // is drawing
    bool scribbling;

    // Stores the image being drawn
    QImage image;
    int myPenWidth;
    QColor myPenColor;

    // Stores the location at the current mouse event
    QPoint lastPoint;
};

#endif
