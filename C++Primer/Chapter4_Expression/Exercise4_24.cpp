/*
条件运算符实际是右结合：cond1 ? expr1 : cond2 ? expr2 : expr3等价：cond1 ? expr1 : ( cond2 ? expr2 : expr3 )求值：先判断cond1；cond1 假，再计算右边整个嵌套条件。
如果条件运算符是左结合，表达式就变成：(cond1 ? expr1 : cond2 ) ? expr2 : expr3
以成绩分级例子：
plaintext
score >=90 ? "high pass" : score >=75 ? "pass" : score >=60 ? "low pass" : "fail";

左结合下分组：
plaintext
((score>=90) ? "high pass" : (score>=75)) ? "pass" : ((score>=60) ? "low pass" : "fail");
求值过程：
先算最左边score>=90 ? "high pass" : score>=75，得到字符串或者布尔值；
将上一步结果作为新条件，判断真假，再选"pass"或者后面结果。
结果完全错误：不再是依次判断分数，而是拿字符串 / 布尔值做条件判断，分级逻辑彻底失效。
总结：条件运算符必须右结合，多分支嵌套才可以正常工作。
*/