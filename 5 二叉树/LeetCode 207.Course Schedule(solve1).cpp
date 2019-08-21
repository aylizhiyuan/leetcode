#include <stdio.h>

#include <vector>
struct GraphNode{
	int label;
	std::vector<GraphNode *> neighbors;
	GraphNode(int x) : label(x) {};
};
bool DFS_graph(GraphNode *node, std::vector<int> &visit){
	visit[node->label] = 0;
	for (int i = 0; i < node->neighbors.size(); i++){
		if (visit[node->neighbors[i]->label] == -1){
			if (DFS_graph(node->neighbors[i], visit) == 0){
				return false;
			}
		}
		else if (visit[node->neighbors[i]->label] == 0){
			return false;
		}
	}
	visit[node->label] = 1;
	return true;
}

class Solution {
public:
    bool canFinish(int numCourses,
		std::vector<std::pair<int, int> >& prerequisites) {
		std::vector<GraphNode*> graph;
		std::vector<int> visit;
		for (int i = 0; i < numCourses; i++){
			graph.push_back(new GraphNode(i));
			visit.push_back(-1);
		}
		for (int i = 0; i < prerequisites.size(); i++){
			GraphNode *begin = graph[prerequisites[i].second];
			GraphNode *end = graph[prerequisites[i].first];
			begin->neighbors.push_back(end);
		}
		for (int i = 0; i < graph.size(); i++){
			if (visit[i] == -1 && !DFS_graph(graph[i], visit)){
				return false;
			}
		}
		for (int i = 0; i < numCourses; i++){
			delete graph[i];
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
