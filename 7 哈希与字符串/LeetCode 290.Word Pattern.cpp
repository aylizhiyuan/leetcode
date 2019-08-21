#include <stdio.h>

#include <string>
#include <map>
class Solution {
public:
    bool wordPattern(std::string pattern, std::string str) {
    	std::map<std::string, char> word_map;
    	char used[128] = {0};
    	std::string word;
    	int pos = 0;
    	str.push_back(' ');
    	for (int i = 0; i < str.length(); i++){
	    	if (str[i] == ' '){
	    		if (pos == pattern.length()){
	    			return false;
		    	}
	    		if (word_map.find(word) == word_map.end()){
	    			if (used[pattern[pos]]){
			    		return false;
			    	}
		    		word_map[word] = pattern[pos];
		    		used[pattern[pos]] = 1;
		    	}
		    	else{
	    			if (word_map[word] != pattern[pos]){
			    		return false;
			    	}
	    		}
	    		word = "";
	    		pos++;
	    	}
	    	else{
	    		word += str[i];
	    	}
	    }
	    if (pos != pattern.length()){
    		return false;
    	}
        return true;
    }
};

int main(){
	std::string pattern = "abba";
	std::string str = "dog cat cat dog";
	Solution solve;
	printf("%d\n", solve.wordPattern(pattern, str));
	return 0;
}
