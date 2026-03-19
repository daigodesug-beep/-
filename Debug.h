#pragma once
#include <iostream>

class Debug
{
private:
	static FILE* m_stream;

public:
	static void Initialize();
	static void Finalize();

	template <typename ...Args>
	static void Log(const char* format, Args const & ...args)
	{
#ifdef _DEBUG
		printf(format, args ...);
#endif
	}
};