#ifndef GA4_ROSTER_H
#define GA4_ROSTER_H

#include <iostream>
#include "player.h"
using namespace std;

class doublell
{
private:
    benchPlayer* head;
    benchPlayer* tail;
public:
    doublell();
    doublell(player a[]);
    benchPlayer* getHead();
    benchPlayer* getTail();
    void setHead(benchPlayer* p);
    void setTail(benchPlayer* p);

    void insert(benchPlayer* add);
    benchPlayer* remove(int quarter);
    void print();
    benchPlayer* search(benchPlayer *x);
    void destroy();
    void getMinutes();

    benchPlayer* deactivate(courtPlayer x);
    benchPlayer* getSecond();
    benchPlayer* remove2ndFromEnd();
    benchPlayer* remove2ndFromBeg();
};

class circularll
{
private:
    courtPlayer* head;
    courtPlayer* tail;
public:
    circularll();
    circularll(player a[]);
    courtPlayer* getHead();
    courtPlayer* getTail();
    void setHead(courtPlayer* p);
    void setTail(courtPlayer* p);

    void insert(courtPlayer* add);
    void remove(courtPlayer* x);
    void rotate(int age, benchPlayer add);
    void print();
    courtPlayer* search(courtPlayer *x);
    void destroy();
    void getMinutes();

    courtPlayer* activate(benchPlayer x);
    double recordTime();
};

#endif