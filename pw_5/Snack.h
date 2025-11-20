#pragma once
#include <string>

using namespace std;

class Snack {
    private:
        string productName;
        float price;
        int caloriesAmount;

    public:
        Snack(string poductName, float price, int caloriesAmount);

        // геттеры
        const string getProductName();
        const float getPrice();
        const int getCaloriesAmount();

        //сеттеры
        void setProductName(const string productName);
        void setPrice(const float price);
        void setCaloriesAmount(const int caloriesAmount);
};
