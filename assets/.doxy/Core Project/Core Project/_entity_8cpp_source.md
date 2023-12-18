

# File Entity.cpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**Entity.cpp**](_entity_8cpp.md)

[Go to the documentation of this file](_entity_8cpp.md)

```C++

#include "Entity.hpp"
#include "WorldBase.hpp"

namespace cse491 {

  Entity & Entity::SetPosition(GridPosition in_pos, size_t grid_id) {
    position = in_pos;
    if (IsItem()) {
      auto & item = static_cast<ItemBase&>(*this);
      item.SetGrid(grid_id);
    }
    return *this;
  }

  Entity & Entity::AddItem(size_t id) {
    assert(!HasItem(id));
    inventory.push_back(id);
    world_ptr->GetItem(id).SetOwner(*this);
    return *this;
  }

  Entity & Entity::RemoveItem(size_t id) {
    assert(HasItem(id));
    inventory.erase(std::find(inventory.begin(), inventory.end(), id));
    world_ptr->GetItem(id).SetUnowned();
    return *this;
  }
 
}

```

