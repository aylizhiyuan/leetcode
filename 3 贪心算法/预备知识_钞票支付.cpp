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
		printf("��Ҫ���Ϊ%d��%d��, ", RMB[i], use);
		printf("ʣ����Ҫ֧��RMB %d.\n", X);
	}
	printf("�ܹ���Ҫ%d��RMB\n", count);
	return 0;
}

