/*
 *要求：实现 Query、Query_base；只写 rep，不实现 eval
 cpp
 #include <iostream>
 #include <memory>
 #include <string>
 using namespace std;
 
 // 抽象基类，只声明rep，eval不需要定义
 class Query_base {
     friend class Query;
 protected:
     virtual ~Query_base() = default;
 private:
     virtual string rep() const = 0;
 };
 
 // 句柄类 Query
 class Query {
     friend Query operator~(const Query&);
     friend Query operator|(const Query&, const Query&);
     friend Query operator&(const Query&, const Query&);
 public:
     Query(const string&);
 private:
     Query(shared_ptr<Query_base> q) : qb(q) {}
     shared_ptr<Query_base> qb;
 public:
     string rep() const { return qb->rep(); }
 };
 
 // WordQuery 派生类
 class WordQuery : public Query_base {
     friend class Query;
     WordQuery(const string& s) : query_word(s) {}
     string rep() const override { return query_word; }
     string query_word;
 };
 inline Query::Query(const string &s) : qb(make_shared<WordQuery>(s)){}
 
 // NotQuery
 class NotQuery : public Query_base {
     friend Query operator~(const Query&);
     NotQuery(const Query& q) : query(q) {}
     string rep() const override { return "~(" + query.rep() + ")"; }
     Query query;
 };
 inline Query operator~(const Query& operand) {
     return shared_ptr<Query_base>(new NotQuery(operand));
 }
 
 // BinaryQuery 基类 AndQuery / OrQuery
 class BinaryQuery : public Query_base {
 protected:
     BinaryQuery(const Query& l, const Query& r, string s) : lhs(l), rhs(r), opSym(s) {}
     string rep() const override {
         return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
     }
     Query lhs, rhs;
     string opSym;
 };
 
 class AndQuery : public BinaryQuery {
     friend Query operator&(const Query&, const Query&);
     AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&") {}
 };
 inline Query operator&(const Query&lhs, const Query&rhs) {
     return shared_ptr<Query_base>(new AndQuery(lhs,rhs));
 }
 
 class OrQuery : public BinaryQuery {
     friend Query operator|(const Query& left, const Query& right) : BinaryQuery(left, right, "|") {}
     OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") {}
 };
 inline Query operator|(const Query&lhs, const Query&rhs) {
     return shared_ptr<Query_base>(new OrQuery(lhs,rhs));
 }
 
 // 输出运算符
 ostream& operator<<(ostream& os, const Query& q) {
     return os << q.rep();
 }
 说明：全部只实现rep()，eval纯虚函数不写实现，满足题目要求。
 */
