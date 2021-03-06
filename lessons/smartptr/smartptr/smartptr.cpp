#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// unique
// shared
// weak

class SomeClass
{
public:
	SomeClass()
	{
		std::cout << "SomeClass is created!\n";
	}
	~SomeClass()
	{
		std::cout << "SomeClass is destroyed!\n";
	}
	void something() {};
private:

};

int main()
{
/*	SomeClass* someClass = new SomeClass();
	someClass->something();
	delete[] someClass;	*/										// klasična new/delete implementacija


	{															// blank scope
		std::unique_ptr<SomeClass> someClass(new SomeClass);
	}

	// std::unique_ptr<SomeClass> secondClass = someClass;			// unique pointer ne može transferat ownership, nema copy operatora
															    	// deleta se kad izađe iz scopea (zato jer prvi koji nestane čisti memoriju ne smije postojavi više kopija)

	{
		std::shared_ptr<SomeClass> sharedClassSecond;	// osim memorije za objekt drži i reference count u memoriji
		// make shared odjednom poziva new i alocira sve potrebno						// dealocira memoriju tek kada taj reference count padne na 0
		{
			std::shared_ptr<SomeClass> sharedClassFirst = std::make_shared<SomeClass>();
			sharedClassSecond = sharedClassFirst;						// kopija pointera
		}
	}

	{
		std::weak_ptr<SomeClass> sharedClassSecond;			// shared pointer koji ne povećava reference count
		{
			std::shared_ptr<SomeClass> sharedClassFirst = std::make_shared<SomeClass>();
			sharedClassSecond = sharedClassFirst;
		}
	}


	system("pause");
    return 0;
}

