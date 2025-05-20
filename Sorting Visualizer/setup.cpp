#include "setup.h"
#include "Algorithms.h"
using namespace std;

void fillWithRandomLengths(vector<int>& barLengths, int modulus)
{
    for (int& length : barLengths)
    {
        int randomLength;
        do {
            randomLength = rand() % modulus; // a random number that is divisible by 20. 
        } while (randomLength == 0);
        length = randomLength;
    }
}

void drawBars(const vector<int>& barLengths)
{
    // Draw each bar on its own line
    for (int length : barLengths)
    {
        for (int count = 0; count < length; ++count)
            cout << "[]";
        cout << "\n";
    }
}

void setup(vector<int>& barLengths, int modulus)
{
    // 1) Populate and display unsorted bars
    fillWithRandomLengths(barLengths, modulus);
    system("color 4");
    cout << "Before Sort:\n";
    drawBars(barLengths);
    // Pause to view initial state
    this_thread::sleep_for(chrono::milliseconds(1000));
}