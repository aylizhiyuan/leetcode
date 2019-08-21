
#include <stdio.h>
#include <string>
#include <vector>

bool is_window_ok(int map_s[], int map_t[], std::vector<int> &vec_t){
	for (int i = 0; i < vec_t.size(); i++){
		if (map_s[vec_t[i]] < map_t[vec_t[i]]){
			return false;
		}
	}
	return true;
}

int main(){
	std::string s = "ADOBECODEBANC";
	std::string t = "ABCDAB";
	const int MAX_ARRAY_LEN = 128;
	int map_t[MAX_ARRAY_LEN] = {0};
 	int map_s[MAX_ARRAY_LEN] = {0};
 	std::vector<int> vec_t;
 	
 	for (int i = 0; i < s.length(); i++){
 		map_s[s[i]]++;
   	}
 	for (int i = 0; i < t.length(); i++){
 		map_t[t[i]]++;
   	}
   	for (int i = 0; i < MAX_ARRAY_LEN; i++){
   		if (map_t[i] > 0){
    		vec_t.push_back(i);
      	}
  	}
  	
  	printf("String S %s 's char number:\n", s.c_str());
  	for (int i = 0; i < MAX_ARRAY_LEN; i++){
	  	if (map_s[i]>0){
	  		printf("%c : %d\n", i, map_s[i]);
	  	}
  	}
  	printf("String T %s 's char number:\n", t.c_str());
  	for (int i = 0; i < MAX_ARRAY_LEN; i++){
	  	if (map_t[i]>0){
	  		printf("%c : %d\n", i, map_t[i]);
	  	}
  	}
  	printf("String T %s 's char:\n", t.c_str());
  	for(int i = 0; i < vec_t.size(); i++){
		printf("%c\n",vec_t[i]);  	
  	}	
	printf("is_window_ok = %d\n", is_window_ok(map_s, map_t, vec_t));	
	return 0;
}

