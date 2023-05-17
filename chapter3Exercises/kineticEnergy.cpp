# include  <iostream> 
# include  <cmath>

using   namespace  std;

double kineticEnergy( double mass , double velocity ){
    return .5 * mass * velocity * velocity ;
}

int   main () {
    double m;
    double v;
    
    cout << "Pick a mass:\n";
    cin >> m;
    cout << "Pick a velocity:\n";
    cin >> v;
    cout << "The associated kinetic energy is \n";
    cout << kineticEnergy( m , v ) << '\n';
     
    return 0;
}
