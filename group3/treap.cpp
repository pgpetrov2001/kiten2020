#include <iostream>
#include <ctime>
#include <random>
#include <vector>

using std::cout; using std::cin; using std::endl; using std::vector; using std::swap; using std::max; using std::min; using std::pair; using std::flush;

int merge(int, int);

const int MAXN = 2e5;

int left[MAXN+1], right[MAXN+1], prior[MAXN+1], value[MAXN+1];

pair<int,int> split(int v, int val) {
    if (!v) {
        return {0,0};
    }
    if (val < value[v]) {
        auto l = split(left[v], val);
        left[v] = l.second;
        return {l.first, v};
    } else {
        auto r = split(right[v], val);
        right[v] = r.first;
        return {v, r.second};
    }
}

int merge(int v1, int v2) {
    if (prior[v2] > prior[v1]) {
        swap(v1, v2);
    }
    if (!v1) {
        return 0;
    }
    if (value[v2] < value[v1]) {
        left[v1] = merge(left[v1], v2);
    } else {
        right[v1] = merge(right[v1], v2);
    }
    return v1;
}

int ROOT;
int LASTIND = 1;
const int MAX = 1e6;
bool taken[MAX];

void insert(int val) {
    int v = LASTIND++;
    value[v] = val;
    while (taken[prior[v] = rand()%MAX]);
    taken[prior[v]] = true;

    auto ret = split(ROOT, value[v]);
    ROOT = merge(merge(v, ret.first), ret.second);
}

void print(int v) {
    if (!v) {
        return;
    }
    cout << value[v]; 
    cout << "(";
    print(left[v]);
    cout << ")";
    cout << "(";
    print(right[v]);
    cout << ")";
}

void print() {
    print(ROOT);
}

bool checkprior(int v) {
    if (!v) {
        return true;
    }
    if (prior[v] < prior[left[v]] || prior[v] < prior[right[v]]) {
        return false;
    }
    return checkprior(left[v]) && checkprior(right[v]);
}

bool checkprior() {
    return checkprior(ROOT);
}

int main() {
    //srand(time(0));
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        insert(x);
    }

    print();
}
