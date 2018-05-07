#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template<class T>
class Database{
    private:
        string fileName;
    public:
        Database(string file){
            ofstream ofs(file.c_str(),ios::app);
            fileName = file;
            ofs.close();
        }
        bool find(fstream& files, T& records){
            T temp;
            files.open(fileName, ios::in | ios::binary);
            while(!files.eof()){
                temp.readFromFile(files);
                if(temp == records){
                    files.close();
                    return true;
                }
            }
            files.close();
            return false;
        }

        void modify(){
            fstream ofs(fileName.c_str());
            T record, temp;
            string checkSSN;
            cout << "Enter your SSN: ";
            getline(cin,checkSSN);
            record.setSSN(checkSSN);

            if(find(ofs,record)){
                temp.readFromFile(ofs);
                temp.modify();
                ofs.seekp(-record.size(), ios::cur);
                temp.writeToFile(ofs);
            }else{
                cout << "SSN is invalid." << endl;
            }
            ofs.close();
        }
        
        void add(){
            fstream ofs(fileName.c_str());
            T record;
            string checkSSN;
            cout << "Enter your SSN: ";
            cin >> checkSSN;
            record.setSSN(checkSSN.c_str());
            if(find(ofs, record)){
                cout << "Record already exists." << endl;
            }else{
                record.modify();
                record.writeToFile(ofs);
            }
        }

        void print(int numOfRecords){
            T record;
            fstream printRecord(fileName.c_str());

            for(int i=0; i < numOfRecords; i++){
                record.readFromFile(printRecord);
                record.print();
            }
        }
};