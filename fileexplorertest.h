#ifndef FILEEXPLORERTEST_H
#define FILEEXPLORERTEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/fileexplorer.h"

class fileexplorerTest : public QObject
{
    Q_OBJECT
public:
    explicit fileexplorerTest(QObject *parent = 0);

private:
    //DBQeurier *dbqe;

private slots:
    void initTestCase();

};

#endif // FILEEXPLORERTEST_H
