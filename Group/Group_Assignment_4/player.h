#ifndef GA4_PLAYER_H
#define GA4_PLAYER_H

#include <iostream>
using namespace std;

class player{
    friend ostream &operator<< (ostream &outp, const player &object);
protected:
    int jersey;
    double age;
    double minutes;
    string report;

public:
    player();
    player(int a, double b, double c, string d);

    int getJersey();
    double getAge();
    double getMin();
    string getReport();

    void setJersey(int a);
    void setAge(double a);
    void setMin(double a);
    void setReport(string a);
    void setAll(player a);

    bool operator== (player& ob1)const;
};

///Bench Player extends Player & is a Node class for a Doubly Linked List.
class benchPlayer : public player{
private:
    char status;
    benchPlayer* prev;
    benchPlayer* next;
public:
    benchPlayer();
    benchPlayer(int a, double b, double c, string d, char e, benchPlayer* f, benchPlayer* g);
    benchPlayer(player a, char b, benchPlayer* c, benchPlayer* d);

    char getStatus();
    benchPlayer* getPrev();
    benchPlayer* getNext();

    void setStatus(char a);
    void setPrev(benchPlayer* a);
    void setNext(benchPlayer* a);
};

///Court Player extends Player & is a Node for a Circular Linked List.
class courtPlayer : public player{
private:
    char status;
    courtPlayer* next;
public:
    courtPlayer();
    courtPlayer(int a, double b, double c, string d, char e, courtPlayer* f);
    courtPlayer(player a, char b, courtPlayer* c);

    char getStatus();
    courtPlayer* getNext();

    void setStatus(char a);
    void setNext(courtPlayer* a);
    void setCourt();

    void printtest();
};

#endif