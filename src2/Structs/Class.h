#ifndef Class_h__
#define Class_h__

#include <string>
#include <vector>

class Method
{
public:

	class Parameter
	{
	public:
		std::string name;
		std::string type;
		
	};

	bool hasAttribute(const std::string& str) const
	{
		for (auto& s : annotations)
		{
			if (s == str)
				return true;
		}
		return false;
	}

	std::string name;
	std::string identifier;
	std::vector<Parameter> parameters;
	std::vector<std::string> annotations;
};

class Class
{
public:
	std::string name;
	std::string extendedName;
	
	std::vector<Class> innerClasses;
	std::vector<Method> methods;
};
#endif // Class_h__
