// Copyright 2018 Your Name <your_email>

#include <Method.h>

#include <iostream>
#include <time.h>
#include <chrono>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    srand(time(0));
    //calculation of the number of experiments
    vector<int> sizes;
    int a = 128 / 2;
    int	b = 3 * 1024 * 3 / 2;
    for (int i = a; i <= b; i *= 2)
    {
        sizes.push_back(i);
    }
    sizes.push_back(b);

    Method A;
    cout << "Random: " << endl << endl;
    A.Random(sizes);
    cout << endl << endl;
    cout << "Straight: " << endl << endl;
    A.PR(sizes);
    cout << endl << endl;
    cout << "Back: " << endl << endl;
    A.OB(sizes);
    cout<< endl << endl;

}