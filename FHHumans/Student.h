#pragma once
#include "Person.h"
#include "Email.h"
#include "PrintExt.h"

using MART = unsigned long long;
class Student :
	public Person, public Email
{
protected:
	 MART mart;

public:
	Student() = default;
	Student(const std::string& str, unsigned int b, Gender g,MART m, const std::string& em):Person(str,b,g),mart(m){
		Email::setterE(em);
	}


	virtual std::ostream& sout(std::ostream& out) {
		out << "Studen={";
		Person::sout(out);
		out << PrintExt::to_PrintItemStr("Martk", mart) << ", ";
		out << PrintExt::to_PrintItemStr("Email", email);
		out << "}";
		return out;
	}
};

