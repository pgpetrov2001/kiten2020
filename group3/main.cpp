#include <iostream>
#include <random>
using namespace std;

int main() {
	for(int i = 0; i < 100000; i ++) {
		cout << (char)(rand() % 256);
	}
	return 0;
}
