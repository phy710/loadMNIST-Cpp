#include "loadMNIST.h"
int reverseInt(int n)
{
	unsigned char ch1, ch2, ch3, ch4;
	ch1 = n & 255;
	ch2 = (n >> 8) & 255;
	ch3 = (n >> 16) & 255;
	ch4 = (n >> 24) & 255;
	return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}

bool loadMNISTImages(string fileName, vector<vector<unsigned char>> &images)
{
	ifstream fp(fileName, ios::binary);
	if (!fp.is_open())
	{
		cout << "Could not open " << fileName << "!" << endl;
		fp.close();
		return false;
	}
	int magic, numImages, numRows, numCols;
	fp.read((char*)&magic, sizeof(magic));
	magic = reverseInt(magic);
	if (magic != 2051)
	{
		cout << "Bad magic number in " << fileName << "!" << endl;
		fp.close();
		return false;
	}
	fp.read((char*)&numImages, sizeof(numImages));
	numImages = reverseInt(numImages);
	fp.read((char*)&numRows, sizeof(numRows));
	numRows = reverseInt(numRows);
	fp.read((char*)&numCols, sizeof(numCols));
	numCols = reverseInt(numCols);
	vector<unsigned char> image;
	unsigned char pixel;
	for (int i = 0; i < numImages; i++)
	{
		image.clear();
		for (char j = 0; j < numRows; j++)
			for (char k = 0; k < numCols; k++)
			{
				fp.read((char*)&pixel, sizeof(pixel));
				image.push_back(pixel);
			}
		images.push_back(image);
	}
	fp.close();
	return true;
}

bool loadMNISTLabels(string fileName, vector<char> &labels)
{
	ifstream fp (fileName, ios::binary);
	if (!fp.is_open())
	{
		cout << "Could not open " << fileName << "!" << endl;
		fp.close();
		return false;
	}
	int magic, numLabels;
	fp.read((char*)&magic, sizeof(magic));
	magic = reverseInt(magic);
	if (magic!=2049)
	{
		cout << "Bad magic number in " << fileName << "!" << endl;
		fp.close();
		return false;
	}
	fp.read((char*)&numLabels, sizeof(numLabels));
	numLabels = reverseInt(numLabels);
	char label;
	for (int i = 0; i < numLabels; i++)
	{
		fp.read(&label, sizeof(label));
		labels.push_back(label);
	}
	fp.close();
	return true;
}

void showMNIST(vector<vector<unsigned char>> &images, vector<char> &labels, int number)
{
	for (int i = 0; i < 28; i++)
	{
		printf("\n");
		for (int j = 0; j < 28; j++)
			printf("%3d ", images[number][i * 28 + j]);
	}
	printf("\nLabel: %d\n", labels[number]);
}
