#ifndef DaevaCodeGenerator_h__
#define DaevaCodeGenerator_h__

#include "CodeGenerator.h"


#include <stdio.h>

class DaevaCodeGenerator : public CodeGenerator
{
public:
	DaevaCodeGenerator();

	virtual void onClassDecl(const Class& c) override;
	virtual void onMethodDecl(const Method& m) override;

private:
	FILE* target;

};
#endif // DaevaCodeGenerator_h__
