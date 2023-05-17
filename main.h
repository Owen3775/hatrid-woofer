#include <iostream>
#include <Windows.h>
#include "protections/lazy.h"
#include "protections/enc.h"




void cleanlauncher()
{
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\\Epic Games\\Launcher\\Engine\\Config\\Base.ini >nul"));
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\\Epic Games\\Launcher\\Engine\\Config\\BaseGame.ini >nul"));
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\\Epic Games\\Launcher\\Engine\\Config\\Windows\\WindowsGame.ini >nul"));
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\\Epic Games\\Launcher\\Engine\\Config\\BaseInput.ini >nul"));
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\\Epic Games\\Launcher\\Portal\\Config\\UserLightmass.ini >nul"));
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\\Epic Games\\Launcher\\Engine\\Config\\Windows\\BaseWindowsLightmass.ini >nul"));
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\Epic Games\\Launcher\\Portal\\Config\\UserScalability.ini >nul"));
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\Epic Games\\Launcher\\Engine\\Config\\BaseHardware.ini >nul"));
	DeleteFileW(skCrypt(L"C:\\Program Files(x86)\Epic Games\\Launcher\\Portal\\Config\\NotForLicensees\\Windows\\WindowsHardware.ini >nul"));
}

void clean_anticheat()
{
	LI_FN(system)(skCrypt("reg delete HKLM\\SOFTWARE\\WOW6432Node\\EasyAntiCheat /f >nul"));
	LI_FN(system)(skCrypt("reg delete HKLM\\SYSTEM\\ControlSet001\\Services\\EasyAntiCheat /f >nul"));
	LI_FN(system)(skCrypt("reg delete HKLM\\SYSTEM\\ControlSet001\\Services\\BEService /f >nul"));
}