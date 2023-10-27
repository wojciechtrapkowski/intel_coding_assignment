#include "tests.hpp"

namespace Task
{
    bool Test1() {
        // Test case with a valid file path & empty data wrapper
        Task::DataWrapper dataWrapper;
        Task::DataWrapper unDataWrapper;
        Task::DataWrapper* unDataWrapperPtr = &unDataWrapper;
        const char* filePath = "test.txt";

        Task::SerializeToFile(&dataWrapper, filePath);
        Task::DeserializeFromFile(unDataWrapperPtr, filePath);

        return Verify(&dataWrapper, &unDataWrapper);
    }

    bool Test2() {
        // Test case with a null (invalid) file path & empty data wrapper
        Task::DataWrapper dataWrapper;
        Task::DataWrapper unDataWrapper;
        Task::DataWrapper* unDataWrapperPtr = &unDataWrapper;

        std::cout << std::endl;
        Task::SerializeToFile(&dataWrapper, nullptr);
        Task::DeserializeFromFile(unDataWrapperPtr, nullptr);

        return Verify(&dataWrapper, &unDataWrapper);
    }

    bool Test3() {
        // Test case with a empty (invalid) file path & empty data wrapper
        Task::DataWrapper dataWrapper;
        Task::DataWrapper unDataWrapper;
        Task::DataWrapper* unDataWrapperPtr = &unDataWrapper;
        const char* filePath = "";

        std::cout << std::endl;
        Task::SerializeToFile(&dataWrapper, filePath);
        Task::DeserializeFromFile(unDataWrapperPtr, filePath);

        return Verify(&dataWrapper, &unDataWrapper);
    }
    bool Test4() {
        // Test case with a valid file path & data filled in datawrapper
        Task::DataWrapper dataWrapper;
        Task::DataWrapper unDataWrapper;
        Task::DataWrapper* unDataWrapperPtr = &unDataWrapper;
        const char* path = "test.bin";

        dataWrapper.numData = 1;

        Task::Data data;

        dataWrapper.data = new Task::Data[dataWrapper.numData];
        for(size_t i = 0; i < dataWrapper.numData; i++) {
            data.value = i;
            dataWrapper.data[i] = data;
        }

        Task::SerializeToFile(&dataWrapper, path);
        Task::DeserializeFromFile(unDataWrapperPtr, path);

        return Verify(&dataWrapper, &unDataWrapper);
    }

    bool Test5() {
        // Test case with a valid file path & buffers filled in datawrapper
        Task::DataWrapper dataWrapper;
        Task::DataWrapper unDataWrapper;
        Task::DataWrapper* unDataWrapperPtr = &unDataWrapper;
        const char* path = "test.bin";

        dataWrapper.numBuffers = 10;
        
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

        Task::SerializeToFile(&dataWrapper, path);
        Task::DeserializeFromFile(unDataWrapperPtr, path);

        return Verify(&dataWrapper, &unDataWrapper);
    }

    bool Test6() {
        // Test case with a valid file path & everything filled in datawrapper
        Task::DataWrapper dataWrapper;
        Task::DataWrapper unDataWrapper;
        Task::DataWrapper* unDataWrapperPtr = &unDataWrapper;
        const char* path = "test.bin";

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

        Task::SerializeToFile(&dataWrapper, path);
        Task::DeserializeFromFile(unDataWrapperPtr, path);
        
        // Save content of both wrappers to files
        Task::ReadWrapper(&dataWrapper, "test_1.txt");
        Task::ReadWrapper(&unDataWrapper, "test_2.txt");

        return Verify(&dataWrapper, &unDataWrapper);
    }
} // namespace Task
