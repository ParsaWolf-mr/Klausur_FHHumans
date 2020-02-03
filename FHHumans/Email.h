#pragma once
#include <string>
#include <stdexcept>
class Email
{
public :
	std::string email;

public: 
	
	Email() = default;

	void setterE(const std::string& em) { this->email = em; }
	std::string getterE() { return this->email; }


	static bool validate(const std::string& e) {
		auto kapos = e.find('@');
		if (kapos == std::string::npos)
			throw std::runtime_error("Missing @");
		else if (kapos == 0)
			throw std::runtime_error("Missing Private part");
		else if (kapos + 1 >= e.length())
			throw std::runtime_error("Missing domain part");
		return true;
	}
};

