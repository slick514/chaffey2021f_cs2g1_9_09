#include <iostream>
#include <ios>
#include <iomanip>
#include "CashRegister.h"
/*
 * Course: Chaffey College 2021-Fall CS2
 * Prof: Dr. Tracy Kocher
 * Date: 2021-10-12
 * Project: 9.09 (NINE-NINE!)
 * Coder: Justin Gries
 * Tester(s):
 *
 * Prompt: After closing time, the store manager would like to know how much
 * business was transacted during the day. Modify the CashRegister class to
 * enable this functionality.
 *  Supply member functions:
        get_sales_total: Gets the total amount of all sale
        get_sales_count: Gets the number of sale.
        reset_sales: Resets any counters and totals so that the next day’s
        sale start from zero.
 *
 * See header file for class and member-function definitions
 */

CashRegister::CashRegister(const double sales_tax_rate) {
    this->tax_rate = sales_tax_rate;
}

int CashRegister::dollars_to_cents(const double &rDollars) {
    return (int)(rDollars * 100);
}

int CashRegister::get_sum_of_prices(const std::vector<Charge> &rCharges) {
    int sum {0};
    for(auto i : rCharges){
        sum += i.get_price_cents();
    }
    return sum;
}

void CashRegister::reset_sales() {
    this->clear();
    this->daily_sales = {};
}

int CashRegister::get_sum_of_taxes(const std::vector<Charge> &rCharges) {
    int sum {0};
    for(auto i : rCharges){
        sum += i.get_tax_cents();
    }
    return sum;
}

unsigned long long CashRegister::get_sales_count() const {
    return daily_sales.size();
}

void CashRegister::clear() {
    this->save_sale();
    this->sale = {};
}

void CashRegister::save_sale() {
    this->daily_sales.push_back(this->sale);
}

double CashRegister::get_sales_total() const {
    int total = 0;
    for(const std::vector<Charge>& rCharge : this->daily_sales){
        total += get_sum_of_prices(rCharge);
    }
    return cents_to_dollars(total);
}

double CashRegister::cents_to_dollars(const int &cents) {
    double dollars {(double)cents};
    return dollars / 100.0;
}

double CashRegister::get_total_tax() const {
    int tax_cents = get_sum_of_taxes(this->sale);
    return cents_to_dollars(tax_cents);
}

void CashRegister::add_taxable_item(const double item_price) {
    int price_cents = dollars_to_cents(item_price);
    int tax_cents = (int)(this->tax_rate * price_cents);
    Charge charge{price_cents, tax_cents};
    this->sale.push_back(charge);
}

void CashRegister::add_item(const double item_price) {
    int cents = dollars_to_cents(item_price);
    Charge charge{cents};
    this->sale.push_back(charge);
}

double CashRegister::get_total() const {
    int cents = get_sum_of_prices(this->sale);
    return cents_to_dollars(cents);
}

unsigned long long CashRegister::get_count() const {
    return this->sale.size();
}

void CashRegister::display_all() const {
    std::cout << "| Sale Charges |" << std::endl;
    print_display_line("Price", "Tax");
    for(const Charge &rC : this->sale){
        std::string price = to_money_str(rC.get_price_cents());
        std::string tax = to_money_str(rC.get_tax_cents());
        print_display_line(price, tax);
    }
}

void CashRegister::print_display_line(const std::string &price_field, const std::string &rTaxField){
    std::cout << std::fixed << std::left;
    std::cout << "| " << std::setw(PRICE_FIELD_W) << price_field << " | " << std::setw(TAX_FIELD_W);
    std::cout << rTaxField << " |" << std::endl;
}

std::string CashRegister::to_money_str(const int cents) {
    double dollars = cents_to_dollars(cents);
    std::ostringstream stream;
    stream << "$" << std::fixed << std::setprecision(2) << dollars;
    return stream.str();
}


int CashRegister::Charge::get_price_cents() const {
    return this->price;
}

int CashRegister::Charge::get_tax_cents() const {
    return this->tax;
}

CashRegister::Charge::Charge(int price_cents, int tax_cents = 0) {
    this->price = price_cents;
    this->tax = tax_cents;
}

CashRegister::Charge::Charge(int price_cents) {
    this->price = price_cents;
    this->tax = 0;
}
