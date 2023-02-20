/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
 

提示：

1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    bool isValid(string s) {
         if (s.size() % 2 != 0) return false;
         stack<char> stk;
         //const char &防深拷贝，foreach循环不用考虑越界
         for(const auto &i : s){
             if(i == '(' || i == '[' || i == '{'){
                 stk.push(i);
             }else if(!stk.empty() && ((i == ')' && stk.top() == '(')
                                   || (i ==']' && stk.top() == '[')
                                   || (i =='}' && stk.top() == '{'))){
                                    stk.pop();
             } else{
                    return false;
             }
         }
         return stk.empty();
    }
};