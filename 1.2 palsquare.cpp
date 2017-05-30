/*
ID: memory71
PROG: palsquare
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
string base(int n, int b) {
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
int main() {
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");
	int b;
	fin >> b;
	for (int i = 1; i <= 300; i++) {
		int square = i*i;
		string s = base(square, b);
		if (check(s)) {
			fout << base(i, b) << ' ' << s << endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}