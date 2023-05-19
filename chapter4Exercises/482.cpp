#include <iostream>
#include <cmath>
#include <stdexcept>


using namespace std;

const double PI = 3.14159265359;

double intSin( double a , double b , int n ) {
    double approx = 0.;
    double h = ( b - a ) / n;
    for ( int i = 0; i < n; i++ ) {
        approx += sin( a + (i + .5)*h );
    }
    return approx/n;
}

double intExp( double x , int n ) {
    double approx = 0.;
    double h =  1.  / n;
    for ( int i = 0; i < n; i++ ) {
        double f = ( 1. / pow( (i + .5)*h , 2 ) );
        f *=  exp( - pow( x + 1 -  1 / ( (i + .5)*h ) , 2  ) / 2. );
        approx += f;
    }
    return approx/n;
}

double Fibonacci( int n ) {
    if ( n == 0 || n == 1 ) {
        return 1;
    } else {
        int i = 1; 
        int j = 1;
        int fib = i + j;
        for( int count = 2; count < n; count++ ) {
            i = j;
            j = fib;
            fib = i + j;
        }
        return fib;
    }
}

double hornerFunction( double x, double a0, double a1) {
    return a0 + x*a1;
}
 
double hornerFunction( double x, double a0, double a1, double a2) {
    return a0 + x*hornerFunction( x, a1, a2);
}
 
double hornerFunction( double x, double a0, double a1, double a2, double a3) {
    return a0 + x*hornerFunction( x, a1, a2, a3);
}
 
double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4);
}
 
double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                       double a5) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5);
}
 
double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                       double a5, double a6) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6);
}
 
double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                       double a5, double a6, double a7) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7);
}
 
double hornerFunction( double x, double a0, double a1, double a2, double a3, double a4,
                       double a5, double a6, double a7, double a8) {
    return a0 + x*hornerFunction( x, a1, a2, a3, a4, a5, a6, a7, a8);
}

double a0 = 2.50662823884; 
double a1 = -18.61500062529; 
double a2 = 41.39119773534; 
double a3 = -25.44106049637; 
double b1 = -8.47351093090; 
double b2 = 23.08336743743; 
double b3 = -21.06224101826; 
double b4 = 3.13082909833; 
double c0 = 0.3374754822726147; 
double c1 = 0.9761690190917186; 
double c2 = 0.1607979714918209; 
double c3 = 0.0276438810333863; 
double c4 = 0.0038405729373609; 
double c5 = 0.0003951896511919; 
double c6 = 0.0000321767881768; 
double c7 = 0.0000002888167364; 
double c8 = 0.0000003960315187;

double normInv( double x , bool exception = true ) {
    if (  ( x < 0 || x > 1 ) && exception == true ) {
        throw logic_error( "x is outside of the domain [0,1]!" );
    }
    double y = x -.5;
    if ( -42 < y && y < 42 ) {
        double r = y * y;
        double h1 = hornerFunction(r , a0 , a1 , a2 , a3 );
        double h2 = hornerFunction(r , 1.0 , b1, b2 , b3 , b4 );
        return y * ( h1 / h2  );
    } else {
            double r = (y < 0) * x + ( 1 - (y < 0) ) * ( 1 - x);
            double s = log(-log(r));
            double t = hornerFunction(s,c0,c1,c2,c3,c4,c5,c6,c7,c8);
        if ( x > 0 ) {
            return t;
        }
        else {
            return -t;
        }
    }
}


int main () {

    cout <<  intSin( 0 , 1 , 10 ) << "\n";
    cout <<  intSin( 0 , 1 , 20 ) << "\n";
    cout <<  intSin( 0 , 1 , 100 ) << "\n\n";

    cout <<  intExp( 1 , 10 ) << "\n";
    cout <<  intExp( 1 , 20 ) << "\n";
    cout <<  intExp( 1 , 1000) << "\n\n";

    cout <<  Fibonacci( 1 ) << "\n";
    cout <<  Fibonacci( 2 ) << "\n";
    cout <<  Fibonacci( 3 ) << "\n";
    cout <<  Fibonacci( 4 ) << "\n";
    cout <<  Fibonacci( 5 ) << "\n\n";

    cout <<  normInv( .9 ) << "\n";
    cout <<  normInv( 2. , false ) << "\n";
    cout <<  normInv( 2. ) << "\n\n";

    return 0;
}