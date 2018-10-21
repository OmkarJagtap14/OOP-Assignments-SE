/*
 * Crete User defined exception to check 
 * the following conditions and throw the 
 * exception if the criterion does not meet.
 * a. User has age between 18 and 55
 * b. User has income between Rs. 50,000 â€“ Rs. 1,00,000 per month
 * c. User stays in Pune/ Mumbai/ Bangalore / Chennai
 * d. User has 4-wheeler
 * Accept age, Income, City, Vehicle from the 
 * user and check for the conditions mentioned
 * above. 
 * If any of the condition not met then throw 
 * the exception.
 */

#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

class CheckuserDetails {
private:
    const static int MIN_AGE = 18;
    const static int MAX_AGE = 55;
    const static float MIN_INCOME = 50000;
    const static float MAX_INCOME = 100000;
    const static int NO_OF_WHEELS = 4;

public:
    void checkAge(int);
    void checkIncome(float);
    void checkCityName(string);
    void checkIfHas4Wheeler(int);

};

void CheckuserDetails::checkAge(int age) {
    try {
        if (age >= MIN_AGE && age <= MAX_AGE) {
            return;
        } else {
            throw (age);
        }
    } catch (int a) {
        cout << "Exception caught : Age should be between 18-55 " << endl;
        cout << "Entered age is " << a << endl;
    }
}

void CheckuserDetails::checkIncome(float income) {
    try {
        if (income >= MIN_INCOME && income <= MAX_INCOME) {
            return;
        } else {
            throw (income);
        }
    } catch (float a) {
        cout << "Exception caught : Income should be between Rs 50000 - Rs 100000 " << endl;
        cout << "Entered Income is " << a << endl;
    }
}

void CheckuserDetails::checkCityName(string cityName) {
    try {
        const char * city = cityName.c_str();

        if (strcasecmp(city,"pune") == 0 || strcasecmp(city,"Bangalore") == 0 ||
                strcasecmp(city,"Mumbai") == 0 || strcasecmp(city,"Chennai ") == 0 ) {
            return;
        } else {
            throw (cityName);
        }
    } catch (string a) {
        cout << "Exception caught : City Should have been Pune/Mumbai/Bangalore/Chennai " << endl;
        cout << "Entered city is " << a << endl;
    }
}

void CheckuserDetails::checkIfHas4Wheeler(int noOfWheels) {
    try {


        if (noOfWheels == NO_OF_WHEELS) {
            return;
        } else {
            throw (noOfWheels);
        }
    } catch (int a) {
        cout << "Exception caught : User should have Four Wheeler " << endl;
        cout << "User has " << a << " Wheeler  " << endl;
    }
}

int main() {
    CheckuserDetails obj;

    char choice;
    int age;
    float income;
    string cityName;
    int noOfWheels;
    

    do {
        cout << "\t\t*****Details of User*****" << endl;
        cout << "\tEnter the Age of User : ";
        cin>>age;
        obj.checkAge(age);

        cout << "\tEnter the Income of User : ";
        cin>>income;
        obj.checkIncome(income);

        cout << "\tEnter the City where the User live : ";
        cin>>cityName;
        obj.checkCityName(cityName);

        cout << "\tHow Many wheels do your vehicle has? : ";
        cin>>noOfWheels;
        obj.checkIfHas4Wheeler(noOfWheels);

        cout << "\tDo you want to continue?(y/n) : ";
        cin>>choice;

    } while (toupper(choice) == 'Y');

}