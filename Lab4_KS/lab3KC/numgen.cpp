#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "numgen.h"

void numgen::generate()
{
	double a = 15;
	double b = 150;
	out1.write(a);
	out2.write(b);

}
