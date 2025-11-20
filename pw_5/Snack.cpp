#include "Snack.h"

Snack::Snack(string poductName, float price, int caloriesAmount): productName(productName), price(price), caloriesAmount(caloriesAmount) {}

// геттеры
const string Snack::getProductName() { return productName; }
const float Snack::getPrice() { return price; }
const int Snack::getCaloriesAmount() { return caloriesAmount; };

//сеттеры
void Snack::setProductName(const string productName) {
    this->productName = productName;
}
void Snack::setPrice(const float price) {
    this->price = price;
}
void Snack::setCaloriesAmount(const int caloriesAmount) {
    this->caloriesAmount = caloriesAmount;
}