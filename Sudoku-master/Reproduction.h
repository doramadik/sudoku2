/**
 * abstract
 * create new puzzle from existing one
 */

#pragma once

#include "Puzzle.h"
#include <memory>
using namespace std;

class Reproduction {
public:
    virtual shared_ptr<Puzzle> makeOffspring(shared_ptr<Puzzle> &p) = 0;
    virtual ~Reproduction() = default;
};
