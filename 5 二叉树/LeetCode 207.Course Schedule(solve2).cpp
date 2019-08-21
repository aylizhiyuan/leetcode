#include <stdio.h>

#include <vector>
#include <queue>

struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};

class Solution {
public:
    bool canFinish(int numCourses,
		std::vector<std::pair<int, int> >& prerequisites) {
		std::vector<GraphNode*> graph;
		std::vector<int> degree;
		for (int i = 0; i < numCourses; i++){
			degree.push_back(0);
			graph.push_back(new GraphNode(i));
		}
		for (int i = 0; i < prerequisites.size(); i++){
			GraphNode *begin = graph[prerequisites[i].second];
			GraphNode *end = graph[prerequisites[i].first];
			begin->neighbors.push_back(end);
			degree[prerequisites[i].first]++;
		}		
		std::queue<GraphNode *> Q;
		for (int i = 0; i < numCourses; i++){
			if (degree[i] == 0){
				Q.push(graph[i]);
			}
		}
		while(!Q.empty()){
			GraphNode *node = Q.front();
			Q.pop();
			for (int i = 0; i < node->neighbors.size(); i++){
				degree[node->neighbors[i]->label]--;
				if (degree[node->neighbors[i]->label] == 0){
					Q.push(node->neighbors[i]);
				}
			}
		}		
		for (int i = 0; i < graph.size(); i++){
			delete graph[i];
		}		
		for (int i = 0; i < degree.size(); i++){
			if (degree[i]){
				return false;
			}
		}
		return true;
    }
};

int main(){	
	std::vector<std::pair<int, int> > prerequisites;
	prerequisites.push_back(std::make_pair(1, 0));
	prerequisites.push_back(std::make_pair(2, 0));
	prerequisites.push_back(std::make_pair(3, 1));
	prerequisites.push_back(std::make_pair(3, 2));
	Solution solve;
	printf("%d\n", solve.canFinish(4, prerequisites));	
	return 0;
}
