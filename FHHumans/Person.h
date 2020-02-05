#pragma once
#include <string>
#include <iostream>
#include "PrintExt.h"


enum class Gender{male,female, diverse};
std::string ToString(Gender g) {
	switch (g)
	{
	case Gender::male: return "male";
	case Gender::female: return "female";
	case Gender::diverse: return "diverse";
	}
	return "nuknown!!!";
}
class Person
{
public:
	std::string Name;
	unsigned int birthday;
	Gender gender;

public:
	Person() = default;
	Person(const std::string& str, unsigned int b, Gender g) : Name(str), birthday(b), gender(g) {}


	virtual std::ostream& sout(std::ostream& out) {
		out << "Person={";
		out << PrintExt::to_PrintItemStr("Name", Name) << ", ";
		out << PrintExt::to_PrintItemStr("Geburthtag", birthday) << ", ";
		out << PrintExt::to_PrintItemStr("Gender",ToString( gender));
		out << "}";
		return out;
	}



};

inline std::ostream& operator<<(std::ostream& s, Person& p) {
	return p.sout(s);
}
