#include <iostream>

using namespace std;


int main() {
    int numerator = 2, denominator = 1;

    long double wallis_total = 1;
    for (int iterCount = 0; iterCount < 16; ++iterCount) {

        wallis_total = double(numerator) / denominator*wallis_total;

        if (numerator > denominator) {
            denominator += 2;
        } else {
            numerator += 2;
        }

        cout << wallis_total << endl;
    }

}