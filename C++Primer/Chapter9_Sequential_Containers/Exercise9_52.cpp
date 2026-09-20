/*
使用 stack 处理括号化的表达式。
当你看到一个左括号，将其记录下来。
当你在一个左括号之后看到一个右括号，从 stack 中 pop 对象，直至遇到左括号，将左括号也一起弹出栈。
然后将一个值（括号内的运算结果）push 到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// 执行一次二元运算
int calc(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b != 0 ? a / b : 0;
    default:
        return 0;
    }
}

int evaluate(const string &expr)
{
    stack<int> num_stack; // 操作数栈
    stack<char> op_stack; // 运算符栈，存放运算符和左括号标记
    for (auto &&i : expr)
    {
        if(i == '(') {
            op_stack.push('(');
        }
    }
    
}

int main()
{
    string expr1 = "(1+2)*(3+4)";
    string expr2 = "((2+3)*4)-5";
    string expr3 = "10+(2*3)-(6/2)";

    cout << expr1 << " = " << evaluate(expr1) << endl;
    cout << expr2 << " = " << evaluate(expr2) << endl;
    cout << expr3 << " = " << evaluate(expr3) << endl;
    return 0;
}
