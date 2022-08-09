#include "Sudoku.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"
#include "SudokuPopulation.h"
#include <algorithm>
#include <memory>
using namespace std;

// population_size: population size
// puzzle: initial puzzle
// SudokuPopulation constructor
SudokuPopulation::SudokuPopulation(int population_size, shared_ptr<Puzzle> &puzzle) {
    size = population_size;
    fitness = make_shared<SudokuFitness>();
    factory = make_shared<SudokuFactory>();
    for (int i=0; i<size; ++i) {
        shared_ptr<Puzzle> p = factory->createPuzzle(puzzle);
        puzzles.emplace_back(fitness->howFit(p), p);
    }
}

// percent: percent to cull from generation
// erase some population with bad fitness
void SudokuPopulation::cull(double percent) {
    sort(puzzles.begin(), puzzles.end());
    int left = (1 - percent) * size;
    left = max(1, left);
    puzzles.erase(puzzles.begin()+left, puzzles.end());
}

// generate next generation from current generation
void SudokuPopulation::newGeneration() {
    int remain = puzzles.size();
    int i = 0;
    while ((int)puzzles.size() < size) {
        shared_ptr<Puzzle> p = factory->createPuzzle(puzzles[i].second);
        puzzles.emplace_back(fitness->howFit(p), p);
        i = i + 1 == remain ? 0 : i + 1;
    }
}

// get best fitness from current generation
int SudokuPopulation::bestFitness() {
    auto it = min_element(puzzles.begin(), puzzles.end());
    return it->first;
}

// get best indiviual of current generation
Individual SudokuPopulation::bestIndividual() {
    return *min_element(puzzles.begin(), puzzles.end());
}

