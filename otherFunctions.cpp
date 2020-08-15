//Satrodub Valentyna
#include "otherFunctions.h"
#include <iostream>
using namespace std;
void doNothing() {
	cout << "nothing to do" << endl;
}

void doIgnored(int&cur, char**argv) {
	cout << argv[cur] << " : ignored" << endl;
	cur++;
}
bool output(const char* fname, const Info&inf) {
	return true;
}
bool stat(const char* fname, const Info&inf) {
	return true;
}
