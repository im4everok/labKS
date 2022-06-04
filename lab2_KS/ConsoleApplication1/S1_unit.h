#pragma once
#include "systemc.h"
#include "cmath"

SC_MODULE(s1_unit)
{
	sc_in<int> x_in, y_in;
	sc_out<int> f1_out, rep_out;

	void outF1()
	{
		int temp = 0;
		temp = (x_in.read() < y_in.read()) ? (x_in.read() - y_in.read()) : (y_in.read() - x_in.read());

		f1_out.write(temp);
	}

	void outRep()
	{
		outF1();
		rep_out.write((y_in.read() > 0) ? !y_in.read() : !x_in.read());
	}
	SC_CTOR(s1_unit)
	{
		SC_METHOD(outRep);

		sensitive << x_in << y_in;
	}

};
