
# Class Hierarchy

This inheritance list is sorted roughly, but not completely, alphabetically:


* **class** [**clogged::Logger**](classclogged_1_1_logger.md) [_**Logger**_](classclogged_1_1_logger.md) _class with colors and team names._
* **class** [**cse491::CoreObject**](classcse491_1_1_core_object.md)     
    * **class** [**cse491::Entity**](classcse491_1_1_entity.md)     
        * **class** [**cse491::AgentBase**](classcse491_1_1_agent_base.md)     
            * **class** [**cse491::InterfaceBase**](classcse491_1_1_interface_base.md) 
        * **class** [**cse491::ItemBase**](classcse491_1_1_item_base.md) 
    * **class** [**cse491::GridPosition**](classcse491_1_1_grid_position.md) _Represents a position within a 2D grid of cells. This class provides utilities to manage a position in 2D space. The position is stored as floating-point values (to allow for smooth motion through a grid), but is easily converted to size\_t for grid-cell identification._ 
    * **struct** [**cse491::PropertyBase**](structcse491_1_1_property_base.md)     
        * **struct** [**cse491::Property**](structcse491_1_1_property.md) 
    * **class** [**cse491::WorldGrid**](classcse491_1_1_world_grid.md) _A common interface class for core objects that sets up required functionality. This class ensures that objects can be serialized (saved), deserialized (restored) and provides helper functions._ 
* **class** [**cse491::WorldBase**](classcse491_1_1_world_base.md) 
* **struct** [**cse491::CellType**](structcse491_1_1_cell_type.md) _Simple data structure to hold info about a TYPE of cell in the world._ 
* **class** **false_type**    
    * **struct** [**cse491::is\_any\_map**](structcse491_1_1is__any__map.md) _Type trait to determine if we are working with any type of map._ 
    * **struct** [**cse491::is\_vector**](structcse491_1_1is__vector.md) _Type trait to determine if we are working with a vector._ 
* **class** **true_type**    
    * **struct** [**cse491::is\_any\_map&lt; std::map&lt; KEY\_T, VALUE\_T &gt; &gt;**](structcse491_1_1is__any__map_3_01std_1_1map_3_01_k_e_y___t_00_01_v_a_l_u_e___t_01_4_01_4.md) 
    * **struct** [**cse491::is\_any\_map&lt; std::unordered\_map&lt; KEY\_T, VALUE\_T &gt; &gt;**](structcse491_1_1is__any__map_3_01std_1_1unordered__map_3_01_k_e_y___t_00_01_v_a_l_u_e___t_01_4_01_4.md) 
    * **struct** [**cse491::is\_vector&lt; std::vector&lt; T &gt; &gt;**](structcse491_1_1is__vector_3_01std_1_1vector_3_01_t_01_4_01_4.md) 

