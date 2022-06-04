#pragma once
#include "systemc.h"
#include "s1_unit.h"

SC_MODULE(s2_unit)
{
	sc_in<int> f1_in, rep_in;
	sc_out<int> r1, r2;

	void OutR1()
	{
		int result = f1_in.read() + rep_in.read();
		r1.write(result);
	}

	void OutR2()
	{
		OutR1();
		r2.write(15);
	}

	SC_CTOR(s2_unit)
	{
		SC_METHOD(OutR2);

		sensitive << f1_in << rep_in;
	}
};
