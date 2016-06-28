题目描述

There are N gas stations along a circular route, where the amount of gas at station i isgas[i]. 

You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station (i+1
You begin the journey with an empty tank at one of the gas stations. 

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1. 

Note: 
 The solution is guaranteed to be unique. 

使用两个变量，分别判断当前的有效性和整个数组的有效性，整个有效则返回下标
时间复杂度O（n）,空间复杂度O（1）
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int index = -1;
        int total = 0;
        for(int i = 0, sum = 0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            
            if(sum < 0){
                index = i;
                sum = 0;
            }
        }
        return total >= 0 ? index + 1 : -1;
    }
};
