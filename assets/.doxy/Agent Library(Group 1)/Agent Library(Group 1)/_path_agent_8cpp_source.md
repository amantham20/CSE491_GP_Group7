

# File PathAgent.cpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**PathAgent.cpp**](_path_agent_8cpp.md)

[Go to the documentation of this file](_path_agent_8cpp.md)

```C++


#include "PathAgent.hpp"

#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

namespace walle {

    PathAgent::PathAgent(size_t id, std::string const &name)
        : cse491::AgentBase(id, name) {}

    PathAgent::PathAgent(size_t id, std::string const &name, std::vector<cse491::GridPosition> offsets)
        : cse491::AgentBase(id, name), offsets_(std::move(offsets)) {
        if (offsets_.empty()) {
            throw std::invalid_argument("Sequence of input offsets must not be empty");
        }
    }

    PathAgent::PathAgent(size_t id, std::string const &name, std::string_view commands)
        : cse491::AgentBase(id, name), offsets_(StrToOffsets(commands)) {
        if (offsets_.empty()) {
            throw std::invalid_argument("Sequence of input offsets must not be empty");
        }
    }

    bool PathAgent::Initialize() {
        if (property_map.contains("path")) {
            offsets_ = StrToOffsets(GetProperty<std::basic_string_view<char>>("path"));
        } else {
            return false;
        }
        return HasAction("move_arbitrary") && index_ >= 0 &&
            static_cast<size_t>(index_) < offsets_.size();
    }

    void PathAgent::IncrementIndex() {
        ++index_;

        // Wrap-around to front of offsets
        if (index_ >= static_cast<int>(offsets_.size())) {
            index_ = 0;
        }
    }

    void PathAgent::DecrementIndex() {
        --index_;

        // Wrap-around to back of offsets
        if (index_ < 0) {
            index_ = static_cast<int>(offsets_.size()) - 1;
        }
    }

    cse491::GridPosition PathAgent::CalcNextPos() const {
        return offsets_[index_] + GetPosition();
    }

    cse491::GridPosition PathAgent::UpdateAndGetNextPos(bool increment) {
        auto next_pos = CalcNextPos();
        if (increment) {
            IncrementIndex();
        } else {
            DecrementIndex();
        }
        return next_pos;
    }

    cse491::GridPosition PathAgent::GetNextPosition() {
        return UpdateAndGetNextPos(true);
    }

    size_t PathAgent::SelectAction(cse491::WorldGrid const & /* grid*/,
                                cse491::type_options_t const & /* type_options*/,
                                cse491::item_map_t const & /* item_map*/,
                                cse491::agent_map_t const & /* agent_map*/) {
        assert(HasAction("move_arbitrary"));
        return action_map["move_arbitrary"];
    }

    PathAgent &PathAgent::SetPath(std::vector<cse491::GridPosition> offsets, size_t start_index) {
        offsets_ = offsets;
        index_ = static_cast<int>(start_index);
        if (static_cast<size_t>(index_) >= offsets_.size()) {
            std::ostringstream what;
            what << "Out of bounds offset index to begin from: " << index_
                << ", number of offsets: " << offsets_.size();
            throw std::invalid_argument(what.str());
        }
        return *this;
    }

    PathAgent &PathAgent::SetPath(std::string_view commands, size_t start_index) {
        offsets_.clear();
        return SetPath(StrToOffsets(commands), start_index);
    }

    int PathAgent::GetIndex() const { return index_; }

    std::vector<cse491::GridPosition> const &PathAgent::GetPath() const { return offsets_; }

} // namespace walle

```

