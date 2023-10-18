

# File GPAgentsRegisters.hpp

[**File List**](files.md) **>** [**Group7\_GP\_Agent**](dir_2917a1bbf314837e5575b308b680803f.md) **>** [**GPAgentsRegisters.hpp**](_g_p_agents_registers_8hpp.md)

[Go to the documentation of this file](_g_p_agents_registers_8hpp.md)

```C++


#pragma once

// #include <array>
#include <assert.h>

#include <iostream>
#include <vector>

namespace cowboys {

class GPAgentRegisters {
 private:
  std::vector<size_t> registers;

  int numRegisters = 16;

 public:
  GPAgentRegisters(int numRegisters = 16) {
    registers.resize(numRegisters);
    this->numRegisters = numRegisters;
  }

  ~GPAgentRegisters() = default;

  bool setRegister(size_t index, size_t value) {
    if (index >= registers.size()) {
      //                assert(index >= registers.size());
      return false;
    }
    registers[index] = value;
    return true;
  }

  size_t getRegister(size_t index) {
    if (index >= registers.size()) {
      //                assert(index >= registers.size());
      return 0;
    }
    return registers[index];
  }

  int getNumRegisters() { return numRegisters; }

  //        friend std::ostream &operator<<(std::ostream &os, GPAgentRegisters
  //        registers) {
  //            os << "registers: ";
  //            for (int i = 0; i < registers.getNumRegisters(); ++i) {
  //                os << registers.getRegister(i) << " ";
  //            }
  //            return os;
  //        }

  class iterator {
   private:
    size_t index;

    GPAgentRegisters &registers;

   public:
    iterator(size_t index, GPAgentRegisters &regs)
        : index(index), registers(regs) {}

    size_t &operator*() { return registers.registers[index]; }

    iterator &operator++() {
      ++index;
      return *this;
    }

    bool operator==(const iterator &other) const {
      return index == other.index;
    }

    bool operator!=(const iterator &other) const {
      return index != other.index;
    }
  };

  // Begin iterator
  iterator begin() { return iterator(0, *this); }

  // End iterator
  iterator end() { return iterator(numRegisters, *this); }
};

}  // namespace cowboys

```

