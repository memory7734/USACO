/*
ID: memory71
PROG: barn1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval
{
	int start;
	int end;
	Interval(int a, int b) :start(a), end(b) {}
};
int main() {
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	int m, s, c;
	fin >> m >> s >> c;
	if (m >= c) {
		fout << c << endl;
		return 0;
	}
	vector<int> stalls(c);
	for (int i = 0; i < c; i++) {
		fin >> stalls[i];
	}
	sort(stalls.begin(), stalls.end());
	vector<Interval> intervals;
	for (int i = 1; i < c; i++) {
		Interval tmp(stalls[i - 1], stalls[i]);
		intervals.push_back(tmp);
	}
	int res = stalls[stalls.size() - 1] - stalls[0] + 1;
	sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return (a.end - a.start) > (b.end - b.start); });
	for (int i = 0; i < m - 1; i++) {
		res -= (intervals[i].end - intervals[i].start - 1);
	}
	fout << res << endl;
	fin.close();
	fout.close();
	return 0;
}