/*
ID: memory71
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> rotate(vector<string> original, int time) {
	if (time % 4 == 0) return original;
	vector<string> after(original.size(), string(original.size(), '-'));
	for (int i = 0; i < original.size(); i++) {
		for (int j = 0; j < original.size(); j++) {
			after[j][original.size() - i - 1] = original[i][j];
		}
	}
	return rotate(after, time - 1);
}
vector<string> reflection(vector<string> original) {
	vector<string> after(original.size(), string(original.size(), '-'));
	for (int i = 0; i < original.size(); i++) {
		for (int j = 0; j < original.size(); j++) {
			after[i][original.size() - j - 1] = original[i][j];
		}
	}
	return after;
}
bool check(vector<string> original, vector<string> after) {
	for (int i = 0; i < original.size(); i++) {
		if (original[i] != after[i]) return false;
	}
	return true;
}
int main() {
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	int n;
	fin >> n;
	vector<string> original(n);
	vector<string> after(n);
	for (int i = 0; i < n; i++) {
		fin >> original[i];
	}
	for (int i = 0; i < n; i++) {
		fin >> after[i];
	}
	original = rotate(original, 1);
	if (check(original, after)) { fout << 1 << endl; return 0; }
	original = rotate(original, 1);
	if (check(original, after)) { fout << 2 << endl; return 0; }
	original = rotate(original, 1);
	if (check(original, after)) { fout << 3 << endl; return 0; }
	original = rotate(original, 1);
	if (check(original, after)) { fout << 6 << endl; return 0; }
	original = reflection(original);
	if (check(original, after)) { fout << 4 << endl; return 0; }
	for (int i = 0; i < 4; i++) {
		original = rotate(original, 1);
		if (check(original, after)) { fout << 5 << endl; return 0; }
	}
	fout << 7 << endl;
	fin.close();
	fout.close();
	return 0;
}