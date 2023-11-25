
# Class Hierarchy

This inheritance list is sorted roughly, but not completely, alphabetically:


* **class** [**cse491::Entity**](classcse491_1_1_entity.md)     
    * **class** [**cse491::AgentBase**](classcse491_1_1_agent_base.md)     
        * **class** [**cse491::InterfaceBase**](classcse491_1_1_interface_base.md) 
* **class** [**cse491::CoreObject**](classcse491_1_1_core_object.md)     
    * **class** [**cse491::WorldGrid**](classcse491_1_1_world_grid.md) _A common interface class for core objects that sets up required functionality. This class ensures that objects can be serialized (saved), deserialized (restored) and provides helper functions._ 
* **class** [**cse491::GridPosition**](classcse491_1_1_grid_position.md) _Represents a position within a 2D grid of cells. This class provides utilities to manage a position in 2D space. The position is stored as floating-point values (to allow for smooth motion through a grid), but is easily converted to size\_t for grid-cell identification._ 
* **class** [**cse491::WorldBase**](classcse491_1_1_world_base.md) 
* **struct** [**cse491::CellType**](structcse491_1_1_cell_type.md) _Simple data structure to hold info about a TYPE of cell in the world._ 
* **struct** [**cse491::Entity::PropertyBase**](structcse491_1_1_entity_1_1_property_base.md)     
    * **struct** [**cse491::Entity::Property**](structcse491_1_1_entity_1_1_property.md) 

