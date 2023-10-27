#pragma once

#include "data.hpp"

namespace Task
{
    bool Verify(const DataWrapper* data, const DataWrapper* reference);

    void ReadWrapper(const DataWrapper* data, const char* filePath);
} // namespace Task
