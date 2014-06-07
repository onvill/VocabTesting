#include <QtTest/QtTest>

#include "DbqeurierTest.h"
#include "addsynonymtest.h"
#include "addwordtest.h"
#include "fileexplorertest.h"
#include "gamestest.h"
#include "logintest.h"
#include "mainwindowtest.h"
#include "newlanguagetest.h"
#include "updatedefinitiontest.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    DbqeurierTest dbqe;
    QTest::qExec(&dbqe);

    /*addwordTest ad;
    QTest::qExec(&ad);

    addwordTest aw;
    QTest::qExec(&aw);

    fileexplorerTest fe;
    QTest::qExec(&fe);

    gamesTest gt;
    QTest::qExec(&gt);

    loginTest lt;
    QTest::qExec(&lt);

    mainwindowTest mw;
    QTest::qExec(&mw);

    newlanguageTest nl;
    QTest::qExec(&nl);

    updatedefinitionTest ud;
    QTest::qExec(&ud);*/

    //MainWindow w;

    return 0;
}


