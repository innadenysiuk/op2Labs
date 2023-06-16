#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    solveButton = ui->pushButton;
    connect(solveButton, &QPushButton::clicked, this, &MainWindow::solveButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::solveButtonClicked()
{
    QString arg1Text = ui->argument1->text();
    QString arg2Text = ui->argument2->text();

    bool conversionOk;
    double arg1 = arg1Text.toDouble(&conversionOk);
    if (!conversionOk) {
        QMessageBox::critical(this, "Помилка", "Невірний формат аргументу 1!");
        return;
    }
    double arg2 = arg2Text.toDouble(&conversionOk);
    if (!conversionOk) {
        QMessageBox::critical(this, "Помилка", "Невірний формат аргументу 2!");
        return;
    }

    try {
        Function function1(arg1);
        Function function2(arg2);

        double result1, result2;
        try {
            result1 = function1.calculateFunction();
        } catch (const char* errorMessage) {
            throw std::runtime_error("Помилка обчислення функції для аргументу 1: " + QString(errorMessage).toStdString());
        }

        try {
            result2 = function2.calculateFunction();
        } catch (const char* errorMessage) {
            throw std::runtime_error("Помилка обчислення функції для аргументу 2: " + QString(errorMessage).toStdString());
        }

        QString maxResultText;
        if (result1 > result2) {
            maxResultText = "Більше значення: " + QString::number(result1) + " (аргумент 1)";
        } else if (result2 > result1) {
            maxResultText = "Більше значення: " + QString::number(result2) + " (аргумент 2)";
        } else {
            maxResultText = "Значення однакові для обох аргументів";
        }

        QString resultText = "Результат:\n";
        resultText += "Значення для аргументу " + arg1Text + ": " + QString::number(result1) + "\n";
        resultText += "Значення для аргументу " + arg2Text + ": " + QString::number(result2) + "\n";
        resultText += maxResultText;

        ui->result->setText(resultText);
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Помилка", e.what());
    }
}
