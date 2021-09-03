//
// Created by oscar on 20/08/2021.
//

#ifndef LISTASDOBLES_FACTURA_H
#define LISTASDOBLES_FACTURA_H

#include <string>
#include <ostream>

using namespace std;

class Factura {
public:
    Factura();

    Factura(int id, const string &productname, const string &description, int amount, double totalvalue);

    int getId() const;

    void setId(int id);

    const string &getProductName() const;

    void setProductName(const string &productName);

    const string &getDescription() const;

    void setDescription(const string &description);

    int getAmount() const;

    void setAmount(int amount);

    double getTotalValue() const;

    void setTotalValue(double totalValue);

    friend ostream &operator<<(ostream &os, const Factura &factura);


    virtual ~Factura();


private:

    int Id;
    string Product_Name;
    string description;
    int amount;
    double total_value;


};

#endif //LISTASDOBLES_FACTURA_H
