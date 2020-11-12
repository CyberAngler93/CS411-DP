//
// Created by Matt on 11/11/2020.
//

#ifndef CS411_DP_BUILD_HPP
#define CS411_DP_BUILD_HPP
#include <vector>
#include <algorithm>
#include <cmath>

using Bridge = std::vector<int>;
int build(int , int , const std::vector<Bridge> &);
int recurse_bridge(const std::vector<Bridge> &, int, int, std::vector<std::vector<int>> &);
#endif //CS411_DP_BUILD_HPP
