#include "stdafx.h"
#include "sum.h"
#include <iostream>


// This is an example of an exported variable
SUM_API int nsum=0;

// This is an example of an exported function.
SUM_API int fnsum(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
Csum::Csum()
{
    return;
}
SUM_API int sum(int a, int b)
{
	return a + b;
}
Base::Base() { std::cout << "this is the base constructor\n"; }
