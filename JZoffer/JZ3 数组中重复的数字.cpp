    //map和set的时间复杂度和空间复杂度都是O(n);
    //map版本
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param numbers int整型vector 
         * @return int整型
         */
        int duplicate(vector<int>& numbers) {
            unordered_map<int, int> m;
            for(int i = 0; i < numbers.size(); i++){
                m[numbers[i]]++;
                if (m[numbers[i]] > 1)
                    return numbers[i];
            }
                return -1;
        }

    };

//set版本
    class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param numbers int整型vector 
         * @return int整型
         */
        int duplicate(vector<int>& numbers) {
            set<int> s;
            for(int i = 0; i < numbers.size(); i++){
                //判断元素是否有存在
                if (s.count(numbers[i]) > 0){
                    return numbers[i];
                }else {
                    s.insert(numbers[i]);
                }   
            }
            return -1;
        }
    };
//go版本
package main

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param numbers int整型一维数组 
 * @return int整型
*/
func duplicate( numbers []int ) int {
    // write code here
    m := make(map[int]int)
    for _, v := range numbers {
        //判断map中是否存在这个数，如果存在，输出v的值
        if _,ok :=m[v]; ok {
            return v
        }else{
            m[v]++
        }
    }
    return -1
}






