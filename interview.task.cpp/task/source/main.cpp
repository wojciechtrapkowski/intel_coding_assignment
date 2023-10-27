#include <iostream>
#include "data.hpp"
#include "serializer.hpp"
#include "verifier.hpp"
int main(int argc, char** argv)
{
    // TODO: 1. Prepare example data for serialization
    Task::DataWrapper dataWrapper;
    dataWrapper.numBuffers = 10;
    dataWrapper.numData = 13;

    dataWrapper.buffers = new Task::Buffer[dataWrapper.numBuffers];
    for(size_t i = 0; i < dataWrapper.numBuffers; i++) {
        Task::Buffer buffer;
        buffer.size = i;
        buffer.data = new uint8_t[buffer.size];

        for(size_t j = 0; j < buffer.size; j++) {
            buffer.data[j] = 'A' + j;
        }
        dataWrapper.buffers[i] = buffer;
    }

    Task::Data data;

    dataWrapper.data = new Task::Data[dataWrapper.numData];
    for(size_t i = 0; i < dataWrapper.numData; i++) {
        data.value = i;
        dataWrapper.data[i] = data;
    }

    const char* path = "test.bin";

    // TODO: 2. Serialize data to file
    Task::SerializeToFile(&dataWrapper, path);

    // TODO: 3. Deserialize data from file
    Task::DataWrapper unDataWrapper;
    Task::DataWrapper* unDataWrapperPtr = &unDataWrapper;
    Task::DeserializeFromFile(unDataWrapperPtr, "test.bin");

    // TODO: 4. Verify deserialized data is correct
    
    if (Task::Verify(&dataWrapper, &unDataWrapper)) {
        std::cout << "Serialization & deserialization was successful. " << std::endl;
    } else {
        std::cout << "There was an error with serialization & deserialization. " << std::endl;
    }

    Task::ReadWrapper(&dataWrapper, "test_1.txt");
    Task::ReadWrapper(&unDataWrapper, "test_2.txt");

    return 0;
}
