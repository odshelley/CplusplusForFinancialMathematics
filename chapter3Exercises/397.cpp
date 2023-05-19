#include<iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265359;
const double sqrt2PI = sqrt( 2. * PI );

double hornerFunction( double x, double a0, double a1) {
    return a0 + x*a1;
}
 
double hornerFunction( double x, double a0, double a1, double a2) {
