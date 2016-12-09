题目描述

Implement strStr(). 

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack. 

时间复杂度O（m+n）,空间复杂度O（n）
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!*needle) return (char*) haystack; 
        int next[1025];
        int position;
        GetNext(needle, next);
        position = KMP(haystack, needle, next);
        if(position == -1) return NULL;
        else return (char*)(haystack+position);
    }
private:
    void GetNext(char *p, int next[]){
        int plen = strlen(p);
        int k = -1;
        next[0] = -1;
        int j = 0;
        while(j < plen-1){
            if(k==-1 || p[j]==p[k]){
                j++;
                k++;
                if(p[j]==p[k])
                    next[j] = next[k];
                else
                    next[j] = k;
            }else{
                k = next[k];
            }
        }
    }
    
    int KMP(char *s, char *p, int next[]){
        int result = -1;
        int slen = strlen(s);
        int plen = strlen(p);
        int i=0,j=0;
        while(i < slen){
            if(j == -1 || s[i] == p[j]){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
            if(j == plen){
                result = i - plen;
                break;
            }
        }
        return result;
    }
};
