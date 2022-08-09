#include "SudokuFactory.h"
#include "SudokuOffspring.h"
#include <memory>
using namespace std;

// Sudoku Factory
SudokuFactory::SudokuFactory() {
    reproduction = make_shared<SudokuOffspring>();
}
