#ifndef ADDWORDTEST_H
#define ADDWORDTEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/addword.h"

class addwordTest : public QObject
{
    Q_OBJECT
public:
    explicit addwordTest(QObject *parent = 0);

private:
    //DBQeurier *dbqe;

private slots:
    void initTestCase();

};

#endif // ADDWORDTEST_H
