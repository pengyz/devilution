//HEADER_GOES_HERE

#include "../types.h"

bool SystemSupported()
{
	bool bSupported = false; // di
	struct _OSVERSIONINFOA VersionInformation; // [esp+4h] [ebp-94h]

	memset(&VersionInformation, 0, sizeof(VersionInformation));
	VersionInformation.dwOSVersionInfoSize = sizeof(VersionInformation);
	if ( GetVersionExA(&VersionInformation)
	  && VersionInformation.dwPlatformId == 2
	  && VersionInformation.dwMajorVersion >= 5 )
	{
		bSupported = true;
	}
	return bSupported;
}

bool RestrictedTest()
{
	bool bSuccess = false; // si
	FILE *pFile; // eax
	char Buffer[260]; // [esp+4h] [ebp-104h]

	if ( SystemSupported() && GetWindowsDirectoryA(Buffer, sizeof(Buffer)) )
	{
		strcat(Buffer, "\\Diablo1RestrictedTest.foo");
		pFile = fopen(Buffer, "wt");
		if ( pFile )
		{
			fclose(pFile);
			remove(Buffer);
		}
		else
		{
			bSuccess = true;
		}
	}
	return bSuccess;
}

bool ReadOnlyTest()
{
	bool bReadOnly = false; // si
	char *pos; // eax
	FILE *pFile; // eax
	char Filename[260]; // [esp+4h] [ebp-104h]

	if ( GetModuleFileNameA(ghInst, Filename, sizeof(Filename)) )
	{
		pos = strrchr(Filename, '\\');
		if ( pos )
		{
			strcpy(pos + 1, "Diablo1ReadOnlyTest.foo");
			pFile = fopen(Filename, "wt");
			if ( pFile )
			{
				fclose(pFile);
				remove(Filename);
			}
			else
			{
				bReadOnly = true;
			}
		}
	}
	return bReadOnly;
}
