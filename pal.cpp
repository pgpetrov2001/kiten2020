#include <iostream>
using namespace std;

/**
 *
 ccxy
 ccxy&yxcc


cyxabbaccabxyc
tozi otg: cyx---xyc
--- = abbaccab
finalen otg: cyxabbaxyc

abbaccab&baccabba
baccabba&abbaccab


 abbaccab&baccabba
 baccabba&abbaccab

 abcde&edcba

 *
 * **/

int LPS[1000001];

int lps(string s) {
    s = s+"&"+reverse(s.begin(), s.end());

    fill(LPS, LPS+s.size()+1, 0); 

    LPS[0] = -1;

    for (int i=1; i<=s.size(); i++) {
        int prefsuf = LPS[i-1];
        while (prefsuf >= 0 && s[prefsuf] != s[i]) {
            prefsuf = LPS[prefsuf];
        }
        LPS[i] = prefsuf+1;
    }

    return s.substr(0,LPS[s.size()]);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string x;
        cin >> x;

        int n = x.size();

        int st;
        /**
        ^        ^
         ^      ^
          ^    ^
      */
        for (st=0; st<n/2 && s[st] == s[n-1-st]; st++); 
        string beg = x.substr(0,st);
        string end = x.substr(n-st);
        string mid = x.substr(st,n-st*2);
        string mid1 = reverse(mid.begin(), mid.end());

        longestPref = lps(mid);
        longestSuf = lps(mid1);

        if (longestPref.size() > longestSuf.size()) {
            ans = beg+longestPref+end;
        } else {
            ans = beg+longestSuf+end;
        }

        cout << ans << '\n';
    }
}
