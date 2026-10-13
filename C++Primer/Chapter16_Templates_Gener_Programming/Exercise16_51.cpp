/*教材 16.4 节 foo 的定义（递归可变参数模板）
 *

 ✅练习 16.51：计算每一组的 sizeof...(Args) / sizeof...(rest)
 foo(i, s, 42, d);实参列表：i（绑定 T），剩下s,42,d → 3 个sizeof...(Args)=3，sizeof...(rest)=3
 foo(s,42,"hi");s绑定 T；剩下42,"hi" →2 个sizeof...(Args)=2，sizeof...(rest)=2
 foo(d,s);d绑定 T；剩下s →1 个sizeof...(Args)=1，sizeof...(rest)=1
 foo("hi");"hi"绑定 T；没有剩余参数sizeof...(Args)=0，sizeof...(rest)=0
 foo(i, s, s, d);i绑定 T；剩下s,s,d →3 个sizeof...(Args)=3，sizeof...(rest)=3
 一句话要点：Args 和 rest 的大小永远相等，Args是类型包，rest是对应的函数参数包；第一个参数不计入包内。
 */
