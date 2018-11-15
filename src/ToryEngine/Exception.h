#include <exception>
#include <string>

namescpae toryengine
{
	class Exception : public std::exception
{
public:
	Exception(const std::string _message);
	~Exception() throw();
	virtual const char *what();

private:
	std::string message;
};
}