#include <iostream>
#include "cPlansza.h"
#include "cGracz.h"
#include "cGraczAI.h"
#include "cAITrudny.h"
#include "cAIRandom.h"
#include "cGra.h"

using namespace std;

int main()
{
    cPlansza plansza;
    cGracz gracz(plansza);
    cGraczAI *graczAITrudny = new cAITrudny(plansza); //    dynamiczne zalokowanie pamieci
    cGraczAI *graczAIRandom = new cAIRandom(plansza);
    cGra gra(plansza, gracz, graczAITrudny, graczAIRandom);
    gra.graj();
    delete graczAIRandom;
    delete graczAITrudny;

    return 0;
}
