#include<iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265359;
const double sqrt2PI = sqrt( 2. * PI );

double normalCDF( double x ) {
    if (x<0) {
        return 1-normalCDF(-x);
    }
    double k = 1/(1 + 0.2316419*x);
    double poly = k*(0.319381530 + k*(-0.356563782 + k*(1.781477937
                    + k*(-1.821255978 + 1.330274429*k))));
    double approx = 1.0 - 1.0/sqrt2PI * exp(-0.5*x*x) * poly;
    return approx;
}

double hornerFunction( double x , double a0 ) {
    return a0;
}
double hornerFunction( double x , double a0 , double a1 ) {
    return a0 + hornerFunction( x , a1 );
}
double hornerFunction( double x , double a0 , double a1 , double a2 ) {
    return a0 + hornerFunction( x , a1 , a2 );
}
double hornerFunction( double x , double a0 , double a1 , double a2 ,  double a3 ) {
    return a0 + hornerFunction( x , a1 , a2 , a3 );
}
double hornerFunction( double x , double a0 , double a1 , double a2 ,  double a3 , double a4 ) {
    return a0 + hornerFunction( x , a1 , a2 , a3 , a4 );
}
double hornerFunction( double x , double a0 , double a1 , double a2 ,  double a3 , double a4 ,  double a5 ) {
    return a0 + hornerFunction( x , a1 , a2 , a3 , a4 , a5 );
}

double normalCDF2( double x ) {
    if (x<0) {
        return 1-normalCDF2(-x);
    }
    double k = 1/(1 + 0.2316419*x);
    double poly = hornerFunction(k,
                                 0.0, 0.319381530, -0.356563782,
                                 1.781477937,-1.821255978,1.330274429);
    double approx = 1.0 - 1.0/sqrt2PI * exp(-0.5*x*x) * poly;
    return approx;
}

int main () {

    double n;
    cout << "Please select number:\n";
    cin >> n;
    cout << "The CDF of a standard Gaussian evaluated at " << n << " is " << normalCDF2(n) << ".\n";

    return 0;
}