/*
ID: memory71
PROG: milk
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Farmer
{
	int unit;
	int total;
	Farmer(int a, int b) :unit(a), total(b) {}
};
int main() {
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	int milk, fam;
	fin >> milk >> fam;
	vector<Farmer> v;
	for (int i = 0; i < fam; i++) {
		int unit, total;
		fin >> unit >> total;
		Farmer f(unit, total);
		v.push_back(f);
	}
	sort(v.begin(), v.end(), [](Farmer a, Farmer b) {return a.unit < b.unit; });
	int price = 0;
	for (int i = 0; i < v.size(); i++) {
		if (milk > v[i].total) {
			milk -= v[i].total;
			price += v[i].total*v[i].unit;
		}
		else {
			price += v[i].unit*milk;
			break;
		}
	}
	fout << price << endl;
	fin.close();
	fout.close();
	return 0;
}