

# File ControlledAgent.hpp

[**File List**](files.md) **>** [**client**](dir_d63376ef77eb621cc9b73f8097e771f8.md) **>** [**ControlledAgent.hpp**](_controlled_agent_8hpp.md)

[Go to the documentation of this file](_controlled_agent_8hpp.md)

```C++


#pragma once

#include <cassert>

#include "../../../core/AgentBase.hpp"
#include "ClientManager.hpp"

namespace netWorth
{

    class ControlledAgent : public cse491::AgentBase
    {
    private:
        ClientManager* m_manager = nullptr;       

    protected:

    public:
        ControlledAgent(size_t id, const std::string& name) : AgentBase(id, name)
        {
        }

        bool Initialize() override
        {
            m_manager = GetProperty<ClientManager*>("manager");
            return HasAction("up") && HasAction("down") && HasAction("left") && HasAction("right");
        }

        size_t SelectAction(const cse491::WorldGrid& /* grid*/,
            const cse491::type_options_t& /* type_options*/,
            const cse491::item_map_t& /* item_map*/,
            const cse491::agent_map_t& /* agent_map*/) override
        {
            if (!m_manager->iDPresent(id))
            {
                return 0;
            }
            return m_manager->getActionID(id);
        }

    };

} // End of namespace cse491

```

