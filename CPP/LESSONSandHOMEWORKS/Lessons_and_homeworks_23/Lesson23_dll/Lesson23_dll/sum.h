// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SUM_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SUM_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SUM_EXPORTS
#define SUM_API __declspec(dllexport)
#else
#define SUM_API __declspec(dllimport)
#endif

// This class is exported from the dll
class SUM_API Csum {
public:
	Csum(void);
	// TODO: add your methods here.
};

extern SUM_API int nsum;

SUM_API int fnsum(void);

extern "C" SUM_API int sum(int, int);

extern "C" class SUM_API Base
{
public:
	Base();
};