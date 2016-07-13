#ifndef ABSTRACTPARSERBACKEND_H__
#define ABSTRACTPARSERBACKEND_H__

#include <string>

class AbstractParserBackend
{
public:

	virtual void parseFile(const std::string& filename) = 0;
};

#endif // !ABSTRACTPARSERBACKEND_H__
