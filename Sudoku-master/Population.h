/**
 * Population class
 * A population is a container for a number of Puzzles.
 * It can use a Fitness strategy (see below) to evaluate the quality of a Puzzle.
 * It can "cull" Puzzles from the population (based on their fitness).
 * It can use a PuzzleFactory and a Reproduction strategy to produce a new generation of Puzzles from
 * the most fit members of the old generation.
 * It performs these operations when commanded by the main GeneticAlgorithm.
 */

#pragma once

#include "Fitness.h"
#include "PuzzleFactory.h"
#include <vector>
#include <memory>
using namespace std;

using Individual = pair<int, shared_ptr<Puzzle>>;

class Population {
public:
    virtual void cull(double percent) = 0;
    virtual void newGeneration() = 0;
    virtual int bestFitness() = 0;
    virtual Individual bestIndividual() = 0;

    Population() = default;
    virtual ~Population();

protected:
    int size; // population size
    vector<Individual> puzzles; // list of puzzles
    shared_ptr<Fitness> fitness; // fitness
    shared_ptr<PuzzleFactory> factory; // puzzle factory
};

