/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_06
Fichier     :
Auteur(s)   : Mathias Brugger et David Gallay
Date        : 28.10.2019

But         :
Remarque(s) : Conventions d'écriture
Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#using namespace std;

int main() {

    int WIDTH_COL1 = 10;
    int WIDTH_COL2 = 10;
    int WIDTH_COL3 = 10;
    int WIDTH_COL4 = 10;
    int WIDTH_COL5 = 10;

    bool retry;
    do {
        cout << "Quelle precision [ 10^-0.. 10^-5] : 10^-";
        int precision_power;
        cin >>  precision_power;
        double PRECISION = power(10, precision_power);

        cout << setw(WIDTH_COL1)              << "No"
             << setw(WIDTH_COL2 + WIDTH_COL3) << "Terme"
             << setw(WIDTH_COL4)              << "Pi/2"
             << right << setw(WIDTH_COL5)     << "Ecart"
             << endl;

        cout << left
             << setw(WIDTH_COL1)              << iterCount
             << setw(WIDTH_COL2)              << numerator << "/"
             << setw(WIDTH_COL3)              << denominator
             << setw(WIDTH_COL4)              << wallisTotal
             << setprecision(precision_power)
             << setw(WIDTH_COL5)              << difference
             << endl;


        cout << "Approx de Pi / 2 : " <<  << endl;
        cout << "Nbre de termes   : " <<  <<endl;

        cout << "Voulez-vous recommencer [o|n] : ";
        cin  >> retry
    } while(retry)


    return 0;
}
