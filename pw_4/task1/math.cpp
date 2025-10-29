#include <string>

double sum(double a, double b) {
    return a + b;
}

double diff(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double mydiv(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        return 0;
    }
}

double mypow(double a, int b) {
    if (b == 0) {
        return 1;
    } else if (b < 0) {
        return mydiv(1, mypow(a, -b));
    } else {
        return a * mypow(a, b - 1);
    }
}

long fact(int num) {
    if (num == 1) {
        return 1;
    }
    return num * fact(num - 1);
}

int AND(int a, int b) {
    return a & b;
}

int OR(int a, int b) {
    return a | b;
}

int NE(int num) {
    return ~num;
}

int XOR(int a, int b) {
    return a ^ b;
}

int left_sdvig(int a, int b) {
    return a << b;
}

int right_sdvig(int a, int b) {
    return a >> b;
}


