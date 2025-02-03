/********************************************************************************
** Form generated from reading UI file 'maincontroller.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONTROLLER_H
#define UI_MAINCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainController
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *mainLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *saveButton;
    QPushButton *addButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteButton;
    QSpinBox *deleteIdBox;
    QLabel *connectionStatus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainController)
    {
        if (MainController->objectName().isEmpty())
            MainController->setObjectName("MainController");
        MainController->resize(800, 600);
        centralwidget = new QWidget(MainController);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        mainLayout = new QHBoxLayout();
        mainLayout->setObjectName("mainLayout");
        mainLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");

        mainLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        verticalLayout_2->addWidget(saveButton);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        verticalLayout_2->addWidget(addButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout->addWidget(deleteButton);

        deleteIdBox = new QSpinBox(centralwidget);
        deleteIdBox->setObjectName("deleteIdBox");

        horizontalLayout->addWidget(deleteIdBox);


        verticalLayout_2->addLayout(horizontalLayout);

        connectionStatus = new QLabel(centralwidget);
        connectionStatus->setObjectName("connectionStatus");

        verticalLayout_2->addWidget(connectionStatus);


        mainLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(mainLayout, 0, 0, 1, 1);

        MainController->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainController);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainController->setMenuBar(menubar);
        statusbar = new QStatusBar(MainController);
        statusbar->setObjectName("statusbar");
        MainController->setStatusBar(statusbar);

        retranslateUi(MainController);

        QMetaObject::connectSlotsByName(MainController);
    } // setupUi

    void retranslateUi(QMainWindow *MainController)
    {
        MainController->setWindowTitle(QCoreApplication::translate("MainController", "MainController", nullptr));
        saveButton->setText(QCoreApplication::translate("MainController", "Save changes", nullptr));
        addButton->setText(QCoreApplication::translate("MainController", "Add", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainController", "Delete Id : ", nullptr));
        connectionStatus->setText(QCoreApplication::translate("MainController", "[+] Conneciton to the DB", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainController: public Ui_MainController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONTROLLER_H
