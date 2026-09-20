/*
练习 4.22
需求：成绩分级
>=90：high pass
75 ~ 89：pass
60 ~74：low pass
<60：fail
版本 1：只用条件运算符（右结合嵌套）
string grade = (score >=90) ? "high pass"
             : (score >=75) ? "pass"
             : (score >=60) ? "low pass"
             : "fail";
             
版本 2：使用 if‑else 语句
string grade;
if (score >= 90)
    grade = "high pass";
else if (score >=75)
    grade = "pass";
else if (score >=60)
    grade = "low pass";
else
    grade = "fail";
哪个更容易理解：if‑else 版本可读性更好。原因：多层嵌套条件运算符阅读困难；条件运算符适合简单二选一；分支多的时候 if‑else 逻辑更直观，便于阅读调试。

*/