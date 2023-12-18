

# File LGPAgent.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**GP**](dir_24320de467b989ce68b31a9ae5cbbd05.md) **>** [**LGPAgent.hpp**](_l_g_p_agent_8hpp.md)

[Go to the documentation of this file](_l_g_p_agent_8hpp.md)

```C++


#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <random>
#include <algorithm>
#include "../../core/AgentBase.hpp"
#include "GPAgentSensors.hpp"

#include "./GPAgentBase.hpp"

namespace cowboys
{
    const int LISTSIZE = 100;

    class LGPAgent : public GPAgentBase
    {
    protected:
        // A dictionary of actions and a dictionary of sensors
        // A sensor is a function that takes in a grid and returns a value (e.g. distance to left wall)

        std::vector<std::string> possibleInstructionsList = {};
        std::vector<std::string> actionsList = {};
        std::vector<std::string> operationsList = {"lessthan", "greaterthan", "equals"};
        std::vector<std::string> sensorsNamesList = {"getLeft", "getRight", "getUp", "getDown"};

        // A list that stores the results of executed instructions
        std::vector<int> resultsList;

        std::vector<std::tuple<std::string, int, int>> instructionsList = {};
        size_t currentInstructionIndex = 0;

        std::random_device rd;
        std::mt19937 gen;

    public:
        LGPAgent(size_t id, const std::string &name) : GPAgentBase(id, name)
        {
            gen = std::mt19937(rd());

            for (auto i = 0; i < LISTSIZE; i++)
            {
                resultsList.push_back(0);
            }
        }

        bool Initialize() override
        {
            possibleInstructionsList = EncodeActions(action_map, sensorsNamesList, operationsList, actionsList);
            GenerateRandomActionList();
            return true;
        }

        void GenerateRandomActionList()
        {
            std::uniform_int_distribution<size_t> dist(0, possibleInstructionsList.size() - 1);
            std::uniform_int_distribution<size_t> dist2(0, LISTSIZE - 1);
            for (int i = 0; i < LISTSIZE; i++)
            {
                instructionsList.push_back(std::make_tuple(possibleInstructionsList[dist(gen)], dist2(gen), dist2(gen)));
            }

        }

        static std::vector<std::string> EncodeActions(const std::unordered_map<std::string, size_t> &action_map, const std::vector<std::string> &sensorsNamesList, 
                                                        const std::vector<std::string> &operationsList, std::vector<std::string> &actionsList)
        {
            std::vector<std::string> instructions;
            for (const auto &[action_name, action_id] : action_map)
            {
                instructions.push_back(action_name);
                actionsList.push_back(action_name);
            }
            for (const auto &sensor : operationsList)
            {
                instructions.push_back(sensor);
            }

            for (const auto &sensor : sensorsNamesList)
            {
                instructions.push_back(sensor);
            }

            return instructions;
        }

        void MutateAgent(double mutation_rate = 0.01) override
        {
            std::uniform_int_distribution<size_t> rnd_mutate(1, 100);
            std::uniform_int_distribution<size_t> dist(0, possibleInstructionsList.size() - 1);
            std::uniform_int_distribution<size_t> dist2(0, LISTSIZE - 1);

            for (auto i = 0; i < LISTSIZE; i++)
            {
                if (rnd_mutate(gen) / 100.0 <= mutation_rate)
                {
                    instructionsList[i] = std::make_tuple(possibleInstructionsList[dist(gen)], dist2(gen), dist2(gen));
                }
            }

            resultsList.clear();
            resultsList.resize(LISTSIZE);
            currentInstructionIndex = 0;
        }

        const std::vector<std::tuple<std::string, int, int>> &GetInstructionsList(){ return instructionsList; }

        void Configure(const LGPAgent &other) {
            instructionsList = other.instructionsList;
            possibleInstructionsList = other.possibleInstructionsList;
            actionsList = other.actionsList;
            operationsList = other.operationsList;
            sensorsNamesList = other.sensorsNamesList;
            resultsList = other.resultsList;
            currentInstructionIndex = other.currentInstructionIndex;
        }

        void Copy(const GPAgentBase &other) override
        {
            assert(dynamic_cast<const LGPAgent *>(&other) != nullptr);
            Configure(dynamic_cast<const LGPAgent &>(other));
        }


        size_t GetAction([[maybe_unused]] const cse491::WorldGrid &grid,
                            [[maybe_unused]] const cse491::type_options_t &type_options,
                            [[maybe_unused]] const cse491::item_map_t &item_set,
                            [[maybe_unused]] const cse491::agent_map_t &agent_set) override
        {
            std::string action;
            std::string sensor;
            std::string operation;
            auto instruction = instructionsList[currentInstructionIndex];
            int i = 0;

            if (currentInstructionIndex != 0)
            {
                resultsList[currentInstructionIndex - 1] = action_result;
            }
            else
            {
                resultsList[LISTSIZE - 1] = action_result;
            }

            while (i < LISTSIZE * 2 && action.empty())
            {
                if (std::find(actionsList.begin(), actionsList.end(), std::get<0>(instruction)) != actionsList.end())
                {
                    // the instruction is in the action list (provided by the world)
                    action = std::get<0>(instruction);
                }
                else if (std::find(sensorsNamesList.begin(), sensorsNamesList.end(), std::get<0>(instruction)) != sensorsNamesList.end())
                {
                    // the instruction is in the sensor list (getLeft, getRight, getUp, getDown)
                    sensor = std::get<0>(instruction);

                    SensorDirection direction = Sensors::getSensorDirectionEnum(sensor);
                    int distance = Sensors::wallDistance(grid, *this, direction);


                    resultsList[currentInstructionIndex] = distance;


                }
                else
                {
                    // the instruction is an operation (lessthan, greaterthan, equals)
                    operation = std::get<0>(instruction);
                    if (operation == "lessthan")
                    {
                        if (std::get<1>(instruction) < std::get<2>(instruction))
                        {
                            resultsList[currentInstructionIndex] = 1;
                        }
                        else
                        {
                            resultsList[currentInstructionIndex] = 0;
                            ++currentInstructionIndex;
                        }
                    }
                    else if (operation == "greaterthan")
                    {
                        if (std::get<1>(instruction) > std::get<2>(instruction))
                        {
                            resultsList[currentInstructionIndex] = 1;
                        }
                        else
                        {
                            resultsList[currentInstructionIndex] = 0;
                            ++currentInstructionIndex;
                        }
                    }
                    else if (operation == "equals")
                    {
                        if (std::get<1>(instruction) == std::get<2>(instruction))
                        {
                            resultsList[currentInstructionIndex] = 1;
                        }
                        else
                        {
                            resultsList[currentInstructionIndex] = 0;
                            ++currentInstructionIndex;
                        }
                    }
                }

                ++currentInstructionIndex;
                if (currentInstructionIndex >= LISTSIZE)
                {
                    currentInstructionIndex = 0;
                }
                ++i;
                instruction = instructionsList[currentInstructionIndex];
            }
            if (!action.empty())
            {
                return action_map[action];
            }

            return 0;
        }


        std::string Export() override {
            std::string encodedLists = "";

            for (auto instruction : instructionsList)
            {
                encodedLists += std::get<0>(instruction);
                encodedLists += ".";
                encodedLists += std::to_string(std::get<1>(instruction));
                encodedLists += ".";
                encodedLists += std::to_string(std::get<2>(instruction));
                encodedLists += ",";
            }

            encodedLists += ";";

            for (auto possInstruction : possibleInstructionsList)
            {
                encodedLists += possInstruction;
                encodedLists += ".";
            }

            encodedLists += ";";

            for (auto action : actionsList)
            {
                encodedLists += action;
                encodedLists += ".";
            }

            return encodedLists;
        }

        void SerializeGP(tinyxml2::XMLDocument & doc, tinyxml2::XMLElement* parentElem, double fitness = -1) override
        {
            auto agentElem = doc.NewElement("LGPAgent");
            parentElem->InsertEndChild(agentElem);

            auto listElem = doc.NewElement("instruction list");
            listElem->SetText(Export().c_str());
            if (fitness != -1)
                listElem->SetAttribute("fitness", fitness);
            agentElem->InsertEndChild(listElem);
        }

        void Import(const std::string & encodedLists) override {
            std::vector<std::tuple<std::string, int, int>> decodedInstructionsList = {};
            std::string decodedInstruction;
            size_t start_pos = 0;
            size_t first_period_pos;
            size_t second_period_pos;
            size_t comma_pos = encodedLists.find(",");

            // Load the instruction list
            while (comma_pos != std::string::npos) {
                decodedInstruction = encodedLists.substr(start_pos, comma_pos - start_pos);
                first_period_pos = decodedInstruction.find(".");
                second_period_pos = decodedInstruction.find(".", first_period_pos + 1);
                decodedInstructionsList.push_back(std::make_tuple(decodedInstruction.substr(0, first_period_pos),
                        std::stoi(decodedInstruction.substr(first_period_pos+1, second_period_pos-first_period_pos+1)), std::stoi(decodedInstruction.substr(second_period_pos+1))));

                start_pos = comma_pos + 1;
                comma_pos = encodedLists.find(",", start_pos);
            }

            std::vector<std::string> decodedPossInstructionsList = {};
            std::vector<std::string> decodedActionsList = {};
            size_t first_semicolon_pos = encodedLists.find(";");
            size_t second_semicolon_pos = encodedLists.find(";", first_semicolon_pos+1);
            std::string unseparated_instruction_list = encodedLists.substr(first_semicolon_pos+1, second_semicolon_pos-first_semicolon_pos+1);
            std::string unseparated_action_list = encodedLists.substr(second_semicolon_pos+1);

            // Load the list of possible instructions
            size_t period_pos = unseparated_instruction_list.find(".");
            start_pos = 0;
            while (period_pos != std::string::npos) {
                decodedPossInstructionsList.push_back(unseparated_instruction_list.substr(start_pos, period_pos));

                start_pos = period_pos + 1;
                period_pos = encodedLists.find(".", start_pos);
            }

            // Load the list of actions
            period_pos = unseparated_action_list.find(".");
            start_pos = 0;
            while (period_pos != std::string::npos) {
                decodedActionsList.push_back(unseparated_action_list.substr(start_pos, period_pos));

                start_pos = period_pos + 1;
                period_pos = encodedLists.find(".", start_pos);
            }

            instructionsList = decodedInstructionsList;
            possibleInstructionsList = decodedPossInstructionsList;
            actionsList = decodedActionsList;
            resultsList.clear();
            resultsList.resize(LISTSIZE);
            currentInstructionIndex = 0;
        }

        void PrintAgent() override {
            for (auto i = 0; i < LISTSIZE; i++)
            {
                std::cout << std::get<0>(instructionsList[i]) << " ";
            }
            std::cout << std::endl;
        }
    };
}

```

