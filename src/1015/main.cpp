#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

vector<int> compute(string p);
int kmp(string, string);

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        string a;
        string p;
        cin >> p;
        cin >> a;
        cout << kmp(a,p) << endl;
    }
    return 0;
}

vector<int> compute(string p) {
    int pl = p.length();
    vector<int> next(pl+1, 0);
    for (int i = 1; i < pl; i++) {
        int j = i;
        while (j > 0) {
            j = next[j];
            if (p[j] == p[i]) {
                next[i+1] = j + 1;
                break;
            }
        }
    }
    return next;
}

int kmp(string a, string p) {
    int ans = 0;
    int al = a.length();
    int pl = p.length();
    vector<int> next;
    next = compute(p);

    for (int i = 0, j = 0; i < al; i++) {
        if (j < pl && a[i] == p[j]) j++;
        else {
            while (j > 0) {
                j = next[j];
                if (a[i] == p[j]) {
                    j++;
                    break;
                }
            }
        }
        if (j == pl) ans++;
    }
    return ans;
}
