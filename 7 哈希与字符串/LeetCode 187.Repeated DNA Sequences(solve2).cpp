#include <stdio.h>

#include <vector>
#include <string>

int g_hash_map[1048576] = {0};

std::string change_int_to_DNA(int DNA){
	static const char DNA_CHAR[] = {'A', 'C', 'G', 'T'};
	std::string str;		    	
	for (int i = 0; i < 10; i++){
		str += DNA_CHAR[DNA & 3];
		DNA = DNA >> 2;
	}
	return str;
}

class Solution {
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    	std::vector<std::string> result;
		if (s.length() < 10){
	    	return result;
	    }
	    for (int i = 0; i < 1048576; i++){
	    	g_hash_map[i] = 0;
	    }	    
    	int char_map[128] = {0};
    	char_map['A'] = 0;
    	char_map['C'] = 1;
    	char_map['G'] = 2;
    	char_map['T'] = 3;    	
    	int key = 0;
    	for (int i = 9; i >= 0; i--){
	    	key = (key << 2) + char_map[s[i]];
	    }
    	g_hash_map[key] = 1;
    	for (int i = 10; i < s.length(); i++){
    		key = key >> 2;
    		key = key | (char_map[s[i]] << 18);
			g_hash_map[key]++;
	    }
	    for (int i = 0; i < 1048576; i++){
    		if (g_hash_map[i] > 1){
	    		result.push_back(change_int_to_DNA(i));
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
