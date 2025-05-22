#include "setup.h"
#include "algorithms.h"
//#include "sortingVisualizer.h"
using namespace std;

int main()
{
   char restart = 0;

   do
   {
        char choice;
        char settings;
        char doAnimate;
        bool animate = false;
        int numberOfBars = 20; // PRESET SIZES
        int maxBarLengthMod = 25;

        system("cls");
        system("color 7");

        // ALGORITHM CHOICE
        while (true)
        {
            cout << "Choose Sorting Algorithm:\n"
                << "(B) Bubble Sort, (I) Insertion Sort, (M) Merge Sort\n"
                << "> ";
            if (cin >> choice &&
                (choice == 'B' || choice == 'b' ||
                    choice == 'I' || choice == 'i' ||
                    choice == 'M' || choice == 'm'))
            {
                break;  // valid
            }
            // invalid path:
            cout << "Invalid choice, please enter B, I or M.\n\n";
            cin.clear();  // clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // PRESET OR CUSTOM
        while (true)
        {
            cout << "\nUse Preset Settings or Custom?\n"
                << "(Number of Rows and Length of Rows)\n"
                << "(P) Preset  (C) Custom\n"
                << "> ";
            if (cin >> settings && (settings == 'P' || settings == 'p' ||
                settings == 'C' || settings == 'c'))
            {
                break;
            }
            cout << "Invalid input, please enter P, p, C or c.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

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

        // ANIMATION
        cout << "\nAnimate Sorting? (Y/N): " << endl;
        cout << "> ";
        cin >> doAnimate;

        animate = (doAnimate == 'Y' || doAnimate == 'y');

        // clear the screen and seed RNG
        system("cls");
        srand(static_cast<unsigned int>(time(nullptr)));
        setup(barLengths, maxBarLengthMod);

        // Start Timer
        auto t_start = chrono::high_resolution_clock::now();
        algorithmChoice(barLengths, choice, animate);
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

        // Restart Prompt
        cout << "Restart? (Y/N): " << endl;
        cout << "> ";
        cin >> restart;
    }
    while (restart == 'Y' || restart == 'y');

    cout << "\nThank you!" << endl;

    return 0;
}