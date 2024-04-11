//---------------------------------------------------------------------------

#ifndef uElapsedTimeH
#define uElapsedTimeH
//---------------------------------------------------------------------------

#include <System.Classes.hpp>
#include <windows.h>

// ---------------------------------------------------------------------------
class TElapsedTime : public TObject
{
private:
	LARGE_INTEGER st;
	LARGE_INTEGER ed;
	LARGE_INTEGER freq;

	double dGap;
	bool bEnable;

	UINT nCount;
	double dTotal_time;

public:
	__fastcall TElapsedTime( );
	__fastcall ~TElapsedTime( );

	void __fastcall Start( );
	void __fastcall End( );
	String _fastcall EndPerformance( );
	String __fastcall Performance( );
	String __fastcall PerformanceXXXXX( );
	String __fastcall Average( );

} ;


#endif
