/*
 *练习 16.11：修正 List 定义
 错误点
 ListItem是模板类ListItem<elemType>，代码只写ListItem *ptr，缺少模板参数。
 ListItem本身是模板，不能单独作为类型使用，必须带上<elemType>。
 修正代码
 cpp
 template <typename elemType> class ListItem;
 
 template <typename elemType> class List {
 public:
     List<elemType>();
     List<elemType>(const List<elemType> &);
     List<elemType>& operator=(const List<elemType> &);
     ~List();
     void insert(ListItem<elemType> *ptr, elemType value);
 private:
     ListItem<elemType> *front, *end;
 };
 */
