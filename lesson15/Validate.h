#pragma once
#include <string>

using namespace std;

namespace validate {
    bool isCorrectAlpha(string str);
    template<typename T> bool isCorrectCount(T count) {
        if (count < 0) return false;
        else return true;
    }
}