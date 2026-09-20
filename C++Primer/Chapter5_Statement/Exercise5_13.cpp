/*
找出 switch 代码错误并修改

(a)
原代码
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++;
    case 'e': eCnt++;
    default: iouCnt++;
}
错误：缺少break;，发生 case 穿透。匹配case 'a'之后会顺序执行 a、e、default 三条；匹配case 'e'会执行 e、default。
修正：每个 case 末尾加 break
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++; break;
    case 'e': eCnt++; break;
    default: iouCnt++; break;
}

(b)
unsigned index = some_value();
switch (index) {
    case 1:
        int ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
}
错误：ix定义在 case1 分支内，作用域仅限于 case1。default 分支使用ix，访问不到，编译报错。
switch 的花括号是整个 switch 块，case 只是标签，不会新建作用域。
修正：把ix定义移到 switch 外面
unsigned index = some_value();
int ix;
switch (index) {
    case 1:
        ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size()-1;
        ivec[ ix ] = index;
}

(c)
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}
错误 1：case 不能用逗号写多个常量。case 1,3,5,7,9:等价于case 9:，逗号运算符丢弃前面值。多个 case 要分开写标签。错误 2：变量名大小写不一致：oddCnt vs oddcnt；evenCnt vs evencnt，C++ 大小写敏感。错误 3：digit 是%10结果，取值只能 0‑9，不可能等于 10。
修正：
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 9:
        oddCnt++;
        break;
    case 2:
    case 4:
    case 6:
    case 8:
        evenCnt++;
        break;
    case 0:
        // 0是偶数，不要漏掉
        evenCnt++;
        break;
}

(d) 题目截图没贴完整，典型考点：
switch 的case标签必须是整型常量表达式，不能用变量。
unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:   // ❌错误！ival是变量，case标签不能是变量
        // ...
        break;
    case jval:   // ❌变量
        // ...
        break;
    case kval:   // ❌变量
        // ...
        break;
}
case 后面只能是字面量、const 整型常量，不能是普通变量。改用 if‑else‑if 链实现。
*/