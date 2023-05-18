// Name: Saif Ahmed Elsayed Abd Elfattah, ID: 900225535
#include <iostream>
#include "Pizza.hpp"
#include "PizzaBoom.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Pizza::Pizza(string var, int sze) {
    variety = var;
    size = sze;
}
Pizza::Pizza() {}

string Pizza::getVariety() {
    return variety;
}

int Pizza::getSize() {
    return size;
}

// PizzaBoom class
PizzaBoom::PizzaBoom(int size) : menu(new Pizza[size]), quantitySold(new int[size]), menuSize(size), numPizzas(0) {for (int i = 0; i < size; i++)
{
    *(quantitySold+i)=0;
}
}

void PizzaBoom::sellPizza(string var, int sze, int nbSold) {
    for (int i = 0; i < numPizzas; i++) {
        if (menu[i].getVariety() == var && menu[i].getSize() == sze) {
            quantitySold[i] += nbSold;
        }
    }
}

PizzaBoom::~PizzaBoom() {
    delete[] menu;
    delete[] quantitySold;
}
void PizzaBoom::logSales(string fileName) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << setw(10) << "Pizza type" << setw(10) << "Size" << setw(10) << "Quantity" << endl;
        for (int i = 0; i < numPizzas; i++) {
            outFile << setw(10) << menu[i].getVariety() << setw(10) << menu[i].getSize() << setw(10) << quantitySold[i] << endl;
        }
        outFile.close();
    } else {
        cout << "can't open file" << fileName << endl;
    }
}
void PizzaBoom::addPizzaToMenu(Pizza pizza) {
    if (numPizzas < menuSize) {
        menu[numPizzas++] = pizza;
    }
}


void PizzaBoom::displaySalesFromFile(string fileName) {
    ifstream inFile(fileName);
    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "can't open file"  << fileName << endl;
    }
}

void PizzaBoom::storeInObjectFile(string fileName) {
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        for (int i = 0; i < numPizzas; i++) {
            outFile << menu[i].getVariety() << " " << menu[i].getSize() << "\n";
        }
        outFile.close();
    } else {
        cout << "can't open file"  << fileName << endl;
    }
}

void PizzaBoom::displayMenuBySizeFromFile(string fileName, int minSize) {
    ifstream infile(fileName);
    string line;

    cout << "Menu:";
    while (getline(infile, line)) {
        istringstream iss(line);
        string variety;
        int size;
        if (!(iss >> variety >> size)) {
            break;
        }

        if (size >= minSize) {
            cout << " " << variety << " " << size << " " << "\n";
        }
    }
    cout << endl;
}
int main() {
    PizzaBoom pb(15); // making PizzaBoom objects
    Pizza pizza1("mexican", 11);
    Pizza pizza2("mexicann", 14);
    Pizza pizza3("vegetarian", 13);
    pb.addPizzaToMenu(pizza1);
    pb.addPizzaToMenu(pizza2);
    pb.addPizzaToMenu(pizza3);
    pb.sellPizza("mexican", 11, 3);
    pb.sellPizza("vegetarian", 13, 9);
    pb.logSales("sales.txt");
    pb.displaySalesFromFile("sales.txt");
    pb.storeInObjectFile("menu.txt");
    pb.displayMenuBySizeFromFile("menu.txt", 14);

    return 0;
}
