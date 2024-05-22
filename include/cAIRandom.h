#ifndef CAIRANDOM_H
#define CAIRANDOM_H

#include <cGraczAI.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

class cAIRandom : public cGraczAI
{
public:
    cAIRandom(cPlansza &aPlansza);
    virtual ~cAIRandom();
    void wprowadz();
};

#endif // CAIRANDOM_H
