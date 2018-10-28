#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
bool loadMNISTImages(string fileName, vector<vector<unsigned char>> &images);
bool loadMNISTLabels(string fileName, vector<char> &labels);
void showMNIST(vector<vector<unsigned char>> &images, vector<char> &labels, int number);
int reverseInt(int n);
