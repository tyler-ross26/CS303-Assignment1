#pragma once
using namespace std;
#include <string>
#include <iostream>

void find(int array[], int size, int val);

void modify(int array[], int index, int newVal, int oldValue);

void add(int*& array, int& size, int& newVal);

void replace(int array[], int index);