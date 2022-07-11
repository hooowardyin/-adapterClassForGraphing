
#include "PS_Display.h"

using namespace std;

PS_Display::PS_Display(ostream& o):out(o){
	adaptee = new PS_adaptee(cout);
}

void PS_Display::start(){
	adaptee->newpath();
	adaptee->setrgbcolor(0.8,0.8,0.8);
	adaptee->moveto(0,0);
	adaptee->rlineto(10,0);
	adaptee->rlineto(0,10);
	adaptee->rlineto(-10,0);
	adaptee->closepath();
	adaptee->fill();
	dw=0.03;								//default width 1
	adaptee->setlinewidth(dw);				
	adaptee->setrgbcolor(0,0,0);			//default color black
	dsh=0;									//default shape circle

}


void PS_Display::color(Color col){
	if (col==Color::RED){
		adaptee->setrgbcolor(1,0,0);
	}
	if (col==Color::GREEN){
		adaptee->setrgbcolor(0,1,0);
	}
	if (col==Color::BLUE){
		adaptee->setrgbcolor(0,0,1);
	}
	if (col==Color::CYAN){
		adaptee->setrgbcolor(0,1,1);
	}
	if (col==Color::MAGENTA){
		adaptee->setrgbcolor(1,0,1);
	}
	if (col==Color::YELLOW){
		adaptee->setrgbcolor(1,1,0);
	}
	if (col==Color::WHITE){
		adaptee->setrgbcolor(1,1,1);
	}
	if (col==Color::BLACK){
		adaptee->setrgbcolor(0,0,0);
	}
}

void PS_Display::shape(Shape s){
	if (s==Shape::CIRCLE){
		dsh=0;
	}
	if (s==Shape::TRIANGLE){
		dsh=1;
	}
	if (s==Shape::SQUARE){
		dsh=2;
	}
}

void PS_Display::width(int w){
	dw=w*0.03;
	adaptee->setlinewidth(dw);
}

void PS_Display::vertex(double x, double y){

	double sw=dw*2;										//radius
	double teex=x*10, teey=y*10;						//scale the coordinates
	double tax, tay, tbx, tby, tcx, tcy;				//triangle's vertices
	double sax, say, sbx, sby, scx, scy, sdx, sdy;		//square's vertices

	//initailize triangle's vertices
	tax=teex-sw;
	tay=teey-sw;
	tcx=tax+sw*2;
	tcy=tay;
	tbx=tcx-sw;
	tby=tcy+sw*2;

	//initialize square's vertices
	sax=teex-sw;
	say=teey-sw;
	sbx=sax+sw*2;
	sby=say;
	scx=sbx;
	scy=sby+sw*2;
	sdx=scx-sw*2;
	sdy=scy;

	//draw circle
	if(dsh==0){
		adaptee->arc(teex,teey,sw,0,360);
		adaptee->fill();
	}

	//draw triangle
	if(dsh==1){
		adaptee->moveto(tax,tay);
		adaptee->lineto(tbx,tby);
		adaptee->lineto(tcx,tcy);
		adaptee->closepath();
		adaptee->fill();

	//draw square
	}
	if(dsh==2){
		adaptee->moveto(sax,say);
		adaptee->lineto(sbx,sby);
		adaptee->lineto(scx,scy);
		adaptee->lineto(sdx,sdy);
		adaptee->closepath();
		adaptee->fill();


	}
}

void PS_Display::edge(double x1, double y1, double x2, double y2){
	double teex1, teey1, teex2, teey2;
	teex1=x1*10;
	teey1=y1*10;
	teex2=x2*10;
	teey2=y2*10;
	adaptee->moveto(teex1,teey1);
	adaptee->lineto(teex2,teey2);
	adaptee->stroke();
}





void PS_Display::end(){

	adaptee->showpage();
}

PS_Display::~PS_Display(){}
