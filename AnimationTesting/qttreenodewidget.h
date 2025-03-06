#ifndef QTTREENODEWIDGET_H
#define QTTREENODEWIDGET_H

#include <QWidget>

namespace Ui {
class QtTreeNodeWidget;
}

class QtTreeNodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QtTreeNodeWidget(QWidget *parent = nullptr);
    ~QtTreeNodeWidget();

private:
    Ui::QtTreeNodeWidget *ui;
};

#endif // QTTREENODEWIDGET_H
