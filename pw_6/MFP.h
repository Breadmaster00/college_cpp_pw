#include "Printer.h"
#include "Scanner.h"

class MFP : public Printer, public Scanner {
private:
    bool wifiSupported;

public:
    MFP(const string& name, double price, const string& brand, int speed, bool color, int res, bool feed, bool wifi);
    virtual ~MFP();

    const bool isWifiSupported();

    const void showDetails();
};

