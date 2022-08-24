#include <iostream>
#include <chrono>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
    const int max = 15000;
    int x[max], y[max];
    int** A = new int* [max];

    /* Initialize A */
  
    for (int i = 0; i < max; ++i)
        A[i] = new int[max];

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            A[i][j] = rand() % 10000;
        }
    }
    /* Initialize x, assign y = 0 */
    for (int i = 0; i < max; i++) {
        x[i] = rand() % 10000;
        y[i] = 0;
    }

    auto started = chrono::high_resolution_clock::now();
    /* First pair of loops */
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto done = chrono::high_resolution_clock::now();
    cout << "Time of first pair of loops: " << chrono::duration_cast<chrono::milliseconds>(done - started).count() << endl;

    /* Assing y = 0 */
    for (int i = 0; i < max; i++) {
        y[i] = 0;
    }

    auto started2 = chrono::high_resolution_clock::now();
    /* Second pair of loops */
    for (int j = 0; j < max; j++) {
        for (int i = 0; i < max; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
    auto done2 = chrono::high_resolution_clock::now();
    cout << "Time of second pair of loops: " << chrono::duration_cast<chrono::milliseconds>(done2 - started2).count() << endl;

    return 0;
}