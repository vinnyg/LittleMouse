#pragma once
#include <exception>
#include <SDL.h>
#include <string>

namespace LM
{
	class Exception :
		public std::exception
	{
	private:
		std::string exceptionString;
		std::string function;
		std::string sdlError;
	public:
		Exception(std::string functionName);
		virtual ~Exception();
		char const* what() const noexcept;
		std::string GetFunction() const;
		std::string GetSDLError() const;
	};
}

