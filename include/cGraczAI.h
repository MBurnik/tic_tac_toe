#ifndef CGRACZAI_H
#define CGRACZAI_H

#include "cPlansza.h"

#include <iostream>

class cGraczAI
{
protected:
    cPlansza &mPlansza;
    int mWiersz;
    int mKolumna;
public:
    cGraczAI(cPlansza &aPlansza);
    virtual ~cGraczAI();
    virtual void wprowadz()=0;
};

#endif // CGRACZAI_H
