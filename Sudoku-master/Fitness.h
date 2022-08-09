/**
 * abstract Fitness class
 */

#pragma once

#include "Puzzle.h"
#include <memory>
using namespace std;

class Fitness {
public:
    virtual int howFit(shared_ptr<Puzzle> &p) = 0;
    virtual ~Fitness() = default;
};
