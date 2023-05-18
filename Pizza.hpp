



#ifndef PIZZA_H
#define PIZZA_H

#include <string>
using namespace std;

class Pizza {
private:
    string variety;
    int size;

public:
    Pizza();
    Pizza(string var, int sze);
    string getVariety();
    int getSize();
};

#endif // PIZZA_H
