#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "stage2.h"

void stage2::user_funk2()
{
	
	int result = a.read() + b.read();
	r1.write(result);
	r2.write(15);
}
