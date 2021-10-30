//
// Created by Justin Gries on 10/24/2021.
//
#include <sstream>
#include <iostream>
#include "cashregistertest.h"

using namespace std;

int CashRegisterTest::run_tests() {
    int error_count = 0;
    error_count += initializers_t();
    error_count += clear_t();
    error_count += add_item_t();
    error_count += get_total_t();
    error_count += get_count_t();
    error_count += add_taxable_item_t();
    error_count += get_total_tax_t();
    error_count += get_sales_total_t();
    error_count += get_sales_count_t();
    error_count += reset_sales_t();
    error_count += dollars_to_cents_t();
    error_count += cents_to_dollars_t();
    error_count += to_money_str_t();
    CashRegisterTest::ChargeTest charge_tester;
    error_count += charge_tester.run_tests();
    this->compound(charge_tester);

    display_all_t();

    return error_count;
}

int CashRegisterTest::initializers_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    num_errs += handle_test(this,
                            "CashRegister Constructor, default tax rate",
                            test_register.get_tax_rate() == DEFAULT_TAX);
    num_errs += test_register_is_in_initial_state("CashRegister constructor", test_register);
    return num_errs;
}

int CashRegisterTest::test_register_is_in_initial_state(const string &test_description, const CashRegister &cr){
    int num_errs = 0;
    num_errs += test_register_is_clear(test_description, cr);
    num_errs += test_daily_figures_reset(test_description, cr);
    return num_errs;
}

int CashRegisterTest::test_register_is_clear(const string &test_description, const CashRegister &cr){
    int num_errs = 0;
    num_errs += handle_test(this,
            (test_description + ", count zero"),
            cr.get_count() == 0);
    num_errs += handle_test(this,
            (test_description + ", total zero"),
            cr.get_total() == 0);
    num_errs += handle_test(this,
            (test_description + ", total tax zero"),
            cr.get_total_tax() == 0);
    return num_errs;
}

int CashRegisterTest::test_daily_figures_reset(const string &test_description, const CashRegister &cr){
    int num_errs = 0;
    num_errs += handle_test(this,
            (test_description + ", sales-count zero") ,
            cr.get_sales_count() == 0);
    num_errs += handle_test(this,
            (test_description + ", sales-total zero"),
            cr.get_sales_total() == 0.0);
    return num_errs;
}

int CashRegisterTest::clear_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_item(16.32);
    test_register.add_item(100);
    test_register.clear();
    num_errs += test_register_is_clear("CashRegister::clear", test_register);
    return num_errs;
}

int CashRegisterTest::add_item_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_item(14.56);
    test_register.add_item(15.44);
    num_errs += handle_test(this,
                           "CashRegister::add_item verify count",
                            test_register.get_count() == 2);
    num_errs += handle_test(this,
                            "CashRegister::add_item verify total",
                            test_register.get_total() == 30.00);
    test_register.add_item(0.009);
    num_errs += handle_test(this,
                            "CashRegister::add_item verify value less than .01",
                            test_register.get_count() == 2);
    return num_errs;
}

int CashRegisterTest::get_total_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_item(14.56);
    test_register.add_item(15.44);
    num_errs += handle_test(this,
                            "CashRegister::get_total verify total",
                            test_register.get_total() == 30.00);
    return num_errs;
}

void CashRegisterTest::display_all_t() {
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_item(14.56);
    test_register.add_taxable_item(15.44);
    test_register.add_taxable_item(10.00);
    cout << "Display Test" << endl;
    test_register.display_all();
}

int CashRegisterTest::get_count_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_item(14.56);
    test_register.add_item(15.44);
    num_errs += handle_test(this,
            "CashRegister::get_item verify count",
            test_register.get_count() == 2);
    return num_errs;
}

int CashRegisterTest::add_taxable_item_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_taxable_item(10.00);
    test_register.add_taxable_item(10.00);
    num_errs += handle_test(this,
                            "CashRegister::add_taxable_item, test count",
                            test_register.get_count() == 2);
    num_errs += handle_test(this,
                            "CashRegister::add_taxable_item, test sales-total",
                            test_register.get_total() == 20.00);
    num_errs += handle_test(this,
                            "CashRegister::add_taxable_item, test tax-total",
                            test_register.get_total_tax() == 1.60);
    return num_errs;
}

int CashRegisterTest::get_total_tax_t() {
    double entry_value = 10.00;
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_taxable_item(entry_value);
    test_register.add_taxable_item(entry_value);
    num_errs += handle_test(this,
                            "CashRegister::get_total_tax, test tax-sum of two taxable items",
                            test_register.get_total_tax() == (2 * entry_value * DEFAULT_TAX));
    return num_errs;
}

int CashRegisterTest::get_sales_total_t() {
    double entry_value = 10.;
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_taxable_item(entry_value);
    test_register.add_item(entry_value);
    test_register.clear();
    test_register.add_taxable_item(entry_value);
    test_register.add_item(entry_value);
    num_errs += handle_test(this,
            "CashRegister::get_sales_total, test daily sales sum",
            test_register.get_sales_total() == (4 * entry_value));
    return num_errs;
}

int CashRegisterTest::get_sales_count_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_item(12.34);
    test_register.add_taxable_item(56.78);
    test_register.clear();
    test_register.add_item(90.12);
    test_register.add_taxable_item(34.56);
    num_errs += handle_test(this,
                           "CashRegister::get_sales_count",
                           test_register.get_sales_count() == 4);
    return num_errs;
}

int CashRegisterTest::reset_sales_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    test_register.add_item(12.34);
    test_register.add_taxable_item(56.78);
    test_register.clear();
    test_register.add_item(90.12);
    test_register.add_taxable_item(34.56);
    test_register.reset_sales();
    num_errs += test_register_is_in_initial_state("CashRegister::reset_sales", test_register);
    return num_errs;
}

int CashRegisterTest::ChargeTest::initializers_t() {
    
    int num_errs = 0;
    const int price = 123;
    const int tax = 64;
    CashRegister::Charge charge1(price);
    num_errs += handle_test(this,
                            "Charge::Charge(int price) check price",
                            charge1.get_price_cents() == price);
    num_errs += handle_test(this,
                            "Charge::Charge(int price) check tax = 0",
                            charge1.get_tax_cents() == 0);

    CashRegister::Charge charge2(price, tax);
    num_errs += handle_test(this,
                            "Charge::Charge(int price, int tax) check price",
                            charge2.get_price_cents() == price);
    num_errs += handle_test(this,
                            "Charge::Charge(int price, int tax) check tax",
                            charge2.get_tax_cents() == tax);
    return num_errs;
}

int CashRegisterTest::ChargeTest::get_price_dollars_str_t() {
    int num_errs = 0;
    const int price = 123;
    CashRegister::Charge charge(price);
    num_errs += handle_test(this,
                            "Charge::get_price_dollars",
                            charge.get_price_dollars_str() == "$1.23");
    return num_errs;
}

int CashRegisterTest::ChargeTest::get_tax_dollars_str_t() {
    int num_errs = 0;
    const int price = 123;
    const int tax = 456;
    CashRegister::Charge charge1(price, tax);
    num_errs += handle_test(this,
            "Charge::get_tax_dollars_str",
            charge1.get_tax_dollars_str() == "$4.56");

    CashRegister::Charge charge2(price, 0);
    num_errs += handle_test(this,
            "Charge::get_tax_dollars_str (zero tax)",
            charge2.get_tax_dollars_str() == "-");
    return num_errs;
}

int CashRegisterTest::ChargeTest::get_tax_cents_t() {
    int num_errs = 0;
    const int price = 123;
    const int tax = 456;
    CashRegister::Charge charge(price, tax);

    num_errs += handle_test(this,
            "Charge::get_tax_cents",
            charge.get_tax_cents() == tax);
    return num_errs;
}

int CashRegisterTest::ChargeTest::get_price_cents_t() {
    int num_errs = 0;
    const int price = 123;
    const int tax = 456;
    CashRegister::Charge charge(price, tax);

    num_errs += handle_test(this,
            "Charge::get_price_cents",
            charge.get_price_cents() == price);
    return num_errs;
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

int CashRegisterTest::to_money_str_t() {
    int num_errs = 0;
    CashRegister test_register(DEFAULT_TAX);
    num_errs += handle_test(this,
            "CashRegister::to_money_string(double dollars)",
            CashRegister::to_money_str(12.34) == "$12.34");
    num_errs += handle_test(this,
            "CashRegister::to_money_string(int cents)",
            CashRegister::to_money_str(1234) == "$12.34");
    num_errs += handle_test(this,
            "CashRegister::to_money_string(ZERO)",
            CashRegister::to_money_str(0) == "-");
    return num_errs;
}

int CashRegisterTest::cents_to_dollars_t() {
    int num_errs = 0;
    int price_in_cents = 123454;
    num_errs += handle_test(this,
            "CashRegister::cents_to_dollars",
            CashRegister::cents_to_dollars(price_in_cents) == 1234.54);
    return num_errs;
}

int CashRegisterTest::dollars_to_cents_t() {
    int num_errs = 0;
    double price_in_dollars = 12545.89;
    num_errs += handle_test(this,
                            "CashRegister::dollar_to_cents",
                            CashRegister::dollars_to_cents(price_in_dollars) == 1254589);
    return num_errs;
}

int CashRegisterTest::handle_test(doeslogging *pLogger, const basic_string<char> &test_description, bool test_result) {
    pLogger->put_log(test_description, test_result);
    return !test_result ? 1 : 0;
}
