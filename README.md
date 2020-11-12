# CS411-DP

This is my solution to the bridges problem using dynamic programing, for CS411 Fall 2020.

## The Problem Background

A river flows from north to south. There are cities on the west bank and
cities on the east bank. We wish to build bridges across the river. Each
bridge will join a west-bank city with an east-bank city. We wish to choose
the bridges we build in such a way as to maximize the tolls we collect from
people crossing them.
There are two restrictions on the bridges we build. First, no city can have
more than one bridge reaching it. Second, no two bridges can cross each
other.
Concerning the second condition: the cities on each bank are numbered.
There are w cities on the west bank, numbered 0, 1, …, w-1 (starting at
zero, because we’re computer scientists), and there are e cities on the east
bank, numbered 0, 1, …, e-1. Suppose one bridge joins city a on the west to
city b on the east. Another bridge joins city c on the west to city d on the
east. If a<c and b>d, then these two bridges cross each other, and we are
not allowed to build both.  

For each pair of cities we might build a bridge between, we know the toll we
will collect from it. Building a bridge never affects the toll collected from
another bridge.  

## Specification

Each single data item (city index, toll) will be represented by an int value.
The description of a bridge will be stored as a vector<int> of size 3.
The 3 items represent, in order:
 - The index of the west-bank city (item 0).
 - The index of the east-bank city (item 1).
 - The toll collected (item 2).

## Test Program

build_test2.cpp is supplied as a testing program and was used to create my soultion. The file was supplied by Dr. Hartman.

## Method

My approach to this problem was to use top down dynamic programing and utilize a memoziation table ``bridge_memo_table`` in the form of a 2d vector of ints all which are initilizaed to ``-1``. 
The main worker fuction is ``recurse_bridge()`` which takes 4 arugments which includes the bridges, number of west cities, number of east cities, and 2d vector of ints for memoization table. 
There is one basecase which checks if the current memozation table value has been intilized to a value besides the starting value of ``-1`` if so then the we have the value already for this position in the table. 

