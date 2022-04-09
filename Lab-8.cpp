//Celeste Going
//Lab 8
/*This program takes the temperature recorded every
hour over a 24-hour period and finds the average.
It also finds the lowest and highest temperatures
recorded, and their position in the array.
The program also calculates the numerical difference
between the average and each recorded
temperature. The program then prints these results.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	int sizeOfArray = 24;

	int* tempArray = new int[sizeOfArray];

	ifstream infile;
	infile.open("data.txt");

	if (!infile)
	{
		cout << "Input file cannot be opened!" << endl;
		exit(0);
	}

	int temp;
	int k = 0;

	infile >> temp;
	while (infile && k < sizeOfArray)
	{
		tempArray[k] = temp;
		k++;

		infile >> temp;
	}

	double total = 0;
	for (k = 0; k < sizeOfArray; k++)
	{
		total += tempArray[k];
	}

	double average = total / sizeOfArray;

	cout << "Average temperature of the data set: " << setprecision(2) << fixed << average << endl << endl;

	cout << setw(4) << "Hour:" << setw(15) << "Temperature:" << setw(30) << "Difference from the Average:" << endl;

	for (k = 0; k < sizeOfArray; k++)
	{
		cout << setw(3) << k << setw(12) << tempArray[k] << setw(20) << setprecision(2) << fixed << (average - tempArray[k]) << endl;
	}
	cout << endl;

	int low = tempArray[0];
	int lowPosition = 0;
	int high = tempArray[0];
	int highPosition = 0;

	for (int i = 0; i < sizeOfArray; ++i)
	{
		if (tempArray[i] < low)
		{
			low = tempArray[i];
			lowPosition = i;
		}

		if (tempArray[i] > high)
		{
			high = tempArray[i];
			highPosition = i;
		}
	}

	cout << "The lowest temperature " << low << " is found at position " << lowPosition << "." << endl;
	cout << "The highest temperature " << high << " is found at position " << highPosition << "." << endl;

	infile.close();

	cout << endl;
	system("PAUSE");
	return 0;
}