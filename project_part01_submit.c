#include <stdio.h>
#include <windows.h>


int main(int argc, char argv[], char envp[]) {

	DWORD dwNtdllBase = 0;

	__asm
	{
		xor ebx, ebx;//clear ebx
		mov eax, DWORD PTR fs:[ebx+0x30];//move to the peb and into eax
		mov eax, DWORD PTR [eax+0x0c];//move from the peb to the ldr
		mov eax, DWORD PTR [eax+0x1c];//move from the ldr to InInitializationOrderModuleList
		mov eax, DWORD PTR [eax+0x8];//moves from the list into the base address of ntdll.dll
		mov dwNtdllBase, eax;//moves teh address to dwNtdllBase

	}
	printf("[*] Found NTDLL Base at 0x%08x", dwNtdllBase);
}