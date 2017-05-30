/*
ID: memory71
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() {
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string comet;
	string group;
	string res;
	fin >> comet >> group;
	int mulc = 1, mulg = 1;
	for (int i = 0; i < comet.length(); i++) mulc *= comet[i] - 'A' + 1;
	for (int i = 0; i < group.length(); i++) mulg *= group[i] - 'A' + 1;
	if (mulc % 47 == mulg % 47)
		res = "GO";
	else
		res = "STAY";
	fout << res << endl;
	fin.close();
	fout.close();
	return 0;
}