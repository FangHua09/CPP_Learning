/*
【题目描述】：说明表达式含义
double slope = static_cast<double>(j / i);

【解答】⚠️注意优先级：括号只作用于j，不是(j/i)整体转 double。
j和i都为 int 类型；先执行 j / i，整数除法，直接舍弃小数部分。
将整数除法得到的 int 结果，强制转换为double类型，赋值给slope。
*/