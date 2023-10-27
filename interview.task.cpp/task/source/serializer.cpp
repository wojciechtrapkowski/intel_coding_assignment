#include "serializer.hpp"
#include <fstream>
#include <iostream>
namespace Task
{
    void SerializeToFile(const DataWrapper* dataWrapper, const char* filePath)
    {
        if (!dataWrapper) {
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

        file.write(reinterpret_cast<const char*>(&dataWrapper->numBuffers), sizeof(dataWrapper->numBuffers));
        file.write(reinterpret_cast<const char*>(&dataWrapper->numData), sizeof(dataWrapper->numData));

        // Write the contents of each buffer to the file
        for (size_t i = 0; i < dataWrapper->numBuffers; i++)
        {
            // Save size of buffer
            file.write(reinterpret_cast<const char*>(&dataWrapper->buffers[i].size), sizeof(dataWrapper->buffers[i].size));

            // Save content of buffer
            for (size_t j=0; j<dataWrapper->buffers[i].size; j++) {
                file.write(reinterpret_cast<const char*>(&dataWrapper->buffers[i].data[j]), sizeof(dataWrapper->buffers[i].data[j]));
            }
        }

        // Save content of data
        for (size_t i = 0; i < dataWrapper->numData; i++)
        {
            file.write(reinterpret_cast<const char*>(&dataWrapper->data[i].value), sizeof(dataWrapper->data[i].value));
        }

        file.close();
    }

    void DeserializeFromFile(DataWrapper*& dataWrapper, const char* filePath)
    {
        if (!dataWrapper) {
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

        // Read the number of buffers and data from the file

        file.read(reinterpret_cast<char*>(&dataWrapper->numBuffers), sizeof(dataWrapper->numBuffers));
        file.read(reinterpret_cast<char*>(&dataWrapper->numData), sizeof(dataWrapper->numData));
        
        // Allocate memory for buffers in dataWrapper
        dataWrapper->buffers = new Buffer[dataWrapper->numBuffers];

        // Read the contents of each buffer from the file
        for (size_t i = 0; i < dataWrapper->numBuffers; i++)
        {
            // Read size of buffer
            file.read(reinterpret_cast<char*>(&dataWrapper->buffers[i].size), sizeof(dataWrapper->buffers[i].size));
            
            // Allocate memory for data in buffer
            dataWrapper->buffers[i].data = new uint8_t[dataWrapper->buffers[i].size];

            // Read content of buffer
            for (size_t j=0; j<dataWrapper->buffers[i].size; j++) {
                file.read(reinterpret_cast<char*>(&dataWrapper->buffers[i].data[j]), sizeof(dataWrapper->buffers[i].data[j]));
            }
        }

        // Allocate memory for data in dataWrapper
        dataWrapper->data = new Data[dataWrapper->numData];

        // Read content of data from file
        for (size_t i = 0; i < dataWrapper->numData; i++)
        {
            file.read(reinterpret_cast<char*>(&dataWrapper->data[i].value), sizeof(dataWrapper->data[i].value));
        }

        file.close();
    }
} // namespace Task
