#include <climits>
#include <iostream>
#include <stack>
using namespace std;

int arr[1001];
int lis[1001];
int prevdafi[1001];

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    arr[n] = INT_MAX;


    for (int i=0; i<=n; i++) {
        lis[i] = 1;
        prevdafi[i] = i;
        for (int j=0; j<i; j++) {
            if (arr[j]<arr[i] && lis[j]+1>lis[i]) {
                lis[i] = lis[j]+1;
                prevdafi[i] = j;
            }
        }
    }
    stack<int> nigga;
    int curr = n;
    while (prevdafi[curr] != curr) {
        nigga.push(arr[prevdafi[curr]]);
        curr = prevdafi[curr];
    }
    while (nigga.size()) {
        cout << nigga.top() << " ";
        nigga.pop();
    }
    
    return 0;
}
