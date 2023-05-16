#include <iostream>
#include <cmath>

using namespace std;

int main() {

    char input;
    int output;

    cout << "Please type a single letter \n";
    cin >> input;
    output = input;
    cout << "This character corresponds to the integer \n";
    cout << output << '\n';

    if ( 97 <= output  &&  output <= 122 ) {

        cout << "You have selected a lower case letter!\n\n";

        int difference = output - 32;
        char uppercaseVersion = difference;

        cout << "Here it is as an uppercase letter:\n";
        cout << uppercaseVersion << '\n';
        cout << "Here's the uppercase letter as an integer:\n";
        cout << difference << '\n';

    }else{
        cout << "... but you didn't do as I asked!";
    }

    return 0; 
}