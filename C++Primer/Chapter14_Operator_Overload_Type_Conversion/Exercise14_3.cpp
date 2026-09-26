/*
 *判断每个表达式使用哪个 ==
 svec1、svec2 是 vector<string>
 
 (a) "cobble" == "stone"
 字符串字面量，两个const char[6]，内置指针比较。比较两个字符数组首地址，不是比较字符串内容。
 内置 ==，比较指针值。
 (b) svec1[0] == svec2[0]svec1[0]是string对象，调用std::string重载的operator==，比较字符串内容。
 (c) svec1 == svec2vector<string>重载的operator==，依次比较 vector 里每个元素是否相等。
 (d) svec1[0] == "stone"string重载的operator==，string和const char*比较，比较字符串内容。
 */

