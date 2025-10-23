#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , justCalculated(false)
{
    ui->setupUi(this);
    currentExpression = "0";
    connectButtons();
    updateDisplay();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectButtons()
{
    // 连接数字按钮
    connect(ui->button0, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button3, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button4, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button5, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button6, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button7, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button8, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    connect(ui->button9, &QPushButton::clicked, this, &MainWindow::onNumberClicked);
    
    // 连接操作符按钮
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->subtractButton, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->multiplyButton, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    connect(ui->divideButton, &QPushButton::clicked, this, &MainWindow::onOperatorClicked);
    
    // 连接功能按钮
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::onClearClicked);
    connect(ui->backspaceButton, &QPushButton::clicked, this, &MainWindow::onBackspaceClicked);
    connect(ui->decimalButton, &QPushButton::clicked, this, &MainWindow::onDecimalClicked);
    connect(ui->equalsButton, &QPushButton::clicked, this, &MainWindow::onEqualsClicked);
    
    // 连接括号按钮
    connect(ui->leftParenButton, &QPushButton::clicked, this, &MainWindow::onParenClicked);
    connect(ui->rightParenButton, &QPushButton::clicked, this, &MainWindow::onParenClicked);
}

void MainWindow::onNumberClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    QString number = button->text();
    
    if (justCalculated) {
        currentExpression = number;
        justCalculated = false;
    } else {
        if (currentExpression == "0") {
            currentExpression = number;
        } else {
            currentExpression += number;
        }
    }
    
    updateDisplay();
}

void MainWindow::onOperatorClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    QString operatorText = button->text();
    QString operatorChar;
    
    // 转换显示符号为计算符号
    if (operatorText == "×") operatorChar = "*";
    else if (operatorText == "÷") operatorChar = "/";
    else operatorChar = operatorText;
    
    if (justCalculated) {
        justCalculated = false;
    }
    
    // 检查是否以操作符结尾，如果是则替换
    if (!currentExpression.isEmpty() && 
        (currentExpression.endsWith("+") || currentExpression.endsWith("-") || 
         currentExpression.endsWith("*") || currentExpression.endsWith("/"))) {
        currentExpression.chop(1);
    }
    
    currentExpression += operatorChar;
    updateDisplay();
}

void MainWindow::onFunctionClicked()
{
    // 这个函数暂时保留，用于扩展功能
}

void MainWindow::onEqualsClicked()
{
    try {
        QString expression = convertDisplayToExpression(currentExpression);
        double result = evaluator.evaluate(expression.toStdString());
        
        // 格式化结果
        QString resultStr;
        if (result == static_cast<long long>(result)) {
            resultStr = QString::number(static_cast<long long>(result));
        } else {
            resultStr = QString::number(result, 'g', 10);
        }
        
        currentExpression = resultStr;
        justCalculated = true;
        updateDisplay();
    } catch (const std::exception& e) {
        showError(QString("计算错误: %1").arg(e.what()));
    }
}

void MainWindow::onClearClicked()
{
    currentExpression = "0";
    justCalculated = false;
    updateDisplay();
}

void MainWindow::onBackspaceClicked()
{
    if (justCalculated) {
        currentExpression = "0";
        justCalculated = false;
    } else if (currentExpression.length() > 1) {
        currentExpression.chop(1);
    } else {
        currentExpression = "0";
    }
    updateDisplay();
}

void MainWindow::onDecimalClicked()
{
    if (justCalculated) {
        currentExpression = "0.";
        justCalculated = false;
    } else {
        // 检查当前数字是否已经有小数点
        QString lastNumber = "";
        for (int i = currentExpression.length() - 1; i >= 0; --i) {
            QChar c = currentExpression.at(i);
            if (c.isDigit() || c == '.') {
                lastNumber = c + lastNumber;
            } else {
                break;
            }
        }
        
        if (!lastNumber.contains('.')) {
            currentExpression += ".";
        }
    }
    updateDisplay();
}

void MainWindow::onParenClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    QString paren = button->text();
    
    if (justCalculated) {
        currentExpression = paren;
        justCalculated = false;
    } else {
        currentExpression += paren;
    }
    
    updateDisplay();
}

void MainWindow::updateDisplay()
{
    ui->display->setText(currentExpression);
}

void MainWindow::appendToExpression(const QString& text)
{
    if (justCalculated) {
        currentExpression = text;
        justCalculated = false;
    } else {
        if (currentExpression == "0") {
            currentExpression = text;
        } else {
            currentExpression += text;
        }
    }
    updateDisplay();
}

void MainWindow::showError(const QString& message)
{
    QMessageBox::warning(this, "错误", message);
    currentExpression = "0";
    justCalculated = false;
    updateDisplay();
}

bool MainWindow::isValidInput(const QString& input)
{
    // 基本输入验证
    if (input.isEmpty()) return false;
    
    // 检查是否包含有效字符
    for (const QChar& c : input) {
        if (!c.isDigit() && c != '.' && c != '+' && c != '-' && 
            c != '*' && c != '/' && c != '(' && c != ')' && c != ' ') {
            return false;
        }
    }
    
    return true;
}

QString MainWindow::convertDisplayToExpression(const QString& display)
{
    QString expression = display;
    
    // 处理可能的显示符号转换
    expression.replace("×", "*");
    expression.replace("÷", "/");
    
    return expression;
}
