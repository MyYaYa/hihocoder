#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct TrieNode {
    char c;
    int cnt;
    TrieNode* next[26];
    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 26; ++i) {
            next[i] = NULL;
        }
    }
};

TrieNode root;

void insertWord(char* str) {
    int len = strlen(str);
    TrieNode *head = &root;
    for (int i = 0; i < len; ++i) {
        int idx = str[i] - 'a';
        if (head->next[idx] == NULL) {
            TrieNode *node = new TrieNode;
            node->c = str[i];
            head->next[idx] = node;
        }
        head = head->next[idx];
        head->cnt ++;
    }
}

int queryWord(char *str) {
    TrieNode *head = &root;
    int len = strlen(str);
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        int idx = str[i] - 'a';
        if (head->next[idx] == NULL) return 0;
        else {
            head = head->next[idx];
        }
    }
    return head->cnt;
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; ++i) {
        char str[10];
        scanf("%s", str);
        insertWord(str);
    }
    int queryNum;
    scanf("%d", &queryNum);
    for (int j = 0; j <queryNum; ++j) {
        char str[10];
        scanf("%s", str);
        int res = queryWord(str);
        printf("%d\n", res);
    }
    return 0;
}