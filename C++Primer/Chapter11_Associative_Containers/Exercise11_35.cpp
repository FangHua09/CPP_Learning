/*
题目描述：在buildMap中：
trans_map[key] = value.substr(1);

改为
trans_map.insert({key, value.substr(1)});
会有什么效果？知识点：map[]：key 存在就覆盖旧值；insert：key 已经存在则不做任何操作，不会覆盖。
*/
