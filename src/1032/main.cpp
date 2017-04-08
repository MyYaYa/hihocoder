#include <cstdio>
#include <cstring>

using namespace std;

#define MAX 10000

int palindrome(char* str);

int main() {
        int num;
        scanf("%d", &num);
        char str[MAX]={0};
        for (int i = 0; i < num; ++i) {
                scanf("%s", str);
                printf("%d\n", palindrome(str));
        }
        return 0;
}

int palindrome(char* str) {
        int len = strlen(str);
        int len1 = len*2+1;
        int pos=0, maxRight=0;
        int maxLen=0;
        char str1[len1];
        for (int i = 0; i < len; ++i) {
                str1[2*i] = '#';
                str1[2*i+1] = str[i];
        }
        str1[2*len] = '#';
        int p[len1];
        for (int i = 0; i < len1; ++i) {
                if (i < maxRight) {
                        if (p[2*pos-i] < maxRight-i) {
                                p[i] = p[2*pos-i];
                        } else {
                                p[i] = maxRight - i;
                        }
                } else {
                        p[i] = 1;
                }
                while (i-p[i] >= 0 && i+p[i] < len1 && str1[i-p[i]]==str1[i+p[i]]) {
                        p[i] += 1;
                }
                if (i+p[i]-1 > maxRight) {
                        maxRight = i+p[i]-1;
                        pos = i;
                }
                if (p[i]-1 > maxLen) {
                        maxLen = p[i] - 1;
                }
        }
        return maxLen;
}