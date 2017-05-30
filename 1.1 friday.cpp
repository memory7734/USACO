/*
ID: memory71
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;
int main() {
	ofstream fout("friday.out");
	ifstream fin("friday.in");
	int n;
	fin >> n;
	map<int, int> week;
	int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < 7; i++) {
		week[i] = 0;
	}
	int point = 13;
	for (int i = 0; i < n; i++) {
		int year = 1900 + i;
		bool flag = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
		for (int j = 0; j < 12; j++) {
			point %= 7;
			week[point]++;
			point += day[j];
			if (j == 1 && flag) point++;
		}
	}

	fout << week[6];
	for (int i = 0; i < 6; i++) {
		fout << ' ' << week[i];
	}
	fout << endl;
	fin.close();
	fout.close();
	return 0;
}