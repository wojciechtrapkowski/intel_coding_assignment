#include "serializer.hpp"
#include <fstream>
#include <iostream>
namespace Task
{
    void SerializeToFile(const DataWrapper* data, const char* filePath)
    {
        if (!data) {
            std::cerr << "Error: data is null" << std::endl;
            return;
        }

        if (!filePath || filePath[0] == '\0') {
            std::cerr << "Error: filePath is null or empty" << std::endl;
            return;
        }

        std::ofstream file(filePath, std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "Error: failed to open file " << filePath << std::endl;
            return;
        }

        // Write the number of buffers and data to the file

        file.write(reinterpret_cast<const char*>(&data->numBuffers), sizeof(data->numBuffers));
        file.write(reinterpret_cast<const char*>(&data->numData), sizeof(data->numData));

        // Write the contents of each buffer to the file
        for (size_t i = 0; i < data->numBuffers; i++)
        {
            // Save size of buffer
            file.write(reinterpret_cast<const char*>(&data->buffers[i].size), sizeof(data->buffers[i].size));

            // Save content of buffer
            for (size_t j=0; j<data->buffers[i].size; j++) {
                file.write(reinterpret_cast<const char*>(&data->buffers[i].data[j]), sizeof(data->buffers[i].data[j]));
            }
        }

        // Save content of data
        for (size_t i = 0; i < data->numData; i++)
        {
            file.write(reinterpret_cast<const char*>(&data->data[i].value), sizeof(data->data[i].value));
        }

        file.close();
    }

    void DeserializeFromFile(DataWrapper*& data, const char* filePath)
    {
        if (!data) {
            std::cerr << "Error: data is null" << std::endl;
            return;
        }

        if (!filePath || filePath[0] == '\0') {
            std::cerr << "Error: filePath is null or empty" << std::endl;
            return;
        }

        std::ifstream file(filePath, std::ios::binary);

        if (!file.is_open()) {
            std::cerr << "Error: failed to open file " << filePath << std::endl;
            return;
        }

        // Read the number of buffers and data to the file

        file.read(reinterpret_cast<char*>(&data->numBuffers), sizeof(data->numBuffers));
        file.read(reinterpret_cast<char*>(&data->numData), sizeof(data->numData));
        
        // Allocate memory for buffers in data
        data->buffers = new Buffer[data->numBuffers];

        // Read the contents of each buffer from the file
        for (size_t i = 0; i < data->numBuffers; i++)
        {
            // Read size of buffer
            file.read(reinterpret_cast<char*>(&data->buffers[i].size), sizeof(data->buffers[i].size));
            
            // Allocate memory for data in buffers
            data->buffers[i].data = new uint8_t[data->buffers[i].size];

            // Read content of buffer
            for (size_t j=0; j<data->buffers[i].size; j++) {
                file.read(reinterpret_cast<char*>(&data->buffers[i].data[j]), sizeof(data->buffers[i].data[j]));
            }
        }
        data->data = new Data[data->numData];

        // Read content of data in data structure
        for (size_t i = 0; i < data->numData; i++)
        {
            file.read(reinterpret_cast<char*>(&data->data[i].value), sizeof(data->data[i].value));
        }

        file.close();
    }
} // namespace Task
