#pragma once

#include "OfficeDevice.h"

using namespace std;

class Printer : virtual public OfficeDevice {
protected:
    int printSpeed;   
    bool colorPrint; 

public:
    Printer(const string& name, double price, const string& brand, int speed, bool color);
    virtual ~Printer();

    const int getPrintSpeed();
    const bool getColorPrint();

    void replaceCartridge();        
    virtual const void showDetails();
};
