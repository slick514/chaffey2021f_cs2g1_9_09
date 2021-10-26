//
// Created by Justin Gries on 10/24/2021.
//

#ifndef CHAFFEY2021F_CS2G1_9_09_CASHREGISTERTEST_H
#define CHAFFEY2021F_CS2G1_9_09_CASHREGISTERTEST_H


#include <string>
#include "CashRegister.h"

class CashRegisterTest {
public:
    CashRegisterTest();
    int run_tests();
    void print_log() const;
    void print_errors() const;
    class ChargeTest{
        bool ChargeTest_t();
        bool get_price_dollars_str_t();
        bool get_tax_dollars_str_t();
        bool get_tax_cents_t();
        bool get_price_cents_t();
    };
private:
    std::vector<std::string> errors;
    std::vector<std::string> log;
    CashRegister get_test_register() const;
    bool CashRegister_t();
    bool clear_t();
    bool add_item_t();
    bool get_total_t();
    bool get_count_t();
    bool display_all_t();
    bool add_taxable_item_t();
    bool get_total_tax_t();
    bool get_sales_total_t();
    bool get_sales_count_t();
    bool reset_sales_t();
    bool get_sum_of_prices_cents_t();
    bool get_sum_of_taxes_cents_t();
};

static bool dollars_to_cents_t();
static bool cents_to_dollars_t();
static bool to_money_str_t();


#endif //CHAFFEY2021F_CS2G1_9_09_CASHREGISTERTEST_H
