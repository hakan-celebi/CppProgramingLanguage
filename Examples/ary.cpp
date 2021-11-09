#include "ary.h"
#ifndef _ARY_
#define _ARY_
bool Contains(int ary[], int val)
{
	for(int i = 0; i < sizeof(ary); i++)
	{
		if(ary[i] == val)
			return true;
	}
	return false;
}
#endif
