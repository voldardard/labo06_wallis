/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_06
Fichier     : labo_06_brugger_mathias_gallay_david.cpp
Auteur(s)   : Mathias Brugger et David Gallay
Date        : 28.10.2019

But         : Ask the user for the precision he wants for PI / 2
              and return the approximated value of PI / 2 using
              the wallis formula
Remarque(s) : To get the boolean retry, we don't process a verification
              on read failure since we try to get a char.

              We made the code to correspond the result shown in the pdf
              Otherwise, we would have declare oldWallisTotal in the loop.
              Also, We display oldWallisTotal at the end. 
	      That is the value shown in the pdf, even if displaying 
	      WallisTotal would be, for us, more logic.
Compilateur : MinGW-g++ 6.3.0 or gcc version 9.2.1
-----------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cmath>
using namespace std;

#define CLEAR_BUFFER std::cin.ignore\
                     (numeric_limits<streamsize>::max(), '\n')
#define PAUSE CLEAR_BUFFER

int main() {

    // Declare constants
    const int WIDTH_COL1          = 10;
    const int WIDTH_COL2          = 10;
    const int WIDTH_COL3          = 10;
    const int WIDTH_COL4          = 10;
    const int WIDTH_COL5          = 10;

    const int MIN_PRECISION_POWER = 0;
    const int MAX_PRECISION_POWER = 5;

    const int DECIMAL_PRECISION   = 5;

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
            inputInvalid                         or
            precisionPower < MIN_PRECISION_POWER or
            precisionPower > MAX_PRECISION_POWER
        );

        const int PRECISION_POWER = precisionPower;
        const double PRECISION    = pow(10, -PRECISION_POWER);

        // Compute PI / 2 and display the values on each step
        cout << left
             << setw(WIDTH_COL1)		<< "No"
             << setw(WIDTH_COL2 + WIDTH_COL3)	<< "Terme"
             << setw(WIDTH_COL4)		<< "Pi/2"
             << right
             << setw(WIDTH_COL5)		<< "Ecart"
             << endl;

        int         numerator       = 2,
                    denominator     = 1;
        int         iterCount       = 1;
        long double wallisTotal     = double(numerator) / double(denominator);
        long double oldWallisTotal  = wallisTotal;
        long double difference      = abs(wallisTotal - oldWallisTotal);

        do{
            // Display current step's values
            cout << left
                 << setw(WIDTH_COL1)              << iterCount
                 << setw(WIDTH_COL2)              << numerator << "/"
                 << setw(WIDTH_COL3)              << denominator
                 << fixed
                 << setprecision(PRECISION_POWER)
                 << setw(WIDTH_COL4)              << wallisTotal
                 << setprecision(DECIMAL_PRECISION)
                 << setw(WIDTH_COL5)              << difference
                 << endl;

            // Update Values
            ++iterCount;
            if ( numerator > denominator ) {
                denominator += 2;
            } else {
                numerator   += 2;
            }

            oldWallisTotal  =   wallisTotal;
            wallisTotal     =   wallisTotal * numerator / denominator;
            difference      =   abs(wallisTotal - oldWallisTotal);

        } while (difference >= PRECISION);

        // Display the result
        cout << "Approx de Pi / 2 : "
             << setprecision(PRECISION_POWER) << oldWallisTotal << endl;
        cout << "Nbre de termes   : "         << iterCount   	<<endl;

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

    PAUSE;
    return EXIT_SUCCESS;
}
