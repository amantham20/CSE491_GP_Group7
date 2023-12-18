

# File GPAgentAnalyze.h

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**GP**](dir_24320de467b989ce68b31a9ae5cbbd05.md) **>** [**GPAgentAnalyze.h**](_g_p_agent_analyze_8h.md)

[Go to the documentation of this file](_g_p_agent_analyze_8h.md)

```C++

//
// A class that analyzes the data of the best agent in the GP algorithm
// and saves it to a csv file
//

#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

namespace cowboys {

    class GPAgentAnalyzer {
    private:
        std::vector<double> average_fitness;

        std::vector<double> max_fitness;

        std::vector<double> elite_score;

        std::vector<double> average_score;

        std::vector<double> max_agents;

    public:
        GPAgentAnalyzer() = default;

        ~GPAgentAnalyzer() = default;

        void addAverageFitness(double fitness) {
            average_fitness.push_back(fitness);
        }

        void addMaxFitness(double fitness) {
            max_fitness.push_back(fitness);
        }

        void addEliteScore(double score) {
            elite_score.push_back(score);
        }

        void addAverageScore(double score) {
            average_score.push_back(score);
        }

        void addNumAgentsWithMaxFitness(double num_agents) {
            max_agents.push_back(num_agents);
        }

        void saveToFile() {
            // create a new file
            std::ofstream file("gp_agent_analyzer.csv");

            // write the data to the file
            file << "average_fitness,max_fitness,average_elite_score,best_agent_weighted_score,agents_with_max_fitness\n";

            for (size_t i = 0; i < average_fitness.size(); i++) {
                file << average_fitness[i] << "," << max_fitness[i] << "," << elite_score[i] << "," << average_score[i] << "," << max_agents[i] << "\n";
            }
            std::cout << "Saved GP Agent Analyzer data to gp_agent_analyzer.csv" << std::endl;

            // close the file
            file.close();
        }
    };

}  // namespace cowboys


```

