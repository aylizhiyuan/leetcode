#include <stdio.h>

class MedianFinder {
    public: 
        MedianFinder(){

        }
        void addNum(int num){

        }
        double findMedian(){

        }
};
int main(){
    MedianFinder M;
    M.addNum(2);
    M.addNum(1);
    printf("%lf\n",M.findMedian());
    M.addNum(4);
    printf("%lf\n",M.findMedian());
    M.addNum(3);
    printf("%lf\n",M.findMedian());
    return 0;
}