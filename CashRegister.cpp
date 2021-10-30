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
    this->daily_sales = {};
    this->sale = {};
}

int CashRegister::dollars_to_cents(const double &rDollars) {
    return (int)(rDollars * 100.0);
}

int CashRegister::Charge::get_sum_of_prices_cents(const std::vector<Charge> &rCharges) {
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

int CashRegister::Charge::get_sum_of_taxes_cents(const std::vector<Charge> &rCharges) {
    int sum = 0;
    for(auto i : rCharges){
        sum += i.get_tax_cents();
    }
    return sum;
}

unsigned long long CashRegister::get_sales_count() const {
    return daily_sales.size();
}

void CashRegister::clear() {
    this->sale.clear();
}

double CashRegister::get_sales_total() const {
    return cents_to_dollars(Charge::get_sum_of_prices_cents(this->daily_sales));
}

double CashRegister::cents_to_dollars(const int &cents) {
    double dollars { double(cents) };
    return dollars / 100.0;
}

double CashRegister::get_total_tax() const {
    int tax_cents = CashRegister::Charge::get_sum_of_taxes_cents(this->sale);
    return cents_to_dollars(tax_cents);
}

void CashRegister::add_taxable_item(const double item_price) {
    int price_cents = dollars_to_cents(item_price);
    int tax_cents = (int)(this->tax_rate * price_cents);
    Charge charge{price_cents, tax_cents};
    this->sale.push_back(charge);
    this->daily_sales.push_back(charge);
}

void CashRegister::add_item(const double item_price) {
    if (item_price >= 0.01){
        int cents = dollars_to_cents(item_price);
        Charge charge{cents};
        this->sale.push_back(charge);
        this->daily_sales.push_back(charge);
    }
}

double CashRegister::get_total() const {
    int cents = Charge::get_sum_of_prices_cents(this->sale);
    return cents_to_dollars(cents);
}

unsigned long long CashRegister::get_count() const {
    return this->sale.size();
}

void CashRegister::display_all() const {
    print_display_header();
    for(const Charge &rC : this->sale){
        print_display_line(rC.get_price_dollars_str(), rC.get_tax_dollars_str());
    }
    print_display_line("Total Sales", "Total Tax");
    std::string sum_of_prices = to_money_str(this->get_total());
    std::string sum_of_taxes = to_money_str(this->get_total_tax());
    print_display_line(sum_of_prices, sum_of_taxes);
}

void CashRegister::print_display_line(const std::string &rPrice_field, const std::string &rTaxField){
    std::cout << std::fixed << std::right;
    std::cout << FIELD_START << std::setw(PRICE_FIELD_W) << rPrice_field << FIELD_SEPARATOR << std::setw(TAX_FIELD_W);
    std::cout << rTaxField << FIELD_END << std::endl;
}

void CashRegister::print_display_header() {
    std::cout << "SALE ITEMS AND TAX" << std::endl;
}

double CashRegister::get_tax_rate() const {
    return this->tax_rate;
}

std::string CashRegister::to_money_str(const double &dollars) {
    std::string display_string;
    if(dollars >= .01) {
        std::ostringstream stream;
        stream << "$" << std::fixed << std::setprecision(2) << dollars;
        display_string = stream.str();
    }else{
        display_string = "-";
    }
    return display_string;
}

std::string CashRegister::to_money_str(const int &cents) {
    std::string display_string = to_money_str(cents_to_dollars(cents));
    return display_string;
}


std::string CashRegister::Charge::get_price_dollars_str() const {
    return to_money_str(this->price_cents);
}


std::string CashRegister::Charge::get_tax_dollars_str() const {
    return to_money_str(this->tax_cents);
}

CashRegister::Charge::Charge(int price_cents, int tax_cents = 0) {
    this->price_cents = price_cents;
    this->tax_cents = tax_cents;
}

CashRegister::Charge::Charge(int price_cents) {
    this->price_cents = price_cents;
    this->tax_cents = 0;
}

int CashRegister::Charge::get_tax_cents() const {
    return this->tax_cents;
}

int CashRegister::Charge::get_price_cents() const {
    return this->price_cents;
}
