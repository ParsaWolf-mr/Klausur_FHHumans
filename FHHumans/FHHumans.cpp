// FHHumans.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "PrintExt.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

void check_email_validation(const std::string& s)
{
	// Aufruf der Email Validierungsfunktion und Abfangen einer möglichen 
	// Exception zur Ausgabe einer Fehlermeldung auf cerr
	try {
		Email::validate(s);
	}
	catch (std::runtime_error e) {
		std::cerr << e.what() << std::endl;
	}catch(...) {
		std::cerr << "Unknow exceptions!!\n";
	}
}



int main()
{
	// -------------------------------------------------------------------
	// // Person instanziieren
	Person  p1("Mustermann, Max", 19770707, Gender::male);
	// // Student instanziieren
	Student s1("Example, Eva Maria", 19970217, Gender::female, 1910581005, "evae@gmail.com");
	// // Teacher instanziieren
	Teacher t1("Tempo, Theox", 20010605, Gender::diverse, 8976, "ttempo@fh.co.at");
	// // Einfügen eines Studenten s2 mit den eigenen Daten
	Student s2("Rostami, Marthin", 19970217, Gender::male, 1910581005, "Marthin@gmail.com");

	// -------------------------------------------------------------------
	// Testen der Methode getExtSVNr
	auto temp = t1.getExtSVNr();
	std::cout << "SV: " << temp << std::endl;

	// Testen der Klasse Email mit Getter und Setter
	Email e1;
	e1.setterE("Marthin.rostami@outlook.de");
	std::cout << "Email: " << e1.getterE() << std::endl;


	// -------------------------------------------------------------------
	// Testen der Function to_PrintItemStr aus dem Namensraum PrintExt
	PrintExt::to_PrintItemStr("Name:", "Marthin");
	PrintExt::to_PrintItemStr<int>("Mart: ", 1523435);


	// -------------------------------------------------------------------
	//  Container für Person, Studenten und Teacher befüllen
	std::vector<std::shared_ptr<Person>>persons;


	persons.push_back(std::make_shared< Person>("Mustermann, Max", 19770707, Gender::male));
	persons.push_back(std::make_shared< Student>("Example, Eva Maria", 19970217, Gender::female, 1910581005, "evae@gmail.com"));
	persons.push_back(std::make_shared< Teacher>("Tempo, Theox", 20010605, Gender::diverse, 8976, "ttempo@fh.co.at"));
	persons.push_back(std::make_shared< Student>("Rostami, Marthin", 19970217, Gender::male, 1910581005, "Marthin@gmail.com"));

	// -------------------------------------------------------------------
	// Wir testen die operator << Methode einzeln für jeden Typ
	//std::cout << p1 << std::endl;
	//std::cout << s1 << std::endl;
	//std::cout << t1 << std::endl;

	// -------------------------------------------------------------------
	// Geben Sie in einer Schleife über alle Elemente des Container die 
	// einzelnen Elemente so auf cout aus, dass eine Ausgabe passend für 
	// den jeweils zugrundeliegenden Typ erfolgt.
	for (auto& elem : persons) {
		std::cout << *elem << std::endl;
	}


	// -------------------------------------------------------------------
	// Alle Nachname in der Collection mit Hilfe von transform() und einer 
	// lambda function in Großbuchstaben konvertieren
	// INSERT YOUR CODE HERE!
	std::transform(persons.begin(), persons.end(), persons.begin(), [](std::shared_ptr<Person> p)->auto {
		std::string n = p->Name;
		auto found = n.find(',');
		if (found != std::string::npos) {
			auto nn = n.substr(0, found);
			auto nv = n.substr(found + 1);

			std::transform(nn.begin(), nn.end(), nn.begin(), ::toupper);
		}
		return p;
		});


	// -------------------------------------------------------------------
	// Email validieren über eigene kleine Validierungsfunktion
	check_email_validation("roland.graf@fh-salzburg.ac.at");
	check_email_validation("@fh-salzburg.ac.at");
	check_email_validation("roland.graf.fh-salzburg.ac.at");
	check_email_validation("roland.graf@");

	std::cout << "Bye!\n";
}

