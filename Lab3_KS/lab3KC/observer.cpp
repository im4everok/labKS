#define _CRT_SECURE_NO_WARNINGS
#include "systemc.h"
#include "observer.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

void observer::observe()
{
	printf("x= %f ", x.read());
	printf("y= %f ", y.read());
	printf("f1= %f ", f1.read());
	printf("rep= %f ", rep.read());
	printf("r1= %f ", r1.read());
	printf("r2= %f ", r2.read());
	printf("sum= %f ", sum.read());
	printf("diff= %f ", diff.read());
	printf("prod= %f ", prod.read());
	printf("quot= %f ", quot.read());
	printf("powr= %f\n\n", powr.read());

}
