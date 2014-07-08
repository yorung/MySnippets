// Fiber.cpp : Defines the entry point for the console application.
//

#include <Windows.h>
#include <stdio.h>

LPVOID mainFiber;
LPVOID fiberA;
LPVOID fiberB;

VOID WINAPI FiberA(DWORD)
{
	for (;;) {
		puts("A");
		SwitchToFiber(mainFiber);
		puts("B");
		SwitchToFiber(mainFiber);
		puts("C");
		SwitchToFiber(mainFiber);
	}
}

VOID WINAPI FiberB(DWORD)
{
	for (;;) {
		puts("1");
		SwitchToFiber(mainFiber);
		puts("2");
		SwitchToFiber(mainFiber);
		puts("3");
		SwitchToFiber(mainFiber);
	}
}

int main(int argc, WCHAR* argv[])
{
	fiberA = CreateFiber(0, (LPFIBER_START_ROUTINE)FiberA, (LPVOID)0);
	fiberB = CreateFiber(0, (LPFIBER_START_ROUTINE)FiberB, (LPVOID)0);
	mainFiber = ConvertThreadToFiber(NULL);
	for (int i = 0; i < 20; i++) {
		SwitchToFiber(fiberA);
		SwitchToFiber(fiberB);
		Sleep(100);
	}
	return 0;
}

