//
// Created by Matt on 11/11/2020.
//

#include "build.hpp"
// PRE: A vector containing 3 values for a start and end node and cost
// POST: This will return the value of the best toll to build for the bridges given.
int build(int west, int east, const std::vector<Bridge> & bridges){
    auto bridge_memo_table = std::vector<std::vector<int>>(west + 1, std::vector<int>(east + 1, -1));
    if (bridges.empty()) {
        return 0;
    }
    else if (bridges.size() == 1) {
        return bridges[0][2];
    }
    else{
        std::vector<Bridge> bridges_copy = (bridges);
        return recurse_bridge(bridges_copy, west, east, bridge_memo_table);
    }

}
// Recursive work function for
int recurse_bridge(const std::vector<Bridge> & bridges, int west, int east, std::vector<std::vector<int>> & bridge_memo_table){
    auto toll = 0;
    //Base Case already found this value!
    if (bridge_memo_table[west][east] != -1){
        return bridge_memo_table[west][east];
    }
    for (auto & bridge:bridges) {
        //Check if the the bridge is legal by checking current bridge. Check if its a new greatest value!
        if(bridge[0] < west && bridge[1] < east){
            toll = std::max(recurse_bridge(bridges, bridge[0], bridge[1], bridge_memo_table) + bridge[2], toll);
        }
    }
    bridge_memo_table[west][east] = toll;
    return toll;
}

