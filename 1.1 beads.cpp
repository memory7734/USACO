/*
ID: memory71
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ofstream fout("beads.out");
	ifstream fin("beads.in");
	int n;
	fin >> n;
	string s;
	fin >> s;
	int res = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		char left_color = s[i];
		char right_color = s[(i + 1) % len];

		int left_len = 0;
		for (int j = 0; j < len; j++) {
			char color = s[(i - j) % len];
			if (color != left_color&&left_color == 'w')
				left_color = color;
			if (color == left_color || color == 'w')
				left_len++;
			else
				break;
		}
		int right_len = 0;
		for (int j = 1; j < len; j++) {
			char color = s[(i + j) % len];
			if (color != right_color&&right_color == 'w')
				right_color = color;
			if (color == right_color || color == 'w')
				right_len++;
			else
				break;
		}
		res = max(res, left_len + right_len);
	}
	fout << min(res,len) << endl;
	fin.close();
	fout.close();
	return 0;
}