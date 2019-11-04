//
// Created by yasha on 04.11.2019.
//

#include "../include/Method.h"

void Method::Random( std::vector<int> sizes) {
    int e = 1;
    for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
        int buff_size_int = *it * 1024 / sizeof(int);
        int* buff = new int[buff_size_int];

        int* indexes = new int[buff_size_int];
        for (int j = 0; j < buff_size_int; j++) {
            indexes[j] = -1;
        }

        int index = 0;
        while (true)
        {
            short sr = std::rand();
            u_int r = sr;
            r <<= 15;
            sr = std::rand();
            r += sr;
            r %= buff_size_int;
            while (indexes[r] != -1)
            {
                r++;
                if (r == (u_int)buff_size_int) {
                    r = 0;
                }
            }

            indexes[r] = index;
            index++;
            if (index == buff_size_int) {
                break;
            }
        }
        //Warming up
        int counter = 0;
        while (true)
        {
            buff[indexes[counter]] = 1;
            counter++;
            if (counter == buff_size_int) {
                break;
            }

        }

//A series of experiments for random
        // timer On
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < N; i++) {
            int counter1 = 0;
            while (true)
            {
                buff[indexes[counter1]] = 1;
                counter1++;
                if (counter1 == buff_size_int) {
                    break;
                }
            }
        }
        //timer Off
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout <<e<< ")buf size = " << *it << "      time = " << microseconds << "mcs" << std::endl;
        e++;
        delete[] buff;
        delete[] indexes;
    }
}

//Straight
void Method::PR( std::vector<int> sizes)
{
    int e = 1;
    for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
        int buff_size_int = *it * 1024 / sizeof(int);
        int* buff = new int[buff_size_int];


        //warming up
        int counter = 0;
        while (true)
        {
            buff[counter++] = 1;
            if (counter == buff_size_int) {
                break;
            }

        }


        //A series of experiments straight
        // timer On
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < N; i++) {
            int counter1 = 0;
            while (true)
            {
                buff[counter1++] = 1;
                if (counter1 == buff_size_int) {
                    break;
                }
            }
        }
        //timer Off

        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout <<e<< ")buf size = " << *it << "      time = " << microseconds << "mcs" << std::endl;
        e++;
        delete[] buff;
    }
}

//Back
void Method::OB(std::vector<int> sizes)
{
    int e = 1;
    for (std::vector<int>::iterator it = sizes.begin(); it != sizes.end(); it++) {
        int buff_size_int = *it * 1024 / sizeof(int);
        buff1 = new int[buff_size_int];

        //Warming up
        int counter = 0;
        while (true)
        {
            buff1[counter++] = 1;
            if (counter == buff_size_int) {
                break;
            }
        }

        //A series of experiments back
        // timer On
        auto start = std::chrono::high_resolution_clock::now();

        for (int i = 0; i < N; i++) {
            int counter1 = buff_size_int;
            while (true)
            {
                buff1[--counter1] = 1;

                if (counter1 < 0) {
                    break;
                }
            }
        }
        //timer Off
        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        std::cout<<e << ")buf size = " << *it << "      time = " << microseconds << "mcs" << std::endl;
        e++;
        //delete[] buff1;
    }
}
