#include<iostream>
using namespace std;

int kuli[50];

int main() {
    int brKuli;
    cin >> brKuli;

    for (int i=0; i<brKuli; i++) {
        cin >> kuli[i];
    }

    int naiDobraKula, maxOsvKuli=0;

    for (int sv=0; sv<brKuli; sv++) {
        int brOsveteni = 0;
        //kod za prebroiava
        //naliavo
        int naiVisokaDosega = 0;
        for (int i=sv-1; i>=0; i--) {
            if (kuli[i]>kuli[sv]) {
                break;
            }
            if (kuli[i]>naiVisokaDosega) {
                naiVisokaDosega = kuli[i];
                brOsveteni++;
            }
        }
        //nadiasno
        naiVisokaDosega = 0;
        for (int i=sv+1; i<brKuli; i++) {
            if (kuli[sv]<kuli[i]) {
                break;
            }
            if (kuli[i]>naiVisokaDosega) {
                naiVisokaDosega = kuli[i];
                brOsveteni++;
            }
        }

        if (brOsveteni > maxOsvKuli) {
            maxOsvKuli = brOsveteni;
            naiDobraKula = sv;
        }
    }

    cout << maxOsvKuli << " " << naiDobraKula << "\n";


}
