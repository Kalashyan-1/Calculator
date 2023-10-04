#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
double num1;
bool typing = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    map["+/-"] = OP::PlusMinus;
    map["+"] = OP::Add;
    map["-"] = OP::Sub;
    map["/"] = OP::Divide;
    map["X"] = OP::Myltyply;
    map["%"] = OP::Percent;
    connect(ui->Button_0, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_1, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_2, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_3, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_4, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_5, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_6, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_7, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_8, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_9, SIGNAL(released()), this, SLOT(push_digit()));
    connect(ui->Button_PlusMinus, SIGNAL(released()), this, SLOT(operators()));
    connect(ui->Button_Percent, SIGNAL(released()), this, SLOT(operators()));
    connect(ui->Button_add, SIGNAL(released()), this, SLOT(operators()));
    connect(ui->Button_sub, SIGNAL(released()), this, SLOT(operators()));
    connect(ui->Button_divide, SIGNAL(released()), this, SLOT(operators()));
    connect(ui->Button_multiply, SIGNAL(released()), this, SLOT(operators()));
    connect(ui->Button_equals, SIGNAL(released()), this, SLOT(operators()));
    ui->Button_add->setCheckable(true);
    ui->Button_sub->setCheckable(true);
    ui->Button_divide->setCheckable(true);
    ui->Button_multiply->setCheckable(true);

}
void MainWindow::push_digit() {
    double num;
    QString text;
    QPushButton* button = (QPushButton*)sender();
    qDebug() << typing  ;
    qDebug() << "outside";
    if ((!typing) && (ui->Button_add->isChecked() ||
        ui->Button_sub->isChecked() ||
        ui->Button_divide->isChecked() ||
        ui->Button_multiply->isChecked()))
    {
        qDebug() << "!typing";
        num = button->text().toDouble();
        typing = true;
        qDebug() << typing  ;
        qDebug() << "inside";
        text = QString::number(num,'g',14);
    } else {
        if (ui->text->text().contains('.') && button->text() == "0") {
            qDebug() << "contains";
            text = ui->text->text() + button->text();
        } else {
            qDebug() << "else";
            num = (ui->text->text() + button->text()).toDouble();
            text = QString::number(num,'g',14);
        }
    }
    ui->text->setText(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Button_point_released()
{
    if (!(ui->text->text().contains('.'))) {
        ui->text->setText(ui->text->text() + ".");
    }
}

void MainWindow::operators() {
    double num = ui->text->text().toDouble();
    QString text;
    QPushButton* button = (QPushButton*)sender();
    switch (map[button->text()]) {
    case OP::PlusMinus:
        num *= -1;
        text = QString::number(num, 'g', 14);
        ui->text->setText(text);
        break;
    case OP::Percent:
         num *= 0.01;
         text = QString::number(num, 'g', 14);
         ui->text->setText(text);
        break;
    case OP::Add:
    case OP::Divide:
    case OP::Sub:
    case OP::Myltyply:
        qDebug() << "binar";
        num1 = ui->text->text().toDouble();
        qDebug() << num1;
        button->setChecked(true);
    default:
        break;
    }
}

void MainWindow::on_Button_clear_released()
{
       ui->Button_add->setChecked(false);
       ui->Button_sub->setChecked(false);
       ui->Button_divide->setChecked(false);
       ui->Button_multiply->setChecked(false);
       ui->text->setText("0");
       typing = false;
}


void MainWindow::on_Button_equals_released()
{
        double num;
        double num2 = ui->text->text().toDouble();
        QString text;
        if (ui->Button_add->isChecked()) {
            num = num1 + num2;
            qDebug() << num;
            text = QString::number(num, 'g', 14);
            ui->text->setText(text);
            ui->Button_add->setChecked(false);
        } else if (ui->Button_sub->isChecked()) {
            num = num1 - num2;
            text = QString::number(num, 'g', 14);
            ui->text->setText(text);
            ui->Button_sub->setChecked(false);
        } else if (ui->Button_divide->isChecked()) {
            num = num1 / num2;
            text = QString::number(num, 'g', 14);
            ui->text->setText(text);
            ui->Button_divide->setChecked(false);
        } else if (ui->Button_multiply->isChecked()) {
            num = num1 * num2;
            text = QString::number(num, 'g', 14);
            ui->text->setText(text);
            ui->Button_multiply->setChecked(false);
        }
        qDebug() << "equls";
        typing = false;

}






















