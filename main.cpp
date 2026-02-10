#include <iostream>
#include <vector>

#include "GObject.h"
#include "GAnimal.h"
#include "GCat.h"
#include "GDog.h"

int main() {
	GCat cat1("Oreo");
	GCat cat2("Daisy");
	GDog dog1("Violette");
	GDog dog2("Violet");

	std::cout << "Cat 1: " << cat1.GetType() << std::endl;
	std::cout << "Cat 2: " << cat2.GetType() << std::endl;
	std::cout << "Dog 1: " << dog1.GetType() << std::endl;
	std::cout << "Dog 2: " << dog2.GetType() << std::endl;\
	std::cout << std::endl;
	
	std::cout << "cat1.IsTypeOf('GCat'): " << cat1.IsTypeOf("GCat") << std::endl;
	std::cout << "cat2.IsTypeOf('GDog'): " << cat2.IsTypeOf("GDog") << std::endl;
	std::cout << "dog1.IsTypeOf('GAnimal'): " << dog1.IsTypeOf("GAnimal") << std::endl;
	std::cout << "dog2.IsTypeOf('GObject'): " << dog2.IsTypeOf("GObject") << std::endl;
	std::cout << std::endl;
	
	std::vector<GAnimal*> animals;
	animals.push_back(&cat1);
	animals.push_back(&cat2);
	animals.push_back(&dog1);
	animals.push_back(&dog2);

	for (auto animal : animals)
	{
		GCat* cat = Cast<GCat>(animal);

		if (cat != nullptr)
			cat->MakeNoise();
	}

	std::cout << std::endl;
	
	for (auto animal : animals)
	{
		GDog* dog = Cast<GDog>(animal);

		if (dog != nullptr)
			dog->MakeNoise();
	}

	std::cout << std::endl;

	std::cout << "GAnimal::StaticType(): " << GAnimal::StaticType() << std::endl;
	std::cout << "GCat::StaticType(): " << GCat::StaticType() << std::endl;
	std::cout << "GDog::StaticType(): " << GDog::StaticType() << std::endl;

	return 0;
}