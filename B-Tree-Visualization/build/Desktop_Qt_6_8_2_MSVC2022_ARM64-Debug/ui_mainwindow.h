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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
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
    QLabel *Qlabel_at_top;
    QTextEdit *message_display_textedit;
    QGroupBox *spawnNode;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *skip_back_button;
    QPushButton *step_back_button;
    QPushButton *pause_button;
    QPushButton *step_forward_button;
    QPushButton *skip_forward_button;
    QSlider *animation_speed_slider;
    QGroupBox *groupBox1;
    QLineEdit *input_textbox;
    QPushButton *insert_button;
    QPushButton *delete_button;
    QPushButton *find_button;
    QPushButton *clear_button;
    QComboBox *comboBox;
    QRadioButton *bplus_radio_button;
    QRadioButton *bstar_radio_button;
    QRadioButton *btree_radio_button;
    QFrame *tree;
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
        Qlabel_at_top = new QLabel(centralwidget);
        Qlabel_at_top->setObjectName("Qlabel_at_top");
        Qlabel_at_top->setGeometry(QRect(9, 9, 901, 43));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Qlabel_at_top->sizePolicy().hasHeightForWidth());
        Qlabel_at_top->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(244, 121, 32, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        Qlabel_at_top->setPalette(palette1);
        QFont font;
        font.setPointSize(24);
        font.setBold(false);
        Qlabel_at_top->setFont(font);
        Qlabel_at_top->setAutoFillBackground(true);
        Qlabel_at_top->setTextFormat(Qt::TextFormat::PlainText);
        Qlabel_at_top->setScaledContents(true);
        Qlabel_at_top->setAlignment(Qt::AlignmentFlag::AlignCenter);
        message_display_textedit = new QTextEdit(centralwidget);
        message_display_textedit->setObjectName("message_display_textedit");
        message_display_textedit->setGeometry(QRect(700, 110, 200, 401));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(message_display_textedit->sizePolicy().hasHeightForWidth());
        message_display_textedit->setSizePolicy(sizePolicy1);
        message_display_textedit->setMaximumSize(QSize(200, 16777215));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush1);
        QBrush brush3(QColor(130, 130, 130, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        message_display_textedit->setPalette(palette2);
        message_display_textedit->setMouseTracking(true);
        message_display_textedit->setAcceptDrops(true);
        message_display_textedit->setReadOnly(true);
        message_display_textedit->setAcceptRichText(true);
        message_display_textedit->setCursorWidth(1);
        message_display_textedit->setTextInteractionFlags(Qt::TextInteractionFlag::NoTextInteraction);
        spawnNode = new QGroupBox(centralwidget);
        spawnNode->setObjectName("spawnNode");
        spawnNode->setGeometry(QRect(810, 290, 16, 16));
        spawnNode->setAutoFillBackground(false);
        horizontalLayout_2 = new QHBoxLayout(spawnNode);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(9, 512, 891, 81));
        horizontalLayout_5 = new QHBoxLayout(groupBox);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        skip_back_button = new QPushButton(groupBox);
        skip_back_button->setObjectName("skip_back_button");
        QPalette palette3;
        QBrush brush4(QColor(129, 130, 131, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        skip_back_button->setPalette(palette3);

        horizontalLayout_5->addWidget(skip_back_button);

        step_back_button = new QPushButton(groupBox);
        step_back_button->setObjectName("step_back_button");
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        step_back_button->setPalette(palette4);

        horizontalLayout_5->addWidget(step_back_button);

        pause_button = new QPushButton(groupBox);
        pause_button->setObjectName("pause_button");
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        pause_button->setPalette(palette5);

        horizontalLayout_5->addWidget(pause_button);

        step_forward_button = new QPushButton(groupBox);
        step_forward_button->setObjectName("step_forward_button");
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        step_forward_button->setPalette(palette6);

        horizontalLayout_5->addWidget(step_forward_button);

        skip_forward_button = new QPushButton(groupBox);
        skip_forward_button->setObjectName("skip_forward_button");
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        skip_forward_button->setPalette(palette7);

        horizontalLayout_5->addWidget(skip_forward_button);

        animation_speed_slider = new QSlider(groupBox);
        animation_speed_slider->setObjectName("animation_speed_slider");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(animation_speed_slider->sizePolicy().hasHeightForWidth());
        animation_speed_slider->setSizePolicy(sizePolicy2);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
        animation_speed_slider->setPalette(palette8);
        animation_speed_slider->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        animation_speed_slider->setAcceptDrops(false);
        animation_speed_slider->setMaximum(10);
        animation_speed_slider->setSliderPosition(5);
        animation_speed_slider->setOrientation(Qt::Orientation::Horizontal);
        animation_speed_slider->setTickPosition(QSlider::TickPosition::TicksAbove);
        animation_speed_slider->setTickInterval(1);

        horizontalLayout_5->addWidget(animation_speed_slider);

        groupBox1 = new QGroupBox(centralwidget);
        groupBox1->setObjectName("groupBox1");
        groupBox1->setGeometry(QRect(9, 58, 768, 26));
        input_textbox = new QLineEdit(groupBox1);
        input_textbox->setObjectName("input_textbox");
        input_textbox->setGeometry(QRect(2, 2, 131, 22));
        sizePolicy2.setHeightForWidth(input_textbox->sizePolicy().hasHeightForWidth());
        input_textbox->setSizePolicy(sizePolicy2);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush5(QColor(27, 27, 27, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        input_textbox->setPalette(palette9);
        input_textbox->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        input_textbox->setAutoFillBackground(true);
        insert_button = new QPushButton(groupBox1);
        insert_button->setObjectName("insert_button");
        insert_button->setGeometry(QRect(139, 2, 75, 22));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        insert_button->setPalette(palette10);
        delete_button = new QPushButton(groupBox1);
        delete_button->setObjectName("delete_button");
        delete_button->setGeometry(QRect(220, 2, 75, 22));
        sizePolicy2.setHeightForWidth(delete_button->sizePolicy().hasHeightForWidth());
        delete_button->setSizePolicy(sizePolicy2);
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        delete_button->setPalette(palette11);
        find_button = new QPushButton(groupBox1);
        find_button->setObjectName("find_button");
        find_button->setGeometry(QRect(301, 2, 75, 22));
        sizePolicy2.setHeightForWidth(find_button->sizePolicy().hasHeightForWidth());
        find_button->setSizePolicy(sizePolicy2);
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        find_button->setPalette(palette12);
        clear_button = new QPushButton(groupBox1);
        clear_button->setObjectName("clear_button");
        clear_button->setGeometry(QRect(382, 2, 75, 22));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        clear_button->setPalette(palette13);
        comboBox = new QComboBox(groupBox1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(463, 2, 112, 22));
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        comboBox->setPalette(palette14);
        comboBox->setAcceptDrops(true);
        bplus_radio_button = new QRadioButton(groupBox1);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(bplus_radio_button);
        bplus_radio_button->setObjectName("bplus_radio_button");
        bplus_radio_button->setGeometry(QRect(645, 3, 59, 20));
        sizePolicy3.setHeightForWidth(bplus_radio_button->sizePolicy().hasHeightForWidth());
        bplus_radio_button->setSizePolicy(sizePolicy3);
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette15.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
        bplus_radio_button->setPalette(palette15);
        bstar_radio_button = new QRadioButton(groupBox1);
        buttonGroup->addButton(bstar_radio_button);
        bstar_radio_button->setObjectName("bstar_radio_button");
        bstar_radio_button->setGeometry(QRect(710, 3, 56, 20));
        sizePolicy3.setHeightForWidth(bstar_radio_button->sizePolicy().hasHeightForWidth());
        bstar_radio_button->setSizePolicy(sizePolicy3);
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
        bstar_radio_button->setPalette(palette16);
        btree_radio_button = new QRadioButton(groupBox1);
        buttonGroup->addButton(btree_radio_button);
        btree_radio_button->setObjectName("btree_radio_button");
        btree_radio_button->setGeometry(QRect(582, 3, 56, 20));
        sizePolicy3.setHeightForWidth(btree_radio_button->sizePolicy().hasHeightForWidth());
        btree_radio_button->setSizePolicy(sizePolicy3);
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Highlight, brush2);
        palette17.setBrush(QPalette::Active, QPalette::Accent, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Highlight, brush2);
        palette17.setBrush(QPalette::Inactive, QPalette::Accent, brush2);
        palette17.setBrush(QPalette::Disabled, QPalette::Accent, brush2);
        btree_radio_button->setPalette(palette17);
        btree_radio_button->setChecked(true);
        tree = new QFrame(centralwidget);
        tree->setObjectName("tree");
        tree->setGeometry(QRect(0, 100, 691, 371));
        tree->setFrameShape(QFrame::Shape::StyledPanel);
        tree->setFrameShadow(QFrame::Shadow::Raised);
        MainWindow->setCentralWidget(centralwidget);
        spawnNode->raise();
        Qlabel_at_top->raise();
        message_display_textedit->raise();
        groupBox->raise();
        groupBox->raise();
        tree->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 916, 22));
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
        spawnNode->setTitle(QString());
        skip_back_button->setText(QCoreApplication::translate("MainWindow", "Skip Back", nullptr));
        step_back_button->setText(QCoreApplication::translate("MainWindow", "Step Back", nullptr));
        pause_button->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        step_forward_button->setText(QCoreApplication::translate("MainWindow", "Step Forward", nullptr));
        skip_forward_button->setText(QCoreApplication::translate("MainWindow", "Skip Forward", nullptr));
#if QT_CONFIG(tooltip)
        animation_speed_slider->setToolTip(QCoreApplication::translate("MainWindow", "Animation Speed", nullptr));
#endif // QT_CONFIG(tooltip)
        insert_button->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        delete_button->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        find_button->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
        clear_button->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Max. Degree = 3", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Max. Degree = 4", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "Max. Degree = 5", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "Max. Degree = 6", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "Max. Degree = 7", nullptr));

        bplus_radio_button->setText(QCoreApplication::translate("MainWindow", "B+Tree", nullptr));
        bstar_radio_button->setText(QCoreApplication::translate("MainWindow", "B*Tree", nullptr));
        btree_radio_button->setText(QCoreApplication::translate("MainWindow", "B-Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
