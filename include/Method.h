//
// Created by yasha on 04.11.2019.
//

#include <iostream>
#include <time.h>
#include <chrono>
#include <stdio.h>
#include <vector>

#ifndef LAB_02_CACHE_METHOD_H
#define LAB_02_CACHE_METHOD_H


class Method {

public:
    const int N = 1000;

    void Random( std::vector<int> sizes);
    void PR( std::vector<int> sizes);
    void OB(std::vector<int> sizes);


private:

    int* buff1;

};


#endif //LAB_02_CACHE_METHOD_H
