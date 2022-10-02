#include <thread>
#include <eyestep_utility.h>

using namespace EyeStep::scanner;
using namespace EyeStep::util;

using print_typedef = int(__cdecl*)(int, const char*, ...);
print_typedef print;

int main()
{
	EyeStep::open(GetCurrentProcess());
	print = reinterpret_cast<print_typedef>(getPrologue(nextCall(scan_xrefs("Video recording started")[0])));

	print(0, "white color");
	print(1, "blue color");
	print(2, "yellow color");
	print(3, "red color");
}

int __stdcall DllMain(void*, int reason, void*)
{
	if (reason == 1)
	{
		std::thread(main).detach();
	}
	return 1;
}
