#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *display;
    QGridLayout *buttonLayout;
    QPushButton *clearButton;
    QPushButton *backspaceButton;
    QPushButton *leftParenButton;
    QPushButton *rightParenButton;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *divideButton;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *multiplyButton;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *subtractButton;
    QPushButton *button0;
    QPushButton *decimalButton;
    QPushButton *equalsButton;
    QPushButton *addButton;
    QPushButton *squareButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 500);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #2b2b2b;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #1e1e1e;\n"
"    color: #ffffff;\n"
"    border: 2px solid #404040;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #404040;\n"
"    color: #ffffff;\n"
"    border: 2px solid #555555;\n"
"    border-radius: 8px;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    min-height: 50px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #555555;\n"
"    border-color: #666666;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #333333;\n"
"}\n"
"\n"
"QPushButton#numberButton {\n"
"    background-color: #2d2d2d;\n"
"}\n"
"\n"
"QPushButton#operatorButton {\n"
"    background-color: #ff9500;\n"
"    color: #000000;\n"
"}\n"
"\n"
"QPushButton#operatorButton:hover {\n"
"    background-color: #ffad33;\n"
"}\n"
"\n"
"QPushButton#functionButton {\n"
"    background-color: #666666;\n"
"}\n"
"\n"
"QPushButton#functionButton:hover {\n"
"    background-color: #777777;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        display = new QLineEdit(centralwidget);
        display->setObjectName(QString::fromUtf8("display"));
        display->setReadOnly(true);
        display->setAlignment(Qt::AlignRight);
        display->setText(QString::fromUtf8("0"));

        verticalLayout->addWidget(display);

        buttonLayout = new QGridLayout();
        buttonLayout->setObjectName(QString::fromUtf8("buttonLayout"));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        clearButton->setText(QString::fromUtf8("C"));

        buttonLayout->addWidget(clearButton, 0, 0, 1, 1);

        backspaceButton = new QPushButton(centralwidget);
        backspaceButton->setObjectName(QString::fromUtf8("backspaceButton"));
        backspaceButton->setText(QString::fromUtf8("⌫"));

        buttonLayout->addWidget(backspaceButton, 0, 1, 1, 1);

        leftParenButton = new QPushButton(centralwidget);
        leftParenButton->setObjectName(QString::fromUtf8("leftParenButton"));
        leftParenButton->setText(QString::fromUtf8("("));

        buttonLayout->addWidget(leftParenButton, 0, 2, 1, 1);

        rightParenButton = new QPushButton(centralwidget);
        rightParenButton->setObjectName(QString::fromUtf8("rightParenButton"));
        rightParenButton->setText(QString::fromUtf8(")"));

        buttonLayout->addWidget(rightParenButton, 0, 3, 1, 1);

        button7 = new QPushButton(centralwidget);
        button7->setObjectName(QString::fromUtf8("button7"));
        button7->setText(QString::fromUtf8("7"));

        buttonLayout->addWidget(button7, 1, 0, 1, 1);

        button8 = new QPushButton(centralwidget);
        button8->setObjectName(QString::fromUtf8("button8"));
        button8->setText(QString::fromUtf8("8"));

        buttonLayout->addWidget(button8, 1, 1, 1, 1);

        button9 = new QPushButton(centralwidget);
        button9->setObjectName(QString::fromUtf8("button9"));
        button9->setText(QString::fromUtf8("9"));

        buttonLayout->addWidget(button9, 1, 2, 1, 1);

        divideButton = new QPushButton(centralwidget);
        divideButton->setObjectName(QString::fromUtf8("divideButton"));
        divideButton->setText(QString::fromUtf8("÷"));

        buttonLayout->addWidget(divideButton, 1, 3, 1, 1);

        button4 = new QPushButton(centralwidget);
        button4->setObjectName(QString::fromUtf8("button4"));
        button4->setText(QString::fromUtf8("4"));

        buttonLayout->addWidget(button4, 2, 0, 1, 1);

        button5 = new QPushButton(centralwidget);
        button5->setObjectName(QString::fromUtf8("button5"));
        button5->setText(QString::fromUtf8("5"));

        buttonLayout->addWidget(button5, 2, 1, 1, 1);

        button6 = new QPushButton(centralwidget);
        button6->setObjectName(QString::fromUtf8("button6"));
        button6->setText(QString::fromUtf8("6"));

        buttonLayout->addWidget(button6, 2, 2, 1, 1);

        multiplyButton = new QPushButton(centralwidget);
        multiplyButton->setObjectName(QString::fromUtf8("multiplyButton"));
        multiplyButton->setText(QString::fromUtf8("×"));

        buttonLayout->addWidget(multiplyButton, 2, 3, 1, 1);

        button1 = new QPushButton(centralwidget);
        button1->setObjectName(QString::fromUtf8("button1"));
        button1->setText(QString::fromUtf8("1"));

        buttonLayout->addWidget(button1, 3, 0, 1, 1);

        button2 = new QPushButton(centralwidget);
        button2->setObjectName(QString::fromUtf8("button2"));
        button2->setText(QString::fromUtf8("2"));

        buttonLayout->addWidget(button2, 3, 1, 1, 1);

        button3 = new QPushButton(centralwidget);
        button3->setObjectName(QString::fromUtf8("button3"));
        button3->setText(QString::fromUtf8("3"));

        buttonLayout->addWidget(button3, 3, 2, 1, 1);

        subtractButton = new QPushButton(centralwidget);
        subtractButton->setObjectName(QString::fromUtf8("subtractButton"));
        subtractButton->setText(QString::fromUtf8("-"));

        buttonLayout->addWidget(subtractButton, 3, 3, 1, 1);

        button0 = new QPushButton(centralwidget);
        button0->setObjectName(QString::fromUtf8("button0"));
        button0->setText(QString::fromUtf8("0"));

        buttonLayout->addWidget(button0, 4, 0, 1, 1);

        decimalButton = new QPushButton(centralwidget);
        decimalButton->setObjectName(QString::fromUtf8("decimalButton"));
        decimalButton->setText(QString::fromUtf8("."));

        buttonLayout->addWidget(decimalButton, 4, 1, 1, 1);

        equalsButton = new QPushButton(centralwidget);
        equalsButton->setObjectName(QString::fromUtf8("equalsButton"));
        equalsButton->setText(QString::fromUtf8("="));

        buttonLayout->addWidget(equalsButton, 4, 2, 1, 1);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setText(QString::fromUtf8("+"));

        buttonLayout->addWidget(addButton, 4, 3, 1, 1);

        squareButton = new QPushButton(centralwidget);
        squareButton->setObjectName(QString::fromUtf8("squareButton"));
        squareButton->setText(QString::fromUtf8("x²"));

        buttonLayout->addWidget(squareButton, 5, 0, 1, 1);


        verticalLayout->addLayout(buttonLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 400, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
