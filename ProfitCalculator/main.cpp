#include <iostream>
#include <cmath>
using namespace std;
 
int main() {

    double revenue;
    double costs;
    double taxRate;

    cout << "What is your revenue?\n";
    cin >> revenue;
    cout << "What are your costs?\n";
    cin >> costs;
    cout << "What is the tax rate (%)?\n";
    cin >> taxRate;

    double grossProfit = revenue - costs;

    if ( grossProfit >= 0 ) {
        double netProfit = grossProfit - taxRate * grossProfit;
        cout << "Your gross profit is\n";
        cout << grossProfit;
        cout << '\n';
        cout << "Your net profit is\n";
        cout << netProfit;
        cout << '\n';
    } else {
        cout << "Your net and gross profit is\n";
        cout << grossProfit;
        cout << '\n';
    }

    int pi = 3.141;
    double r = 4;
    double area = 0.5 * pi * r * r;
    cout << area;
    cout << '\n';

    return 0;
}