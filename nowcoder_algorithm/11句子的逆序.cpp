

对于一个字符串，请设计一个算法，只在字符串的单词间做逆序调整，也就是说，字符串由一些由空格分隔的部分组成，你需要将这些部分逆序。

给定一个原字符串A和他的长度，请返回逆序后的字符串。
测试样例：

"dog loves pig",13

返回："pig loves dog"


class Reverse {
public:
    void reverseWord(string &A, int from, int to){
        while(from < to){
            char tmp = A[from];
            A[from++] = A[to];
            A[to--] = tmp;
        }
    }
    string reverseSentence(string A, int n) {
        // write code here
        int begin = 0;
        int end = n - 1;
        for(int i = 0; i < n; i++){
            if(A[i] == ' '){
                reverseWord(A, begin, i-1);
                begin = i + 1;
            }
        }
        reverseWord(A, begin, end);
        reverseWord(A, 0, end);
        return A;
    }
};
