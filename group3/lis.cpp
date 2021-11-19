#include <iostream>
#include <stack>
#include <climits>

using namespace std;

const int maxn = 1e5;

int arr[maxn];
int lis[maxn];
int prev[maxn+1];

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    arr[n] = INT_MAX;

    for (int i=0; i<=n; i++) {
        lis[i] = 1;
        prev[i] = i;
        for (int j=0; j<i; j++) {
            if (arr[j] <= arr[i] && lis[j]+1 > lis[i]) {
                lis[i] = lis[j]+1;
                prev[i] = j;
            }
        }
    }

    stack<int> seq;
    int curr = prev[n];
    while (prev[curr] != curr) {
        seq.push(curr);
        curr = prev[curr];
    }

    cout << lis[n] << "\n";

    while (seq.size()) {
        cout << seq.top() << " ";
        seq.pop();
    }

    cout << "\n";

    cout 
}
