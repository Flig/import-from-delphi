#pragma once
#include <Unknwn.h>

//struct __declspec(uuid("1C8F8EB1-E57D-4BF8-90EA-594A95FEA120")) FuckingDelphiInterface : public IUnknown
struct FuckingDelphiInterface
{
	virtual int ReturnSomeInteger(char* Data, int LenData) = 0;
	virtual void GetSomeNumber(int &Number) = 0;
	virtual void Shake() = 0;
};