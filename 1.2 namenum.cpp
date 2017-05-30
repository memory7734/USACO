/*
ID: memory71
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int getnumber(char c) {
	if (c < 'A' || c >= 'Z')return 0;
	if (c < 'Q') return (c - 'A') / 3 + 2;
	else return (c - 1 - 'A') / 3 + 2;
}
int main() {
	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	string n;
	fin >> n;
	string s;
	ifstream dict("dict.txt");
	int count = 0;
	while (!dict.eof()) {
		getline(dict, s);
		if (s.length() != n.length()) continue;
		bool flag = true;
		for (int i = 0; i < n.length(); i++) {
			if (n[i] - '0' != getnumber(s[i])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			fout << s << endl;
			count++;
		}
	}
	if (count == 0) fout << "NONE" << endl;
	fin.close();
	fout.close();
	return 0;
}