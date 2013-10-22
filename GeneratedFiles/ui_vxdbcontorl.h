/********************************************************************************
** Form generated from reading UI file 'vxdbcontorl.ui'
**
** Created: Wed Oct 23 01:16:34 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VXDBCONTORL_H
#define UI_VXDBCONTORL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VxDBContorlClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VxDBContorlClass)
    {
        if (VxDBContorlClass->objectName().isEmpty())
            VxDBContorlClass->setObjectName(QString::fromUtf8("VxDBContorlClass"));
        VxDBContorlClass->resize(600, 400);
        menuBar = new QMenuBar(VxDBContorlClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        VxDBContorlClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VxDBContorlClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        VxDBContorlClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(VxDBContorlClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        VxDBContorlClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(VxDBContorlClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        VxDBContorlClass->setStatusBar(statusBar);

        retranslateUi(VxDBContorlClass);

        QMetaObject::connectSlotsByName(VxDBContorlClass);
    } // setupUi

    void retranslateUi(QMainWindow *VxDBContorlClass)
    {
        VxDBContorlClass->setWindowTitle(QApplication::translate("VxDBContorlClass", "VxDBContorl", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class VxDBContorlClass: public Ui_VxDBContorlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VXDBCONTORL_H
