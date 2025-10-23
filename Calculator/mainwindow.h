#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include "expression_evaluator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNumberClicked();
    void onOperatorClicked();
    void onFunctionClicked();
    void onEqualsClicked();
    void onClearClicked();
    void onBackspaceClicked();
    void onDecimalClicked();
    void onParenClicked();

private:
    Ui::MainWindow *ui;
    ExpressionEvaluator evaluator;
    QString currentExpression;
    bool justCalculated;
    
    void connectButtons();
    void updateDisplay();
    void appendToExpression(const QString& text);
    void showError(const QString& message);
    bool isValidInput(const QString& input);
    QString convertDisplayToExpression(const QString& display);
};

#endif // MAINWINDOW_H
