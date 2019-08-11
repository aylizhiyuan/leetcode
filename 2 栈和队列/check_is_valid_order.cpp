#include <stack>
#include <stdio.h>
#include <queue>
bool check_is_valid_order(std::queue<int> &order){
    std::stack<int> S;
    int n = order.size();
    for(int i=1;i<=n;i++){
        S.push(i);
        while(!S.empty() && order.front() == S.top()){
            S.top();
            order.pop();
        }
    }
    if(!S.empty()){
        return false;
    }
    return true;
}
int main(){
    int n;
    int train;
    scanf("%d",&n);
    while(n){
        scanf("%d",&train);
        while(train){
            std::queue<int> order;
            order.push(train);
            for(int i=1;i<n;i++){
                scanf("%d",&train);
                order.push(train);
            }
            if(check_is_valid_order(order)){
                printf("yes");
            }else{
                printf("no");
            }
            scanf("%d",&train);
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}