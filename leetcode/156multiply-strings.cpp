题目描述


Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative. 


//solution
vector<int> make_bigint(string const& repr){
    vector<int> n;
    transform(repr.rbegin(), repr.rend(), back_inserter(n),
             [](char c) {return c - '0';});
    return n;
}
vector<int> operator*(vector<int> const& x, vector<int> const& y){
    vector<int> z(x.size() + y.size());
    for(size_t i = 0; i < x.size(); i++){
        for(size_t j = 0; j < y.size(); j++){
            z[i+j] += x[i] * y[j];
            z[i+j+1] += z[i+j] / 10;
            z[i+j] = z[i+j] % 10;
        }
    }
    return z;
}
string to_string(vector<int> const& num){
    string str;
    transform(find_if(num.rbegin(),prev(num.rend()),
              [](char c) {return c > '\0';}), num.rend(),
             back_inserter(str), [](char c) {return c+'0';});
    return str;
}

class Solution {
public:
    //时间复杂度Ｏ(m*n),空间复杂度Ｏ(m+n)
    string multiply(string num1, string num2) {
        return to_string(make_bigint(num1)*make_bigint(num2));
    }   
};
