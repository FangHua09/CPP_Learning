/*
Sales_data 类构造函数（教材版本）
class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(n*p) {}
    Sales_data(std::istream &is);
    // ...其余成员
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data first_item(cin);调用：Sales_data(std::istream &is)构造函数。从 cin 读取输入给bookNo、units_sold、revenue；成员值由标准输入决定。
Sales_data next; main 函数内调用：默认构造函数 Sales_data() = default;成员值：bookNo为空字符串""；units_sold = 0；revenue = 0.0。
Sales_data last("9-999-99999-9");调用：Sales_data(const std::string &s)单参数构造函数。成员值：bookNo = "9-999-99999-9"；units_sold = 0；revenue = 0.0。
*/