/*
ID: memory71
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
void rotate(string &s) {
	for (int i = 0; i < s.length() / 2; i++) {
		swap(s[i], s[s.length() - 1 - i]);
	}
}
bool check(string s) {
	for (int i = 0; i < s.length() / 2; i++) {
		if (s[i] != s[s.length() - 1 - i]) return false;
	}
	return true;
}
string base(long n, int b) {
	string s;
	while (n > 0)
	{
		if (n%b < 10) s.push_back('0' + n%b);
		else s.push_back('A' + n%b - 10);
		n /= b;
	}
	rotate(s);
	return s;
}
bool isdualpal(long n) {
	int count = 0;
	for (int i = 2; i <= 10; i++) {
		if (check(base(n, i))) {
			count++;
			if (count > 1)return true;
		}
	}
	return false;
}
int main() {
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");
	int n;
	long s;
	fin >> n >> s;
	while (n) {
		s++;
		if (isdualpal(s)) {
			fout << s << endl;
			n--;
		}
	}
	fin.close();
	fout.close();
	return 0;
}