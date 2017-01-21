
小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
你能帮帮小Q吗？ 

#include<iostream>
#include<string>
using namespace std;
 
int main(){
    string s;
    while(cin >> s){
        int len = s.size();
        int lower = 0;
        int upper = 0;
        for(int i = 0; i < len; i++){
            if(s[i] >= 'a' && s[i] <= 'z') ++lower;
            else if(s[i] >= 'A' && s[i] <= 'Z') ++upper;
        }
        for(int i = len-1; i >= lower; i--){
            for(int j = 0; j <= i; j++){
                if(s[j] >= 'A' && s[j] <= 'Z' && s[j+1] >= 'a' && s[j+1] <= 'z'){
                    char t = s[j];
                    s[j] = s[j+1];
                    s[j+1] = t;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
