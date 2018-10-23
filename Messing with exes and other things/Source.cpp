#include <iostream>
#include <Windows.h>
// trying to understand how to manipulate programs
void Space()
{
	INPUT input;
	WORD vkey = VK_SPACE;
	input.type = INPUT_KEYBOARD;
	input.ki.wScan= MapVirtualKey(vkey, MAPVK_VK_TO_VSC);

	SendInput(1, &input, sizeof(INPUT));
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));

}

bool bhop = false;

void bunnHop()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		Sleep(100);
		bhop != bhop;
	}

	if (bhop)
	{
		Space();
	}
}

int main()
{
	bunnHop();
}