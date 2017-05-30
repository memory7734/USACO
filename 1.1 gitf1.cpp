/*
ID: memory71
PROG: gift1
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
	ofstream fout("gift1.out");
	ifstream fin("gift1.in");
	map<string, int> group;
	vector<string> name_group;
	int np;
	fin >> np;
	string name;
	for (int i = 0; i < np; i++) {
		fin >> name;
		name_group.push_back(name);
		group[name] = 0;
	}
	for (int i = 0; i < np; i++) {
		fin >> name;
		int money, reciver;
		fin >> money >> reciver;
		if (reciver > 0)
			group[name] -= (money / reciver*reciver);
		for (int j = 0; j < reciver; j++) {
			fin >> name;
			group[name] += money / reciver;
		}
	}
	for (int i = 0; i < np; i++) {
		fout << name_group[i] << ' ' << group[name_group[i]] << endl;
	}
	fin.close();
	fout.close();
	return 0;
}