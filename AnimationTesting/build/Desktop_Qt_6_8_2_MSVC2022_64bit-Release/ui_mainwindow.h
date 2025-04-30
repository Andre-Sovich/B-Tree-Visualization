/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *Qlabel_at_top;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *createButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QComboBox *comboBox;
    QRadioButton *btree_radio_button;
    QHBoxLayout *horizontalLayout;
    QRadioButton *bplus_radio_button;
    QRadioButton *bstar_radio_button;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *compareButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *tile2;
    QPushButton *childButton;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *message_display_textedit;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        Qlabel_at_top = new QLabel(centralwidget);
        Qlabel_at_top->setObjectName("Qlabel_at_top");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Qlabel_at_top->sizePolicy().hasHeightForWidth());
        Qlabel_at_top->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(244, 121, 32, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        Qlabel_at_top->setPalette(palette);
        QFont font;
        font.setPointSize(24);
        font.setBold(false);
        Qlabel_at_top->setFont(font);
        Qlabel_at_top->setAutoFillBackground(true);
        Qlabel_at_top->setTextFormat(Qt::TextFormat::PlainText);
        Qlabel_at_top->setScaledContents(true);
        Qlabel_at_top->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(Qlabel_at_top);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout_2->addWidget(lineEdit);

        createButton = new QPushButton(centralwidget);
        createButton->setObjectName("createButton");

        horizontalLayout_2->addWidget(createButton);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_2->addWidget(pushButton_3);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);

        btree_radio_button = new QRadioButton(centralwidget);
        btree_radio_button->setObjectName("btree_radio_button");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btree_radio_button->sizePolicy().hasHeightForWidth());
        btree_radio_button->setSizePolicy(sizePolicy1);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        btree_radio_button->setPalette(palette1);
        btree_radio_button->setChecked(true);

        horizontalLayout_2->addWidget(btree_radio_button);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        bplus_radio_button = new QRadioButton(centralwidget);
        bplus_radio_button->setObjectName("bplus_radio_button");
        sizePolicy1.setHeightForWidth(bplus_radio_button->sizePolicy().hasHeightForWidth());
        bplus_radio_button->setSizePolicy(sizePolicy1);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        bplus_radio_button->setPalette(palette2);

        horizontalLayout->addWidget(bplus_radio_button);

        bstar_radio_button = new QRadioButton(centralwidget);
        bstar_radio_button->setObjectName("bstar_radio_button");
        sizePolicy1.setHeightForWidth(bstar_radio_button->sizePolicy().hasHeightForWidth());
        bstar_radio_button->setSizePolicy(sizePolicy1);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Accent, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Accent, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Accent, brush1);
        bstar_radio_button->setPalette(palette3);

        horizontalLayout->addWidget(bstar_radio_button);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        compareButton = new QPushButton(centralwidget);
        compareButton->setObjectName("compareButton");

        horizontalLayout_3->addWidget(compareButton);

        leftButton = new QPushButton(centralwidget);
        leftButton->setObjectName("leftButton");

        horizontalLayout_3->addWidget(leftButton);

        rightButton = new QPushButton(centralwidget);
        rightButton->setObjectName("rightButton");

        horizontalLayout_3->addWidget(rightButton);

        tile2 = new QPushButton(centralwidget);
        tile2->setObjectName("tile2");

        horizontalLayout_3->addWidget(tile2);

        childButton = new QPushButton(centralwidget);
        childButton->setObjectName("childButton");

        horizontalLayout_3->addWidget(childButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        message_display_textedit = new QTextEdit(centralwidget);
        message_display_textedit->setObjectName("message_display_textedit");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(message_display_textedit->sizePolicy().hasHeightForWidth());
        message_display_textedit->setSizePolicy(sizePolicy2);
        message_display_textedit->setMaximumSize(QSize(200, 16777215));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush);
        QBrush brush2(QColor(130, 130, 130, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        message_display_textedit->setPalette(palette4);
        message_display_textedit->setMouseTracking(true);
        message_display_textedit->setAcceptDrops(true);
        message_display_textedit->setReadOnly(true);
        message_display_textedit->setAcceptRichText(true);
        message_display_textedit->setCursorWidth(1);
        message_display_textedit->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        horizontalLayout_4->addWidget(message_display_textedit);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy3);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        graphicsView->setPalette(palette5);
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ArrowCursor)));
        graphicsView->setMouseTracking(true);
        graphicsView->setTabletTracking(true);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        graphicsView->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
        graphicsView->setResizeAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
        graphicsView->setViewportUpdateMode(QGraphicsView::ViewportUpdateMode::MinimalViewportUpdate);

        horizontalLayout_4->addWidget(graphicsView);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Qlabel_at_top->setText(QCoreApplication::translate("MainWindow", " B Trees", nullptr));
        createButton->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Max. Degree = 3", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Max. Degree = 4", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Max. Degree = 5", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Max. Degree = 6", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Max. Degree = 7", nullptr));

        btree_radio_button->setText(QCoreApplication::translate("MainWindow", "B-Tree", nullptr));
        bplus_radio_button->setText(QCoreApplication::translate("MainWindow", "B+Tree", nullptr));
        bstar_radio_button->setText(QCoreApplication::translate("MainWindow", "B*Tree", nullptr));
        compareButton->setText(QCoreApplication::translate("MainWindow", "Compare", nullptr));
        leftButton->setText(QCoreApplication::translate("MainWindow", "Left", nullptr));
        rightButton->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
        tile2->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        childButton->setText(QCoreApplication::translate("MainWindow", "child", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
