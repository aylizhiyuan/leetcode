#include <stdio.h>

#include <vector>
#include <string>
#include <map>

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    	std::map<std::string, int> word_map;
    	std::vector<std::string> result;
    	for (int i = 0; i < s.length(); i++){
    		std::string word = s.substr(i, 10);
	    	if (word_map.find(word) != word_map.end()){
	    		word_map[word] += 1;
	    	}
	    	else{
	    		word_map[word] = 1;
	    	}
	    }
	    std::map<std::string, int> ::iterator it;
	    for (it = word_map.begin(); it != word_map.end(); it++){
    		if (it->second > 1){
		    	result.push_back(it->first);
		    }
    	}
    	return result;
    }
};

int main(){
	std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution solve;
	std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
	for (int i = 0; i < result.size(); i++){
		printf("%s\n", result[i].c_str());
	}
	return 0;
}
