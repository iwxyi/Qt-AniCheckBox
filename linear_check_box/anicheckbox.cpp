#include "anicheckbox.h"
#include <QPainter>
#include <QPainterPath>
#include <QDebug>

AniCheckBox::AniCheckBox(QWidget *parent) : QCheckBox(parent)
{
    connect(this, &QCheckBox::stateChanged, this, [=](int state) {
        if (state == Qt::Unchecked)
        {

        }
        else if (state == Qt::PartiallyChecked)
        {

        }
        else if (state == Qt::Checked)
        {

        }
    });
}

void AniCheckBox::paintEvent(QPaintEvent *e)
{
    // QCheckBox::paintEvent(e);
    QPainter painter(this);

    QRectF rect;
    double textLeft;
    if (boxSide <= 0)
    {
        // 自适应大小：优先一行文字大小，其次按比例
        const double fixedProp = 0.8; // 默认比例
        QFontMetricsF fm(painter.font());
        double side = fm.lineSpacing(); // 一行文字的高度
        if (side >= this->height() * fixedProp)
            side = this->height() * fixedProp;

        double margin = side / 3;
        rect = QRectF(margin, (height() - side) / 2, side, side);
        textLeft = rect.right() + margin;
    }
    else
    {
        // 固定大小
        double margin = (this->height() - boxSide) / 2;
        rect = QRectF(margin, margin, boxSide, boxSide);
        textLeft = rect.right() + margin;
    }

    // 绘制边界
    // painter.drawRect(this->rect());

    // 绘制选择框
    painter.save();
    drawBox(painter, rect);
    painter.restore();

    // 绘制文字
    painter.save();
    painter.drawText(QRectF(textLeft, 0, this->width() - textLeft, this->height()), this->text(), Qt::AlignVCenter | Qt::AlignLeft);
    painter.restore();
}

void AniCheckBox::drawBox(QPainter& painter, QRectF rect)
{
    painter.drawRect(rect);

    int state = this->checkState();
    if (state == Qt::Unchecked)
    {

    }
    else if (state == Qt::PartiallyChecked)
    {
        const double prop = 0.6;
        rect = QRectF(
                    rect.left() + rect.width() * (1 - prop) / 2,
                    rect.top() + rect.height() * (1 - prop) / 2,
                    rect.width() * prop,
                    rect.height() * prop
                    );
        painter.drawRect(rect);
    }
    else if (state == Qt::Checked)
    {
        const double prop = 0.6;
        rect = QRectF(
                    rect.left() + rect.width() * (1 - prop) / 2,
                    rect.top() + rect.height() * (1 - prop) / 2,
                    rect.width() * prop,
                    rect.height() * prop
                    );
        painter.fillRect(rect, Qt::blue);
    }
}
