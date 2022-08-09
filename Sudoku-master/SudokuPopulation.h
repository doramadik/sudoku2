/**
 * population of Sudoku
 */

#pragma once

#include "Population.h"
#include <memory>
using namespace std;

class SudokuPopulation : public Population {
public:
    SudokuPopulation(int population_size, shared_ptr<Puzzle> &puzzle);
    void cull(double percent) override;
    void newGeneration() override;
    int bestFitness() override;
    Individual bestIndividual() override;
};

