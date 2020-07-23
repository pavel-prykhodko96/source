#pragma once
#ifdef SUM_EXPORTS
#define SUM_API __declspec(dllexport)
#else
#define SUM_API __declspec(dllimport)
#endif

#include <iostream>
using std::cout;
class SUM_API Another_class
{
public:
	Another_class();
	~Another_class();
};

