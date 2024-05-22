#ifndef CAITRUDNY_H
#define CAITRUDNY_H

#include <cGraczAI.h>
#include "cPlansza.h"

#include <iostream>

class cAITrudny : public cGraczAI
{
    cPlansza mPlanszaKopia;
public:
    cAITrudny(cPlansza &aPlansza);
    virtual ~cAITrudny();
    void wprowadz();
    int minimax(bool maksymalizowanie);
    void kopiuj();
};

#endif // CAITRUDNY_H
