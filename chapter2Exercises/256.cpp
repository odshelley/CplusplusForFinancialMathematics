#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () {

    double decimal;
    int nearestInt;

    cout << "Please input a decimal number:\n";
    cin >> decimal;
    cout << '\n';

    double check = ( int ( decimal + .5 ) )  -  int ( decimal );

    if ( check == 1 ) {
        int nearestInt = ( decimal + 1 ) / 1;
        cout << "The nearest integer is " << nearestInt << ".\n";
    } else {
        int nearestInt = ( decimal ) / 1;
        cout << "The nearest integer is " << nearestInt << ".\n";
    }

    return 0;
}