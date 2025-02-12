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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *message_display_textedit;
    QGraphicsView *graphicsView;
    QPushButton *step_back_button;
    QPushButton *find_button;
    QPushButton *pause_button;
    QPushButton *insert_button;
    QPushButton *step_forward_button;
    QPushButton *skip_forward_button;
    QPushButton *delete_button;
    QComboBox *comboBox;
    QPushButton *clear_button;
    QPushButton *skip_back_button;
    QSlider *animation_speed_slider;
    QLineEdit *input_textbox;
    QLabel *Qlabel_at_top;
    QHBoxLayout *horizontalLayout;
    QRadioButton *btree_radio_button;
    QRadioButton *bplus_radio_button;
    QRadioButton *bstar_radio_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(916, 645);
        QPalette palette;
        QBrush brush(QColor(44, 46, 47, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setInputMethodHints(Qt::InputMethodHint::ImhMultiLine);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        MainWindow->setDockOptions(QMainWindow::DockOption::AllowTabbedDocks|QMainWindow::DockOption::AnimatedDocks);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        message_display_textedit = new QTextEdit(centralwidget);
        message_display_textedit->setObjectName("message_display_textedit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(message_display_textedit->sizePolicy().hasHeightForWidth());
        message_display_textedit->setSizePolicy(sizePolicy);
        message_display_textedit->setMaximumSize(QSize(200, 16777215));
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush1);
        QBrush brush2(QColor(130, 130, 130, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        message_display_textedit->setPalette(palette1);
        message_display_textedit->setMouseTracking(true);
        message_display_textedit->setAcceptDrops(true);
        message_display_textedit->setReadOnly(true);
        message_display_textedit->setAcceptRichText(true);
        message_display_textedit->setCursorWidth(1);
        message_display_textedit->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);

        gridLayout->addWidget(message_display_textedit, 15, 6, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        graphicsView->setPalette(palette2);
        graphicsView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::ArrowCursor)));
        graphicsView->setMouseTracking(true);
        graphicsView->setTabletTracking(true);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        graphicsView->setDragMode(QGraphicsView::DragMode::ScrollHandDrag);
        graphicsView->setTransformationAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
        graphicsView->setResizeAnchor(QGraphicsView::ViewportAnchor::AnchorUnderMouse);
        graphicsView->setViewportUpdateMode(QGraphicsView::ViewportUpdateMode::MinimalViewportUpdate);

        gridLayout->addWidget(graphicsView, 15, 0, 1, 6);

        step_back_button = new QPushButton(centralwidget);
        step_back_button->setObjectName("step_back_button");
        QPalette palette3;
        QBrush brush3(QColor(129, 130, 131, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        step_back_button->setPalette(palette3);

        gridLayout->addWidget(step_back_button, 25, 1, 1, 1);

        find_button = new QPushButton(centralwidget);
        find_button->setObjectName("find_button");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(find_button->sizePolicy().hasHeightForWidth());
        find_button->setSizePolicy(sizePolicy2);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        find_button->setPalette(palette4);

        gridLayout->addWidget(find_button, 14, 3, 1, 1);

        pause_button = new QPushButton(centralwidget);
        pause_button->setObjectName("pause_button");
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        pause_button->setPalette(palette5);

        gridLayout->addWidget(pause_button, 25, 2, 1, 1);

        insert_button = new QPushButton(centralwidget);
        insert_button->setObjectName("insert_button");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        insert_button->setPalette(palette6);

        gridLayout->addWidget(insert_button, 14, 1, 1, 1);

        step_forward_button = new QPushButton(centralwidget);
        step_forward_button->setObjectName("step_forward_button");
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        step_forward_button->setPalette(palette7);

        gridLayout->addWidget(step_forward_button, 25, 3, 1, 1);

        skip_forward_button = new QPushButton(centralwidget);
        skip_forward_button->setObjectName("skip_forward_button");
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        skip_forward_button->setPalette(palette8);

        gridLayout->addWidget(skip_forward_button, 25, 4, 1, 1);

        delete_button = new QPushButton(centralwidget);
        delete_button->setObjectName("delete_button");
        sizePolicy2.setHeightForWidth(delete_button->sizePolicy().hasHeightForWidth());
        delete_button->setSizePolicy(sizePolicy2);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        delete_button->setPalette(palette9);

        gridLayout->addWidget(delete_button, 14, 2, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        comboBox->setPalette(palette10);
        comboBox->setAcceptDrops(true);

        gridLayout->addWidget(comboBox, 14, 5, 1, 1);

        clear_button = new QPushButton(centralwidget);
        clear_button->setObjectName("clear_button");
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        clear_button->setPalette(palette11);

        gridLayout->addWidget(clear_button, 14, 4, 1, 1);

        skip_back_button = new QPushButton(centralwidget);
        skip_back_button->setObjectName("skip_back_button");
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        skip_back_button->setPalette(palette12);

        gridLayout->addWidget(skip_back_button, 25, 0, 1, 1);

        animation_speed_slider = new QSlider(centralwidget);
        animation_speed_slider->setObjectName("animation_speed_slider");
        sizePolicy2.setHeightForWidth(animation_speed_slider->sizePolicy().hasHeightForWidth());
        animation_speed_slider->setSizePolicy(sizePolicy2);
        QPalette palette13;
        QBrush brush4(QColor(244, 121, 32, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette13.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        palette13.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        animation_speed_slider->setPalette(palette13);
        animation_speed_slider->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        animation_speed_slider->setAcceptDrops(false);
        animation_speed_slider->setMaximum(10);
        animation_speed_slider->setSliderPosition(5);
        animation_speed_slider->setOrientation(Qt::Orientation::Horizontal);
        animation_speed_slider->setTickPosition(QSlider::TickPosition::TicksAbove);
        animation_speed_slider->setTickInterval(1);

        gridLayout->addWidget(animation_speed_slider, 25, 5, 1, 2);

        input_textbox = new QLineEdit(centralwidget);
        input_textbox->setObjectName("input_textbox");
        sizePolicy2.setHeightForWidth(input_textbox->sizePolicy().hasHeightForWidth());
        input_textbox->setSizePolicy(sizePolicy2);
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush5(QColor(27, 27, 27, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        input_textbox->setPalette(palette14);
        input_textbox->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        input_textbox->setAutoFillBackground(true);

        gridLayout->addWidget(input_textbox, 14, 0, 1, 1);

        Qlabel_at_top = new QLabel(centralwidget);
        Qlabel_at_top->setObjectName("Qlabel_at_top");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(Qlabel_at_top->sizePolicy().hasHeightForWidth());
        Qlabel_at_top->setSizePolicy(sizePolicy4);
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette15.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        Qlabel_at_top->setPalette(palette15);
        QFont font;
        font.setPointSize(24);
        font.setBold(false);
        Qlabel_at_top->setFont(font);
        Qlabel_at_top->setAutoFillBackground(true);
        Qlabel_at_top->setTextFormat(Qt::TextFormat::PlainText);
        Qlabel_at_top->setScaledContents(true);
        Qlabel_at_top->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(Qlabel_at_top, 0, 0, 1, 7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btree_radio_button = new QRadioButton(centralwidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(btree_radio_button);
        btree_radio_button->setObjectName("btree_radio_button");
        sizePolicy3.setHeightForWidth(btree_radio_button->sizePolicy().hasHeightForWidth());
        btree_radio_button->setSizePolicy(sizePolicy3);
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        palette16.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        btree_radio_button->setPalette(palette16);
        btree_radio_button->setChecked(true);

        horizontalLayout->addWidget(btree_radio_button);

        bplus_radio_button = new QRadioButton(centralwidget);
        buttonGroup->addButton(bplus_radio_button);
        bplus_radio_button->setObjectName("bplus_radio_button");
        sizePolicy3.setHeightForWidth(bplus_radio_button->sizePolicy().hasHeightForWidth());
        bplus_radio_button->setSizePolicy(sizePolicy3);
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        bplus_radio_button->setPalette(palette17);

        horizontalLayout->addWidget(bplus_radio_button);

        bstar_radio_button = new QRadioButton(centralwidget);
        buttonGroup->addButton(bstar_radio_button);
        bstar_radio_button->setObjectName("bstar_radio_button");
        sizePolicy3.setHeightForWidth(bstar_radio_button->sizePolicy().hasHeightForWidth());
        bstar_radio_button->setSizePolicy(sizePolicy3);
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette18.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette18.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette18.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        bstar_radio_button->setPalette(palette18);

        horizontalLayout->addWidget(bstar_radio_button);


        gridLayout->addLayout(horizontalLayout, 14, 6, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 916, 21));
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
        step_back_button->setText(QCoreApplication::translate("MainWindow", "Step Back", nullptr));
        find_button->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        pause_button->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        insert_button->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        step_forward_button->setText(QCoreApplication::translate("MainWindow", "Step Forward", nullptr));
        skip_forward_button->setText(QCoreApplication::translate("MainWindow", "Skip Forward", nullptr));
        delete_button->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Max. Degree = 3", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Max. Degree = 4", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Max. Degree = 5", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Max. Degree = 6", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Max. Degree = 7", nullptr));

        clear_button->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        skip_back_button->setText(QCoreApplication::translate("MainWindow", "Skip Back", nullptr));
#if QT_CONFIG(tooltip)
        animation_speed_slider->setToolTip(QCoreApplication::translate("MainWindow", "Animation Speed", nullptr));
#endif // QT_CONFIG(tooltip)
        Qlabel_at_top->setText(QCoreApplication::translate("MainWindow", " B Trees", nullptr));
        btree_radio_button->setText(QCoreApplication::translate("MainWindow", "B-Tree", nullptr));
        bplus_radio_button->setText(QCoreApplication::translate("MainWindow", "B+Tree", nullptr));
        bstar_radio_button->setText(QCoreApplication::translate("MainWindow", "B*Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
