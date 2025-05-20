//testing
#include "setup.h"
#include "algorithms.h"
using namespace std;

int main()
{
    // ALGORITHM CHOICE
    char choice;
    while (true) 
    {
        cout << "Choose what type of sort you want:\n"
            << "(B) Bubble Sort, (I) Insertion Sort, (M) Merge Sort\n"
            << "> ";
        if (cin >> choice &&
            (choice == 'B' || choice == 'b' ||
             choice == 'I' || choice == 'i' ||
             choice == 'M' || choice == 'm' ))
        {
            break;  // valid
        }
        // invalid path:
        cout << "Invalid choice, please enter B, I or M.\n\n";
        cin.clear();  // clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // PRESET OR CUSTOM
    char settings;
    while (true) 
    {
        cout << "\nUse Preset Settings or Custom?\n"
            << "  (P) Preset  (C) Custom\n"
            << "> ";
        if (cin >> settings && (settings == 'P' || settings == 'p' ||
            settings == 'C' || settings == 'c')) 
        {
            break;
        }
        cout << "Invalid input, please enter P, p, C or c.\n\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // PRESET SIZES
    int numberOfBars = 20;
    int maxBarLengthMod = 25;
    // Now that we know the size, build the vector

    if (settings == 'C' || settings == 'c')
    {
        // number of rows
        cout << "\nEnter number of rows: ";

        while (!(cin >> numberOfBars) || numberOfBars < 1)
        {
            cout << "Please enter a positive integer for rows: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // max bar length
        cout << "Enter maximum bar length: ";
        while (!(cin >> maxBarLengthMod) || maxBarLengthMod < 1)
        {
            cout << "Please enter a positive integer for max length: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    vector<int> barLengths(numberOfBars); // change number of bars. 


    // clear the screen and seed RNG
    system("cls");
    srand(static_cast<unsigned int>(time(nullptr)));
    setup(barLengths, maxBarLengthMod);

    // Start Timer
    auto t_start = chrono::high_resolution_clock::now();

    // ALGORITHM CHOICE
    if (choice == 'B' || choice == 'b')
    {
        // RUN ALGO OF CHOICE
        bubbleSortAndVisualize(barLengths);
    }
    else if (choice == 'I' || choice == 'i')
    {
        // RUN ALGO OF CHOICE
        insertionSortAndVisualize(barLengths);
    }
    else if (choice == 'M' || choice == 'm')
    {
        // RUN ALGO OF CHOICE
        mergeSortAndVisualize(barLengths);
    }
    // Stop Timer
    auto t_end = chrono::high_resolution_clock::now();

    // FINAL DISPLAY
    system("cls");
    // Display Time
    auto duration_ms = chrono::duration_cast<chrono::milliseconds>(t_end - t_start).count();
    cout << "Sorting Took: " << duration_ms << "ms" << endl;
    system("color 2");
    cout << "After Sort:\n";
    drawBars(barLengths);

    return 0;
}