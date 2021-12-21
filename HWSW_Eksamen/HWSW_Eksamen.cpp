#include "systemc.h"
#include "Source.h"
#include <time.h>
using namespace sc_core;

int sc_main(int sc_argc, char* sc_argv[])
{
	//clock_t start = clock();
	m1 mod1("sensor1");
	m1 mod2("sensor2");
	m2 mod3("control");
	m3 mod4("camera");
	sc_signal<int> data_s1, data_s2;
	sc_signal<std::vector<int>> data_c;


	mod1.port1(data_s1);
	mod2.port1(data_s2);

	mod3.port1(data_s1);
	mod3.port2(data_s2);
	mod3.port3(data_c);

	mod4.port3(data_c);
	
	sc_start(600, SC_SEC);
	//clock_t end = clock();


	//std::cout << "time " << ((end - start) * 1000 / CLOCKS_PER_SEC) << " ms" << std::endl;
	return 0;
}