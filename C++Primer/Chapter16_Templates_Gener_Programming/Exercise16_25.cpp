/*
 *练习 16.25
 extern template class vector<string>;
 template class vector<Sales_data>;
 
 extern template class vector<string>;
 外部模板声明（显式实例化声明）
 告诉编译器：vector<string> 的实例化版本在其他源文件中已经完成，本文件不要实例化它，直接使用别处已经生成的代码。作用：避免在多个.cpp重复实例化，减少编译开销。
 
 template class vector<Sales_data>;
 显式实例化定义
 强制编译器在当前文件实例化vector<Sales_data>这个完整类模板，生成全部成员函数的代码。不管成员有没有被使用，全部实例化。
 一句话区分：extern template：不实例化，声明实例在外部template class：强制在当前文件实例化
 */
