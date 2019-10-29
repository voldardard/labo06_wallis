/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_06
Fichier     :
Auteur(s)   : Mathias Brugger et David Gallay
Date        : 28.10.2019

But         : Ask the user for the precision he wants for PI / 2
              and return the approximated value of PI / 2 using
              the wallis formula
Remarque(s) : To get the boolean retry, we don't process a verification
              on read failure since we try to get a char.
Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
using namespace std;

#define CLEAR_BUFFER  std::cin.ignore\
                      (numeric_limits<streamsize>::max(), '\n')


int main() {

    // Declare constants
    int WIDTH_COL1          = 10;
    int WIDTH_COL2          = 10;
    int WIDTH_COL3          = 10;
    int WIDTH_COL4          = 10;
    int WIDTH_COL5          = 10;

    int MIN_PRECISION_POWER = 0;
    int MAX_PRECISION_POWER = 5;

    int DECIMAL_PRECISION   = 5;

    bool retry;
    bool inputInvalid;
    do {
        // Ask the user the precision he wants
        int precisionPower;
        do {
            cout << "Quelle precision "
                 << "[ 10^-"  << MIN_PRECISION_POWER
                 << ".. 10^-" << MIN_PRECISION_POWER
                 << "] : 10^-";
            cin >>  precisionPower;
            inputInvalid = cin.fail();
            if (inputInvalid)
                cin.clear();
            CLEAR_BUFFER;
        } while (
            inputInvalid                          or
            precisionPower <= MIN_PRECISION_POWER or
            precisionPower >= MAX_PRECISION_POWER
        );

        double PRECISION = pow(10, -precisionPower);


        // Compute PI / 2 and display the values on each step
        cout << left
             << setw(WIDTH_COL1)                    << "No"
             << setw(WIDTH_COL2 + WIDTH_COL3)       << "Terme"
             << setw(WIDTH_COL4)                    << "Pi/2"
             << right
             << setw(WIDTH_COL5)                    << "Ecart"
             << endl;

        int         numerator   = 2,
                    denominator = 1;
        int         iterCount   = 0;
        long double wallisTotal = 1.L;
        long double difference;

        do{

            ++iterCount;
            long double divide      =   double(numerator) / double(denominator);
            long double tempWallis  =   wallisTotal;
                        wallisTotal =   divide * wallisTotal;
                        difference  =   abs(wallisTotal - tempWallis);

            cout << left
                 << setw(WIDTH_COL1)              << iterCount
                 << setw(WIDTH_COL2)              << numerator << "/"
                 << setw(WIDTH_COL3)              << denominator
                 << fixed
                 << setprecision(DECIMAL_PRECISION)
                 << setw(WIDTH_COL4)              << wallisTotal
                 << setw(WIDTH_COL5)              << difference
                 << endl;

            if ( numerator > denominator ) {
                denominator += 2;
            } else {
                numerator   += 2;
            }

        } while (difference > PRECISION);



        cout << "Approx de Pi / 2 : " << wallisTotal << endl;
        cout << "Nbre de termes   : " << iterCount <<endl;

        // Ask the user if he wants to retry
        char retryInput;
        bool inputInvalid;
        do {
            inputInvalid = false;
            cout << "Voulez-vous recommencer [o|n] : ";
            retryInput = getchar();
            CLEAR_BUFFER;
            switch (retryInput) {

                case 'o':
                    retry = true;
                    break;
                case 'n':
                    retry = false;
                    break;
                default :
                    inputInvalid = true;

            }
        } while (inputInvalid);

    } while(retry);


    return 0;
}
