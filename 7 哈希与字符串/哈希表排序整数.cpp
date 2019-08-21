#include <stdio.h>

int main(){
	int random[10] = {999, 1, 444, 7, 20, 9, 1, 3, 7, 7};
	int hash_map[1000] = {0};
	for (int i = 0; i < 10; i++){
		hash_map[random[i]]++;
	}	
	for (int i = 0; i < 1000; i++){
		for (int j = 0; j < hash_map[i]; j++){
			printf("%d\n", i);
		}
	}	
	return 0;
}

