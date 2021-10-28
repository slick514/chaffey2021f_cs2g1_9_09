//
// Created by Justin Gries on 10/24/2021.
//
#include <sstream>
#include <iostream>
#include "cashregistertest.h"

using namespace std;

CashRegisterTest::CashRegisterTest(){
    test_register = new CashRegister(DEFAULT_TAX);
}

int CashRegisterTest::run_tests() {
    int error_count = 0;
    error_count += initializers_t(); // TODO
    error_count += clear_t(); // TODO
    error_count += add_item_t(); // TODO
    error_count += get_total_t(); // TODO
    error_count += get_count_t(); // TODO
    error_count += display_all_t(); // TODO
    error_count += add_taxable_item_t(); // TODO
    error_count += get_total_tax_t(); // TODO
    error_count += get_sales_total_t(); // TODO
    error_count += get_sales_count_t(); // TODO
    error_count += reset_sales_t(); // TODO
    error_count += get_sum_of_prices_cents_t(); // TODO
    error_count += get_sum_of_taxes_cents_t(); // TODO
    error_count += dollars_to_cents_t(); // TODO
    error_count += cents_to_dollars_t(); // TODO
    error_count += to_money_str_t(); // TODO
    CashRegisterTest::ChargeTest charge_tester;
    error_count += charge_tester.run_tests();
    this->compound(charge_tester);
    return error_count;
}

int CashRegisterTest::initializers_t() {//TODO
    int num_errs = 0;
    CashRegister cr(DEFAULT_TAX);
    put_log("Register-constructor, default tax rate", cr.get_tax_rate() == DEFAULT_TAX);
    put_log("Register-Constructor, count zero", cr.get_count() == 0);
    put_log("Register-Constructor, total zero", cr.get_total() == 0);
    put_log("Register-Constructor, total tax zero", cr.get_total_tax() == 0);
    put_log("Register-Constructor, sales-count zero" , cr.get_sales_count() == 0);
    put_log("Register-Constructor, sales-total", cr.get_sales_total() == 0.0);
    return num_errs;
}

int CashRegisterTest::clear_t() {//TODO
    return 0;
}

int CashRegisterTest::add_item_t() {//TODO
    return 0;
}

int CashRegisterTest::get_total_t() {//TODO
    return 0;
}

int CashRegisterTest::display_all_t() {//TODO
    return 0;
}

int CashRegisterTest::get_count_t() {//TODO
    return 0;
}

int CashRegisterTest::add_taxable_item_t() {//TODO
    return 0;
}

int CashRegisterTest::get_total_tax_t() {//TODO
    return 0;
}

int CashRegisterTest::get_sales_total_t() {//TODO
    return 0;
}

int CashRegisterTest::get_sales_count_t() {//TODO
    return 0;
}

int CashRegisterTest::reset_sales_t() {//TODO
    return 0;
}

int CashRegisterTest::get_sum_of_prices_cents_t() {//TODO
    return 0;
}

int CashRegisterTest::get_sum_of_taxes_cents_t() {//TODO
    return 0;
}

CashRegisterTest::~CashRegisterTest() {
    delete this->test_register;
}


int CashRegisterTest::ChargeTest::initializers_t() {//TODO:
    return 0;
}

int CashRegisterTest::ChargeTest::get_price_dollars_str_t() {//TODO:
    return 0;
}

int CashRegisterTest::ChargeTest::get_tax_dollars_str_t() {//TODO:
    return 0;
}

int CashRegisterTest::ChargeTest::get_tax_cents_t() {//TODO:
    return 0;
}

int CashRegisterTest::ChargeTest::get_price_cents_t() {//TODO
    return 0;
}

int CashRegisterTest::ChargeTest::run_tests() {
    int error_count = 0;
    error_count+= initializers_t();
    error_count+= get_price_dollars_str_t();
    error_count+= get_tax_dollars_str_t();
    error_count+= get_tax_cents_t();
    error_count+= get_price_cents_t();
    return error_count;
}

CashRegisterTest::ChargeTest::ChargeTest() {
    this->test_charge = new CashRegister::Charge(DEFAULT_CHARGE);
}

CashRegisterTest::ChargeTest::~ChargeTest() {
    delete this->test_charge;
}

int to_money_str_t() {
    return 0;
}

int cents_to_dollars_t() {
    return 0;
}

int dollars_to_cents_t() {
    return 0;
}
