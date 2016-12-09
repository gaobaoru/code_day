题目描述


Implementint sqrt(int x).

Compute and return the square root of x. 

class Solution {
public:
    //时间复杂度O(logn),空间复杂度O(1)
    int sqrt(int x) {
        int left = 1, right = x / 2;
        int last_mid;
        
        if(x < 2) return x;
        while(left <= right){
            int mid = (left + right) / 2;
            if(x / mid > mid){
                left = mid + 1;
                last_mid = mid;
            }else if(x / mid < mid){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return last_mid;
    }
};
