#include <stdio.h>

#include <vector>
#include <algorithm>
#include <queue>

bool cmp(const std::pair<int, int> &a, const std::pair<int ,int> &b) {
    return a.first > b.first;
}

int get_minimum_stop(int L, int P, std::vector<std::pair<int, int> > &stop){
	std::priority_queue<int> Q;
	int result = 0;
	stop.push_back(std::make_pair(0, 0));
	std::sort(stop.begin(), stop.end(), cmp);
	for (int i = 0; i < stop.size(); i++){
		int dis = L - stop[i].first;
		while (!Q.empty() && P < dis){
			P += Q.top();
			Q.pop();
			result++;
		}
		if (Q.empty() && P < dis){
			return -1;
		}
		P = P - dis;
		L = stop[i].first;
		Q.push(stop[i].second);
	}
	return result;
}

int main(){
	std::vector<std::pair<int, int> > stop;
	int N;
	int L;
	int P;
	int distance;
	int fuel;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d %d", &distance, &fuel);
		stop.push_back(std::make_pair(distance, fuel));
	}
	scanf("%d %d", &L, &P);
	printf("%d\n", get_minimum_stop(L, P, stop));
	return 0;
}
