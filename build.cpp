//
// Created by Matt Perry on 11/11/2020
// Dynamic Programing Solution to HW5
// CS411 Fall 2020 Prof. Hartman
// Last Modified on 11/11/2020
// build.cpp

#include "build.hpp"
// PRE: A vector containing 3 values for a start and end node and cost
// POST: This will return the value of the best toll to build for the bridges given.
int build(int west, int east, const std::vector<Bridge> & bridges){
    auto bridge_memo_table = std::vector<std::vector<int>>(west + 1, std::vector<int>(east + 1, -1));
    return recurse_bridge(bridges, west, east, bridge_memo_table);
}
// Recursive work function for dynamic programing bottom up approach utilizing memoization table.
int recurse_bridge(const std::vector<Bridge> & bridges, int west, int east, std::vector<std::vector<int>> & bridge_memo_table){
    auto toll = 0;
    //Base Case already found this value!
    if (bridge_memo_table[west][east] != -1){
        return bridge_memo_table[west][east];
    }
    for (auto const & bridge:bridges) {
        // Check if the the bridge is legal by checking current bridge vs the previous west, east bridge.
        // std::max to take the best of the new legal bridges.
        if(bridge[0] < west && bridge[1] < east){
            toll = std::max(recurse_bridge(bridges, bridge[0], bridge[1], bridge_memo_table) + bridge[2], toll);
        }
    }
    bridge_memo_table[west][east] = toll;
    return toll;
}

