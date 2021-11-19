//https://pastebin.com/9GrwWJWZ
//https://pastebin.com/4DX3DDyv

#include <iostream>
using namespace std;

const int MAXN = 1e6;

int lsp[MAXN];
        //_________________
        //---___________---
        //abcabcabcabcabcab
        //int x = n-lsp[n-1]
        //n%x == 0


        
/*lsp: 0 0 0 1 2 3 4 2 0 1 2 3 4 5 6 7 5 6 7 0 1 2 3
abcabxabcabyabcabxabcabc

abcdabcdabcd
abcdabcdabcdabcdabcdabcd

ab - 0
abcab - 2
abcabxabcab - 5
abcabxabcabyabcabxabcab - 11
abcabxabcabyabcabxabcabb - 0
1: 0
4: 2
10: 5
22: 11
23:
currSP = lsp[23-1] = 11
s[23] != s[11]
currSP = lsp[11-1] = 5
s[23] != s[5]
currSP = lsp[5-1] = 2
s[23] != s[2]
currSP = lsp[2-1] = 0
s[23] != s[0]
currSP = lsp[0-1]*/

int kmp(const string& s) {
    lsp[0] = 0;

    for (int i=1; i<s.size(); i++) {
        int currSP = lsp[i-1];

        while (currSP>0 && s[i] != s[currSP]) {
            currSP = lsp[currSP-1];
        }
        if (s[i] == s[currSP]) {
            lsp[i] = currSP+1;
        } else {
            lsp[i] = 0;
        }
    }

    return lsp[s.size()-1];
}

int main() {
     string a,b;
     cin >> a >> b;

     int lena = a.size()-kmp(a);
     int lenb = b.size()-kmp(b);

     /*
      * ---______---
        _________
           _________

       lena = ---*/

     if (lena > a.size()/2 || a.size()%lena) {
         lena = a.size();
     }
     if (lenb > b.size()/2 || b.size()%lenb) {
         lenb = b.size();
     }

     if (a.substr(0, lena) == b.substr(0, lenb)) {
         int ans = 0;
         for (int i=1; i<=a.size()/lena; i++) 
             if ((a.size()/lena)%i == 0 && (b.size()/lenb)%i == 0) {
                 ans++;
             }

         cout << ans << "\n";
     } else {
         cout << "0\n";
     }
}
