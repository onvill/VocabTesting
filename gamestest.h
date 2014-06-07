#ifndef GAMESTEST_H
#define GAMESTEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/games.h"

class gamesTest : public QObject
{
    Q_OBJECT
public:
    explicit gamesTest(QObject *parent = 0);

private:
    //DBQeurier *dbqe;

private slots:
    void initTestCase();

};

#endif // GAMESTEST_H
