#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

using namespace std;

struct coordinate 
{
	private:
		int hor;
		int ver;
		void sethor(int h);
		void setver(int v);
	
	public:
		coordinate();		
		~coordinate();
		int gethor();
		int getver();
		void set(int h, int v);
		
};

#endif
