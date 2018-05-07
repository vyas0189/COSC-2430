#include <iostream>
#include "player.h"
using namespace std;


////PLAYER IMPLEMENTATION
//Default Constructor
player::player(){
    jersey=0;
    age=0.0;
    minutes=0.0;
    report=" ";
}

//Explicit Constructor
player::player(int a, double b, double c, string d){
    jersey=a;
    age=b;
    minutes=c;
    report=d;
}

//Accessors
int player::getJersey() { return jersey;}
double player::getAge(){ return age;}
double player::getMin(){ return minutes;}
string player::getReport() { return report;}

//Mutators
void player::setJersey(int a){jersey=a;}
void player::setAge(double a){age=a;}
void player::setMin(double a){minutes = a;}
void player::setReport(string a) {report +=a+"{";}
void player::setAll(player a) {
    jersey=a.getJersey();
    age=a.getAge();
    minutes= a.getMin();
    report=a.getReport();
}

//Overloaded Extraction Operator
ostream &operator<< (ostream &outp, const player &object){
    outp <<"P"<< object.jersey;
    outp <<" Age: "<< object.age;
    outp <<" Min: "<< object.minutes;
    //outp <<"\tReport: "<< object.report <<endl;
    return outp;
}

bool player::operator== (player& ob1)const {
    if (jersey == ob1.getJersey()){ return true; }
    else { return false;}
}


////BENCH PLAYER IMPLEMENTATION
//Default Constructor
benchPlayer::benchPlayer():player(), status(' '), next(nullptr), prev(nullptr){}

//Explicit Constructor
benchPlayer::benchPlayer(int a, double b, double c, string d, char e, benchPlayer* f, benchPlayer* g){
    jersey=a;
    age=b;
    minutes= c;
    report=d;
    status=e;
    prev=f;
    next=g;
}

//Overloaded Constructor
benchPlayer::benchPlayer(player a, char b, benchPlayer* c, benchPlayer* d){
    jersey=a.getJersey();
    age=a.getAge();
    minutes= a.getMin();
    report=a.getReport();
    status=b;
    prev=c;
    next=d;
}

//Accessors
char benchPlayer::getStatus(){return status;}
benchPlayer* benchPlayer::getPrev(){ return prev;}
benchPlayer* benchPlayer::getNext(){return next;}

//Mutators
void benchPlayer::setStatus(char a){status=a;}
void benchPlayer::setPrev(benchPlayer* a){prev=a;}
void benchPlayer::setNext(benchPlayer* a){next=a;}


//// COURT PLAYER IMPLEMENTATION
//Default Constructor
courtPlayer::courtPlayer():player(), status(' '), next(nullptr){}

//Explicit Constructor
courtPlayer::courtPlayer(int a, double b, double c, string d, char e, courtPlayer* f){
    jersey=a;
    age=b;
    minutes= c;
    report=d;
    status=e;
    next=f;
}

//Overloaded Constructor
courtPlayer::courtPlayer(player a, char b, courtPlayer* c){
    jersey=a.getJersey();
    age=a.getAge();
    minutes= a.getMin();
    report=a.getReport();
    status=b;
    next=c;
}

//Accessors
char courtPlayer::getStatus(){return status;}
courtPlayer* courtPlayer::getNext(){return next;}

//Mutators
void courtPlayer::setStatus(char a){status=a;}
void courtPlayer::setNext(courtPlayer* a){next=a;}

void courtPlayer::printtest() {
    if (jersey<10){
        cout<<" ";
    }
    cout << "P" << getJersey();
    cout<< " Status: "<<getStatus();
    cout<< " Time Played: "<<getMin()<<endl;
}