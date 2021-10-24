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

double CashRegister::cents_to_dollars(const int cents) {
    double dollars {(double)cents};
    return 0;
}

int CashRegister::Charge::get_price_cents() const {
    return this->price;
}

int CashRegister::Charge::get_tax_cents() const {
    return this->tax;
}

CashRegister::Charge::Charge(int price_cents, int tax_cents) {
    this->price = price_cents;
    this->tax = tax_cents;
}
