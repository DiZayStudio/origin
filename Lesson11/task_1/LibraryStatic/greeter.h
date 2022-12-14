#pragma once
#include <string>

namespace Greet
{
	class Greeter {

	public:
		Greeter();
		std::string greet(std::string s);
	};
}