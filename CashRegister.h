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
     * @param sales_tax_rate is the tax rate that will be applied to items which are taxed.
     */
    explicit CashRegister(double sales_tax_rate);

    /**
     * Resets the register to be ready for the next customer
     */
    void clear();

    /**
     * Adds an item to this cash register.
     * @param item_price the price of this item
     */
    void add_item(const double item_price);

    /**
      * Gets the price of all items in the current sale.
      * @return the total amount
     */
    double get_total() const;

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
     * Add a price that will need tax added to it
     * @param item_price
     */
    void add_taxable_item(double item_price);

    /**
     *
     * @return the total tax that is applied to this sale
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

private:

    class Charge{
    public:
        explicit Charge(int price_cents);
        Charge(int price_cents, int tax_cents);
        int get_price_cents() const;
        int get_tax_cents() const;
    private:
        int price;
        int tax;
    };

    /**
     * @return the sum of all purchases
     */
    static int get_sum_of_prices(const std::vector<Charge> &rCharges) ;

    /**
     * @return the sum of all taxes
     */
    static int get_sum_of_taxes(const std::vector<Charge> &rCharges);

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

    double tax_rate;
    std::vector<Charge> sale{};
    std::vector<std::vector<Charge>> daily_sales{};

    /**
     * saves the current sale in the daily list of sales;
     */
    void save_sale();

    static void print_display_line(const std::string &rPrice_field, const std::string &rTaxField);

    static std::string to_money_str(const int cents);
};




#endif //CHAFFEY2021F_CS2G1_9_09_CASHREGISTER_H
