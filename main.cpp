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
	unsigned int n;
	while (true)
	{
		cout << "Please choose a number: ";
		cin >> n;
		if (n < 60000)
			showMNIST(trainImages, trainLabels, n);
		else
			break;		
	}
	return 0;
}
