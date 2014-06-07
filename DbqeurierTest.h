#ifndef DBQEURIERTEST_H
#define DBQEURIERTEST_H

#include <QtTest/QtTest>
#include "../VocabWidener/dbqeurier.h"
#include <QByteArray>

class DbqeurierTest : public QObject
{
    Q_OBJECT
public:
    explicit DbqeurierTest(QObject *parent = 0);

private:
    DBQeurier *dbqe;

private slots:
    void initTestCase();

    //Dictionary methods
    void testGetDefinition_data();
    void testGetDefinition();
    void testGetDictOutput_data();
    void testGetDictOutput();
    void testUpdateDefinition();
    void testAddEntry();

    //Thesaurus methods
    void testGetSynonyms_data();
    void testGetSynonyms();
    void testAssociateWord();
    void testAddNewLanguage();
    void testAddSynEntry();

    //Games methods
    void testGetWordsSet_data();
    void testGetWordsSet();
    void testGetSynSet_data();
    void testGetSynSet();
    void testGetSoundOrPicBytes_data();
    void testGetSoundOrPicBytes();

    //Login
    void testLogin();
    void testNewLanguage();
    void cleanupTestCase();

};

#endif // DBQEURIERTEST_H
