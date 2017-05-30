/*
ID: memory71
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
int main() {
	ofstream fout("combo.out");
	ifstream fin("combo.in");
	int n, a[3], b[3];
	fin >> n >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
	int space = (n < 5) ? n : 5;
	int shared[3] = { 0 };
	for (int i = 0; i < 3; i++) {
		int top = space - abs(min(a[i], b[i]) + n - max(a[i], b[i]));
		int bot = space - abs(a[i] - b[i]);
		if (top < 0) top = 0;
		if (bot < 0) bot = 0;
		shared[i] = (n <= 5) ? space : bot + top;
	}
	long na = space*space*space;
	long nb = na;
	long num_shared = 1;
	bool has_shared = false;
	for (int i = 0; i < 3; i++) {
		if (shared[i] > 0) {
			has_shared = true;
			num_shared *= shared[i];
		}
	}
	if (has_shared)
		fout << na + nb - num_shared << endl;
	else
		fout << na + nb << endl;
	fin.close();
	fout.close();
	return 0;
}