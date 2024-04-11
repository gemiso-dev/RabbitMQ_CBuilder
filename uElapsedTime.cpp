//---------------------------------------------------------------------------

#pragma hdrstop

#include "uElapsedTime.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)



__fastcall TElapsedTime::TElapsedTime( )
{
	bEnable     = false;
	nCount      = 0;
	dTotal_time = 0.0;

	QueryPerformanceCounter( & st );

	if ( st.QuadPart == 0 )
	{
		bEnable = false;

		//ShowMessage( L"시스템이 지원이 안됨,,, 사용할 수 없음" );
	}
	else
	{
		bEnable = true;
	}
}

__fastcall TElapsedTime::~TElapsedTime( )
{

}

void __fastcall TElapsedTime::Start( )
{
	if ( !bEnable )
	{
		return;
	}

	nCount++ ;
	QueryPerformanceCounter( & st );
}

void __fastcall TElapsedTime::End( )
{
	if ( !bEnable )
	{
		return;
	}

	QueryPerformanceCounter( & ed );
	QueryPerformanceFrequency( & freq );
}

String _fastcall TElapsedTime::EndPerformance( )
{  	// 2014-10-03
	if ( !bEnable )
	{
		return L"NONE";
	}

	QueryPerformanceCounter( & ed );
	QueryPerformanceFrequency( & freq );

	// 소요 시간 계산
	dGap = ( ( double )( ed.QuadPart - st.QuadPart ) ) / ( ( double ) freq.QuadPart );

	dTotal_time += dGap;

	String strTime = String( ).sprintf( L"%.8f", dGap );
	return strTime;
}

String __fastcall TElapsedTime::Performance( )
{
	if ( !bEnable )
	{
		return L"NONE";
	}

	// 소요 시간 계산
	dGap = ( ( double )( ed.QuadPart - st.QuadPart ) ) / ( ( double ) freq.QuadPart );

	dTotal_time += dGap;

	String strTime = String( ).sprintf( L"%.8f", dGap );
	return strTime;
}

String __fastcall TElapsedTime::PerformanceXXXXX( )
{
	if ( !bEnable )
	{
		return L"NONE";
	}

	// 소요 시간 계산
	dGap = ( ( double )( ed.QuadPart - st.QuadPart ) ) / ( ( double ) freq.QuadPart );

	dTotal_time += dGap;

	String strTime = String( ).sprintf( L"%.5f", dGap );
	return strTime;
}

String __fastcall TElapsedTime::Average( )
{
	if ( !bEnable )
	{
		return L"NONE";
	}

	String strTime = String( ).sprintf( L"%.3f", dTotal_time / ( double ) nCount );
	return strTime;
}