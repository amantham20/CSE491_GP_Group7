

# File CoreObject.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**CoreObject.hpp**](_core_object_8hpp.md)

[Go to the documentation of this file](_core_object_8hpp.md)

```C++


#pragma once

#include <fstream>
#include <iostream>
#include <string>

namespace cse491 {

  class CoreObject {
  protected:
    // -- Required functionality in all core classes --
    // These functions are core functionality that must be implemented in all derived
    // classes.  They will enable the public interface to behave correctly.

    virtual std::string GetTypeName_impl() const = 0;

    virtual void Serialize_impl(std::ostream &) const = 0;

    virtual void Deserialize_impl(std::istream &) = 0;


    // -- Helper functions --
    // The functions below can be used in derived classes to implement above functionality.

    void StartSerialize(std::ostream & os) const {
      os << ":::START " << GetTypeName() << "\n";
    }

    void EndSerialize(std::ostream & os) const {
      os << ":::END " << GetTypeName() << "\n";
    }

    bool StartDeserialize(std::istream & is) {
      std::string line;
      std::getline(is, line);
      std::string expected = ":::START " + GetTypeName();
      if (line != expected) {
        std::cerr << "Deserialization error.  Expected: " << expected
                  << "...Found: " << line;
        return false;
      }
      return true;
    }

    bool EndDeserialize(std::istream & is) {
      std::string line;
      std::getline(is, line);
      std::string expected = ":::END " + GetTypeName();
      if (line != expected) {
        std::cerr << "Deserialization error.  Expected: " << expected
                  << "...Found: " << line;
        return false;
      }
      return true;
    }

  public:
    virtual ~CoreObject() { }

    std::string GetTypeName() const { return GetTypeName_impl(); }

    void Serialize(std::ostream & os) const {
      StartSerialize(os);
      Serialize_impl(os);
      EndSerialize(os);
    }

    void Deserialize(std::istream & is) {
      StartDeserialize(is);
      Deserialize_impl(is);
      EndDeserialize(is);
    }

    bool Serialize(std::string filename) const {
      std::ofstream os(filename);
      if (!os.is_open()) {
        std::cerr << "Could not open file '" << filename << "' for Serialize()." << std::endl;
        return false;
      }
      Serialize(os);
      return true;
    }

    bool Deserialize(std::string filename) {
      std::ifstream is(filename);
      if (!is.is_open()) {
        std::cerr << "Could not open file '" << filename << "' for Serialize()." << std::endl;
        return false;
      }
      Deserialize(is);
      return true;
    }

  };

} // End of namespace cse491

```

