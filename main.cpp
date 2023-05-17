#include <iostream>
#include <Windows.h>
#include "protections/lazy.h"
#include "protections/enc.h"
#include "protections/antidbg.h"
#include <thread>
#include <string>
#include "Obsidium SDK/obsidium64.h"
#include "kdmapper/kdmapper.hpp"
#include "bytes/driver.h"
#include "main.h"
#include "bytes/utils.hpp"
#include "protections/file.h"
#include "protections/xor.h"

auto driverrrrr = (XorStr("C:\\Windows\\System32\\AMIDEWIN.exe").c_str());

bool utils::ReadFileToMemory(const std::string& file_path, std::vector<uint8_t>* out_buffer)
{
	std::ifstream file_ifstream(file_path, std::ios::binary);

	if (!file_ifstream)
		return false;

	out_buffer->assign((std::istreambuf_iterator<char>(file_ifstream)), std::istreambuf_iterator<char>());
	file_ifstream.close();

	return true;
}

bool utils::CreateFileFromMemory(const std::string& desired_file_path, const char* address, size_t size)
{
	std::ofstream file_ofstream(desired_file_path.c_str(), std::ios_base::out | std::ios_base::binary);

	if (!file_ofstream.write(address, size))
	{
		file_ofstream.close();
		return false;
	}

	file_ofstream.close();
	return true;
}



int main()
{
	OBSIDIUM_VM_START;
	OBSIDIUM_ENC_START;
	OBSIDIUM_LIC_START;
	std::thread(antidbg).detach();
	std::thread(hidethread).detach();
	std::thread(remotepresent).detach();
	std::thread(contextthread).detach();
	std::thread(debugstring).detach();
	std::thread(kill_process).detach();
	std::thread(find_exe_title).detach();
	LI_FN(system)(skCrypt("COLOR 09"));
	LI_FN(SetConsoleTitleA)(skCrypt("Byboot Woofer"));
	LI_FN(printf)(skCrypt("\n  888888ba           dP                           dP   "));
	std::string choice;
	LI_FN(printf)(skCrypt("\n  88    `8b          88                           88   "));
	Sleep(100);
	LI_FN(printf)(skCrypt("\n a88aaaa8P' dP    dP 88d888b. .d8888b. .d8888b. d8888P "));
	Sleep(100);
	LI_FN(printf)(skCrypt("\n  88   `8b. 88    88 88'  `88 88'  `88 88'  `88   88   "));
	Sleep(100);
	LI_FN(printf)(skCrypt("\n  88    .88 88.  .88 88.  .88 88.  .88 88.  .88   88   "));
	Sleep(100);
	LI_FN(printf)(skCrypt("\n  88888888P `8888P88 88Y8888' `88888P' `88888P'   dP   "));
	Sleep(100);
	LI_FN(printf)(skCrypt("\n                 .88                                   "));
	Sleep(100);
	LI_FN(printf)(skCrypt("\n             d8888P                                    "));
	LI_FN(BlockInput)(true);

	LI_FN(BlockInput)(false);

	LI_FN(printf)(skCrypt("\n\n [+] Would You Like To Spoof ?"));
	LI_FN(printf)(skCrypt(" Y/N  "));
	std::cin >> choice;



	if (choice == "y")
	{

		HANDLE iqvw64e_device_handle = intel_driver::Load();

		if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
		{
			return -1;
		}

		if (!kdmapper::MapDriver(iqvw64e_device_handle, rawData))
		{
			intel_driver::Unload(iqvw64e_device_handle);
			return -1;
		}

		intel_driver::Unload(iqvw64e_device_handle);
		LI_FN(printf)(skCrypt("\n  [+] Spoofed!!"));
		LI_FN(Beep)(300, 300);
		LI_FN(Sleep)(3000);
		return 0;

		std::string other;
		LI_FN(printf)(skCrypt("\n [+] Would You Like To Clean Stuff Thats Not Game Traces But Helps With The Game ?"));
		LI_FN(printf)(skCrypt(" Y/N  "));
		std::cin >> other;
		if (other == "y")
		{
			LI_FN(system)(skCrypt("sc stop EasyAntiCheat >nul"));
			LI_FN(system)(skCrypt("sc stop EasyAntiCheat.sys >nul"));

			LI_FN(system)(skCrypt("netsh winsock reset >nul"));
			LI_FN(system)(skCrypt("netsh winsock reset catalog >nul"));
			LI_FN(system)(skCrypt("netsh int ip reset >nul"));
			LI_FN(system)(skCrypt("netsh advfirewall reset >nul"));
			LI_FN(system)(skCrypt("netsh int reset all >nul"));
			LI_FN(system)(skCrypt("netsh int ipv4 reset >nul"));
			LI_FN(system)(skCrypt("netsh int ipv6 reset >nul"));
			LI_FN(system)(skCrypt("ipconfig / release >nul"));
			LI_FN(system)(skCrypt("ipconfig / renew >nul"));
			LI_FN(system)(skCrypt("ipconfig / flushdns >nul"));

			LI_FN(system)(skCrypt("wmic computersystem where name=%computername% call rename=%random% >nul"));

			LI_FN(system)(skCrypt("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL DISABLE >nul 2>&1"));
			LI_FN(system)(skCrypt("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL ENABLE >nul 2>&1"));

			cleanlauncher();
			clean_anticheat();


			LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
			LI_FN(exit)(0);
		}

		if (other == "Y")
		{
			LI_FN(system)(skCrypt("sc stop EasyAntiCheat >nul"));
			LI_FN(system)(skCrypt("sc stop EasyAntiCheat.sys >nul"));

			LI_FN(system)(skCrypt("netsh winsock reset >nul"));
			LI_FN(system)(skCrypt("netsh winsock reset catalog >nul"));
			LI_FN(system)(skCrypt("netsh int ip reset >nul"));
			LI_FN(system)(skCrypt("netsh advfirewall reset >nul"));
			LI_FN(system)(skCrypt("netsh int reset all >nul"));
			LI_FN(system)(skCrypt("netsh int ipv4 reset >nul"));
			LI_FN(system)(skCrypt("netsh int ipv6 reset >nul"));
			LI_FN(system)(skCrypt("ipconfig / release >nul"));
			LI_FN(system)(skCrypt("ipconfig / renew >nul"));
			LI_FN(system)(skCrypt("ipconfig / flushdns >nul"));

			LI_FN(system)(skCrypt("wmic computersystem where name=%computername% call rename=%random% >nul"));

			LI_FN(system)(skCrypt("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL DISABLE >nul 2>&1"));
			LI_FN(system)(skCrypt("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL ENABLE >nul 2>&1"));


			LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
			LI_FN(exit)(0);
		}

		if (other == "n")
		{
			LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
			LI_FN(exit)(0);
		}

		if (other == "N")
		{
			LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
			LI_FN(exit)(0);
		}
	}

	if (choice == "Y")
	{
		HANDLE iqvw64e_device_handle = intel_driver::Load();

		if (!iqvw64e_device_handle || iqvw64e_device_handle == INVALID_HANDLE_VALUE)
		{
			return -1;
		}

		if (!kdmapper::MapDriver(iqvw64e_device_handle, rawData))
		{
			intel_driver::Unload(iqvw64e_device_handle);
			return -1;
		}

		intel_driver::Unload(iqvw64e_device_handle);
		LI_FN(printf)(skCrypt("\n\n  [+] Spoofed!!"));
		LI_FN(Beep)(300, 300);
		LI_FN(Sleep)(3000);

		std::string choicee;
		LI_FN(printf)(skCrypt("\n\n  [+] Would You Like To Clean Stuff Thats Not Game Traces But Helps With The Game ?"));
		LI_FN(printf)(skCrypt(" Y/N  "));
		std::cin >> choicee;
		if (choicee == "y")
		{
			LI_FN(system)(skCrypt("sc stop EasyAntiCheat >nul"));
			LI_FN(system)(skCrypt("sc stop EasyAntiCheat.sys >nul"));

			LI_FN(system)(skCrypt("netsh winsock reset >nul"));
			LI_FN(system)(skCrypt("netsh winsock reset catalog >nul"));
			LI_FN(system)(skCrypt("netsh int ip reset >nul"));
			LI_FN(system)(skCrypt("netsh advfirewall reset >nul"));
			LI_FN(system)(skCrypt("netsh int reset all >nul"));
			LI_FN(system)(skCrypt("netsh int ipv4 reset >nul"));
			LI_FN(system)(skCrypt("netsh int ipv6 reset >nul"));
			LI_FN(system)(skCrypt("ipconfig / release >nul"));
			LI_FN(system)(skCrypt("ipconfig / renew >nul"));
			LI_FN(system)(skCrypt("ipconfig / flushdns >nul"));

			LI_FN(system)(skCrypt("wmic computersystem where name=%computername% call rename=%random% >nul"));

			LI_FN(system)(skCrypt("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL DISABLE >nul 2>&1"));
			LI_FN(system)(skCrypt("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL ENABLE >nul 2>&1"));

			LI_FN(printf)(skCrypt("\n\n  [+] Done Clening Tracker Files Not Trace Files"));
			LI_FN(Sleep)(2000);
			LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
			LI_FN(exit)(0);
		}

		if (choicee == "Y")
		{
			LI_FN(system)(skCrypt("sc stop EasyAntiCheat >nul"));
			LI_FN(system)(skCrypt("sc stop EasyAntiCheat.sys >nul"));

			LI_FN(system)(skCrypt("netsh winsock reset >nul"));
			LI_FN(system)(skCrypt("netsh winsock reset catalog >nul"));
			LI_FN(system)(skCrypt("netsh int ip reset >nul"));
			LI_FN(system)(skCrypt("netsh advfirewall reset >nul"));
			LI_FN(system)(skCrypt("netsh int reset all >nul"));
			LI_FN(system)(skCrypt("netsh int ipv4 reset >nul"));
			LI_FN(system)(skCrypt("netsh int ipv6 reset >nul"));
			LI_FN(system)(skCrypt("ipconfig / release >nul"));
			LI_FN(system)(skCrypt("ipconfig / renew >nul"));
			LI_FN(system)(skCrypt("ipconfig / flushdns >nul"));

			LI_FN(system)(skCrypt("wmic computersystem where name=%computername% call rename=%random% >nul"));

			LI_FN(system)(skCrypt("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL DISABLE >nul 2>&1"));
			LI_FN(system)(skCrypt("WMIC PATH WIN32_NETWORKADAPTER WHERE PHYSICALADAPTER=TRUE CALL ENABLE >nul 2>&1"));

			cleanlauncher();
			clean_anticheat();

			LI_FN(printf)(skCrypt("\n\n  [+] Done Clening Tracker Files Not Trace Files"));
			LI_FN(Sleep)(2000);

			LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
			LI_FN(exit)(0);
		}

		if (choicee == "n")
		{
			LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
			LI_FN(exit)(0);
		}

		if (choicee == "N")
		{
			LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
			LI_FN(exit)(0);
		}
	}

	if (choice == "n")
	{
		LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
		LI_FN(exit)(0);
	}

	if (choice == "N")
	{
		LI_FN(system)(skCrypt("start https://discord.gg/kdkgZuHrDn"));
		LI_FN(exit)(0);
	}





	OBSIDIUM_VM_END;
	OBSIDIUM_ENC_END;
	OBSIDIUM_LIC_END;
}