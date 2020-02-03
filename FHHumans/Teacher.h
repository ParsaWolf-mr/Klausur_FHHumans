#pragma once
#include "Person.h"
#include "Email.h"
#include "PrintExt.h"

class Teacher :
	public Person, public Email
{
protected:
	unsigned short sv;

public:
	Teacher() = default;
	Teacher(const std::string& str, unsigned int b, Gender g, unsigned short s, const std::string& em):Person(str, b, g),sv(s){
		Email::setterE(em);
	}

	std::string  getExtSVNr() {
		std::string temp = std::to_string(birthday);

		return std::to_string(sv) + temp.substr(6, 2) + temp.substr(4, 2) + temp.substr(2, 2);
	}	

	virtual std::ostream& sout(std::ostream& out) {
		out << "Teacher={";
		Person::sout(out);
		out << PrintExt::to_PrintItemStr("SV", sv) << ", ";
		out << PrintExt::to_PrintItemStr("Email", email);
		out << "}";
		return out;
	}
};

