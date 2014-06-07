#include "DbqeurierTest.h"

DbqeurierTest::DbqeurierTest(QObject *parent) :
    QObject(parent)
{
}

void DbqeurierTest::initTestCase(){
    dbqe = DBQeurier::instance();
}

//-------- Dictionary methods --------//
void DbqeurierTest::testGetDefinition_data(){
    QTest::addColumn<int>("lang_id");
    QTest::addColumn<QString>("wordToFind");
    QTest::addColumn<QString>("definition");
    QTest::newRow("Spanish 1st word ") << 1 << "abrigo" << "coat";
    QTest::newRow("Spanish 2nd word ") << 1 << "adios" << "Goodbye";
    QTest::newRow("Spanish 3rd word ") << 1 << "amarillo" << "yellow";
    QTest::newRow("Irish 1st word ") << 2 << "agus" << "and";
    QTest::newRow("Irish 2nd word ") << 2 << "amach" << "out";
    QTest::newRow("Irish 3rd word ") << 2 << "anuas" << "past";
    QTest::newRow("Cebuano 1st word ") << 3 << "abo" << "ash";
    QTest::newRow("Cebuano 2nd word ") << 3 << "abog" << "dust";
    QTest::newRow("Cebuano 3rd word ") << 3 << "ako" << "me";
}

void DbqeurierTest::testGetDefinition(){
    QFETCH(int, lang_id);
    QFETCH(QString, wordToFind);
    QFETCH(QString, definition);

    QCOMPARE(dbqe->getDefinition(lang_id, wordToFind), definition);
}

void DbqeurierTest::testGetDictOutput_data(){
    QTest::addColumn<int>("lang_id2");
    QTest::addColumn<QString>("wordToFind2");
    QStringList spaOne, spaTwo, spaThree;
    spaOne << "yellow" << "ah - mah - reel - lyo";
    spaTwo << "white" << "blahn - co";
    spaThree << "almost" << "cah - se";

    QStringList gleOne, gleTwo, gleThree;
    gleOne << "home" << " ";
    gleTwo << "out" << " ";
    gleThree << "father" << " ";

    QStringList cebOne, cebTwo, cebThree;
    cebOne << "liver" << "a - tay";
    cebTwo << "to take care of self" << "a-ti-man";
    cebThree << "fight - violent struggle" << "a - way";
    QTest::addColumn<QStringList>("defAndPron");

    QTest::newRow("Spanish 1st word ") << 1 << "amarillo" << spaOne;
    QTest::newRow("Spanish 1st word ") << 1 << "blanco" << spaTwo;
    QTest::newRow("Spanish 1st word ") << 1 << "casi" << spaThree;
    QTest::newRow("Irish 1st word ") << 2 << "abhaile" << gleOne;
    QTest::newRow("Irish 1st word ") << 2 << "amach" << gleTwo;
    QTest::newRow("Irish 1st word ") << 2 << "athair" << gleThree;
    QTest::newRow("Cebuano 1st word ") << 3 << "atay" << cebOne;
    QTest::newRow("Cebuano 1st word ") << 3 << "atiman" << cebTwo;
    QTest::newRow("Cebuano 1st word ") << 3 << "away" << cebThree;

}

void DbqeurierTest::testGetDictOutput(){
    QFETCH(int, lang_id2);
    QFETCH(QString, wordToFind2);
    QFETCH(QStringList, defAndPron);

    QCOMPARE(dbqe->getDictOutput(lang_id2, wordToFind2), defAndPron);
}

void DbqeurierTest::testUpdateDefinition(){
}

void DbqeurierTest::testAddEntry(){
}

//-------- Thesaurus methods --------//
void DbqeurierTest::testGetSynonyms_data(){
    QTest::addColumn<int>("lang_id3");
    QTest::addColumn<QString>("wordToFind3");
    QTest::addColumn<QStringList>("synonyms");

    QStringList one = QString("compañero|camarada|conocido").split("|");
    QStringList two = QString("acá|inmediato|junto").split("|");
    QStringList three = QString("ash|residue").split("|");

    QTest::newRow("GetSyn 1st word  ") << 1 << "amigo" << one;
    QTest::newRow("GetSyn 2st word  ") << 1 << "aqui" << two;
    QTest::newRow("GetSyn 3st word  ") << 3 << "abo" << three;
}

void DbqeurierTest::testGetSynonyms(){
    QFETCH(int, lang_id3);
    QFETCH(QString, wordToFind3);
    QFETCH(QStringList, synonyms);
    QCOMPARE(dbqe->getSynonyms(lang_id3, wordToFind3), synonyms);
}

void DbqeurierTest::testAssociateWord(){
}

void DbqeurierTest::testAddNewLanguage(){
}

void DbqeurierTest::testAddSynEntry(){
}

//-------- Games methods --------//
void DbqeurierTest::testGetWordsSet_data(){
    QTest::addColumn<int>("id2");
    QTest::addColumn<QStringList>("wordSet");

    QStringList spaLevel, gleLevel, cebLevel;
    spaLevel << "abrigo : coat" <<  "adios : Goodbye" <<
                "ahora : now" << "amar : to love" << "amarillo : yellow" <<
                "amigo : friend" << "andar : to walk" << "año : year";

    gleLevel << "agus : and" <<  "ainm : name" <<
                "áit : where" << "amach : out" << "ann : there" <<
                "ansin : then" << "anuas : past" << "aon : no";

    cebLevel << "abog : dust" <<  "abogado : lawyer" <<
                "adlaw : sun" << "agas : flow"
                << "ako : me" << "amahan : Father" << "anak : child"
                << "anhi : over here";

    qDebug() << spaLevel.length() << " " << gleLevel.length() << " " <<cebLevel.length();
    QTest::newRow("DefLevel 1 spa ") << 1 << spaLevel;
    QTest::newRow("DefLevel 1 gle ") << 2 << gleLevel;
    QTest::newRow("DefLevel 1 ceb ") << 3 << cebLevel;
}

/* Gets one set of words for each language.
 * checks that each element is in the set
*/
void DbqeurierTest::testGetWordsSet(){
    QFETCH(int, id2);
    QFETCH(QStringList, wordSet);
    QStringList strs = dbqe->getWordsSet(id2, 8);
    boolean allIn = true;
    foreach(QString str, wordSet){
        if(!strs.contains(str)){
            allIn = false;
            break;
        }
    }

    QVERIFY(allIn == true);
}

void DbqeurierTest::testGetSynSet_data(){
    QTest::addColumn<int>("synIDs");
    QTest::addColumn<QStringList>("synSet");

    QStringList spaLevel, gleLevel, cebLevel;
    spaLevel << "abrigo : gabán|sobretodo|capa|pelliza" <<  "adios : despedida|au revoir" <<
                "ahora : actualmente|hoy|hogaño|en este momento|hoy en día"
                << "amar : querer|apreciar|estimar|idolatrar|adorar" << "amarillo : amber|orange|golden" <<
                "amigo : compañero|camarada|conocido" << "andar : caminar|circular|recorrer|avanzar" << "año : añada|temporada|anualidad";

    gleLevel << "agus : chomh maith" <<  "ainm : teideal|chlib" << "áit : suíomh|láthair" << "amach : ar shiúl|as láthair"
             << "ann : thall|ar fail" << "ansin : an uair úd" << "anuas : siar|thios|go talamh" << "aon : ní hea|ar bith";

    cebLevel << "abog : alikabo|bugaw|kabukabo" <<  "abogado : atorni|manlalaban" <<
                "adlaw : sun" << "agas : flow|flowing|gushing"
                << "ako : me|mine" << "amahan : ama|papa|tatay" << "anak : child|kid|minor"
                << "anhi : diri|dali diri";

    qDebug() << spaLevel.length() << " " << gleLevel.length() << " " <<cebLevel.length();
    QTest::newRow("SynLevel 1 spa ") << 1 << spaLevel;
    QTest::newRow("SynLevel 1 gle ") << 2 << gleLevel;
    QTest::newRow("SynLevel 1 ceb ") << 3 << cebLevel;
}

void DbqeurierTest::testGetSynSet(){
    QFETCH(int, synIDs);
    QFETCH(QStringList, synSet);
    QStringList strs = dbqe->getSynSet(synIDs, 8);
    boolean allIn = true;
    foreach(QString str, synSet){
        if(!strs.contains(str)){
            allIn = false;
            break;
        }
    }

    QVERIFY(allIn == true);
}

void DbqeurierTest::testGetSoundOrPicBytes_data(){
    QTest::addColumn<QString>("words");
    QTest::addColumn<QByteArray>("wavByetes");

    QFile wavFile1("C:/Users/Onchie/Dropbox/VocabTesting/soundToTest/abrigo.wav");
    if(wavFile1.open(QIODevice::ReadOnly)){
        QByteArray wavSpaBytes(wavFile1.readAll());
        QTest::newRow("soundByte spa - 1 ") << "abrigo" << wavSpaBytes;
        qDebug() << "wavSpaBytes " << wavSpaBytes;
    }

    QFile wavFile2("C:/Users/Onchie/Dropbox/VocabTesting/soundToTest/abhaile.wav");
    if(wavFile2.open(QIODevice::ReadOnly)){
        QByteArray wavGleBytes(wavFile2.readAll());
        QTest::newRow("soundByte gle - 2 ") << "abhaile" << wavGleBytes;
        qDebug() << "wavGleBytes " << wavGleBytes;
    }

    QFile wavFile3("C:/Users/Onchie/Dropbox/VocabTesting/soundToTest/abogado.wav");
    if(wavFile3.open(QIODevice::ReadOnly)){
        QByteArray wavCebBytes(wavFile3.readAll());
        QTest::newRow("soundByte ceb - 3 ") << "abogado" << wavCebBytes;
        qDebug() << "wavCebBytes " << wavCebBytes;
    }
}

void DbqeurierTest::testGetSoundOrPicBytes(){
    QFETCH(QString, words);
    QFETCH(QByteArray, wavByetes);

    // from DB, correct bytes
    QCOMPARE(dbqe->getSoundOrPicBytes(words, "sound"), wavByetes);
}

//-------- Login --------//
// there is a username sarg with password 123
void DbqeurierTest::testLogin(){
    QVERIFY(dbqe->login("sarg", "123") == 1);
}

void DbqeurierTest::testNewLanguage(){
    //addNewLanguage
}

void DbqeurierTest::cleanupTestCase(){
    delete dbqe;
}

/*????????????
    testUpdateDefinition
    testAddEntry
    testAssociateWord
    testAddNewLanguage
    testAddSynEntry
    testNewLanguage
*/
