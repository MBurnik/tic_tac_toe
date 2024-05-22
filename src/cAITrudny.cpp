#include "cAITrudny.h"

using namespace std;

cAITrudny::cAITrudny(cPlansza &aPlansza) : cGraczAI(aPlansza)
{
    cout << "Konstruktor AI Trudnego" << endl;
    //ctor
}

cAITrudny::~cAITrudny()
{
    cout << "Destruktor AI Trudnego" << endl;
    //dtor
}

void cAITrudny::wprowadz()
{
    kopiuj();

    int wynik=-9999, wynik2;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(mPlanszaKopia.mPlansza[i][j]=='.')
            {
                mPlanszaKopia.mPlansza[i][j] = 'O';
                wynik2 = minimax(false);
                mPlanszaKopia.mPlansza[i][j] = '.';
                if(wynik2>wynik)
                {
                    wynik = wynik2;
                    mWiersz = i;
                    mKolumna = j;
                }
            }
        }
    }
    mPlansza.wstaw(mWiersz, mKolumna);
}

int cAITrudny::minimax(bool maksymalizowanie)
{
    if(mPlanszaKopia.status()!=0)
    {
        if(mPlanszaKopia.status()==1) return -1;
        if(mPlanszaKopia.status()==2) return 1;
        if(mPlanszaKopia.status()==3) return 0;
    }
    int wynik, wynik2;

//    maksymalizacja
    if(maksymalizowanie==true)
    {
        wynik = -9999;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(mPlanszaKopia.mPlansza[i][j]=='.')
                {
                    mPlanszaKopia.mPlansza[i][j] = 'O';
                    wynik2 = minimax(false);
                    mPlanszaKopia.mPlansza[i][j] = '.';
                    if(wynik2 > wynik) wynik = wynik2;
                }
            }
        }
    }


//    minimalizacja
    else
    {
        wynik = 9999;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(mPlanszaKopia.mPlansza[i][j]=='.')
                {
                    mPlanszaKopia.mPlansza[i][j] = 'X';
                    wynik2 = minimax(true);
                    mPlanszaKopia.mPlansza[i][j] = '.';
                    if(wynik2 < wynik) wynik = wynik2;
                }
            }
        }
    }
    return wynik;
}

void cAITrudny::kopiuj()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            mPlanszaKopia.mPlansza[i][j]=mPlansza.mPlansza[i][j];
        }
    }
}
