#include "coordinate.h"

coordinate::coordinate()
{
	set(0,0);
}

coordinate::~coordinate()
{
	//N�o executa nenhuma a��o.
}


int coordinate::gethor() const
{
	return hor;
}

int coordinate::getver() const
{
	return ver;
}

void coordinate::sethor(const int h)
{
	hor = h;	
}

void coordinate::setver(const int v)
{
	ver = v;
}

void coordinate::set(const int h, const int v)
{
	sethor(h);
	setver(v);
}
