# Genetic Programming for Autonomous Agents

## CSE 491 Final Project · Group 7

**Project namespace:** `Cowboys`  
**Team members:** Aman, Jason, Rajmeet, and Simon

## Project Overview

The project implements a genetic programming framework for evolving autonomous agents in simulated worlds. Agents interact with their environment, receive fitness scores, and undergo selection and mutation across successive generations.

The team developed two agent representations: Cartesian Genetic Programming (`CGPAgent`) and Linear Genetic Programming (`LGPAgent`). Supporting work included a training loop, parallel world execution, scavenger queuing and checkpointing, a genetic programming analyzer, profiling, and unit tests.

## Genetic Programming Process

Genetic programming evolves executable behavior by evaluating a population of candidate programs and generating new variants from selected candidates. In this project, each candidate program controls an agent.

The training process follows these steps:

1. **Initialize the population.** Create agents with different program variations.
2. **Run simulations.** Place agents in simulated worlds and evaluate their behavior through interactions with other agents and the environment.
3. **Calculate fitness.** Assign a score to each agent using a fitness function.
4. **Rank the population.** Sort agents by fitness.
5. **Preserve elite agents.** Retain the strongest candidates unchanged through elitism.
6. **Mutate selected agents.** Modify promising candidates to create new program variations.
7. **Replace lower-performing agents.** Introduce new candidates into the population.
8. **Repeat.** Evaluate the next generation using the same process.

The presentation illustrates fitness scoring with the following examples:

| Remaining health | Damage dealt | Fitness score |
| ---: | ---: | ---: |
| 0 | 0 | −10 |
| 0 | 0 | −10 |
| 80 | 60 | 120 |

These examples demonstrate how simulated outcomes inform selection. The presentation does not specify the complete fitness formula.

## System Architecture

The training loop coordinates agent creation, simulated world execution, fitness evaluation, and mutation. The architecture connects the loop to an analyzer and TinyXML, with an additional connection to the `Walle::AStar` component.

The agent hierarchy extends the existing agent base through `GPAgentBase`, which supports the two genetic programming implementations.

| Component | Role in the architecture |
| --- | --- |
| GP training loop | Coordinates training and generation progression. |
| World | Provides the simulation environment for agents. |
| Analyzer | Supports analysis of training behavior and fitness metrics. |
| `GPAgentBase` | Provides a shared base for genetic programming agents. |
| `LGPAgent` | Represents behavior as a sequence of instructions. |
| `CGPAgent` | Represents behavior using a genotype and computational graph. |
| Graph and genotype | Support the Cartesian Genetic Programming representation. |
| Sensors | Provide environmental information to agent programs. |
| Registers | Support the Linear Genetic Programming implementation. |
| TinyXML | Appears as the XML dependency connected to the training loop. |
| `Walle::AStar` | Provides the A* component shown in the architecture. |

The design distinguishes components from the CSE 491 namespace, the `Cowboys` namespace, the `Walle` namespace, and third-party dependencies.

## Cartesian Genetic Programming

Cartesian Genetic Programming represents a program as a graph of computational nodes. A genotype encodes node functions and connections, while the corresponding phenotype describes the executable graph.

The presentation uses a reference illustration to show how encoded functions and connections map to graph inputs, intermediate computations, and outputs.

### Function Set

The project uses functions including:

- Sum and product.
- Sine and cosine.
- Exponential functions.
- Maximum and minimum.
- Additional functions not individually identified in the presentation.

The accompanying reference table presents a broader function set from *Evolving Simple Programs for Playing Atari Games* by Wilson et al. It groups functions into mathematical, statistical, and comparison operations. The table serves as reference material and does not establish that the project implements every listed function.

### Sensor Inputs

The presentation identifies two categories of environmental inputs:

- Distance to the nearest wall in each cardinal direction.
- A* distance.

These inputs provide information that agent programs can use to determine behavior.

## Linear Genetic Programming

Linear Genetic Programming represents an agent program as an instruction sequence. The implementation uses three primary data structures:

| Data structure | Purpose |
| --- | --- |
| Instruction list | Stores the program's instructions. |
| Results list | Stores instruction results. |
| Current instruction index | Tracks the current position in the instruction sequence. |

Instructions fall into three categories:

- **Sensors:** obtain information from the environment.
- **Operations:** process values within the program.
- **Actions:** produce agent behavior in the simulated world.

The presentation describes the linear representation as straightforward to mutate and fast to execute. It raises the question of drawbacks but does not provide a specific limitation or quantitative comparison with Cartesian Genetic Programming.

## Training and Parallel Execution

The genetic programming loop manages agent instantiation, fitness scoring, mutation, and world execution.

The multithreading design distributes simulated arenas across threads so that multiple worlds can run concurrently. The presentation reports the following runtime comparison:

| Thread count | Reported runtime |
| ---: | ---: |
| 1 | 245.91 seconds |
| 12 | 46.88 seconds |

These figures correspond to approximately **5.25× speedup** and an **80.9% reduction in runtime**, calculated from the reported timings. The deck does not specify the hardware, workload details, or number of repeated measurements for this comparison.

### Scavenger Queuing and Checkpointing

The presentation identifies scavenger queuing and checkpointing as training support features. It uses a task-scheduling illustration to introduce scheduling behavior, but does not document the queue policy, checkpoint format, or recovery procedure.

## Evaluation and Analysis

The evaluation setup includes:

| Parameter | Value |
| --- | ---: |
| Arenas | 16 |
| Agents | 1,000 |
| Generations | 100 |

The presentation introduces several metrics for assessing population behavior over time.

| Metric | Description |
| --- | --- |
| Average fitness | Mean fitness of the population in a generation. |
| Maximum fitness | Highest fitness achieved by an individual in a generation. |
| Average elite score | Mean score of the elite population retained unchanged. |
| Best agent weighted score | Weighted score for the best agent. The weighting formula is not specified. |
| Number of agents with maximum fitness | Count of agents achieving the maximum fitness value. |

The displayed graph for the number of agents with maximum fitness shows substantial variation across generations, including sharp declines and intermittent peaks. The presentation does not provide the underlying numerical dataset or a statistical assessment of improvement.

The original deck also includes demonstrations of training and metric visualization. This Markdown conversion describes the evaluation framework without reproducing the embedded videos.

## Software Validation

### Runtime Diagnostics

The team used runtime diagnostics to investigate software defects. The presentation lists Google Sanitizers and Valgrind, including:

| Tool | Diagnostic focus |
| --- | --- |
| AddressSanitizer (ASan) | Invalid memory access. |
| LeakSanitizer (LSan) | Memory leaks. |
| ThreadSanitizer (TSan) | Data races. |
| UndefinedBehaviorSanitizer (UBSan) | Undefined behavior. |
| MemorySanitizer (MSan) | Use of uninitialized memory. |
| Valgrind | Memory and runtime analysis. |

The slides show runtime debugging and report a fix for undefined behavior. A separate screenshot in the discussion of project risks shows an invalid memory-free error during a longer training run. The deck does not establish that all runtime defects had been resolved.

### Profiling

The team profiled the application to identify expensive execution paths and investigate CPU usage. Screenshots show Intel VTune, a flame graph profiler, and a time profiling view. These tools supported performance analysis, although the deck does not report a separate before-and-after result for each optimization.

### Unit Tests and Coverage

The unit test screenshots show passing checks for:

- `CGPAgent` and `CGPGenotype`.
- Graph, graph builder, and graph node components.
- `LGPAgent` and the base agent component.
- Registers and sensors.
- XML formatting, file reading, and serialization.

The presentation also includes a coverage-check section, but does not provide a coverage percentage or a detailed coverage report.

## Challenges and Limitations

The presentation identifies several areas requiring attention:

- **Restart seeding:** maintaining appropriate random-seed behavior when restarting training.
- **Seed determinism:** reproducing training behavior consistently from a given seed.
- **Local optima:** avoiding populations becoming trapped in locally favorable behavior.
- **Runtime stability:** investigating failures that may occur during extended training runs.

These issues affect reproducibility, continued exploration, and the reliability of longer experiments.

## Future Improvements

The team proposes the following next steps:

1. Develop alternative fitness functions for more specialized agent behaviors.
2. Deploy training on the high-performance computing cluster (HPCC).
3. Add integration testing to validate interactions across the training loop, agents, simulation worlds, and supporting components.

## References and Credits

The original presentation credits the following sources:

- Mitchell Spryn and Miragaia et al. for Cartesian Genetic Programming reference material. Full bibliographic details are not provided in the deck.
- Wilson et al., *Evolving Simple Programs for Playing Atari Games*, for the reference function set.
- [DigiKey: Introduction to RTOS, Task Scheduling](https://www.digikey.com/en/maker/projects/introduction-to-rtos-solution-to-part-3-task-scheduling/8fbb9e0b0eed4279a2dd698f02ce125f), for the scheduling illustration.
- [EmojiTerra: Stadium](https://emojiterra.com/stadium/), for arena illustrations.
- [DeviantArt](https://www.deviantart.com/) and [PNGimg](https://pngimg.com/image/104752), for visual assets credited in the presentation.

*Adapted from “CSE 491 Group 7 Final Presentation (1).pptx.” Repeated animation slides have been consolidated, informal wording has been revised, and decorative images have been omitted. Technical details and reported figures remain grounded in the original presentation.*
