

对于一个字符串，请设计一个算法，将字符串的长度为len的前缀平移到字符串的最后。

给定一个字符串A和它的长度，同时给定len，请返回平移后的字符串。
测试样例：

"ABCDE",5,3

返回："DEABC"


class Translation {
public:
    void reverse(string &A, int from, int to){
        while(from < to){
            char tmp = A[from];
            A[from++] = A[to];
            A[to--] = tmp;
        }
    }
    string stringTranslation(string A, int n, int len) {
        // write code here
        len %= n;
        reverse(A, 0, len-1);
        reverse(A, len, n-1);
        reverse(A, 0, n-1);
        return A;
    }
};
