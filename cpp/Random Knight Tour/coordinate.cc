#include "coordinate.h"

coordinate::coordinate()
{
	//Não executa nenhuma ação.
}

coordinate::~coordinate()
{
	//Não executa nenhuma ação.
}


int coordinate::gethor()
{
	return hor;
}

int coordinate::getver()
{
	return ver;
}

void coordinate::sethor(int h)
{
	hor = h;	
}

void coordinate::setver(int v)
{
	ver = v;
}

void coordinate::set(int h, int v)
{
	sethor(h);
	setver(v);
}
