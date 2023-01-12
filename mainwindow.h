#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#include "QMap"

enum class OP {
    Plus,
    Myltyply,
    Divide,
    Percent,
    Add,
    Sub,
    PlusMinus,
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMap<QString, OP> map;



private slots:

    void push_digit();
    void on_Button_point_released();
    void operators();
    void on_Button_clear_released();
    void on_Button_equals_released();
};
#endif // MAINWINDOW_H
