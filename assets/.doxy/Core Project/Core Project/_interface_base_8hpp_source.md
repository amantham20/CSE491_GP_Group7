

# File InterfaceBase.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**InterfaceBase.hpp**](_interface_base_8hpp.md)

[Go to the documentation of this file](_interface_base_8hpp.md)

```C++


#pragma once

#include <string>

#include "AgentBase.hpp"

namespace cse491 {

  class InterfaceBase : public AgentBase {
  protected:

  public:
    InterfaceBase(size_t id, const std::string & name) : AgentBase(id, name) { }
    ~InterfaceBase() = default; // Already virtual from Entity

    // -- Entity Overrides --

    bool IsInterface() const override { return true; }


    // -- AgentBase overrides --
    //
    // Multiple functions defined as virtual in AgentBase can also be overridden from
    // custom Interfaces.  Specific available function to override include:

    // bool Initialize() { return true; }
    //
    // Initialize is run AFTER the world configures the interface with actions, etc, allowing
    // for additional setup, such as targeted buttons.


    // size_t SelectAction([[maybe_unused]] const WorldGrid & grid) { return 0; }
    //
    // SelectAction is run when the world is given the player an opportunity to choose
    // and action to perform. The interface will be provided with the current WorldGrid
    // Return the ID associated with the action to perform; (zero is always "no action")
  };

} // End of namespace cse491

```

