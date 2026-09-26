/*
 *Sales_data 输入格式预期：bookNo units_sold price
 (a) 0-201-99999-9 10 24.95
 顺序完全匹配：bookNo=0-201-99999-9，units_sold=10，price=24.95。
 ✅ 正常读取，revenue = 10 * 24.95 = 249.5。
 (b) 10 24.95 0-210-99999-9
 读取顺序：
 item.bookNo读入字符串"10"
 item.units_sold尝试读取24.95 → unsigned无法解析小数，istream 进入 fail 状态
 流失败，item被重置为空 Sales_data 对象。
 小结：(a) 正常读取；(b) 类型不匹配，输入失败，对象清空。
 */

