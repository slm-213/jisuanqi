/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

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
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
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
""
                        "\n"
"QPushButton#functionButton:hover {\n"
"    background-color: #777777;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        display = new QLineEdit(centralwidget);
        display->setObjectName("display");
        display->setReadOnly(true);
        display->setAlignment(Qt::AlignRight);

        verticalLayout->addWidget(display);

        buttonLayout = new QGridLayout();
        buttonLayout->setObjectName("buttonLayout");
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        buttonLayout->addWidget(clearButton, 0, 0, 1, 1);

        backspaceButton = new QPushButton(centralwidget);
        backspaceButton->setObjectName("backspaceButton");

        buttonLayout->addWidget(backspaceButton, 0, 1, 1, 1);

        leftParenButton = new QPushButton(centralwidget);
        leftParenButton->setObjectName("leftParenButton");

        buttonLayout->addWidget(leftParenButton, 0, 2, 1, 1);

        rightParenButton = new QPushButton(centralwidget);
        rightParenButton->setObjectName("rightParenButton");

        buttonLayout->addWidget(rightParenButton, 0, 3, 1, 1);

        button7 = new QPushButton(centralwidget);
        button7->setObjectName("button7");

        buttonLayout->addWidget(button7, 1, 0, 1, 1);

        button8 = new QPushButton(centralwidget);
        button8->setObjectName("button8");

        buttonLayout->addWidget(button8, 1, 1, 1, 1);

        button9 = new QPushButton(centralwidget);
        button9->setObjectName("button9");

        buttonLayout->addWidget(button9, 1, 2, 1, 1);

        divideButton = new QPushButton(centralwidget);
        divideButton->setObjectName("divideButton");

        buttonLayout->addWidget(divideButton, 1, 3, 1, 1);

        button4 = new QPushButton(centralwidget);
        button4->setObjectName("button4");

        buttonLayout->addWidget(button4, 2, 0, 1, 1);

        button5 = new QPushButton(centralwidget);
        button5->setObjectName("button5");

        buttonLayout->addWidget(button5, 2, 1, 1, 1);

        button6 = new QPushButton(centralwidget);
        button6->setObjectName("button6");

        buttonLayout->addWidget(button6, 2, 2, 1, 1);

        multiplyButton = new QPushButton(centralwidget);
        multiplyButton->setObjectName("multiplyButton");

        buttonLayout->addWidget(multiplyButton, 2, 3, 1, 1);

        button1 = new QPushButton(centralwidget);
        button1->setObjectName("button1");

        buttonLayout->addWidget(button1, 3, 0, 1, 1);

        button2 = new QPushButton(centralwidget);
        button2->setObjectName("button2");

        buttonLayout->addWidget(button2, 3, 1, 1, 1);

        button3 = new QPushButton(centralwidget);
        button3->setObjectName("button3");

        buttonLayout->addWidget(button3, 3, 2, 1, 1);

        subtractButton = new QPushButton(centralwidget);
        subtractButton->setObjectName("subtractButton");

        buttonLayout->addWidget(subtractButton, 3, 3, 1, 1);

        button0 = new QPushButton(centralwidget);
        button0->setObjectName("button0");

        buttonLayout->addWidget(button0, 4, 0, 1, 1);

        decimalButton = new QPushButton(centralwidget);
        decimalButton->setObjectName("decimalButton");

        buttonLayout->addWidget(decimalButton, 4, 1, 1, 1);

        equalsButton = new QPushButton(centralwidget);
        equalsButton->setObjectName("equalsButton");

        buttonLayout->addWidget(equalsButton, 4, 2, 1, 1);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        buttonLayout->addWidget(addButton, 4, 3, 1, 1);


        verticalLayout->addLayout(buttonLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 400, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Calculator", nullptr));
        display->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        clearButton->setObjectName(QCoreApplication::translate("MainWindow", "functionButton", nullptr));
        backspaceButton->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        backspaceButton->setObjectName(QCoreApplication::translate("MainWindow", "functionButton", nullptr));
        leftParenButton->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        leftParenButton->setObjectName(QCoreApplication::translate("MainWindow", "operatorButton", nullptr));
        rightParenButton->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        rightParenButton->setObjectName(QCoreApplication::translate("MainWindow", "operatorButton", nullptr));
        button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button7->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button8->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button9->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        divideButton->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        divideButton->setObjectName(QCoreApplication::translate("MainWindow", "operatorButton", nullptr));
        button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button4->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button5->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button6->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        multiplyButton->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        multiplyButton->setObjectName(QCoreApplication::translate("MainWindow", "operatorButton", nullptr));
        button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button1->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        button2->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button3->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        subtractButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        subtractButton->setObjectName(QCoreApplication::translate("MainWindow", "operatorButton", nullptr));
        button0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button0->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        decimalButton->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        decimalButton->setObjectName(QCoreApplication::translate("MainWindow", "numberButton", nullptr));
        equalsButton->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        equalsButton->setObjectName(QCoreApplication::translate("MainWindow", "operatorButton", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        addButton->setObjectName(QCoreApplication::translate("MainWindow", "operatorButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
