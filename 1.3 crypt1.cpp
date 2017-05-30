/*
ID: memory71
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool islegal(bool nums[], int digit) {
	while (digit > 0) {
		if (nums[digit % 10] == false) return false;
		digit /= 10;
	}
	return true;
}
int main() {
	ofstream fout("crypt1.out");
	ifstream fin("crypt1.in");
	bool digit[10] = { false,false,false,false,false,false,false,false,false,false };
	int n, tmp;
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> tmp;
		digit[tmp] = true;
	}
	n = 0;
	for (int i = 100; i < 1000; i++) {
		if (!islegal(digit, i)) continue;
		for (int j = 10; j < 100; j++) {
			if (!islegal(digit, j))
				continue;
			int a = i*(j % 10);
			int b = i*(j / 10);
			int m = i*j;
			if (a > 999 || b > 999 || m > 9999)
				continue;
			if (islegal(digit, a) && islegal(digit, b) && islegal(digit, m))
				n++;
		}
	}
	fout << n << endl;
	fin.close();
	fout.close();
	return 0;
}