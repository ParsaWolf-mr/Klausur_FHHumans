#pragma once
#include <string>

namespace PrintExt {

	template<typename T>
	std::string to_PrintItemStr(const std::string& p1, const T& p2) {
		return  "\"" + p1 + "\"=" + std::to_string(int(p2));
	}
	std::string to_PrintItemStr(const std::string& p1, const std::string& p2) {
		return  "\"" + p1 + "\"= \"" + p2 + "\"";
	}

}