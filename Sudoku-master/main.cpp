/**
 * Driver program
 *
 * read sudoku puzzle from file
 * run GA
 */

#include "Sudoku.h"
#include "SudokuPopulation.h"
#include "GeneticAlgorithm.h"
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;

int main(int argc, char **argv) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <POPULATION SIZE> <MAX GENERATION>\n";
        return 1;
    }

    // initilize population size and max generation
    int population_size = atoi(argv[1]);
    int max_generation = atoi(argv[2]);

    cout << "Enter file name: ";
    cout.flush();

    string file;
    cin >> file;

    ifstream ifin(file);

    // read in initial puzzle
    shared_ptr<Puzzle> puzzle = make_shared<Sudoku>();
    ifin >> *puzzle;
    cout << *puzzle;

    // initial GA with max generation, population size and initial puzzle
    GeneticAlgorithm<SudokuPopulation> ga(max_generation, population_size, puzzle);
    // run GA
    Individual best = ga.run();

    // output algorithm result
    cout << "Best fit: " << best.first << "\n";
    cout << "**the smaller, the better. 0 means got solution**\n";
    cout << *best.second;

    return 0;
}
