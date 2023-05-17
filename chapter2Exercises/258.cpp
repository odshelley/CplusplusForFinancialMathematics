# include  <iostream> 
# include  <cmath>
# include  <stdio.h> 

using   namespace  std;

int   main () {
    int  a =  -1; 
    unsigned  int b = 0; 
    if (a<b) {
        cout   << "a is  smaller \n";
    } 
    else  {
        cout   << "a is  bigger \n";
    } 
    cout   << " Because  we 're  interpreting  a to  equal  "; 
    unsigned  int  castValue  = ( unsigned  int)a; 
    cout   <<  castValue ; 
    cout   << "\n";
    cout << "\a\n";
    return 0;
}
