#include<iostream>
#include <cmath>

using namespace std;

int fibonacci( int n ) {
    if ( n == 0 || n == 1) {
        return 1;
    } else {
        return fibonacci( n - 1 ) + fibonacci( n - 2 );
    }
}

int main () {

    int n;
    cout << "Please select a positive integer:\n";
    cin >> n;
    cout << "The " << n << "th fibonacci number is " << fibonacci(n) << ".\n";

    return 0;
}