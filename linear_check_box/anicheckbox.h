#ifndef LINEARCHECKBOX_H
#define LINEARCHECKBOX_H

#include <QCheckBox>

class AniCheckBox : public QCheckBox
{
    Q_OBJECT
public:
    AniCheckBox(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent *e) override;

    virtual void drawBox(QPainter &painter, QRectF rect);

private:
    int boxSide = 0; // 选择框边长，0为自适应
};

#endif // LINEARCHECKBOX_H
