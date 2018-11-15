#include "Exception.h"

Exception::Exception(std::string _message)
{
	message = _message;
}

const char Exception::what()
{
	return message;
}