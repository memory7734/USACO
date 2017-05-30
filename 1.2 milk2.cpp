/*
ID: memory71
PROG: milk2
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
	Interval() :start(0), end(0) {}
};
int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int n;
	fin >> n;
	vector<Interval>interval;
	vector<Interval>res;
	for (int i = 0; i < n; i++) {
		int start, end;
		fin >> start >> end;
		Interval now(start, end);
		interval.push_back(now);
	}
	sort(interval.begin(), interval.end(), [](Interval a, Interval b) {return a.start < b.start; });
	res.push_back(interval[0]);
	for (int i = 1; i < interval.size(); i++) {
		if (res.back().end < interval[i].start) res.push_back(interval[i]);
		else res.back().end = max(res.back().end, interval[i].end);
	}
	int maxlen = 0, maxrelax = 0;
	for (int i = 0; i < res.size(); i++) {
		maxlen = max(maxlen, res[i].end - res[i].start);
		if (i > 0) maxrelax = max(maxrelax, res[i].start - res[i - 1].end);
	}
	fout << maxlen << " " << maxrelax << endl;
	fin.close();
	fout.close();
	return 0;
}