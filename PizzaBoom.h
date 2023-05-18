#ifndef PIZZABOOM_H
#define PIZZABOOM_H

#include "Pizza.hpp"
using namespace std;


class PizzaBoom {
private:
    Pizza* menu;
    int menuSize;
    int* quantitySold;
    int numPizzas;

public:
    PizzaBoom(int size);
    ~PizzaBoom();
   void addPizzaToMenu(Pizza pizza);
    void sellPizza(string var, int sze, int nbSold);
    void logSales(string fileName);
    void displaySalesFromFile(string fileName);
    void storeInObjectFile(string fileName);
    void displayMenuBySizeFromFile(string fileName, int minSize);
    
};

#endif // PIZZABOOM_H
