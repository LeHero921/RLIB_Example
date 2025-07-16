#include "base.h"
#include "resourceLoader.h"

ResourceLoader::ResourceLoader()
{
    ;
};

ResourceLoader::~ResourceLoader()
{
    ;
};

bool ResourceLoader::loadResource(const std::string& path)
{
    return false;
};

bool ResourceLoader::unloadResource(const std::string& path)
{
    return false;
};

bool ResourceLoader::unloadAll()
{
    return false;
};