#include "cAIRandom.h"

using namespace std;

cAIRandom::cAIRandom(cPlansza &aPlansza) : cGraczAI(aPlansza)
{
    cout << "Konstruktor AI Random" << endl;
    srand(time(NULL));
    //ctor
}

cAIRandom::~cAIRandom()
{
    cout << "Destruktor AI Random" << endl;
    //dtor
}

void cAIRandom::wprowadz()
{
    int wiersz, kolumna;
    do
    {
        wiersz = rand()%3;
        kolumna = rand()%3;
    }
    while(mPlansza.mPlansza[wiersz][kolumna]!='.');
        mWiersz = wiersz;
        mKolumna = kolumna;
        mPlansza.wstaw(mWiersz, mKolumna);
}
