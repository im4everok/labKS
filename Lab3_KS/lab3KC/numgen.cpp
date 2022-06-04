#include "systemc.h"
#include "numgen.h"

// definition of the `generate' method
void numgen::generate()
{
	static double a = 15.1;
	static double b = 150.0;
	a -= 2.5;
	b -= 3.6;
	out1.write(a);
	out2.write(b);

} // end of `generate' method
