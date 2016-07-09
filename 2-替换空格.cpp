题目描述

请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。 

class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length <= 0)
            return;
        int originalLength = 0;
        int numberOfSpace = 0;
        int i=0;
        while(str[i] != '\0'){
            ++ originalLength;
            if(str[i]==' ')
                ++ numberOfSpace;
            ++i;
        }
        int newLength = originalLength + 2*numberOfSpace;
        if(newLength > length)
            return;
        int originalIndex = originalLength;
        int newIndex = newLength;
        while(originalIndex >= 0 && newIndex > originalIndex){
            if(str[originalIndex] == ' '){
                str[newIndex--] = '0';
                str[newIndex--] = '2';
                str[newIndex--] = '%';
            }
            else
                str[newIndex--] = str[originalIndex];
            --originalIndex;
        }
	}
};
