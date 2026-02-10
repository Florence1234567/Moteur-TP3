#pragma once
#include <iostream>

class GObject {
public:
    virtual ~GObject() = default;

    virtual std::string GetType() const
    {
        return "GObject";
    };

    virtual bool IsTypeOf(const std::string& name) const
    {
        return GetType() == name;
    };
};

#define GENERATE_REFLECTION(ClassName, ParentClass) \
public: \
    std::string GetType() const override { return #ClassName; } \
    static std::string StaticType() { return #ClassName; } \
    bool IsTypeOf(const std::string& name) const override { \
        if (name == #ClassName) return true; \
        return ParentClass::IsTypeOf(name); \
} \
        
template<class T>
T* Cast(GObject* object)
{
    if (!object)
        return nullptr;

    if (object->IsTypeOf(T::StaticType()))
        return static_cast<T*>(object);

    return nullptr;
}