#include "qttreenodewidget.h"
#include "ui_qttreenodewidget.h"

QtTreeNodeWidget::QtTreeNodeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::QtTreeNodeWidget)
{
    ui->setupUi(this);
}

QtTreeNodeWidget::~QtTreeNodeWidget()
{
    delete ui;
}
