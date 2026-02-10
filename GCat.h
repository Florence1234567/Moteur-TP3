#pragma once
#include <iostream>
#include "GAnimal.h"

class GCat : public GAnimal {
    GENERATE_REFLECTION(GCat, GAnimal)

public:
    GCat(const std::string& name) : GAnimal(name) {}
    ~GCat() = default;
    
    void MakeNoise() const override { std::cout << "Miaw" << std::endl; }
};