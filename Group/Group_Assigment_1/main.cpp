
//Help was accepted from Sarah Syed 

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int ssnLen = 9, nameLen = 10, cityLen = 10, yObLen = 4, salLen = 6;
class Personnel{

    protected:
        
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
            char cSal[4];
            int *salPtr;
            if(ifs.is_open()){
                ifs.read(SSN,10);
                ifs.read(name,nameLen);
                ifs.read(city, cityLen);
                ifs.read(yOb, yObLen);
                salPtr = (reinterpret_cast<int*>(cSal));
                salary = *salPtr;

            }else{
                cout << "File not found." <<endl;
            }
           
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
			    yOb[i] = sYoB[i];
		    }
	    }
	    void setSalary(int sSal){
		    salary = sSal;
	    }

        virtual void modify(){
            int userChoice;
            bool counter = true;

            cout << "What do you want to modify? "<< endl;
            cout << "1. Name\n2. City\n3. Year of Birth\n4. Salary\n5.Exit" << endl;
            while(counter){
                cout << "Enter your choice: ";
                cin >> userChoice;
                if(userChoice ==1){
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
                    
            }else if(userChoice =2){
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
                   
            }else if(userChoice == 3){
                        string yr;
                        cout << "Enter the your year of birth: " << endl;
                        cin.ignore();
                        getline(cin,yr);
                        if(yr.length() <= yObLen){
                            int index =0;
                            while(index < (yObLen - yr.length())){
                                yr += ' ';
                                index++;
                            }
                            setYOB(yr);
                        }else{
                            cout << "Your year of birth is more than 4 digits." << endl;
                        }
                     
            }else if(userChoice == 4){
                        int sl;
                        cout << "Enter your salary: " << endl;
                        cin >> sl;
                        setSalary(sl);
                       
            }else if(userChoice == 5){
                        counter = false;
            
            }else{
                        cout << "Enter a correct choice." << endl;
                      
                }
            }
        }

        virtual void print(){
            cout << SSN << " " << name << " " << city << " " << yOb << " " << salary << " " << endl;
        }

        bool operator==(const Personnel& per){
            return (string(SSN) == string(per.SSN));
        }
        ~Personnel(){
            delete SSN;
            delete name;
            delete city;
            delete yOb;
        }
};

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
                if(userChoice == 1){
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
                     
                }else if(userChoice ==2){
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
                       
                }else if(userChoice ==3){
                        string yr;
                        cout << "Enter the your year of birth: " << endl;
                        cin.ignore();
                        getline(cin,yr);
                        if(yr.length() <= yObLen){
                            int index =0;
                            while(index < (yObLen - yr.length())){
                                yr += ' ';
                                index++;
                            }
                            setYOB(yr);
                        }else{
                            cout << "Your year of birth is more than 4 digits." << endl;
                        }
                    
                }else if(userChoice == 4){
                        int sl;
                        cout << "Enter your salary: " << endl;
                        cin >> sl;
                        setSalary(sl);
                  
                }else if(userChoice ==5){
                        string maj;
                        cout << "Enter your major: ";
                        cin.ignore();
                        getline(cin,maj);
                        if(maj.length() <= majorLen){
                            int index=0;
                            while(index < (majorLen - maj.length())){
                                maj += ' ';
                                index++;
                            }
                            setMajor(maj);
                        }else{
                            cout << "The major name is too long."<< endl;
                        }
              
                }else if(userChoice == 6){
                        counter = false;
                 
                }else{
                        cout << "Enter a correct choice." << endl;
                }//
            }

        }
        void readFromFile(fstream& ifs){
            char cSal[4];
            int *salPtr;
            if(ifs.is_open()){
                ifs.read(SSN,10);
                ifs.read(name,nameLen);
                ifs.read(city,cityLen);
                ifs.read(yOb,yObLen);
                salPtr = (reinterpret_cast<int*>(cSal));
                salary = *salPtr;
                ifs.read(major,majorLen);
            }else{
                cout << "File not found." << endl;
            }
            
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
           
        }
        void print(){
            cout << SSN << " " << name << " " << city << " " << yOb << " " << salary << " " << major << endl;
        }
        ~Student(){
            delete major;
        }
};

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
                
                    return true;
                }
            }
            return false;
        }

        void modify(){
            fstream ofs(fileName.c_str());
            T record, temp;
            string checkSSN;
            cout << "Enter your SSN: ";
            getline(cin,checkSSN);
            record.setSSN(checkSSN.c_str());

            if(find(ofs,record)){
                temp.readFromFile(ofs);
                temp.modify();
                ofs.seekp(-record.size(), ios::cur);
                temp.writeToFile(ofs);
            }else{
                cout << "SSN is invalid." << endl;
            }
        
        }
        
        void add(){
    
            T record;
            string checkSSN;
            cout << "Enter your SSN: ";
            cin >> checkSSN;
            record.setSSN(checkSSN.c_str());
            fstream ofs(fileName.c_str());
            if(find(ofs, record)){
                cout << "Record already exists." << endl;
            }else{
                record.modify();
                record.writeToFile(ofs);
            }
        }

        void print(){
            T record;
            fstream printRecord(fileName.c_str());

                record.readFromFile(printRecord);
                record.print();
        
        }
};

int main(){
    bool counter= true;
    int classType;
    string fileName;
    string checkSSN;

    cout << "1.Personnel\n2.Student" << endl;
    cin >> classType;
    cout << "Enter the file name followed by .txt: ";
    cin >> fileName;
    
    while(counter){
        int userChoice;
        cout << "1.Find a record.\n2.Modify a record.\n3.Add a record\n4.Print the records.\n5.Exit.\n";
        cin >> userChoice;

        fstream ofs(fileName.c_str());

        if(classType == 1){
                Database<Personnel> rec(fileName.c_str());
                Personnel obj;
                if(userChoice == 1){
                        cout << "Enter SSN: " << endl;
                        getline(cin,checkSSN);
                        obj.setSSN(checkSSN.c_str());
                        if(rec.find(ofs,obj)){
                            cout << "Record Found." << endl;
                        }else{
                            cout << "No record." << endl;
                        }
                      
                }else if(userChoice == 2){
                        rec.modify();
                     
                }else if(userChoice == 3){
                        rec.add();
                       
                        
                }else if(userChoice ==4){
                        rec.print();
                     
                }else if(userChoice == 5){
                        break;
                }else{ 
                    cout << "Invalid choice "<< endl;
                }
        }else if(classType == 2){
                Database<Student> stRec(fileName.c_str());
                Student sObj;
                if(userChoice == 1){
                        cout << "Enter SSN: " << endl;
                        getline(cin,checkSSN);
                        sObj.setSSN(checkSSN.c_str());
                        if(stRec.find(ofs,sObj)){
                            cout << "Record Found." << endl;
                        }else{
                            cout << "No record." << endl;
                        }
                       
                }else if(userChoice ==2){
                        stRec.modify();
                 
                }else if(userChoice == 3){ 
                        stRec.add();
                        
                        
                }else if(userChoice == 4){
                        stRec.print();
                       
                }else if(userChoice == 5){
                       
                }else{ 
                    cout << "Invalid choice "<< endl;
                
                }//
            }else{
                cout << "Invalid choice "<< endl;
                break;

        }//
    }

    return 0;
}

/*
*Vyas Ramankulangara -- 91%
*Sam Parker --  7%
* Louis Dang -- 2%
*/