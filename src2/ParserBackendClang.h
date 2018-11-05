#ifndef CLANGPARSERBACKEND_H__
#define CLANGPARSERBACKEND_H__

#include "AbstractParserBackend.h"
#include <string>

class ClangParserBackend : public AbstractParserBackend
{
public:

	virtual void parseFile(const std::string& filename) override;
};

#endif // !CLANGPARSERBACKEND_H__
