#include <stdio.h>
#include <string>
#include <map>
class Solution {
    public: 
        bool wordPattern(std::string pattern,std::string str){
            std::map<std::string,char> word_map;
            char used[128] = {0};
            std::string word;
            int pos = 0;
            str.push_back(' ');
            for(int i=0;i<str.length();i++){
                if(str[i] == ' '){
                    // pattern到末尾了
                    if(pos == pattern.length()){
                        return false;
                    }
                    //如果word未出现过，则放入哈希表中
                    if(word_map.find(word) == word_map.end()){
                        //如果该单词的pattern已经使用过了
                        if(used[pattern[pos]]){
                            return false;
                        }
                        word_map[word] = pattern[pos];
                        used[pattern[pos]] = 1;
                    }else{
                        //如果word已经出现过了，判断是否等于pattern
                        if(word_map[word] != pattern[pos]){
                            return false;
                        }
                    }
                    //完成一个单词的插入和查询后，清空word
                    //指向pattern的字符pos指针后移
                    word = "";
                    pos++;
                }else{
                    word += str[i];
                }
            }
            if(pos != pattern.length()){
                return false;
            }
            return true;
        }
};
int main(){
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    Solution solve;
    printf("%d\n",solve.wordPattern(pattern,str));
    return 0;
}