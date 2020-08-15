//variant 56
//Starodub Valentyna
//структуру main розблено на лабораторних заняттях; самостійно дороблено doOutput, doStat
#include "copyright.h"
#include "info.h"
#include "builder.h"
#include "otherFunctions.h"
#include <cstring>
#include <iostream>
using namespace std;
void input(Info&inf, const char*fname) {//work on input, OK if successfully
	cout << "input " << fname << " :";
	Builder b;
	b.loadData(inf, fname);
	cout << "OK" << endl;
}


void doOutput(int&cur, int argc, char** argv, Info&inf) {// OK if successfully, UPS if not successfully
	cout << "output "; ++cur;
	if (cur >= argc) {
		cout << "undefined" << endl;
	}
	else {
		bool res = output(argv[cur], inf);
		if (strcmp(argv[cur], "#con") == 0)
			cout << "#con :" << endl;
		else {
			cout << argv[cur] << " : ";

			if (res) cout << "OK" << endl;
			else cout << "UPS" << endl;
		}
	}++cur;
}
void doStat(int&cur, int argc, char** argv, Info&inf) {// OK if successfully, UPS if not successfully
	cout << "stat ";
	++cur;
	if (cur >= argc) {
		cout << "undefined" << endl;
	}
	else {
		bool res = stat(argv[cur], inf);
		if (strcmp(argv[cur], "#con") == 0)
			cout << "#con :" << endl;
		
		else {

			cout << argv[cur] << " : ";

			if (res) cout << "OK" << endl;
			else cout << "UPS" << endl;
		}
	}++cur;
}
void do_command(int&cur, int argc, char**argv, Info&inf) {
	
	if (strcmp(argv[cur], "-stat") == 0) doStat(cur, argc, argv, inf);
	else if (strcmp(argv[cur], "-output") == 0) doOutput(cur, argc, argv, inf);
	
	else doIgnored(cur, argv);
}


void help() {
	cout << "Help:" << endl;
	cout << "-stat <file> - to connect for stat" << endl;
	cout << "-output <file> - to connect for output" << endl;
}
void task() {
	cout << "Task:" << endl;
	cout << "get the list of student with marks" << endl;
	cout << "find who failed, give info about each" << endl;
	cout << "sort for each student: mark, subject" << endl;
	cout << "sort students: how many fails, average point, gradebook number" << endl;
}

int main(int argc, char**argv) {
	PrintCopyright();
	task();
	help();

	try {
		cout << "*****" << endl;
		Info inf;
		if (argc == 1) doNothing();
		
		else {
			input(inf, argv[1]);

			int cur = 2;
			
			while (cur < argc)
				
				do_command(cur, argc, argv, inf);
			
		}
		cout << "*****" << endl;
	}
	catch (const exception &ex) {
		cout << ex.what() << endl;
	}
	catch (...) {
		cout << "Error" << endl;
	}
	system("pause");
	return 0;
}