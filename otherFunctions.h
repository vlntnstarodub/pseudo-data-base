//Starodub Valentyna
//означено на лабораторних заняттях
#pragma once
#include "info.h"

//iff only .exe is given
void doNothing();
//iff unknown command
void doIgnored(int&cur, char**argv);
bool output(const char* fname, const Info&inf);
bool stat(const char* fname, const Info&inf);