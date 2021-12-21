#define HelloExample
#include <systemc.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace sc_core;

SC_MODULE(m1) {
	sc_out<int> port1;
	SC_CTOR(m1) {
		SC_THREAD(sensor);
		//dont_initialize();
		sensitive << port1;
	}

	void sensor()
	{
		int val;
		srand(time(NULL));

		while (true)
		{
			val = rand() % 2;
			wait(10, SC_MS);
			port1.write(val);
			wait(40, SC_MS);
		}
	}

};

SC_MODULE(m2) {
	sc_in<int> port1, port2;
	sc_in<std::vector<int>> port3;

	SC_CTOR(m2) {
		SC_THREAD(dataanalysis);
		//dont_initialize();
		sensitive << port1;
		sensitive << port2;
		sensitive << port3;
	}

	void dataanalysis()
	{
		int val1, val2;
		std::vector<int> val3;
		while (true)
		{
			val1 = port1.read();
			val2 = port2.read();

			val3 = port3.read();
			
			
			

			wait(10, SC_SEC);
			for (int i = 0; i < 16; i++)
			{
				std::cout << val3[i];
			}
			std::cout << std::endl;
			
			// intruder function
			
			wait(50, SC_MS);
		}
	}

};


SC_MODULE(m3) {
	sc_out<std::vector<int>> port3;
	SC_CTOR(m3) {
		SC_THREAD(camera);
		/*
		for (int i = 0; i < 16; i++)
		{
			sensitive << port3;
		}
		*/
		//sensitive << port3;
	}

	void camera()
	{
		
		srand(time(NULL));

		while (true)
		{
			std::vector<int> val;
			for (int i = 0; i < 16; i++)
			{
				val.push_back(i);
			}
			
			for (int i = 0; i < 16; i++)
			{
				port3.write(val);
			}
			wait();
		}
	}

};