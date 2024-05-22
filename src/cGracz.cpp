#include "cGracz.h"


using namespace std;

cGracz::cGracz(cPlansza &aPlansza) : mPlansza (aPlansza)
{
    cout << "Konstruktor gracza" << endl;
    //ctor
}

cGracz::~cGracz()
{
    cout << "Destruktor gracza" << endl;
    //dtor
}

void cGracz::wprowadz(int aWiersz, int aKolumna)
{
//    int wiersz, kolumna;
//    cout << "Wprowadz nr wiersza, kolumny: \n";
//    cin >> mWiersz;
//    cin >> mKolumna;
    if(obslugaBledow(aWiersz, aKolumna)==false)
    {
        mPlansza.wstaw(aWiersz, aKolumna);
    }
    else
    {
        cout << napis() << endl;
    }
}

bool cGracz::obslugaBledow(int aWiersz, int aKolumna)
{
    if((aWiersz<0 || aWiersz>3 || aKolumna<0 || aKolumna>3) || (mPlansza.mPlansza[aWiersz][aKolumna]!='.'))
    {
//        mPlansza.wyswietl();
//        wprowadz();
        return true;
    }
    return false;
}

ostream & operator <<(ostream &aWyjscie, cGracz &aGracz)
{

    return aWyjscie << aGracz.napis();
}

string cGracz::napis()
{
    string napisZwrotny = "Niedozwolony ruch";
    return napisZwrotny;
}
