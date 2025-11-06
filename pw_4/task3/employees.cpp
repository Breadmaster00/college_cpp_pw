#include <iostream>

int calculateSum(int array[], int array_len) {
    int sum = 0;
    for (int el = 0; el < array_len; ++el) {
        sum += array[el];
    }
    return sum;
}

int getMinValue(int array[], int array_len) {
    int min_value = *array;
    for (int i = 0; i < array_len; ++i) {
        if (min_value > array[i]) {
            min_value = array[i];
        }
    }
    return min_value;
}