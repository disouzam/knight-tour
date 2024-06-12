#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

using namespace std;

struct coordinate 
{
	private:
		int hor;
		int ver;
		void sethor(const int h);
		void setver(const int v);
	
	public:
		coordinate();		
		~coordinate();
		int gethor() const;
		int getver() const;
		void set(const int h, const int v);
		
};

#endif
