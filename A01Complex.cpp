  /* Implement a class Complex which represents the Complex Number data type. Implement the following operations:
   * 1. Constructor (including a default constructor which creates the complex number 0+0i). 
   * 2. Overloaded operator+ to add two complex numbers. 
   * 3. Overloaded operator* to multiply two complex numbers. 
   * 4. Overloaded << and >> to print and read Complex Numbers. */

#include<iostream>
#include<cctype>
using namespace std;

class complex {
    
    friend istream & operator>>(istream & refToCin, complex & c1);
    friend ostream & operator<<(ostream & refToCout, complex & ref);

private:
    int real;
    int imaginary;

public:
    complex();
    complex operator+(complex &);
    complex operator*(complex &);

};

complex::complex() {
    real = 0;
    imaginary = 0;
}

// Overloaded Operator+() function for adding two complex objects
complex complex::operator+(complex & ref) {
    complex localObj;

    localObj.real = this->real + ref.real;
    localObj.imaginary = this->imaginary + ref.imaginary;
    return localObj;

}

// Overloaded Operator* function for multiplying two complex objects
complex complex::operator*(complex &ref) {
    complex localObj;

    localObj.real = (this ->real * ref.real) - (this ->imaginary * ref.imaginary);
    localObj.imaginary = (this ->real * ref.imaginary) - (this ->imaginary * ref.real);
    return localObj;
}

// Overloaded operator function for extracting Complex Object
istream & operator>>(istream & refToCin, complex & ref) {

    cout << "Real Number : ";
    refToCin >> ref.real;
    cout << "Imaginary Number : ";
    refToCin >> ref.imaginary;
    return refToCin;

}

// Overloaded operator function for inserting Complex Object
ostream & operator<<(ostream & refToCout, complex & ref) {
    refToCout << "(" << ref.real << " + " << ref.imaginary << "i" << ")";
    return refToCout;
}

int main() {
    complex c1;
    complex c2;
    char
    choice;
    do {

        cout << "Enter the First Complex Number \n";
        cin>>c1;

        cout << "Enter the Second Complex Number \n";
        cin>>c2;
        cout << endl;

        cout << "The Complex Number are :\n";
        cout << "\t" << c1 << endl;
        cout << "\t" << c2 << endl;
        cout << endl;
        
        complex c3 = c1 + c2;
        cout << "Additon\n";
        cout << "\t" << c1 << " + " << c2 << " = " << c3 << endl;
        cout << endl;
        
        complex c4 = c1*c2;
        cout << "Multiplication\n";
        cout << "\t" << c1 << " * " << c2 << " = " << c4 << endl;
        cout << endl;
        
        cout << "Do you want to continue ? (y/n) : ";
        cin>>choice;


    } while (toupper(choice) == 'Y');
}


