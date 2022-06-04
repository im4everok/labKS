#pragma once
#include "systemc.h"

SC_MODULE(Stimulator)
{
	sc_out<int> X, Y;
	sc_in<bool> CLK;

	void Generator()
	{
		X.write(15);
		Y.write(77 + 73);
		wait();
	}

	SC_CTOR(Stimulator)
	{
		SC_THREAD(Generator);
		sensitive << CLK.pos();
	}
};
