#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <bitset>
#include <fstream>
#include <ctime>
#include <typeinfo>
#include <iomanip>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
#include <map>

#define CharCount 256
#define LL long long
#define ls nod<<1
#define rs (nod<<1)+1
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)


const double eps = 1e-8;
const int N = 2e6 + 10;
const LL MOD = 1e9 + 7;
const int mlog=20;
const int maxn = 1e5 + 10;

int sgn(double a) { return a < -eps ? -1 : a < eps ? 0 : 1; }

using namespace std;

struct node {
    int xpos,ypos;
}P[1010];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> P[i].xpos >> P[i].ypos;
    }
    int x = P[m].xpos,y = P[m].ypos;
    int id = 0;
    int Min = INF;
    bool fl = false;
    for (int i = 1;i <= n;i++) {
        if (i == m)
            continue;
        if (P[i].xpos >= x && P[i].ypos >= y) {
            if (P[i].ypos < Min) {
                Min = P[i].ypos;
                id = i;
                fl = true;
            }
        }
    }
    if (fl) {
        cout << id << endl;
        return 0;
    }
    Min = -INF;
    for (int i = 1;i <= n;i++) {
        if (i == m)
            continue;
        if (P[i].xpos <= x && P[i].ypos >= y) {
            if (P[i].xpos > Min) {
                Min = P[i].xpos;
                id = i;
                fl = true;
            }
        }
    }
    if (fl) {
        cout << id << endl;
        return 0;
    }
    Min = -INF;
    for (int i = 1;i <= n;i++) {
        if (i == m)
            continue;
        if (P[i].xpos <= x && P[i].ypos <= y) {
            if (P[i].ypos > Min) {
                Min = P[i].ypos;
                id = i;
                fl = true;
            }
        }
    }
    if (fl) {
        cout << id << endl;
        return 0;
    }
    Min = INF;
    for (int i = 1;i <= n;i++) {
        if (i == m)
            continue;
        if (P[i].xpos >= x && P[i].ypos <= y) {
            if (P[i].xpos < Min) {
                Min = P[i].xpos;
                id = i;
                fl = true;
            }
        }
    }
    if (fl) {
        cout << id << endl;
        return 0;
    }
}