#ifndef __divisors_H_INCLUDED__
#define __divisors_H_INCLUDED__

#include <vector>
#include <algorithm>
#include <map>
#include <factors.h>
#include <statistics.h>

std::vector<int> divisors(std::vector<int> &factors); //it does the work
std::vector<int> divisors(int number); //interface

#endif
