/********************************************************************************
** Form generated from reading UI file 'TestWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWINDOW_H
#define UI_TESTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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
    QTextEdit *message_display_textedit;
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
    QWidget *widget;
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
        message_display_textedit = new QTextEdit(centralwidget);
        message_display_textedit->setObjectName("message_display_textedit");
        message_display_textedit->setGeometry(QRect(707, 88, 200, 472));
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
        step_back_button = new QPushButton(centralwidget);
        step_back_button->setObjectName("step_back_button");
        step_back_button->setGeometry(QRect(148, 567, 75, 24));
        QPalette palette2;
        QBrush brush3(QColor(129, 130, 131, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        step_back_button->setPalette(palette2);
        find_button = new QPushButton(centralwidget);
        find_button->setObjectName("find_button");
        find_button->setGeometry(QRect(369, 58, 75, 24));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(find_button->sizePolicy().hasHeightForWidth());
        find_button->setSizePolicy(sizePolicy1);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        find_button->setPalette(palette3);
        pause_button = new QPushButton(centralwidget);
        pause_button->setObjectName("pause_button");
        pause_button->setGeometry(QRect(258, 567, 75, 24));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        pause_button->setPalette(palette4);
        insert_button = new QPushButton(centralwidget);
        insert_button->setObjectName("insert_button");
        insert_button->setGeometry(QRect(148, 58, 75, 24));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        insert_button->setPalette(palette5);
        step_forward_button = new QPushButton(centralwidget);
        step_forward_button->setObjectName("step_forward_button");
        step_forward_button->setGeometry(QRect(369, 567, 77, 24));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        step_forward_button->setPalette(palette6);
        skip_forward_button = new QPushButton(centralwidget);
        skip_forward_button->setObjectName("skip_forward_button");
        skip_forward_button->setGeometry(QRect(479, 567, 76, 24));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        skip_forward_button->setPalette(palette7);
        delete_button = new QPushButton(centralwidget);
        delete_button->setObjectName("delete_button");
        delete_button->setGeometry(QRect(258, 58, 75, 24));
        sizePolicy1.setHeightForWidth(delete_button->sizePolicy().hasHeightForWidth());
        delete_button->setSizePolicy(sizePolicy1);
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        delete_button->setPalette(palette8);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(589, 59, 112, 22));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        comboBox->setPalette(palette9);
        comboBox->setAcceptDrops(true);
        clear_button = new QPushButton(centralwidget);
        clear_button->setObjectName("clear_button");
        clear_button->setGeometry(QRect(479, 58, 75, 24));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        clear_button->setPalette(palette10);
        skip_back_button = new QPushButton(centralwidget);
        skip_back_button->setObjectName("skip_back_button");
        skip_back_button->setGeometry(QRect(9, 567, 75, 24));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush3);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush3);
        skip_back_button->setPalette(palette11);
        animation_speed_slider = new QSlider(centralwidget);
        animation_speed_slider->setObjectName("animation_speed_slider");
        animation_speed_slider->setGeometry(QRect(589, 566, 84, 27));
        sizePolicy1.setHeightForWidth(animation_speed_slider->sizePolicy().hasHeightForWidth());
        animation_speed_slider->setSizePolicy(sizePolicy1);
        QPalette palette12;
        QBrush brush4(QColor(244, 121, 32, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette12.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        palette12.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
        palette12.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette12.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        animation_speed_slider->setPalette(palette12);
        animation_speed_slider->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        animation_speed_slider->setAcceptDrops(false);
        animation_speed_slider->setMaximum(10);
        animation_speed_slider->setSliderPosition(5);
        animation_speed_slider->setOrientation(Qt::Orientation::Horizontal);
        animation_speed_slider->setTickPosition(QSlider::TickPosition::TicksAbove);
        animation_speed_slider->setTickInterval(1);
        input_textbox = new QLineEdit(centralwidget);
        input_textbox->setObjectName("input_textbox");
        input_textbox->setGeometry(QRect(9, 59, 133, 22));
        sizePolicy1.setHeightForWidth(input_textbox->sizePolicy().hasHeightForWidth());
        input_textbox->setSizePolicy(sizePolicy1);
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        QBrush brush5(QColor(27, 27, 27, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush5);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        input_textbox->setPalette(palette13);
        input_textbox->setFocusPolicy(Qt::FocusPolicy::ClickFocus);
        input_textbox->setAutoFillBackground(true);
        Qlabel_at_top = new QLabel(centralwidget);
        Qlabel_at_top->setObjectName("Qlabel_at_top");
        Qlabel_at_top->setGeometry(QRect(9, 9, 891, 43));
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Qlabel_at_top->sizePolicy().hasHeightForWidth());
        Qlabel_at_top->setSizePolicy(sizePolicy3);
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush4);
        palette14.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        palette14.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        palette14.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        Qlabel_at_top->setPalette(palette14);
        QFont font;
        font.setPointSize(24);
        font.setBold(false);
        Qlabel_at_top->setFont(font);
        Qlabel_at_top->setAutoFillBackground(true);
        Qlabel_at_top->setTextFormat(Qt::TextFormat::PlainText);
        Qlabel_at_top->setScaledContents(true);
        Qlabel_at_top->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btree_radio_button = new QRadioButton(widget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName("buttonGroup");
        buttonGroup->addButton(btree_radio_button);
        btree_radio_button->setObjectName("btree_radio_button");
        sizePolicy2.setHeightForWidth(btree_radio_button->sizePolicy().hasHeightForWidth());
        btree_radio_button->setSizePolicy(sizePolicy2);
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Highlight, brush4);
        palette15.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Highlight, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        btree_radio_button->setPalette(palette15);
        btree_radio_button->setChecked(true);

        horizontalLayout->addWidget(btree_radio_button);

        bplus_radio_button = new QRadioButton(widget);
        buttonGroup->addButton(bplus_radio_button);
        bplus_radio_button->setObjectName("bplus_radio_button");
        sizePolicy2.setHeightForWidth(bplus_radio_button->sizePolicy().hasHeightForWidth());
        bplus_radio_button->setSizePolicy(sizePolicy2);
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette16.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        bplus_radio_button->setPalette(palette16);

        horizontalLayout->addWidget(bplus_radio_button);

        bstar_radio_button = new QRadioButton(widget);
        buttonGroup->addButton(bstar_radio_button);
        bstar_radio_button->setObjectName("bstar_radio_button");
        sizePolicy2.setHeightForWidth(bstar_radio_button->sizePolicy().hasHeightForWidth());
        bstar_radio_button->setSizePolicy(sizePolicy2);
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Active, QPalette::Accent, brush4);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette17.setBrush(QPalette::Inactive, QPalette::Accent, brush4);
        palette17.setBrush(QPalette::Disabled, QPalette::Accent, brush4);
        bstar_radio_button->setPalette(palette17);

        horizontalLayout->addWidget(bstar_radio_button);

        MainWindow->setCentralWidget(centralwidget);
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

#endif // UI_TESTWINDOW_H
