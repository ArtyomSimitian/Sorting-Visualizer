// setup.h
#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>
using namespace std;

void setup(std::vector<int>& barLengths, int modulus);
void fillWithRandomLengths(std::vector<int>& barLengths, int modulus);
void drawBars(const std::vector<int>& barLengths);
void algorithmChoice(vector<int>& barLengths, char choice, bool animate);

#endif