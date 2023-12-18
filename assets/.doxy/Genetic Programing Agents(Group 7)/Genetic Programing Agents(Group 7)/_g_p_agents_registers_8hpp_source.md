

# File GPAgentsRegisters.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**GP**](dir_24320de467b989ce68b31a9ae5cbbd05.md) **>** [**GPAgentsRegisters.hpp**](_g_p_agents_registers_8hpp.md)

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


 public:
  GPAgentRegisters(int numRegisters = 16) : registers(numRegisters) {}
  ~GPAgentRegisters() = default;

  bool setRegister(size_t index, size_t value) {
    if (index >= registers.size()) {
      assert(index >= registers.size());
      return false;
    }

    registers[index] = value;
    return true;
  }

  std::optional<size_t> getRegister(size_t index) {
    if (index >= registers.size()) {
      return std::nullopt;  // Indicates that the value is absent
    }
    return registers[index];
  }

  size_t getNumRegisters() { return registers.size(); }

  size_t size() { return registers.size(); }

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
  iterator end() { return iterator(size(), *this); }
};

}  // namespace cowboys

```

