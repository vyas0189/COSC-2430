#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Personnel{

    protected:`
        const int ssnLen = 9, nameLen = 10, cityLen = 10, yObLen = 4, salLen = 6;
        char* SSN, *name, *city, *yOb;
        int salary;
    public:
        Personnel(){
            SSN = new char[ssnLen];
            name = new char[nameLen];
            city = new char[cityLen];
            yOb = new char[yObLen];
        }
        virtual int size(){
            return ssnLen + nameLen + cityLen + yObLen + salLen;
        }
        virtual void readFromFile(fstream& ifs){

            if(ifs.is_open()){
                ifs.read(SSN,10);
                ifs.read(name,nameLen);
                ifs.read(city, cityLen);
                ifs.read(yOb, yObLen);
                ifs.read(reinterpret_cast<const char*>(&salary), sizeof(int));
            }else{
                cout << "File not found." <<endl;
            }
            ifs.close();
        }
        virtual void writeToFile(fstream& ofs){
            if(ofs.is_open()){
                ofs.write(SSN,10);
                ofs.write(name,nameLen);
                ofs.write(city,cityLen);
                ofs.write(yOb,yObLen);
                ofs.write(reinterpret_cast<const char*>(&salary), sizeof(int));
            }else{
                cout << "File not found." << endl;
            }
            ofs.close();
        }

        void setSSN(string sSSN){
		    for (int i = 0; i < 10; i++){
			    SSN[i] = sSSN[i];
		    }

	    }
	    void setName(string sName){
		    for (int i = 0; i < nameLen; i++){
			    name[i] = sName[i];
		    }
	    }

	    void setCity(string sCity){
		    for (int i = 0; i < cityLen; i++){
			    city[i] = sCity[i];
		    }
	    }
	    void setYOB(string sYoB){
		    for (int i = 0; i < yObLen; i++){
			    dateOfBirth[i] = sYoB[i];
		    }
	    }
	    void setSalary(int sSal){
		    salary = theSalary;
	    }

        virtual void modify(){
            int userChoice;
            bool counter = true;

            cout << "What do you want to modify? "<< endl;
            cout << "1. Name\n2. City\n3. Year of Birth\n4. Salary\n5.Exit" << endl;
            while(counter){
                cout << "Enter your choice: ";
                cin >> userChoice;
                switch(userChoice){
                    case 1: 
                        string n;
                        cout << "Enter your name: ";
                        cin.ignore();
                        getline(cin,n);
                        if(n.length() <= nameLen){
                            int index =0;
                            while(index < (nameLen - n.length())){
                                n += ' ';
                                index++;
                            }
                            setName(n);
                        }else{
                            cout << "Name is too long." << endl;
                        }
                        break;
                    case 2:
                        string c;
                        cout << "Enter your city: ";
                        cin.ignore();
                        getline(cin,c);
                        if(c.length() <= cityLen){
                            int index =0;
                            while(index < (cityLen-c.length())){
                                c += ' ';
                                index++;
                            }
                            setCity(c);
                        }else{
                            cout << "City is too long." << endl;
                        }
                        break;
                    case 3:
                        string yr;
                        cout << "Enter the your year of birth: " << endl;
                        cin.ignore();
                        getline(cin,yr);
                        if(yr.length() <= yObLen){
                            int index =0;
                            while(inde < (yObLen - yr.length())){
                                yr += ' ';
                                index++
                            }
                            setYOB(yr);
                        }else{
                            cout << "Your year of birth is more than 4 digits." << endl;
                        }
                        break;
                    case 4:
                        int sl;
                        cout << "Enter your salary: " << endl;
                        cin >> sl;
                        setSalary(sl);
                        break;
                    case 5:
                        counter = false;
                        break;
                    default:
                        cout << "Enter a correct choice." << endl;
                        break;
                }
            }
        }

        virtual void print(){
            cout << SSN << " " << name << " " << city << " " << yOb << " " << salary << " " << endl;
        }

        bool operator==(const Personnel& per){
            return (strncmp(SSN,per.SSN,9) == 0);
        }
        ~Personnel(){
            delete SSN;
            delete name;
            delete city;
            delete yOb;
        }
};