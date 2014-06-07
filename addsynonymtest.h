#ifndef ADDSYNONYMTEST_H
#define ADDSYNONYMTEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/addsynonym.h"

class addSynonymTest : public QObject
{
    Q_OBJECT
public:
    explicit addSynonymTest(QObject *parent = 0);

private:
    //DBQeurier *dbqe;

private slots:
    void initTestCase();

};

#endif // ADDSYNONYMTEST_H
