#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

class NFA
{
public:
    NFA(const std::unordered_map<char, std::unordered_map<char, std::unordered_set<char>>> &transitions,
        char startState, const std::unordered_set<char> &acceptStates)
        : transitions(transitions), startState(startState), acceptStates(acceptStates) {}

private:
    std::unordered_map<char, std::unordered_map<char, std::unordered_set<char>>> transitions;
    char startState;
    std::unordered_set<char> acceptStates;
};