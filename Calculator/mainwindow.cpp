#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)//初始化列表
    , ui(new Ui::MainWindow)//初始化成员变量
    , justCalculated(false)//初始化成员变量justCalculated
{
    ui->setupUi(this);//初始化ui组件
    currentExpression = "0";//初始显示为0
    connectButtons();//连接按钮信号和槽函数
    updateDisplay();//更新显示
}

MainWindow::~MainWindow()//析构函数
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

void MainWindow::onNumberClicked()//处理数字按钮点击的槽函数，sender为信号发送者，信号为clicked，MainWindow为信号接受者
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());//获取触发当前槽函数的按钮对象，并将其转换为QPushButton类型的指针
    if (!button) return;
    
    QString number = button->text();//获取触发当前槽函数的操作符按钮上显示的文本
    
    if (justCalculated) {//如果刚完成一次计算
        currentExpression = number;//用新数字替换当前表达式
        justCalculated = false;//重置状态
    } else {
        if (currentExpression == "0") {//当前表达式是初始的0
            currentExpression = number;//新输入的数字替换0
        } else {
            currentExpression += number;//不是0则继续追加数字
        }
    }
    
    updateDisplay();//将表达式表示出来
}

void MainWindow::onOperatorClicked()//处理操作符的槽函数
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());//获取触发当前槽函数的按钮对象，并将其安全转换为QPushButton类型的指针
    if (!button) return;
    
    QString operatorText = button->text();//获取当前点击的操作符按钮上显示的文本内容
    QString operatorChar;//声明一个字符串变量，用于存储转换后可直接参与计算的标准操作符符号。
    
    // 转换显示符号为计算符号
    if (operatorText == "×") operatorChar = "*";
    else if (operatorText == "÷") operatorChar = "/";
    else operatorChar = operatorText;
    
    if (justCalculated) {//刚计算完
        justCalculated = false;
    }
    
    // 检查是否以操作符结尾，如果是则替换
    if (!currentExpression.isEmpty() && 
        (currentExpression.endsWith("+") || currentExpression.endsWith("-") || 
         currentExpression.endsWith("*") || currentExpression.endsWith("/"))) {
        currentExpression.chop(1);//如果满足条件，通过 chop(1) 删除表达式末尾的最后一个字符（替换旧操作符）
    }
    
    currentExpression += operatorChar;//转换之后的标准操作符追加到当前表达式末尾
    updateDisplay();//调用显示更新函数
}

void MainWindow::onFunctionClicked()//扩展，还没写呢还
{
}

void MainWindow::onEqualsClicked()//处理等号的槽函数
{
    try {
        QString expression = convertDisplayToExpression(currentExpression);//转换表达式格式
        double result = evaluator.evaluate(expression.toStdString());//调用表达式计算器对转换后的表达式进行计算，并获取计算结果
        
        // 变量储存格式化结果
        QString resultStr;
        if (result == static_cast<long long>(result)) {//判断结果是否为整数
            resultStr = QString::number(static_cast<long long>(result));//不含小数
        } else {
            resultStr = QString::number(result, 'g', 10);//转化为小数
        }
        
        currentExpression = resultStr;//将格式化后的计算结果字符串赋值给当前表达式变量，作为后续运算的基础
        justCalculated = true;//状态设置成true
        updateDisplay();//更新显示器
    } catch (const std::exception& e) {
        showError(QString("计算错误: %1").arg(e.what()));
    }
}

void MainWindow::onClearClicked()//C清除
{
    currentExpression = "0";//当前表达式初始化为0
    justCalculated = false;//重置状态
    updateDisplay();//更新显示
}

void MainWindow::onBackspaceClicked()//退格
{
    if (justCalculated) {
        currentExpression = "0";//若刚计算完直接到初始状态
        justCalculated = false;
    } else if (currentExpression.length() > 1) {//长度大于1就删除最后一个字符
        currentExpression.chop(1);
    } else {
        currentExpression = "0";//仅剩单个字符重置
    }
    updateDisplay();//更新显示
}

void MainWindow::onDecimalClicked()//小数点点击
{
    if (justCalculated) {
        currentExpression = "0.";//以小数点开头
        justCalculated = false;
    } else {
        // 检查当前数字是否已经有小数点
        QString lastNumber = "";//初始化空字符串
        for (int i = currentExpression.length() - 1; i >= 0; --i) {//从表达式末尾向前遍历，提取最后一个数字（包括可能的小数点
            QChar c = currentExpression.at(i);//获取当前位置字符
            if (c.isDigit() || c == '.') {
                lastNumber = c + lastNumber;//从后向前拼接字符，构建表达式中最后一个数字的完整字符串
            } else {
                break;
            }
        }
        
        if (!lastNumber.contains('.')) {//若最后一个数字无小数点就添加
            currentExpression += ".";
        }
    }
    updateDisplay();//更新显示
}

void MainWindow::onParenClicked()//括号点击
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());//将发送点击事件的对象转换为QPushButton指针（获取被点击的按钮）
    if (!button) return;
    
    QString paren = button->text();//获取显示的文本
    
    if (justCalculated) {
        currentExpression = paren;//若刚计算完，直接用括号替换当前结果（开始新的表达式）
        justCalculated = false;
    } else {
        currentExpression += paren;//在表达式末尾添加括号
    }
    
    updateDisplay();//显示
}

void MainWindow::updateDisplay()//显示更新函数
{
    ui->display->setText(currentExpression);
}

void MainWindow::appendToExpression(const QString& text)//表达式追加函数
{
    if (justCalculated) {//若刚完成计算（处于结果显示状态），直接用新文本替换当前表达式
        currentExpression = text;
        justCalculated = false;
    } else {
        if (currentExpression == "0") {//若是0直接替换
            currentExpression = text;
        } else {
            currentExpression += text;//否则追加新文本
        }
    }
    updateDisplay();
}

void MainWindow::showError(const QString& message)//错误处理
{
    QMessageBox::warning(this, "错误", message);//弹出警告对话框
    currentExpression = "0";
    justCalculated = false;
    updateDisplay();
}

bool MainWindow::isValidInput(const QString& input)//输入验证
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

QString MainWindow::convertDisplayToExpression(const QString& display)//显示符号到计算符号的转换函数
{
    QString expression = display;
    
    // 处理可能的显示符号转换
    expression.replace("×", "*");
    expression.replace("÷", "/");
    
    return expression;
}
