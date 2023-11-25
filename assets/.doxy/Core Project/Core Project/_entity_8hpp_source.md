

# File Entity.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**Entity.hpp**](_entity_8hpp.md)

[Go to the documentation of this file](_entity_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <string>
#include <unordered_map>

#include "GridPosition.hpp"

namespace cse491 {

  class Entity {
  protected:
    const size_t id;        
    std::string name;       
    GridPosition position;  

    struct PropertyBase {
      virtual ~PropertyBase() { }
    };

    template <typename T>
    struct Property : public PropertyBase {
      T value;
      Property(const T & in) : value(in) { }
      Property(T && in) : value(in) { }
    };

    std::unordered_map<std::string, std::unique_ptr<PropertyBase>> property_map;

    // -- Helper Functions --

    template <typename T>
    Property<T> & AsProperty(const std::string & name) const {
      assert( HasProperty(name) );
      PropertyBase * raw_ptr = property_map.at(name).get();
      assert( dynamic_cast<Property<T> *>(raw_ptr) );
      auto property_ptr = static_cast<Property<T> *>(raw_ptr);
      return *property_ptr;
    }

  public:
    Entity(size_t id, const std::string & name) : id(id), name(name) { }
    Entity(const Entity &) = delete; // Entities must be unique and shouldn't be copied.
    Entity(Entity &&) = default;
    virtual ~Entity() = default;

    Entity & operator=(const Entity &) = delete; // Entities must be unique and shouldn't be copied.
    Entity & operator=(Entity &&) = delete;      // Entities should never have IDs change.

    // -- Accessors --
    [[nodiscard]] size_t GetID() const { return id; }
    [[nodiscard]] const std::string & GetName() const { return name; }
    [[nodiscard]] GridPosition GetPosition() const { return position; }

    Entity & SetName(const std::string in_name) { name = in_name; return *this; }
    Entity & SetPosition(GridPosition in_pos) { position = in_pos; return *this; }
    Entity & SetPosition(double x, double y) { position = GridPosition{x,y}; return *this; }

    virtual bool IsAgent() const { return false; }

    virtual bool IsInterface() const { return false; }


    // -- Property Management --

    [[nodiscard]] bool HasProperty(const std::string & name) const {
      return property_map.count(name);
    }

    template <typename T=double>
    [[nodiscard]] const T & GetProperty(const std::string & name) const {
      assert(HasProperty(name));   // Break if property does not already exist.
      return AsProperty<T>(name).value;
    }

    template <typename T>
    Entity & SetProperty(const std::string & name, const T & value) {
      if (HasProperty(name)) {
        AsProperty<T>(name).value = value;
      } else {
        property_map[name] = std::make_unique<Property<T>>(value);
      }
      return *this;
    }

    Entity & SetProperties() { return *this; }

    template <typename VALUE_T, typename... EXTRA_Ts>
    Entity & SetProperties(const std::string & name, VALUE_T && value, EXTRA_Ts &&... extras) {
      SetProperty(name, std::forward<VALUE_T>(value));        // Set the first property...
      return SetProperties(std::forward<EXTRA_Ts>(extras)...); // And any additional properties...
    }

    Entity & RemoveProperty(const std::string & name) {
      property_map.erase(name);
      return *this;
    }    
  };

} // End of namespace cse491

```

