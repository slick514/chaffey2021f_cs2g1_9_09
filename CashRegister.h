//
// Created by justi on 10/13/2021.
//

#ifndef CHAFFEY2021F_CS2G1_9_09_CASHREGISTER_H
#define CHAFFEY2021F_CS2G1_9_09_CASHREGISTER_H
#include <vector>

static const int PRICE_FIELD_W = 5;
static const int TAX_FIELD_W = 5;

class CashRegister {
public:
    /**
     * Constructor.
     * @param sales_tax_rate is the tax_cents rate that will be applied to items which are taxed. Format of input
     * expected as a decimal fraction; e.g.: 8.5 tax rate expected to be entered as ".085"
     */
    explicit CashRegister(double sales_tax_rate);

    /**
     * Resets the register to be ready for the next customer
     */
    void clear();

    /**
     * Adds an item to this cash register.
     * @param item_price the price_cents of this item
     */
    void add_item(double item_price);

    /**
      * Gets the price_cents of all items in the current sale.
      * @return the total amount
     */
    double get_total() ;

    /**
     * Gets the number of items in the current sale
     * @return the item count
     */
    unsigned long long get_count() const;

    /**
     * Displays the prices of all items in the current sale.
     */
    void display_all() const;

    /**
     * Add a price_cents that will need tax_cents added to it
     * @param item_price
     */
    void add_taxable_item(double item_price);

    /**
     *
     * @return the total tax_cents that is applied to this sale
     */
    double get_total_tax() const;

    /**
     *
     * @return the sum of all sale on this register since the last time that reset_sales() was called.
     */
    double get_sales_total() const;

    /**
     *
     * @return the total number of sale on this register since the last time that reset_sales() was called.
     */
    unsigned long long get_sales_count() const;

    /**
     * Resets the daily register
     */
    void reset_sales();

    /**
     * accessor function for the tax_rate field;
     * @return this object's tax-rate.
     */
    double get_tax_rate() const;

    class Charge{
    public:
        /**
         * Constructor for case where only price is entered
         * Sets tax to 0
         * @param price_cents the cent-amount of the charge
         */
        explicit Charge(int price_cents);

        /**
         * Constructor for when both price and tax are used
         * @param price_cents the price, in cents
         * @param tax_cents the tax, in dollars
         */
        Charge(int price_cents, int tax_cents);

        /**
         * Sets the amount to a new value;
         * @param amt_cents the amount of the new value;
         */
        void set_amount(const int &amt_cents);

        /**
         * Sets the tax to a new value
         * @param new_tax the new tax value to be set
         */
        void set_tax(const int &new_tax);

        /**
         * @return a string representing the dollar amount of the price, including dollar-sign
         */
        std::string get_price_dollars_str() const;

        /**
         * @return a string representing the dollar amount of the tax, including dollar-sign
         */
        std::string get_tax_dollars_str() const;

        /**
         * @return the amount of tax, in cents
         */
        int get_tax_cents() const;

        /**
         * @return the amount of the price, in cents.
         */
        int get_price_cents() const;

    private:
        int price_cents;
        int tax_cents;
    };
private:
    double tax_rate;
    std::vector<Charge> sale{};
    std::vector<std::vector<Charge>> daily_sales{};

    /**
     * saves the current sale in the daily list of sales;
     */
    void save_sale();

    /**
     * @return the sum of all purchases
     */
    static int get_sum_of_prices_cents(const std::vector<Charge> &rCharges);

    /**
     * @return the sum of all taxes
     */
    static int get_sum_of_taxes_cents(const std::vector<Charge> &rCharges);

    static void print_display_header();

    /**
     * Printing a line of
     * @param rPrice_field
     * @param rTaxField
     */
    static void print_display_line(const std::string &rPrice_field, const std::string &rTaxField);
};



/**
 * Converts whole number cents to dollars
 * @param rDollars fractional number representing dollars
 * @return an int that represents the conversion of dollars to cents
 */
static int dollars_to_cents(const double &rDollars);

/**
 * Converts whole number cents to dollars
 * @param rCents fractional number representing cents
 * @return a double that represents the conversion of cents to dollars
 */
static double cents_to_dollars(const int &rCents);

/**
 * Converts an integer representing money,in terms of cents to a string representing dollars
 * @param cents
 * @return a string representing the dollar amount
 */
static std::string to_money_str(int cents);


#endif //CHAFFEY2021F_CS2G1_9_09_CASHREGISTER_H
