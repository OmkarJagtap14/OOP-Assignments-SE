/*Write a C++ program create a calculator for an arithmetic operator (+, -, *, /).  
 *The program should take two operands from user and performs the operation on those two operands
 *depending upon the operator entered by user. Use a switch statement to select the operation. 
 *Finally, display the result.  Some sample interaction with the program might look like this: 
 *Enter first number, operator, second number: 10 / 3 
 *Answer = 3.333333 
 *Do another (y/n)? y 
 *Enter first number, operator, second number: 12 + 100 
 *Answer = 112 
 *Do another (y/n)? n*/

#include<iostream>
#include<cctype>
using namespace std;

class calculator {
private:
    double num1;
    double num2;
    double result;

public:
    calculator();
    double addition(double, double);
    double subtraction(double, double);
    double multiple(double, double);
    double division(double, double);

};

calculator::calculator() {
    num1 = 0.0;
    num2 = 0.0;
    result = 0.0;

}

double calculator::addition(double num1, double num2) {

    double result;
    return result = num1 + num2;

}

double calculator::subtraction(double num1, double num2) {

    double result;
    return result = num1 - num2;
}

double calculator::multiple(double num1, double num2) {

    double result;
    return result = num1 * num2;
}

double calculator::division(double num1, double num2) {
    double result;
    return result = num1 / num2;
}

int main() {
    double n1;
    double n2;
    char opr;
    char choice;

    calculator obj1;

    do {
        cout << "Enter the first number, operator, second number: ";
        cin >> n1 >> opr >> n2;

        switch (opr) {
            case '+': cout << "Addition\n" << n1 << " + " << n2 << " = " << obj1.addition(n1, n2) << endl;
                break;

            case '-': cout << "Subtraction\n" << n1 << " - " << n2 << " = " << obj1.subtraction(n1, n2) << endl;
                break;

            case '*': cout << "Multiple\n" << n1 << " * " << n2 << " = " << obj1.multiple(n1, n2) << endl;
                break;

            case '/': cout << "Division\n" << n1 << " / " << n2 << " = " << obj1.division(n1, n2) << endl;
                break;

            default: cerr << "\n\tWrong operator was entered ! \n" << endl;
        }

        cout << "Do you want to continue ? (y/n) : ";
        cin>>choice;

    } while (tolower(choice) == 'y');
    cout << endl;
}

