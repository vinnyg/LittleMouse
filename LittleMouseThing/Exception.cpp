#include "Exception.h"

namespace LM
{
	Exception::Exception(std::string functionName)
	{
		function = functionName;
		sdlError = SDL_GetError();
		exceptionString = function + " threw an exception: " + sdlError;
	}

	Exception::~Exception()
	{
	}

	char const* Exception::what() const
	{
		return exceptionString.c_str();
	}

	std::string Exception::GetFunction() const
	{
		return function;
	}

	std::string Exception::GetSDLError() const
	{
		return sdlError;
	}
}
