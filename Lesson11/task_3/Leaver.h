#pragma once

#include <string>

#ifdef LIBRARYDYNAMIC_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif
namespace Dynamic
{
	class Leaver
	{
	public:
		LIBRARY_API std::string leave(std::string s);
	};
}