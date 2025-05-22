#include "algorithms.h"
#include "setup.h"

void bubbleSortAndVisualize(vector<int>& barLengths, bool animate)
{
    bool hasSwapped;
    do
    {
        hasSwapped = false;
        for (size_t i = 0; i + 1 < barLengths.size(); ++i)
        {
            if (barLengths[i] > barLengths[i + 1])
            {
                swap(barLengths[i], barLengths[i + 1]);
                hasSwapped = true;

                if (animate)
                {
                    // Clear console (Windows)
                    system("cls");

                    // Show updated bars
                    cout << "Sorting..." << endl;
                    drawBars(barLengths);

                    // Pause briefly to animate
                    this_thread::sleep_for(chrono::milliseconds(50));
                }
            }
        }
    } while (hasSwapped);
}

void insertionSortAndVisualize(vector<int>& barLengths, bool animate)
{
    int n = static_cast<int>(barLengths.size());

    for (int i = 1; i < n; i++)
    {
        int temp = barLengths[i];
        int j = i - 1;

        while (j >= 0 && barLengths[j] > temp)
        {
            barLengths[j + 1] = barLengths[j];
            j--;
        }
        barLengths[j + 1] = temp;

        if (animate)
        {
            // Clear console (Windows)
            system("cls");

            //Show updated bars
            cout << "Sorting..." << endl;
            drawBars(barLengths);

            // Pause briefly to animate
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }
}

void mergeSortAndVisualize(vector<int>& barLengths, bool animate)
{
    // Recursive sort on [0 … N-1]
    function<void(int, int)> mergeSortRec = [&](int left, int right)
        {
            if (left >= right)
            {
                return;
            }

            int mid = (left + right) / 2;
            // sort left half
            mergeSortRec(left, mid);
            // sort right half
            mergeSortRec(mid + 1, right);

            // merge the two runs
            vector<int> temp(right - left + 1);
            int i = left,        // runs over left half
                j = mid + 1,     // runs over right half
                k = 0;           // runs over temp[]

            // 1) merge until one side is exhausted
            while (i <= mid && j <= right)
            {
                if (barLengths[i] <= barLengths[j])
                    temp[k++] = barLengths[i++];
                else
                    temp[k++] = barLengths[j++];
            }
            // 2) copy any leftovers
            while (i <= mid)    temp[k++] = barLengths[i++];
            while (j <= right)  temp[k++] = barLengths[j++];
            // 3) write back **with animation**
            for (int idx = 0; idx < k; ++idx)
            {
                barLengths[left + idx] = temp[idx];

                if (animate)
                {
                    // --- VISUALIZE ONE STEP ---
                    system("cls");
                    cout << "Sorting...\n";
                    drawBars(barLengths);
                    this_thread::sleep_for(chrono::milliseconds(50));
                }
            }
        };

    // call the lambda on the full array
    mergeSortRec(0, static_cast<int>(barLengths.size()) - 1);
}

