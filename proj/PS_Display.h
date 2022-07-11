#pragma once
#include <iostream>
#include "Display.h"
#include "PS_adaptee.h"

class PS_Display: public Display {
	public:
		PS_Display(std::ostream& o);
		virtual void start();
		virtual void color(Color col);
		virtual void shape(Shape s);
		virtual void width(int w);
		virtual void edge(double x1, double y1, double x2, double y2);
		virtual void vertex(double x, double y);
		virtual void end();
		virtual ~PS_Display();
	private:
		std::ostream& out;
		//std::ostream& adaptee;
		PS_adaptee* adaptee;    		
		double dw;						//display width
		int dsh;						//display shape


};
