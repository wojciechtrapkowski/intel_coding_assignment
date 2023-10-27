#include "verifier.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

namespace Task
{
    bool Verify(const Task::DataWrapper* wrapper, const Task::DataWrapper* referenceWrapper)
    {
        if (wrapper == referenceWrapper)
            return true;

        if ((wrapper == nullptr && referenceWrapper != nullptr) || (wrapper != nullptr && referenceWrapper == nullptr))
            return false;

        if (wrapper->numBuffers != referenceWrapper->numBuffers)
            return false;

        for (size_t bufferIdx = 0; bufferIdx < wrapper->numBuffers; ++bufferIdx) {
            const auto& buffer          = wrapper->buffers[bufferIdx];
            const auto& referenceBuffer = referenceWrapper->buffers[bufferIdx];
            if (buffer.size != referenceBuffer.size)
                return false;
            // Was referenceWrapper->data, fixed it to: referenceBuffer.data
            if (std::memcmp(buffer.data, referenceBuffer.data, buffer.size) != 0)
                return false;
        }

        if (wrapper->numData != referenceWrapper->numData)
            return false;

        for (size_t dataIdx = 0; dataIdx < wrapper->numData; ++dataIdx) {
            const auto& data          = wrapper->data[dataIdx];
            const auto& referenceData = referenceWrapper->data[dataIdx];

            if (data.value != referenceData.value)
                return false;
        }

        return true;
    }

    void ReadWrapper(const DataWrapper* data, const char* filePath) {
        std::ofstream outputFile;

        if (filePath == nullptr) return; 

        if (!filePath || filePath[0] == '\0') {
            std::cerr << "Error: filePath is null or empty" << std::endl;
            return;
        }

        outputFile.open(filePath);

        if (!outputFile.is_open()) {
            std::cerr << "Error: failed to open file " << filePath << std::endl;
            return;
        }        
        
        outputFile << "Number of buffers " << data->numBuffers << std::endl;
        outputFile << "Number of data " << data->numData << std::endl;
        
        outputFile << "Reading buffers: " << std::endl;
        for(size_t i=0; i < data->numBuffers; i++) {
            outputFile << "\t Buffer " << i << " size: " << data->buffers[i].size << std::endl;
            outputFile << "\t Buffer " << i << " data: " << std::endl;
            
            for (size_t j=0; j<data->buffers[i].size; j++) {
                outputFile << "\t \t Buffer " << i << " data " << j << " " << data->buffers[i].data[j] << std::endl;
            }
        }

        outputFile << "Reading data: " << std::endl;
        for(size_t i=0; i < data->numData; i++) {
            outputFile << "\t Data " << i << " value: " << data->data[i].value << std::endl;
        }
        
        outputFile.close();
        
    }
} // namespace Task
