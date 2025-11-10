#include "Validate.h"

using namespace std;

namespace validate {
    bool isCorrectAlpha(string str) {
        for (int i = 0; i < str.length(); ++i) {
            if (isdigit(str.at(i)) || ispunct(str.at(i))) return false;
        }
        return true;
    }
}