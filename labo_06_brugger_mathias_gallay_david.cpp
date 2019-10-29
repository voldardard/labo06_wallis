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
    bool input_invalid;
    do {
        // Ask the user the precision he wants
        int precision_power;
        do {
            cout << "Quelle precision "
                 << "[ 10^-"  << MIN_PRECISION_POWER
                 << ".. 10^-" << MIN_PRECISION_POWER
                 << "] : 10^-";
            cin >>  precision_power;
            input_invalid = cin.fail();
            if (input_invalid)
                cin.clear();
            CLEAR_BUFFER;
        } while (
            input_invalid                          or
            precision_power <= MIN_PRECISION_POWER or
            precision_power >= MAX_PRECISION_POWER
        );

        double PRECISION = pow(10, -precision_power);


        // Compute PI / 2 and display the values on each step
        cout << setw(WIDTH_COL1)                    << "No"
             << setw(WIDTH_COL2 + WIDTH_COL3)       << "Terme"
             << setw(WIDTH_COL4)                    << "Pi/2"
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
        char retry_input;
        bool input_invalid;
        do {
            input_invalid = false;
            cout << "Voulez-vous recommencer [o|n] : ";
            retry_input = getchar();
            CLEAR_BUFFER;
            switch (retry_input) {

                case 'o':
                    retry = true;
                    break;
                case 'n':
                    retry = false;
                    break;
                default :
                    input_invalid = true;

            }
        } while ( input_invalid );

    } while(retry);


    return 0;
}
