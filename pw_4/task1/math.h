#pragma once

const std::string pomosch = "<---#### ПСИХОЛОГИЧЕСКА ПОМОЩЬ С КАЛЬКУЛЯТОРОМ ####--->\n"
"Чтобы посчитать выражение введите через пробел сначала первое число, потом действие, затем второе число, вот так - \"5 + 3\"\n"
"если нужно посчитать действие с одним числом - не указывайте второе число, вот так - \"5 !\"\n"
"если нужно посчитать побитовое действие, то так - \"n XOR m\"\n"
"Список всех возможных действий:\n"
"Сложение - n + m\n"
"<---#### - - - - - - - - - ####--->\n> ";

double sum(double a, double b);
double diff(double a, double b);
double mul(double a, double b);
double mydiv(double a, double b);
double mypow(double a, int b);
long fact(int num);

int AND(int a, int b);
int OR(int a, int b);
int NE(int num);
int XOR(int a, int b);
int left_sdvig(int a, int b);
int right_sdvig(int a, int b);

