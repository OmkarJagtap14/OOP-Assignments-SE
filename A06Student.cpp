/* Develop an object oriented program in C++ to create a 
 * database of student information system containing the 
 * following information: Name, Roll number, Class, division, 
 * Date of Birth, Blood group, Contact address, telephone number, 
 * driving license no. etc Construct the database with suitable 
 * member functions for initializing and destroying the data 
 * viz constructor, default constructor, Copy constructor, 
 * destructor, static member functions, friend class, this pointer, 
 * inline code and dynamic memory allocation operators-new and delete. 
 */


#include<iostream>
#include<string>
using namespace std;

class date {
    friend class Student;

private:
    int day;
    int month;
    int year;
    static const int MAX_DAY = 31;
    static const int MIN_DAY = 1;
    static const int MAX_MONTH = 12;
    static const int MIN_MONTH = 1;
    static const int MAX_YEAR = 2015;
    static const int MIN_YEAR = 1990;


public:
    date();
    void isDayValid(int);
    void isMonthValid(int);
    void  isYearValid(int); 
protected:

};

date::date() {
    day = 1;
    month = 1;
    year = 1990;
}

 void  date :: isDayValid(int day){
     if(day >= MIN_DAY && day <=MAX_DAY)
     {
         return;
     }else{
         throw(day);
     }
 }
 
 void  date :: isMonthValid(int month){
     if(month >= MIN_MONTH && month <= MAX_MONTH)
     {
         return;
     }else{
         throw(month);
     }
 }
 
 void  date :: isYearValid(int year){
     if(year >= MIN_YEAR && year <= MAX_YEAR)
     {
         return;
     }else{
         throw(year);
     }
 }


class Student {
private:
    string name;
    int rollNo;
    int cls;
    char div;
    date dateOfBirth;
    string bloodGroup;
    string address;
    long long int telephoneNo;
    string drivingLicenseNo;

public:
    Student();
    Student(const Student &);
    void acceptData(size_t);
    void printData(size_t);
  void isRollNumberValid(int);

};

Student::Student() {

}

Student::Student(const Student& orig) {

    name = orig.name;
    rollNo = orig.rollNo;
    cls = orig.cls;
    div = orig.div;
    dateOfBirth = orig.dateOfBirth;
    bloodGroup = orig.bloodGroup;
    address = orig.address;
    telephoneNo = orig.telephoneNo;
    drivingLicenseNo = orig.drivingLicenseNo;

}

void Student::acceptData(size_t studentCounter) {

    date obj;
    cout << "\t\t*****Enter the details of Student " << ++studentCounter << "*****" << endl;
    cout << endl;
    cin.ignore();
    cout << "Name: ";
    getline(std::cin, name);

    cout << "Roll number: ";
    cin>>rollNo;
     isRollNumberValid(rollNo);
    cout << "Class(1-10): ";
    cin>>cls;

    cout << "Division(A-Z): ";
    cin>>div;

    cout << "Date of birth:\n";
    cout << "Day :";
    cin >> obj.day;
    obj.isDayValid(obj.day);
    cout << "Month :";
    cin >> obj.month;
    obj.isMonthValid(obj.month);
    cout << "Year :";
    cin >> obj.year;
    obj.isYearValid(obj.year);

    cout << "Blood Group: ";
    cin>>bloodGroup;

    cout << "Address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Telephone number: ";
    cin>>telephoneNo;

    cout << "Driving License Number: ";
    cin>>drivingLicenseNo;

}

void Student::printData(size_t studentCounter) {

    date obj;

    cout << endl;
    cout << "\t\t***** Details of Student " << ++studentCounter << "*****" << endl;
    cout << endl;
    cout << "Name: " << name << endl;

    cout << "Roll number: " << rollNo << endl;
    isRollNumberValid(rollNo);

    cout << "Class(1-10): " << cls << endl;

    cout << "Division(A-Z): " << div << endl;

    cout << "Date of birth:\n" << cout << obj.day << "/" << obj.month << "/" << obj.year << endl;

    cout << "Blood Group: " << bloodGroup << endl;

    cout << "Address: " << address << endl;

    cout << "Telephone number: " << telephoneNo << endl;

    cout << "Driving License Number: " << drivingLicenseNo << endl;


}

void Student :: isRollNumberValid(int rollNo){
    if(rollNo >= 1 && rollNo <= 100 ){
        return;
    }else{
        throw(rollNo);
    }
}

int main() {
    size_t totalStudents;

    cout << "Enter the total number of Students: ";
    cin>>totalStudents;
    cout << endl;


    Student *ptrToStud = new Student[totalStudents];

    try {
        for (size_t i = 0; i < totalStudents; i++) {
            ptrToStud[i].acceptData(i);
            cout << endl;
        }

        for (size_t i = 0; i < totalStudents; i++) {
            ptrToStud[i].printData(i);
            cout << endl;
        }
    }
    catch(...){
      cout<<"Wrong Entry ! "<<endl;  
    }
    
    delete[ ]  ptrToStud;


}



