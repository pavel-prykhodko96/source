// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MOVINGRECTANGLE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MOVINGRECTANGLE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MOVINGRECTANGLE_EXPORTS
#define MOVINGRECTANGLE_API __declspec(dllexport)
#else
#define MOVINGRECTANGLE_API __declspec(dllimport)
#endif

// This class is exported from the movingRectangle.dll
class MOVINGRECTANGLE_API CmovingRectangle {
public:
	CmovingRectangle(void);
	// TODO: add your methods here.
};

extern MOVINGRECTANGLE_API int nmovingRectangle;

MOVINGRECTANGLE_API int fnmovingRectangle(void);

#include <iostream>
#include <conio.h>

using std::cout;
using std::cin;
using std::endl;

extern "C" MOVINGRECTANGLE_API void movingSquare(const size_t nSquareSize);