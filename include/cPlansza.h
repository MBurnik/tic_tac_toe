#ifndef CPLANSZA_H
#define CPLANSZA_H

#include <iostream>


class cPlansza
{
    int mLicznikTury;
public:
    char mPlansza[3][3];

    cPlansza();
    virtual ~cPlansza();
    void wyswietl();
    void wstaw(int aWiersz, int aKolumna);
    int status();
    void zeruj();
    cPlansza & operator =(const cPlansza &);
};

#endif // CPLANSZA_H
