#pragma once
#include <exception>
#include <string>

namespace toryengine
{
	class Exception : public std::exception
	{
	public:
		Exception(const std::string _message);
		//~Exception() throw();
		virtual const char *what() { return message.c_str(); }

	private:
		std::string message;
	};
}