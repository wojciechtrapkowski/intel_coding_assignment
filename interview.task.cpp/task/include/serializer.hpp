#pragma once

#include "data.hpp"

namespace Task
{
    void SerializeToFile(const DataWrapper* dataWrapper, const char* filePath);

    void DeserializeFromFile(DataWrapper*& dataWrapper, const char* filePath);
} // namespace Task
