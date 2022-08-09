/**
 * Main Genetic Algorithm Class
 */

#pragma once

#include "Puzzle.h"
#include "Population.h"
#include <limits>
#include <memory>
using namespace std;

template<typename T>
class GeneticAlgorithm {
public:
    GeneticAlgorithm(int max_generation, int population_size, shared_ptr<Puzzle> &initial);
    Individual run();

private:
    int max_generation; // max number of generations
    shared_ptr<Population> population; // population class
};

template<typename T>
GeneticAlgorithm<T>::GeneticAlgorithm(int max_generation, int population_size, shared_ptr<Puzzle> &initial)
    : max_generation(max_generation) , population(make_shared<T>(population_size, initial)) { }

// run genetic algorithm
template<typename T>
Individual GeneticAlgorithm<T>::run() {
    Individual best{numeric_limits<int>::max(), nullptr};

    // run for max_generation times
    for (int k=0; k<max_generation; ++k) {
        // get current best individual
        Individual current_best = population->bestIndividual();
        // if found the solution
        if (current_best.first == 0) {
            best = current_best;
            break;
        }
        // update best individual
        if (current_best.first < best.first) {
            best = current_best;
        }
        // cull 90% individuals
        population->cull(0.9);
        // make new generation
        population->newGeneration();
    }

    return best;
}
