#include "setup.h"
#include "Algorithms.h"

void fillWithRandomLengths(vector<int>& barLengths, int modulus)
{
    for (int& length : barLengths)
    {
        int randomLength;
        do {
            randomLength = rand() % modulus; // a random number that is divisible by 20 (or user #). 
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

void algorithmChoice(vector<int>& barLengths, char choice, bool animate)
{
    // ALGORITHM CHOICE
    switch (choice)
    {
    case 'B':
    case 'b':
        bubbleSortAndVisualize(barLengths, animate);
        break;
    case 'I':
    case 'i':
        insertionSortAndVisualize(barLengths, animate);
        break;
    case 'M':
    case 'm':
        mergeSortAndVisualize(barLengths, animate);
        break;
    default:
        cout << "Invalid algorithm choice!" << endl;
        break;
    }
}

//void algorithmChoice(vector<int>& barLengths, char choice, bool animate)
//{
//    // ALGORITHM CHOICE
//    if (choice == 'B' || choice == 'b')
//    {
//        // RUN ALGO OF CHOICE
//        bubbleSortAndVisualize(barLengths, animate);
//    }
//    else if (choice == 'I' || choice == 'i')
//    {
//        // RUN ALGO OF CHOICE
//        insertionSortAndVisualize(barLengths, animate);
//    }
//    else if (choice == 'M' || choice == 'm')
//    {
//        // RUN ALGO OF CHOICE
//        mergeSortAndVisualize(barLengths, animate);
//    }
//}