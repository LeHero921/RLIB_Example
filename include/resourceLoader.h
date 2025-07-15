#pragma once
#include <iostream>

class ResourceLoader
{
public:
    ResourceLoader();
    ~ResourceLoader();

    bool loadResource(const std::string& path);
    bool unloadResource(const std::string& path);
    bool unloadAll();
};