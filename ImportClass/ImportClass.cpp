// ImportClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


typedef FuckingDelphiInterface*(STDMETHODCALLTYPE *fCreateInstance)();
typedef void (STDMETHODCALLTYPE *fFreeInstance)(FuckingDelphiInterface* instance);
const size_t MaxPath = 255;

int main()
{
	int SomeNumber = 0, SomeInteger = 0;
	char WhereAmI[MaxPath];
	memset(WhereAmI, 0, MaxPath);

	FuckingDelphiInterface* FDI = nullptr;
	fCreateInstance CreateInstance = nullptr;
	fFreeInstance   FreeInstance = nullptr;
	HMODULE LibHandle = nullptr;

	::GetCurrentDirectoryA(255, WhereAmI);

	LibHandle = ::LoadLibraryA("ExportClass.dll");
	if (!LibHandle)
	{
		std::cout << "ExportClass.dll load error" << std::endl;
		return -1;
	}

	CreateInstance = (fCreateInstance)::GetProcAddress(LibHandle, "CreateInstance");
	FreeInstance = (fFreeInstance)::GetProcAddress(LibHandle, "FreeInstance");
	if (CreateInstance == nullptr || FreeInstance == nullptr)
	{
		std::cout << "Resolving error" << std::endl;
		return -1;
	}

	FDI = CreateInstance();

	FDI->Shake();
	FDI->GetSomeNumber(SomeNumber);
	SomeInteger = FDI->ReturnSomeInteger(WhereAmI, MaxPath);

	FreeInstance(FDI);

	return 0;
}

