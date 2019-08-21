#include <stdio.h>

#include <vector>
#include <string>
#include <map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(
			std::vector<std::string>& strs) {
		std::map<std::string, std::vector<std::string> > anagram;
		std::vector<std::vector<std::string> > result;		
		for (int i = 0; i < strs.size(); i++){
			std::string str = strs[i];
			std::sort(str.begin(), str.end());
			if (anagram.find(str) == anagram.end()){
				std::vector<std::string> item;
				anagram[str] = item;
			}
			anagram[str].push_back(strs[i]);
		}
		std::map<std::string, std::vector<std::string> > ::iterator it;
		for (it = anagram.begin(); it != anagram.end(); it++){
			result.push_back((*it).second);
		}
    	return result;
    }
};

int main(){
	std::vector<std::string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	Solution solve;
	std::vector<std::vector<std::string> > result 
		= solve.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}	
	return 0;
}
