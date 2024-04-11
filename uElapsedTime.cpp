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

		//ShowMessage( L"�ý����� ������ �ȵ�,,, ����� �� ����" );
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

	// �ҿ� �ð� ���
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

	// �ҿ� �ð� ���
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

	// �ҿ� �ð� ���
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