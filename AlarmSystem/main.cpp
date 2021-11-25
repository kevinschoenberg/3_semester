#include "systemc.h"
#include "HelloExample.h"
#include <time.h>
using namespace sc_core;

int sc_main(int sc_argc, char *sc_argv[])
{
	clock_t start = clock();
	m1 mod1("sensor");
	m2 mod2("control");
	m3 mod3("camera");
	sc_signal<int> data1, data2;
	mod1.s(data1);
	mod2.s(data1);
	mod2.c(data2);
	mod3.c(data2);
	sc_start(60000, SC_SEC);
	clock_t end = clock();


	std::cout << "time " << ((end - start) * 1000 / CLOCKS_PER_SEC) << " ms" << std::endl;
	return 0;
}