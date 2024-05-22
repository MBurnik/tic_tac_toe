#ifndef CGRACZ_H
#define CGRACZ_H

#include "cPlansza.h"

#include <iostream>
#include <string.h>


class cGracz
{
    cPlansza &mPlansza;
//    int mWiersz;
//    int mKolumna;
public:
    cGracz(cPlansza &aPlansza);
    virtual ~cGracz();
    void  wprowadz(int aWiersz, int aKolumna);
    bool obslugaBledow(int aWiersz, int aKolumna);
    friend std::ostream & operator <<(std::ostream &aWyjscie, cGracz &aGracz);
    std::string napis();
};

#endif // CGRACZ_H
