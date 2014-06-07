#ifndef MAINWINDOWTEST_H
#define MAINWINDOWTEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/mainwindow.h"

class mainwindowTest : public QObject
{
    Q_OBJECT
public:
    explicit mainwindowTest(QObject *parent = 0);

private:
    //DBQeurier *dbqe;

private slots:
    void initTestCase();

};

#endif // MAINWINDOWTEST_H
