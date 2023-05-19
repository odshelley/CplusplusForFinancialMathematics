#include<iostream>
#include <cmath>

using namespace std;

int factorialWhile( int n ) {
    int m = 1;

    while ( n > 1 ) {
        m *= n;
        n--;
    }
    return m;
}

int factorialFor( int n ) {
    int m = 1;

    for( ; n > 1; n-- ) {
        m *= n;
    }
    return m;
}

int factorialDoWhile( int n ) {
    int m = 1;

    do{
        m *= n;
        n--;
    } while( n > 1 );

    return m;
}

int main () {

    cout <<  factorialWhile( 1 ) << "\n";
    cout <<  factorialWhile( 2 ) << "\n";
    cout <<  factorialWhile( 3 ) << "\n";
    cout <<  factorialWhile( 4 ) << "\n\n";

    cout <<  factorialFor( 1 ) << "\n";
    cout <<  factorialFor( 2 ) << "\n";
    cout <<  factorialFor( 3 ) << "\n";
    cout <<  factorialFor( 4 ) << "\n\n";

    cout <<  factorialDoWhile( 1 ) << "\n";
    cout <<  factorialDoWhile( 2 ) << "\n";
    cout <<  factorialDoWhile( 3 ) << "\n";
    cout <<  factorialDoWhile( 4 ) << "\n\n";

    return 0;
}