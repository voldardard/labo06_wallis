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
#include <limits>
#include <cstdlib>
#include <cmath>
using namespace std;

#define CLEAR_BUFFER           std::cin.ignore\
                               (numeric_limits<streamsize>::max(), '\n')
                               // ou while(getchar() != '\n')
#define WAIT_ENTER             CLEAR_BUFFER


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
        CLEAR_BUFFER;
        double PRECISION = pow(10, -precision_power);

        cout << left << setw(WIDTH_COL1)      << "No"
             << setw(WIDTH_COL2 + WIDTH_COL3) << "Terme"
             << setw(WIDTH_COL4)              << "Pi/2"
             << right << setw(WIDTH_COL5)     << "Ecart"
             << endl;

        int numerator = 2, denominator = 1;
        int iterCount = 0;
        long double difference;
        long double wallisTotal = 1;

        do {


            long double tempTotal = double(numerator) / denominator;
            wallisTotal = tempTotal * wallisTotal;
            difference = wallisTotal - tempTotal;

            if ( numerator > denominator ) {
                denominator += 2;
            } else {
                numerator += 2;
            }

            //cout << "ecart:" << difference << " Total:" << wallisTotal << endl;

            cout << left
                 << setw(WIDTH_COL1)              << iterCount
                 << setw(WIDTH_COL2)              << numerator << "/"
                 << setw(WIDTH_COL3)              << denominator
                 << fixed
                 << setprecision(precision_power)
                 << setw(WIDTH_COL4)              << wallisTotal
                 << setprecision(5)
                 << setw(WIDTH_COL5)              << difference
                 << endl;

            ++iterCount;
        } while ( abs(difference) < PRECISION );

        cout << "Approx de Pi / 2 : " << wallisTotal << endl;
        cout << "Nbre de termes   : " << iterCount <<endl;


        char retry_input;
        bool input_invalid;
        do {
            input_invalid = false;
            cout << "Voulez-vous recommencer [o|n] : ";
            retry_input = getchar();
            CLEAR_BUFFER;
            if (retry_input == 'o')
                retry = true;
            else if (retry_input == 'n')
                retry = false;
            else
                input_invalid = true;
        } while ( input_invalid );

    } while(retry);


    return 0;
}
