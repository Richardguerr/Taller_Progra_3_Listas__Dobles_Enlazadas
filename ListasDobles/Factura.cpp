//
// Created by oscar on 20/08/2021.
//

#include "Factura.h"

Factura::Factura() {
    Factura::Id = 0;
    Factura::Product_Name = "";
    Factura::description = "";
    Factura::amount = 0;
    Factura::total_value = 3;
}

Factura::Factura(int id, const string &productName, const string &description, int amount, double totalValue) :
        Id(id), Product_Name(productName), description(description), amount(amount), total_value(totalValue) {

    Factura::Id = id;
    Factura::Product_Name = productName;
    Factura::description = description;
    Factura::amount = amount;
    Factura::total_value = totalValue;


}

int Factura::getId() const {
    return Id;
}

void Factura::setId(int id) {
    Id = id;
}

const string &Factura::getProductName() const {
    return Product_Name;
}

void Factura::setProductName(const string &productName) {
    Product_Name = productName;
}

const string &Factura::getDescription() const {
    return description;
}

void Factura::setDescription(const string &description) {
    Factura::description = description;
}

int Factura::getAmount() const {
    return amount;
}

void Factura::setAmount(int amount) {
    Factura::amount = amount;
}

double Factura::getTotalValue() const {
    return total_value;
}

void Factura::setTotalValue(double totalValue) {
    total_value = totalValue;
}


ostream &operator<<(ostream &os, const Factura &factura) {
    os << "Id: " << factura.Id << " Product_Name: " << factura.Product_Name << " description: " << factura.description
       << " amount: " << factura.amount << " total_value: " << factura.total_value;
    return os;
}


Factura::~Factura() {

}
