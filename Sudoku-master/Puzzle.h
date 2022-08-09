/**
 * The Puzzle class defines the abstract interface for
 * any puzzle to be used by the GA framework
 */

#pragma once

#include <iostream>

using std::ostream;
using std::istream;

class Puzzle {
public:
    friend ostream &operator<<(ostream &out, const Puzzle &puzzle);
    friend istream &operator>>(istream &in, Puzzle &puzzle);
    virtual ~Puzzle();

private:
    virtual istream &readin(istream &in) = 0;
    virtual ostream &printout(ostream &out) const = 0;
};
