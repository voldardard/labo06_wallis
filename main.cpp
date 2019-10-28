#include <iostream>

using namespace std;


int main() {
    int numerator = 2, denominator = 1;

    long double wallisTotal = 1;
    for (int iterCount = 0; iterCount < 16; ++iterCount) {


        long double tempTotal=double(numerator) / denominator;
        wallisTotal = tempTotal*wallisTotal;
        long double difference = wallisTotal-tempTotal;

        if (numerator > denominator) {
            denominator += 2;
        } else {
            numerator += 2;
        }

        cout << "ecart:" << difference << " Total:" << wallisTotal << endl;
    }

}