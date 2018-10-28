#include <iostream>
#include <string>
#include "loadMNIST.h"
#include <vector>
int main(void)
{
	vector<vector<unsigned char>> trainImages;
	vector<char> trainLabels;
	loadMNISTImages("train-images.idx3-ubyte", trainImages);
	loadMNISTLabels("train-labels.idx1-ubyte", trainLabels);

	vector<vector<unsigned char>> testImages;
	vector<char> testLabels;
	loadMNISTImages("t10k-images.idx3-ubyte", testImages);
	loadMNISTLabels("t10k-labels.idx1-ubyte", testLabels);
	showMNIST(trainImages, trainLabels, 35642);
	system("pause");
	return 0;
}
