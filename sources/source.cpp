// Copyright 2018 Your Name <your_email>

#include <header.hpp>

#include <iostream>
#include <time.h>
#include <chrono>
#include <stdio.h>
#include <vector>


using namespace std;

void prn(int *arr, int l) {
	for (int i = 0; i < l; i++) {
		std::cout << "arr[" << i << "]=" << arr[i] << endl;
	}
	system("pause");
}

int main() {
	srand(time(0));

	const int N = 1000; //кол-во проходов
	const int Kb = 1024;

	//Расчет кол-ва экспериментов
	vector<int> sizes;
	int a = 128 / 2;
	int	b = 3 * Kb * 3 / 2;
	for (int i = a; i <= b; i *= 2)
	{
		sizes.push_back(i);
	}
	sizes.push_back(b);


	
							   
	//random

	for (vector<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
		int buff_size_int = *it * Kb / sizeof(int);
		int* buff = new int[buff_size_int];
		
		int* indexes = new int[buff_size_int];
		for (int j = 0; j < buff_size_int; j++) {
			indexes[j] = -1;
		}

		int index = 0;
		while (true)
		{
			short sr = std::rand();
			int r = sr;
			r <<= 15;
			sr = std::rand();
			r += sr;
			r %= buff_size_int;
			while (indexes[r] != -1)
			{
				r++;
				if (r == buff_size_int) {
					r = 0;
				}
			}

			indexes[r] = index;
			index++;
			if (index == buff_size_int) {
				break;
			}
		}

		//prn(indexes, buff_size_int);
		

		//прогрев
		int counter = 0;
		while (true)
		{
			buff[indexes[counter]] = 1;
			counter++;
			if (counter == buff_size_int) {
				break;
			}
			
		}
		

		//серия экспериментов для случ
		// timer On
		auto start = std::chrono::high_resolution_clock::now();
		
		for (int i = 0; i < N; i++) {
			int counter = 0;
			while (true)
			{
				int foo = buff[indexes[counter]];
				counter++;
				if (counter == buff_size_int) {
					break;
				}
			}
		}
		//timer Off
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		std::cout << "buf size = " << *it << "   " << microseconds << "mcs" << endl;

		delete[] buff;
		delete[] indexes;
	}
	
	//прямой
	for (vector<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
		int buff_size_int = *it * Kb / sizeof(int);
		int* buff = new int[buff_size_int];


		//прогрев
		int counter = 0;
		while (true)
		{
			buff[counter++] = 1;
			if (counter == buff_size_int) {
				break;
			}

		}


		//серия экспериментов для прям
		// timer On
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < N; i++) {
			int counter = 0;
			while (true)
			{
				int foo = buff[counter++];
				if (counter == buff_size_int) {
					break;
				}
			}
		}
		//timer Off
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		std::cout << "buf size = " << *it << "   " << microseconds << "mcs" << endl;

		delete[] buff;
	}
	

	//обратный
	for (vector<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
		int buff_size_int = *it * Kb / sizeof(int);
		int* buff = new int[buff_size_int];


		//прогрев
		int counter = 0;
		while (true)
		{
			buff[counter++] = 1;
			if (counter == buff_size_int) {
				break;
			}

		}


		//серия экспериментов для обр
		// timer On
		auto start = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < N; i++) {
			int counter = buff_size_int;
			while (true)
			{
				int foo = buff[--counter];
				if (counter < 0) {
					break;
				}
			}
		}
		//timer Off
		auto elapsed = std::chrono::high_resolution_clock::now() - start;
		long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
		std::cout << "buf size = " << *it << "   " << microseconds << "mcs" << endl;

		delete[] buff;
	}
	


	system("pause");
}
