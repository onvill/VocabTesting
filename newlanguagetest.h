#ifndef NEWLANGUAGETEST_H
#define NEWLANGUAGETEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/newlanguage.h"

class newlanguageTest : public QObject
{
    Q_OBJECT
public:
    explicit newlanguageTest(QObject *parent = 0);

private:
    //DBQeurier *dbqe;

private slots:
    void initTestCase();

};

#endif // NEWLANGUAGETEST_H
