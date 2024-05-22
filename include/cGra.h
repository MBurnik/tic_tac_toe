#ifndef CGRA_H
#define CGRA_H

#include "cPlansza.h"
#include "cGracz.h"
#include "cGraczAI.h"
#include <SFML/Graphics.hpp>

#include "iostream"
#include <sstream>


class cGra
{
    cPlansza &mPlansza;
    cGracz &mGracz;
    cGraczAI *mGraczAITrudny;
    cGraczAI *mGraczAIRandom;
    int wynikGracza;
    int wynikAI;
public:
    cGra(cPlansza &aPlansza, cGracz &aGracz, cGraczAI *aGraczAITrudny, cGraczAI *aGraczAIRandom);
    virtual ~cGra();
    void graj();
};

#endif // CGRA_H
