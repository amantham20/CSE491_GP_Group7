

# File Entity.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**Entity.hpp**](_entity_8hpp.md)

[Go to the documentation of this file](_entity_8hpp.md)

```C++


#pragma once

#include <algorithm>
#include <cassert>
#include <istream>
#include <memory>
#include <ostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "CoreObject.hpp"
#include "Data.hpp"
#include "GridPosition.hpp"
#include "Property.hpp"

namespace cse491 {

class WorldBase;

class Entity : public CoreObject {
private:
  WorldBase *world_ptr = nullptr;  

protected:
  size_t id = 0;          
  std::string name = "";  

  size_t grid_id = 0;     
  GridPosition position;  

  std::vector<size_t> inventory; 

  using property_map_t = std::unordered_map<std::string, std::unique_ptr<PropertyBase>>;
  property_map_t property_map;

  // -- Helper Functions --

  template <typename T>
  Property<T> &AsProperty(const std::string &name) const {
    assert(HasProperty(name));
    PropertyBase *raw_ptr = property_map.at(name).get();
    assert(dynamic_cast<Property<T> *>(raw_ptr));
    auto property_ptr = static_cast<Property<T> *>(raw_ptr);
    return *property_ptr;
  }

public:
  Entity(size_t id, const std::string &name) : id(id), name(name) {}
  Entity(const Entity &) = delete;  // Entities must be unique and shouldn't be copied.
  Entity(Entity &&) = default;
  virtual ~Entity() = default;

  Entity &operator=(const Entity &) = delete;  // Entities must be unique and shouldn't be copied.
  Entity &operator=(Entity &&) = delete;       // Entities should never have IDs change.

  // -- Accessors --
  [[nodiscard]] size_t GetID() const { return id; }
  [[nodiscard]] const std::string &GetName() const { return name; }
  [[nodiscard]] GridPosition GetPosition() const { return position; }
  [[nodiscard]] WorldBase &GetWorld() const {
    assert(world_ptr);
    return *world_ptr;
  }
  [[nodiscard]] size_t GetGridID() const { return grid_id; }
  [[nodiscard]] bool IsOnGrid(size_t in_grid_id) const { return grid_id == in_grid_id; }

  [[nodiscard]] bool HasWorld() const { return world_ptr != nullptr; }
  Entity &SetName(const std::string in_name) {
    name = in_name;
    return *this;
  }
  Entity &SetPosition(GridPosition in_pos, size_t grid_id = 0);
  Entity &SetPosition(double x, double y) {
    position = GridPosition{x, y};
    return *this;
  }
  virtual Entity &SetWorld(WorldBase &in_world) {
    world_ptr = &in_world;
    return *this;
  }

  virtual bool IsAgent() const { return false; }      
  virtual bool IsItem() const { return false; }       
  virtual bool IsInterface() const { return false; }  

  // -- Property Management --

  [[nodiscard]] bool HasProperty(const std::string &name) const { return property_map.count(name); }

  [[nodiscard]] size_t GetNumProperties() const { return property_map.size(); }

  template <typename T = double>
  [[nodiscard]] const T &GetProperty(const std::string &name) const {
    assert(HasProperty(name));  // Break if property does not already exist.
    return AsProperty<T>(name).value;
  }

  [[nodiscard]] PropertyType GetPropertyType(const std::string &name) const {
    auto it = property_map.find(name);
    if (it == property_map.end()) return PropertyType::t_other;
    return it->second->GetType();
  }

  template <typename T>
  Entity &SetProperty(const std::string &name, const T &value) {
    if (HasProperty(name)) {
      AsProperty<T>(name).value = value;
    } else {
      property_map[name] = std::make_unique<Property<T>>(value);
    }
    return *this;
  }

  Entity &SetProperties() { return *this; }

  template <typename VALUE_T, typename... EXTRA_Ts>
  Entity &SetProperties(const std::string &name, VALUE_T &&value, EXTRA_Ts &&...extras) {
    SetProperty(name, std::forward<VALUE_T>(value));          // Set the first property...
    return SetProperties(std::forward<EXTRA_Ts>(extras)...);  // And any additional properties...
  }

  Entity &RemoveProperty(const std::string &name) {
    property_map.erase(name);
    return *this;
  }

  property_map_t &GetPropertyMap() {
    return property_map;
  }

  bool HasItem(size_t id) const {
    return std::find(inventory.begin(), inventory.end(), id) != inventory.end();
  }

  Entity &AddItem(size_t id);
  Entity &AddItem(Entity &item) { return AddItem(item.GetID()); }

  Entity &RemoveItem(size_t id);
  Entity &RemoveItem(Entity &item) { return RemoveItem(item.GetID()); }

  void Serialize_impl(std::ostream &os) const override {
    SerializeValue(os, id);
    SerializeValue(os, name);
    SerializeValue(os, grid_id);
    SerializeValue(os, position);
    SerializeValue(os, inventory);

    SerializeValue(os, property_map.size());
    for (const auto & [name, ptr] : property_map) {
      SerializeValue(os, name);
      SerializeValue(os, ptr->GetType());
      SerializeValue(os, ptr->ToString());
    }
  }

  void Deserialize_impl(std::istream &is) override {
    DeserializeValue(is, id);
    DeserializeValue(is, name);
    DeserializeValue(is, grid_id);
    DeserializeValue(is, position);
    DeserializeValue(is, inventory);

    size_t num_properties = 0;
    property_map.clear();
    std::string name;
    PropertyType type;
    DeserializeValue(is, num_properties);
    for (size_t i = 0; i < num_properties; ++i) {
      DeserializeValue(is, name);
      DeserializeValue(is, type);
      switch (type) {
        using enum PropertyType;
      case t_char:     SetProperty(name, DeserializeAs<char>(is));         break;
      case t_double:   SetProperty(name, DeserializeAs<double>(is));       break;
      case t_int:      SetProperty(name, DeserializeAs<int>(is));          break;
      case t_bool:     SetProperty(name, DeserializeAs<bool>(is));          break;
      case t_string:   SetProperty(name, DeserializeAs<std::string>(is));  break;
      case t_position: SetProperty(name, DeserializeAs<GridPosition>(is)); break;
      case t_other:
        std::cerr << "Warning: Cannot deserialize property'" << name << "'." << std::endl;
        std::string tmp_str;
        std::getline(is, tmp_str, '\n');
        std::cerr << "  Data for that property: \"" << tmp_str << "\"." << std::endl;
      }
    }
  }

  [[nodiscard]] std::vector<size_t> GetInventory() const { return inventory; }
};

}  // End of namespace cse491

```

