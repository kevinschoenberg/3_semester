#define HelloExample
#include <stdlib.h>
#include <time.h>
using namespace sc_core;

SC_MODULE(m1){
	sc_signal<int> data1;
	sc_port<sc_signal_out_if<int> > s;
	SC_CTOR(m1){
		SC_THREAD(sensor);
		//dont_initialize();
		sensitive << s;
	}
	
	void sensor()
	{
		int val;
		srand (time(NULL));
		
		while(true)
		{
			val = rand() % 99;
			//cout << "Sensor " << val << endl;
			//data.write(val);
			s->write(val);
			wait(3, SC_SEC);
		}
	}

};

SC_MODULE(m2){
	sc_signal<int> data1, data2;
	sc_port<sc_signal_in_if<int> > s;
	sc_port<sc_signal_in_if<int> > c;
	SC_CTOR(m2){
		SC_THREAD(dataanalysis);
		//dont_initialize();
		sensitive << c;
		sensitive << s;
	}
	
	void dataanalysis()
	{
		int val1, val2;
		while(true)
		{
			int a = 3;
			int b = 2;
			val1 = s->read();
			val2 = pow(a * c->read(), b);
			wait(10, SC_SEC);
			std::cout << val1 << " " << val2 << std::endl;
			bool sensorFaulty = false;
			bool cameraFaulty = false;
			if (val1 < 5 || val1 > 95)
			{
				//faulty sensor data
				sensorFaulty = true;
			}
			if (val2 % 10 == 0)
			{
				//faulty camera data
				cameraFaulty = true;
			}
			if (sensorFaulty && cameraFaulty)
			{
				std::cout << "Faulty data" << std::endl;
			} else if (val1 > 80 && val2 % 4 == 0)
			{
				std::cout << "Intruder" << std::endl;
			} else 
			{
				std::cout << "No intruder" << std::endl;
			}
			wait();
		}
	}
};


SC_MODULE(m3){
	sc_signal<int> data2;
	sc_port<sc_signal_out_if<int> > c;
	SC_CTOR(m3){
		SC_THREAD(camera);
		sensitive << c;
	}
	
	void camera()
	{
		int val;
		srand (time(NULL));
		
		while(true)
		{
			val = rand() % 99;
			//cout << "Camera " << val << endl;
			//data.write(val);
			c->write(val);
			wait(3, SC_SEC);
		}
	}

};