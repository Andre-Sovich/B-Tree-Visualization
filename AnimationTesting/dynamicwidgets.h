#ifndef DYNAMICWIDGETS_H
#define DYNAMICWIDGETS_H


#pragma once

#include <QtWidgets/QMainWindow>

class DynamicWidgets : public QMainWindow
{
    Q_OBJECT


public:
    /// @brief Constructor.
    DynamicWidgets(QWidget *parent = Q_NULLPTR);

    /// @brief Destructor.
    ~DynamicWidgets();

    ///  @brief Handles user clicking on "add widget" button.
    void onAddWidget();

    ///  @brief Handles user clicking on a remove widget button.
    void onRemoveWidget();
};
#endif // DYNAMICWIDGETS_H
