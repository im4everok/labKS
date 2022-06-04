#include "systemc.h"
#include "stage1.h"
#include "stage2.h"
#include "stage3.h"
#include "stage4.h"
#include "stage5.h"
#include "display.h"
#include "observer.h"
#include "numgen.h"
#define NS * 1e-9

int sc_main(int ac, char* av[])
{
	sc_core::sc_report_handler::set_actions("/IEEE_Std_1666/deprecated",
		sc_core::SC_DO_NOTHING);
	//Signals
	sc_signal<double> x;
	sc_signal<double> y;
	sc_signal<double> f1;
	sc_signal<double> rep;
	sc_signal<double> r1;
	sc_signal<double> r2;
	sc_signal<double> sum;
	sc_signal<double> diff;
	sc_signal<double> prod;
	sc_signal<double> quot;
	sc_signal<double> powr;
	sc_signal<bool> clk;

	numgen N("numgen");
	N(x, y, clk);

	stage1 S1("stage1");
	S1.x(x);
	S1.y(y);
	S1.f1(f1);
	S1.rep(rep);
	S1.clk(clk);

	stage2 S2("stage2");
	S2.a(f1);
	S2.b(rep);
	S2.r1(r1);
	S2.r2(r2);
	S2.clk(clk);

	sc_trace_file* wf = sc_create_vcd_trace_file("signals");
	wf->set_time_unit(1, SC_NS);
	sc_trace(wf, clk, "CLK");
	sc_trace(wf, x, "X");
	sc_trace(wf, y, "Y");
	sc_trace(wf, f1, "F1");
	sc_trace(wf, rep, "REP");
	sc_trace(wf, r1, "R1");
	sc_trace(wf, r2, "R2");
	sc_trace(wf, sum, "Sum");
	sc_trace(wf, diff, "Diff");
	sc_trace(wf, prod, "Prod");
	sc_trace(wf, quot, "Quot");
	sc_trace(wf, powr, "Pow");

	stage3 S3("stage3");
	S3(r1, r2, sum, diff, clk);
	stage4 S4("stage4");
	S4(sum, diff, prod, quot, clk);
	stage5 S5("stage5");
	S5(prod, quot, powr, clk);
	/*display D("display");            
	D(powr, clk);     */                                               // Common test
	observer Obs("observer");
	Obs(x, y, f1, rep, r1, r2, sum, diff, prod, quot, powr, clk);     //Test all stages

	sc_start(0, SC_NS);
	for (int i = 0; i < 6; i++)
	{
		clk.write(0);
		sc_start(10, SC_NS);
		clk.write(1);
		sc_start(10, SC_NS);
	}

	 sc_close_vcd_trace_file(wf);

	return 0;
}
