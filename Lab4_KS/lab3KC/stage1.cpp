#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "stage1.h"
#include <math.h>

void stage1::user_funk1()
{
	int x_val = x.read();
	int y_val = y.read();
	int temp1 = 0;
	temp1 = (x.read() < y.read()) ? (x.read() - y.read()) : (y.read() - x.read());

	f1.write(temp1);

	
	int temp2 = 0;
	for (int i = 0; i < y_val; i++)
	{
		temp2 = temp2 + (x_val * i);
	}
	rep.write(temp2);

}
