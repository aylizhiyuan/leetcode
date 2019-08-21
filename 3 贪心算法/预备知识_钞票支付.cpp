#include <stdio.h>

int main(){
	const int RMB[] = {100, 50, 20, 10, 5, 2, 1};
	const int NUM = 7;
	int X = 628;
	int count = 0;
	for (int i = 0; i < NUM; i++){
		int use = X / RMB[i];
		count += use;
		X = X - RMB[i] * use;
		printf("需要面额为%d的%d张, ", RMB[i], use);
		printf("剩余需要支付RMB %d.\n", X);
	}
	printf("总共需要%d张RMB\n", count);
	return 0;
}

