#pragma once
#include <Windows.h>
#include <winternl.h>
#include <vector>
#include <stdexcept>
#include <TlHelp32.h>
#include <intrin.h>
#include "enc.h"
#include "lazy.h"
#include "xor.h"
#include <thread>
#include <chrono>
extern "C"
{
	NTSTATUS NTAPI RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN OldValue);
	NTSTATUS NTAPI NtRaiseHardError(LONG ErrorStatus, ULONG NumberOfParameters, ULONG UnicodeStringParameterMask, PULONG_PTR Parameters, ULONG ValidResponseOptions, PULONG Response);
}

std::uintptr_t process_find(const std::string& name)
{
	const auto snap = LI_FN(CreateToolhelp32Snapshot).safe()(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return 0;
	}

	PROCESSENTRY32 proc_entry{};
	proc_entry.dwSize = sizeof proc_entry;

	auto found_process = false;
	if (!!LI_FN(Process32First).safe()(snap, &proc_entry)) {
		do {
			if (name == proc_entry.szExeFile) {
				found_process = true;
				break;
			}
		} while (!!LI_FN(Process32Next).safe()(snap, &proc_entry));
	}

	LI_FN(CloseHandle).safe()(snap);
	return found_process
		? proc_entry.th32ProcessID
		: 0;
}

void antidbg()
{
	while (true)
	{
		BOOL IsDebugged = IsDebuggerPresent();
		if (IsDebugged)
		{
			LI_FN(exit)(0);
		}
	}
}

void find_exe_title()
{
	while (true) {
		if (process_find(XorStr("KsDumperClient.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("HTTPDebuggerUI.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("HTTPDebuggerSvc.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("FolderChangesView.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("ProcessHacker.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("procmon.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("idaq.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("idaq64.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("Wireshark.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("Fiddler.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("Xenos64.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("Cheat Engine.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("HTTP Debugger Windows Service (32 bit).exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("KsDumper.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("x64dbg.exe")))
		{
			LI_FN(exit)(0);
		}
		else if (process_find(XorStr("ProcessHacker.exe")))
		{
			LI_FN(exit)(0);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	}
}

typedef NTSTATUS(__stdcall* _NtQueryInformationProcess)(_In_ HANDLE, _In_  unsigned int, _Out_ PVOID, _In_ ULONG, _Out_ PULONG);
typedef NTSTATUS(__stdcall* _SetInformationThread)(_In_ HANDLE, _In_ THREAD_INFORMATION_CLASS, _In_ PVOID, _In_ ULONG);
typedef NTSTATUS(__stdcall* _NtSetInformationThread)(_In_ HANDLE, _In_ THREAD_INFORMATION_CLASS, _In_ PVOID, _In_ ULONG);


int remotepresent()
{
	int debugger_present = false;

	LI_FN(CheckRemoteDebuggerPresent).safe()(LI_FN(GetCurrentProcess).safe()(), &debugger_present);

	return debugger_present;
}

void kill_process()
{
	while (1)
	{

		LI_FN(system)(skCrypt("taskkill /f /im procexp.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im procexp64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im procexp64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im mafiaengine-i386.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Mafia Engine.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im mafiaengine-x86_64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Tutorial-i386.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Tutorial-x86_64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im mafiaengine-x86_64-SSE4-AVX2.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im KsDumperClient.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im KsDumper.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im ProcessHacker.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im idaq.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im idaq64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Wireshark.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Fiddler.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im FiddlerEverywhere.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Xenos64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Xenos.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Xenos32.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im de4dot.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Cheat Engine.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im cheatengine-x86_64-SSE4-AVX2.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im MugenJinFuu-x86_64-SSE4-AVX2.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im MugenJinFuu-i386.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im cheatengine-i386.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im HTTP Debugger Windows Service (32 bit).exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im KsDumper.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im OllyDbg.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im x64dbg.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im x32dbg.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Ida64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im OllyDbg.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Dbg64.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im Dbg32.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /f /im ida.exe >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1"));
		LI_FN(system)(skCrypt("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1"));
	}
}

int debugstring()
{
	LI_FN(SetLastError).safe()(0);
	LI_FN(OutputDebugStringA).safe()(XorStr("DENUVO Security").c_str());
	const auto last_error = LI_FN(GetLastError).safe()();

	return last_error != 0;
}


int contextthread()
{
	int found = false;
	CONTEXT ctx = { 0 };
	void* h_thread = LI_FN(GetCurrentThread).safe()();

	ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
	if (LI_FN(GetThreadContext).safe()(h_thread, &ctx))
	{
		if ((ctx.Dr0 != 0x00) || (ctx.Dr1 != 0x00) || (ctx.Dr2 != 0x00) || (ctx.Dr3 != 0x00) || (ctx.Dr6 != 0x00) || (ctx.Dr7 != 0x00))
		{
			found = true;
		}
	}

	return found;
}

int hidethread()
{
	unsigned long thread_hide_from_debugger = 0x11;

	const auto ntdll = LI_FN(LoadLibraryA).safe()(XorStr("ntdll.dll").c_str());

	if (ntdll == INVALID_HANDLE_VALUE || ntdll == NULL) { return false; }

	_NtQueryInformationProcess NtQueryInformationProcess = NULL;
	NtQueryInformationProcess = (_NtQueryInformationProcess)LI_FN(GetProcAddress).safe()(ntdll, XorStr("NtQueryInformationProcess").c_str());

	if (NtQueryInformationProcess == NULL) { return false; }

	(_NtSetInformationThread)(GetCurrentThread(), thread_hide_from_debugger, 0, 0, 0);

}



int anti_dump()
{
	const auto peb = (PPEB)__readgsqword(0x60);

	const auto in_load_order_module_list = (PLIST_ENTRY)peb->Ldr->Reserved2[1];
	const auto table_entry = CONTAINING_RECORD(in_load_order_module_list, LDR_DATA_TABLE_ENTRY, Reserved1[0]);
	const auto p_size_of_image = (PULONG)&table_entry->Reserved3[1];
	*p_size_of_image = (ULONG)((INT_PTR)table_entry->DllBase + 0x100000);

	return 0;

};


