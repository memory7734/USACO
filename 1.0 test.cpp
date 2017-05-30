/*
ID: memory71
PROG: test
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
	fin.close();
	fout.close();
    return 0;
}