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
    int run_tests();
    class ChargeTest : public DoesLogging{
    public:
        int run_tests();
    private:
        int initializers_t();
        int get_price_dollars_str_t();
        int get_tax_dollars_str_t();
        int get_tax_cents_t();
        int get_price_cents_t();
    };
private:
    int initializers_t();
    int clear_t();
    int add_item_t();
    int get_total_t();
    int get_count_t();
    int add_taxable_item_t();
    int get_total_tax_t();
    int get_sales_total_t();
    int get_sales_count_t();
    int reset_sales_t();

    /**
     *
     * @param pLogger
     * @param test_description
     * @param test_result
     * @return 1 or more if test fails, 0 if it passes
     */
    static int handle_test(DoesLogging *pLogger, const std::basic_string<char> &test_description, bool test_result);
    int dollars_to_cents_t();
    int cents_to_dollars_t();
    int to_money_str_t();
    static void display_all_t();
    int test_register_is_in_initial_state(const std::string &test_description, const CashRegister &cr);
    int test_daily_figures_reset(const std::string &test_description, const CashRegister &cr);
    int test_register_is_clear(const std::string &test_description, const CashRegister &cr);
};



#endif //CHAFFEY2021F_CS2G1_9_09_CASHREGISTERTEST_H
