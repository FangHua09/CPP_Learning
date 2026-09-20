#include <iostream>
#include "Sales_data.h"

int main()
{
    // 1.5.1：读取一条销售记录输出
    /*
    Sales_data book;
    double price;
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;
    std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << std::endl;
    */

    // 1.5.2：循环读取多条记录
    /*
    Sales_data book;
    double price;
    while(std::cin >> book.bookNo >> book.units_sold >> price)
    {
        book.revenue = book.units_sold * price;
        std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << std::endl;
    }
    */

    //1.6：两条同ISBN求和
    Sales_data item1, item2;
    double price1, price2;
    std::cin >> item1.bookNo >> item1.units_sold >> price1;
    item1.revenue = item1.units_sold * price1;

    std::cin >> item2.bookNo >> item2.units_sold >> price2;
    item2.revenue = item2.units_sold * price2;

    if(item1.bookNo == item2.bookNo)
    {
        unsigned total_sold = item1.units_sold + item2.units_sold;
        double total_rev = item1.revenue + item2.revenue;
        std::cout << item1.bookNo << " " << total_sold << " " << total_rev << std::endl;
    }
    else
    {
        std::cerr << "ISBN不相同" << std::endl;
        return -1;
    }
    return 0;
}
