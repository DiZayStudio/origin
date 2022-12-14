#include "greeter.h"

namespace Greet
{
	Greeter::Greeter() {};
	std::string Greeter::greet(std::string s) {
		return ("Здравствуйте, " + s);
	};
}