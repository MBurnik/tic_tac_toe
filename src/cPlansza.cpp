#include "cPlansza.h"


using namespace std;

cPlansza::cPlansza()
{
    cout << "Konstruktor planszy" << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            mPlansza[i][j]='.';
        }
    }
    mLicznikTury=0;
}

cPlansza::~cPlansza()
{
    cout << "Destruktor planszy" << endl;
    //dtor
}

void cPlansza::wyswietl()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << mPlansza[i][j];
        }
        cout << endl;
    }
}

void cPlansza::wstaw(int aWiersz, int aKolumna)
{
    mLicznikTury++;

    if(mLicznikTury%2==1) mPlansza[aWiersz][aKolumna]='X';
    else mPlansza[aWiersz][aKolumna]='O';
//    }
}

int cPlansza::status()
{
//    return 0 - rozgrywka trwa
//    return 1 - wygrana gracza, X
//    return 2 - wygrana AI, O
//    return 3 - remis

    //sprawdzanie wygranej
    int licznikX = 0;
    int licznikO = 0;
    int licznik = 0;
    for(int i=0; i<3; i++)
    {
        licznikX=0;
        licznikO=0;
        for(int j=0; j<3; j++)
        {
            if(mPlansza[i][j]=='X') licznikX++; //poziomo
            if(mPlansza[i][j]=='O') licznikO++;
        }
        if(licznikX == 3) return 1;
        if(licznikO == 3) return 2;
    }

    for(int j=0; j<3; j++)
    {
        licznikX=0;
        licznikO=0;
        for(int i=0; i<3; i++)
        {
            if(mPlansza[i][j]=='X') licznikX++; //pionowo
            if(mPlansza[i][j]=='O') licznikO++;
        }
        if(licznikX == 3) return 1;
        if(licznikO == 3) return 2;
    }

    licznikX=0;
    licznikO=0;
    for(int i=0; i<3; i++)
    {
        if(mPlansza[i][i]=='X') licznikX++;     //przekatna w dol
        if(mPlansza[i][i]=='O') licznikO++;
        if(licznikX == 3) return 1;
        if(licznikO == 3) return 2;
    }

    licznikX=0;
    licznikO=0;
    int j=2;
    for(int i=0; i<3; i++)
    {
        if(mPlansza[i][j]=='X') licznikX++;     //przekatna w gore
        if(mPlansza[i][j]=='O') licznikO++;
        if(licznikX == 3) return 1;
        if(licznikO == 3) return 2;
        j--;
    }

    //sprawdzanie wolnych pol
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(mPlansza[i][j]!='.') licznik++;
        }
    }
    if(licznik==9) return 3;
//    if(mLicznikTury==9) return 3;

    return 0;
}

void cPlansza::zeruj()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            mPlansza[i][j]='.';
        }
    }
    mLicznikTury=0;
}

cPlansza& cPlansza::operator =(const cPlansza& aPlansza)
{
    this->zeruj();
    return *this;
}
