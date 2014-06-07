#ifndef UPDATEDEFINITIONTEST_H
#define UPDATEDEFINITIONTEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/updatedefinition.h"

class updatedefinitionTest : public QObject
{
    Q_OBJECT
public:
    explicit updatedefinitionTest(QObject *parent = 0);

private:
    //DBQeurier *dbqe;

private slots:
    void initTestCase();

};

#endif // UPDATEDEFINITIONTEST_H
