#include <stdio.h>

#include <string>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
    	int begin = 0;
    	int result = 0;
    	std::string word = "";
    	int char_map[128] = {0};
    	for (int i = 0; i < s.length(); i++){
    		char_map[s[i]]++;
    		if (char_map[s[i]] == 1){
		    	word += s[i];
		    	if (result < word.length()){
	    			result = word.length();
	    		}
		    }
		    else{
    			while(begin < i && char_map[s[i]] > 1){
					//将hash中记录的之前的字符串出现的次数全部减1是为了重新统计
    				char_map[s[begin]]--;//这个不是很明白？
		    		begin++;
		    	}
		    	word = "";
		    	for (int j = begin; j <= i; j++){
	    			word += s[j];
	    		}
    		}
	    }
    	return result;
    }
};

int main(){
	std::string s = "abcbadab";
	Solution solve;
	printf("%d\n", solve.lengthOfLongestSubstring(s));	
	return 0;
}
