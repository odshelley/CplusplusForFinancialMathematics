#include<iostream>
#include <cmath>

using namespace std;

int recursivePrint( int a, int b ) {
    if ( b == a) {
        return a;
    } else {
        cout << b << '\n';
        return recursivePrint( a , b-1 );
    }
}

int main () {

    int number1;
    int number2;


    cout << "Please select a positive integer:\n";
    cin >> number1;
    cout << "Please select a larger positive integer:\n";
    cin >> number2;
    cout << "The numbers between " << number1 << " and " << number2 << " are:\n";
    cout << recursivePrint( number1 , number2 );
    return 0;
}