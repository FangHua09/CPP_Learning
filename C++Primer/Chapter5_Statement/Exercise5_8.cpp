/*
什么是悬垂 else？C++ 如何处理 else？
悬垂 else（dangling else）：当 if 嵌套，else没有明确对应哪一个if，产生阅读歧义。
C++ 规则：else 总是和离它最近的、尚未配对的内层 if 匹配。

示例：
if (a)
    if(b)
        cout << "b";
else
    cout << "a false";
阅读上容易以为 else 属于外层if(a)；但语法上，这个else属于内层if(b)。
解决悬垂 else：用花括号{}显式限定 if 范围，强制配对关系。
if (a)
{
    if(b)
        cout << "b";
}
else
{
    cout << "a false";
}

*/