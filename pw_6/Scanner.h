#pragma once

#include "OfficeDevice.h"

using namespace std;

class Scanner : virtual public OfficeDevice {
protected:
    int resolution; 
    bool autoFeed;  

public:
    Scanner(const string& name, double price, const string& brand, int res, bool feed);
    virtual ~Scanner();

    const int getResolution();
    const bool getAutoFeed();

    void calibrate();
    virtual const void showDetails();
};
