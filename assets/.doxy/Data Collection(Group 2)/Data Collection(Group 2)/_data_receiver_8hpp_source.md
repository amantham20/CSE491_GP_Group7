

# File DataReceiver.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**DataReceiver.hpp**](_data_receiver_8hpp.md)

[Go to the documentation of this file](_data_receiver_8hpp.md)

```C++

#pragma once

#include <vector>
namespace DataCollection {

    template <typename T>
    class DataReceiver {
    public:
        DataReceiver() = default;

        virtual ~DataReceiver() = default;

        std::vector<T>& getStorage() {
            return storage;
        }

        void StoreIntoStorage(T obj){
            storage.push_back(obj);
        }

        bool IsEmpty() {
            return storage.empty();
        }

    protected:
        std::vector<T> storage; 
    };
} // namespace DataCollection

```

