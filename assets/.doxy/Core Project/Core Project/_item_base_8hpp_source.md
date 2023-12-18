

# File ItemBase.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**ItemBase.hpp**](_item_base_8hpp.md)

[Go to the documentation of this file](_item_base_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <string>
#include <unordered_map>

#include "Data.hpp"
#include "Entity.hpp"

namespace cse491 {

class ItemBase : public Entity {
protected:
  enum OwnerType { NONE = 0, GRID, ITEM, AGENT };
  OwnerType owner_type = OwnerType::NONE;
  size_t owner_id = 0;

public:
  ItemBase(size_t id, const std::string &name) : Entity(id, name) {}
  ~ItemBase() = default;  // Already virtual from Entity

  // -- Entity Overrides --

  bool IsItem() const override { return true; }

  // -- Ownership Info --
  [[nodiscard]] bool IsOnGrid() const { return owner_type == OwnerType::GRID; }
  [[nodiscard]] bool IsOwnedByItem() const { return owner_type == OwnerType::ITEM; }
  [[nodiscard]] bool IsOwnedByAgent() const { return owner_type == OwnerType::AGENT; }
  [[nodiscard]] bool IsOwned() const { return IsOwnedByItem() || IsOwnedByAgent(); }
  [[nodiscard]] bool IsOnGrid(size_t grid_id) const { return IsOnGrid() && owner_id == grid_id; }
  [[nodiscard]] bool IsOwnedByItem(size_t item_id) const {
    return IsOwnedByItem() && owner_id == item_id;
  }
  [[nodiscard]] bool IsOwnedByAgent(size_t agent_id) const {
    return IsOwnedByAgent() && owner_id == agent_id;
  }
  [[nodiscard]] bool IsOwnedBy(size_t entity_id) const {
    return IsOwned() && owner_id == entity_id;
  }
  [[nodiscard]] size_t GetOwnerID() const { return owner_id; }

  ItemBase &SetOwner(const Entity &owner) {
    if (owner.IsItem())
      owner_type = OwnerType::ITEM;
    else if (owner.IsAgent())
      owner_type = OwnerType::AGENT;
    else
      owner_type = OwnerType::NONE;  // Error?
    owner_id = owner.GetID();
    position.MakeInvalid();
    return *this;
  }

  ItemBase &SetGrid(size_t grid_id = 0) {
    owner_type = OwnerType::GRID;
    owner_id = grid_id;
    return *this;
  }
  ItemBase &SetUnowned() {
    owner_type = OwnerType::NONE;
    return *this;
  }

  std::string GetTypeName_impl() const override { return "cse491::ItemBase"; }

  void Serialize_impl(std::ostream &os) const override {
    Entity::Serialize_impl(os);
    SerializeValue(os, owner_type);
    SerializeValue(os, owner_id);
  }

  void Deserialize_impl(std::istream &is) override {
    Entity::Deserialize_impl(is);
    DeserializeValue(is, owner_type);
    DeserializeValue(is, owner_id);
  }
};

}  // End of namespace cse491

```

