// algorithms.h
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>
using namespace std;

void bubbleSortAndVisualize(vector<int>& barLengths, bool animate);
void insertionSortAndVisualize(vector<int>& barLengths, bool animate);
void mergeSortAndVisualize(vector<int>& barLengths, bool animate);

#endif