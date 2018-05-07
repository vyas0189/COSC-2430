#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student:public Personnel{

    private:
        char *major;
        const int majorLen = 10;
    public:
        Student():Personnel(){
            major = new char[majorLen];
        }
        	void setMajor(string sMajor)
	{
		for (int i = 0; i < majorLen; i++)
		{
			major[i] = sMajor[i];
		}
	}
        int size(){
            return Personnel::size() + majorLen;
        }
        void modify(){
            int userChoice;
            bool counter = true;

            cout << "What do you want to modify? "<< endl;
            cout << "1. Name\n2. City\n3. Year of Birth\n4. Salary\n5.Major\n6.Exit" << endl;
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
                            while(index < (yObLen - yr.length())){
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
                        str maj;
                        cout << "Enter your major: ";
                        cin.ignore();
                        getline(cin,maj);
                        if(maj.length() <= majorLen){
                            int index=0
                            while(index < (majorLen - maj.length())){
                                maj += ' ';
                                index++
                            }
                            setMajor(maj);
                        }else{
                            cout << "The major name is too long."<< endl;
                        }
                        break;
                    case 6:
                        counter = false;
                        break;
                    default:
                        cout << "Enter a correct choice." << endl;
                }
            }

        }
        void readFromFile(fstream& ifs){

            if(ifs.is_open()){
                ifs.read(SSN,10);
                ifs.read(name,nameLen);
                ifs.read(city,cityLen);
                ifs.read(yOb,yObLen);
                ifs.read(reinterpret_cast<const char*>(&salary), sizeof(int));
                ifs.read(major,majorLen);
            }else{
                cout << "File not found." << endl;
            }
            ifs.close();
        }
        void writeToFile(fstream& ofs){
            if(ofs.is_open()){
                ofs.write(SSN,10);
                ofs.write(name,nameLen);
                ofs.write(city,cityLen);
                ofs.write(yOb,yObLen);
                ofs.write(reinterpret_cast<const char*>(&salary), sizeof(int));
                ofs.write(major,majorLen);
            }else{
                cout << "File not found." << endl;
            }
            ofs.close();
        }
        void print(){
            cout << SSN << " " << name << " " << city << " " << yOb << " " << salary << " " << major << endl;
        }
        ~Student(){
            delete major;
        }
};