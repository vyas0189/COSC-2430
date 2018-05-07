/*
*Created by Vyas Ramankulangara
*01/18/18
*/
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "ArgumentManager.h"

using namespace std;
/*
*Function to remove whitespaces
*Precondition: Vector will contain the data.
*Postcondition: Remove whitespace and store the data into a string.
*/
void removeSpaces(vector<string>& space, string& out){
    for(int i=0; i < space.size();i++){
        string dataString = space[i];
        for(int j=0; j < dataString.length(); j++){
            if(isspace(dataString[j])){
                continue;
            }
            else{
                out +=dataString[j];
            }
        }
    }
}
/*
 *Funtion to seperate each data
 *Precondition: 
 */
void delimiter(vector<string>& del, string& out){
    string delimiter = "}";
    size_t pStart =0, pEnd, dLen = delimiter.length();
    string token;
    while((pEnd = out.find(delimiter, pStart)) != string::npos){
        token = out.substr(pStart, pEnd +1 - pStart);
        pStart = pEnd + dLen;
        del.push_back(token);
    }
}
/*
*Function to read from the text file
*Precondition:File must exist 
*/
void read(const char* filename, vector<string>& m){
    ifstream ifs(filename);
    string str, output;
    vector<string> map;
    while (getline(ifs, str, ' ')) {
        map.push_back(str);
  }
    removeSpaces(map,output);    
    delimiter(m,output);
    ifs.close();    
}

void checkForSameData(vector<string>& p){
    if(p.size() <= 1){
        return;
    }
    for(int i=0 ; i< p.size();i ++){
        
        for(int j= i+1; j <p.size();j++){
            if( p[i]== p[j]){
                p.erase(p.begin() + j);
            }
        }
    }
    if(p[p.size()-1] == p[p.size()-2]){
        p.pop_back();
    }
}

void write(const char* filename, vector<string>& o){
    ofstream ofs(filename);
    for(int i=0; i < o.size();i++){
            ofs<< setw(0) << o[i] << endl;
        }
        ofs.close();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
       cout << "Usage: removeduplicated input=input1.txt output=output1.txt" <<endl;
        return -1;
    }
    ArgumentManager am(argc, argv);
    const string input = am.get("input");
    const string output = am.get("output");
    cout << "input=" << input << " output=" << output << endl;
    vector<string> data;
    
    read(input.c_str(),data);
    checkForSameData(data);
    write(output.c_str(),data); 
     
    return 0;
}