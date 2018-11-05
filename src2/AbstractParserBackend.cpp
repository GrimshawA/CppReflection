#include "AbstractParserBackend.h"

void AbstractParserBackend::setCodeGenerator(CodeGenerator* generator)
{
	m_codeGen = generator;
}