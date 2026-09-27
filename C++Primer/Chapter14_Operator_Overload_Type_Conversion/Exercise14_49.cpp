/*
 *为上一题的类写bool类型转换运算符（先不管是否合理）以 Screen 为例：
 */

struct Screen
{
    public:
    explicit operator bool()const{
        return data != nullptr;
    }

    private:
    char* data;
    unsigned height, width;
};
