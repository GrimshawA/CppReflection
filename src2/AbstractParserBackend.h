#ifndef ABSTRACTPARSERBACKEND_H__
#define ABSTRACTPARSERBACKEND_H__

#include <string>

class CodeGenerator;

class AbstractParserBackend
{
public:

	virtual void parseFile(const std::string& filename) = 0;
	void setCodeGenerator(CodeGenerator* generator);

	CodeGenerator* m_codeGen;
	
};

#endif // !ABSTRACTPARSERBACKEND_H__
