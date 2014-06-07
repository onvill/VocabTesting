#ifndef LOGINTEST_H
#define LOGINTEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/login.h"

class loginTest : public QObject
{
    Q_OBJECT
public:
    explicit loginTest(QObject *parent = 0);

private:
    //DBQeurier *dbqe;

private slots:
    void initTestCase();

};

#endif // LOGINTEST_H
