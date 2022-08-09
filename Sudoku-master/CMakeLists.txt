cmake_minimum_required(VERSION 3.15)
project(css343_p4_ga_sudoku_v2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(css343_p4_ga_sudoku_v2
        Fitness.h
        GeneticAlgorithm.h
        main.cpp
        Population.cpp
        Population.h
        Puzzle.cpp
        Puzzle.h
        PuzzleFactory.cpp
        PuzzleFactory.h
        Reproduction.h
        Sudoku.cpp
        Sudoku.h
        SudokuFactory.cpp
        SudokuFactory.h
        SudokuFitness.cpp
        SudokuFitness.h
        SudokuOffspring.cpp
        SudokuOffspring.h
        SudokuPopulation.cpp
        SudokuPopulation.h)
