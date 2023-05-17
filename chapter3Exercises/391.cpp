#include<iostream>
#include <cmath>

using namespace std;

int recursiveSum( int n ) {
    if ( n == 1) {
        return 1;
    } else {
        return n + recursiveSum( n - 1 );
    }
}

int main () {

    int number;

    cout << "Please select a positive integer:\n";
    cin >> number;
    cout << "The sum of the first " << number << " integers is " << recursiveSum( number) << ".\n";

    return 0;
}
