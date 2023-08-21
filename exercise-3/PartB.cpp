//
// Created by Trym Hamer Gudvangen on 8/20/23.
//
#include <iostream>

double salesTax = 25;

class Commodity{
public:
    Commodity(char *name_, int id_, double price_): name(name_), id(id_), price(price_) {};

    char *get_name() const;
    int get_id() const;
    double get_price() const;
    double get_price(double quantity) const;
    double get_price_with_sales_tax(double quantity, double percentTax) const;

    void set_price(double newPrice);

private:
    char *name;
    int id;
    double price;

};

/*
 * Implementation
 */


char * Commodity::get_name() const {
    return this->name;
}

int Commodity::get_id() const {
  return this->id;
}

double Commodity::get_price() const {
    return this->price;
}

double Commodity::get_price(double quantity) const {
    return this->price * quantity;
}

double Commodity::get_price_with_sales_tax(double quantity, double percentTax) const {
    return this->price * quantity * ((percentTax / 100) + 1)    ;
}

void Commodity::set_price(double newPrice) {
    this->price = newPrice;
}

int main() {
    const double quantity = 2.5;
    Commodity commodity("Norvegia", 123, 73.50);

    std::cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id()
         << " Pris pr enhet: " << commodity.get_price() << std::endl;

    std::cout << "Kilopris: " << commodity.get_price() << std::endl;
    std::cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
         << " uten moms" << std::endl;
    std::cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity, salesTax)
         << " med moms" << std::endl;

    commodity.set_price(79.60);
    std::cout << "Ny kilopris: " << commodity.get_price() << std::endl;
    std::cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity)
         << " uten moms" << std::endl;
    std::cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity, salesTax)
         << " med moms" << std::endl;
}
