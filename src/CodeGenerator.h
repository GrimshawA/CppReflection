#ifndef CodeGenerator_h__
#define CodeGenerator_h__

class Class;
class Method;

class CodeGenerator
{
public:

	virtual void onClassDecl(const Class& c){}
	virtual void onMethodDecl(const Method& m) {}

};
#endif // CodeGenerator_h__
