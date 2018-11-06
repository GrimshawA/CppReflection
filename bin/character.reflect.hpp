#ifndef REFLECT_HPP_
#define REFLECT_HPP_

template<>
class reflection<GameObject> {
	static const char* name;

	std::vector<reflection_field> fields;
};

template<>
class reflection<Character> {
	static const char* name;

	std::vector<reflection_field> fields;
};

#endif
