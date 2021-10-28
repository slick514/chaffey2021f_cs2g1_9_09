//
// Created by Justin Gries on 10/24/2021.
//

#ifndef CHAFFEY2021F_CS2G1_9_09_CASHREGISTERTEST_H
#define CHAFFEY2021F_CS2G1_9_09_CASHREGISTERTEST_H


#include <string>
#include "CashRegister.h"
#include "DoesLogging.h"

static const double DEFAULT_TAX = .08;
static const int  DEFAULT_CHARGE = 0;

class CashRegisterTest : public DoesLogging{
public:
    CashRegisterTest();
    ~CashRegisterTest();
    int run_tests();
    class ChargeTest : public DoesLogging{
    public:
        ChargeTest();
        ~ChargeTest();
        int run_tests();
    private:
        CashRegister::Charge* test_charge{};
        int initializers_t();
        int get_price_dollars_str_t();
        int get_tax_dollars_str_t();
        int get_tax_cents_t();
        int get_price_cents_t();
    };
private:
    CashRegister* test_register;
    int initializers_t();
    int clear_t();
    int add_item_t();
    int get_total_t();
    int get_count_t();
    int display_all_t();
    int add_taxable_item_t();
    int get_total_tax_t();
    int get_sales_total_t();
    int get_sales_count_t();
    int reset_sales_t();
    int get_sum_of_prices_cents_t();
    int get_sum_of_taxes_cents_t();
};

static int dollars_to_cents_t();
static int cents_to_dollars_t();
static int to_money_str_t();

#endif //CHAFFEY2021F_CS2G1_9_09_CASHREGISTERTEST_H
