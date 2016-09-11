小Q今天在上厕所时想到了这个问题：有n个数，两两组成二元组，差最小的有多少对呢？差最大呢？ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void cacl_pair(vector<int> &data, int n){
    if(n > 1){
        sort(data.begin(), data.end());
        int m1 = 1;
        int m2 = 1;
        for(int i = 0; i < n-1; i++){
            if(data[i] != data[i+1])
                break;
            ++m1;
        }
        for(int i = n-1; i > 0; i--){
            if(data[i] != data[i-1])
                break;
            ++m2;
        }
        int max = m1 * m2;
         
        int min_tmp = data[1] - data[0];
        int min = 0;
        for(int i = 2; i < n; i++)
            if(data[i] - data[i-1] < min_tmp){
                min_tmp = data[i] - data[i-1];
        }
        if(min_tmp == 0){
            for(int i = 1; i < n; i++){
                int j = i-1;
                while(j >= 0 && data[i] == data[j]){
                    ++min;
                    --j;
                }
            }
        }else{
            for(int i = 1; i < n; i++){
                if(data[i] - data[i-1] == min_tmp)
                    ++min;
            }
        }
        cout << min << " " << max << endl;
    }
}
 
int main(){
    int num;
    while(cin >> num){
        int tmp;
        vector<int> data;
        for(int i = 0; i < num; i++){
            cin >> tmp;
            data.push_back(tmp);
        }
        cacl_pair(data, num);
    }
    return 0;
}
