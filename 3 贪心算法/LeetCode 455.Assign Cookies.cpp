#include <stdio.h>

#include <vector>
#include <algorithm>
class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    	std::sort(g.begin(), g.end());
    	std::sort(s.begin(), s.end());
    	int child = 0;
    	int cookie = 0;
    	while(child < g.size() && cookie < s.size()){
	    	if (g[child] <= s[cookie]){
	    		child++;
			}
			cookie++;
	    }
    	return child;
    }
};

int main(){
	Solution solve;
	std::vector<int> g;
	std::vector<int> s;
	g.push_back(5);
	g.push_back(10);
	g.push_back(2);
	g.push_back(9);
	g.push_back(15);
	g.push_back(9);
	s.push_back(6);
	s.push_back(1);
	s.push_back(20);
	s.push_back(3);
	s.push_back(8);	
	printf("%d\n", solve.findContentChildren(g, s));
	return 0;
}
