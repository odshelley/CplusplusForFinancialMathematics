#include<iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265359;
const double sqrt2PI = sqrt( 2. * PI );

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

double normalCDF( double x ) {
    if (x<0) {
        return 1-normalCDF(-x);
    }
    double k = 1/(1 + 0.2316419*x);
    double poly = hornerFunction(k,
                                 0.0, 0.319381530, -0.356563782,
                                 1.781477937,-1.821255978,1.330274429);
    double approx = 1.0 - 1.0/sqrt2PI * exp(-0.5*x*x) * poly;
    return approx;
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

double norminv( double x ) {
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

double blackScholesCallPrice( double s, double r, double sigma, double K, double T ){

    double d1 = ( 1 / ( sigma * sqrt(T) ) ) * ( log(s/K) + (r + sigma * sigma / 2) * sqrt(T) );
    double d2= ( 1 / ( sigma * sqrt(T) ) ) * ( log(s/K) + (r - sigma * sigma / 2) * sqrt(T) );
    double C = normalCDF(d1) * s - normalCDF(d2) * K * exp(-r * T);

    return C;
}

int main () {

    double a;
    double b;
    double c;
    double d;
    double e;

    cout << "Give me a spot, interest rate, volatility, strike and time maturity\n";
    cin >> a >> b >> c >> d >> e;
    cout << "The price of a vanilla call option with these paramaters is "<< blackScholesCallPrice(a,b,c,d,e) << "\n";
    // cout << recursivePrint( number1 , number2 );
    return 0;
}