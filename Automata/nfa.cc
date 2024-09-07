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

    bool accepts(const std::string &input)
    {
        std::unordered_set<char> currentStates = {startState};
        for (char symbol : input)
        {
            std::unordered_set<char> nextStates;
            for (char state : currentStates)
            {
                if (transitions.count(state) && transitions.at(state).count(symbol))
                {
                    nextStates.insert(transitions.at(state).at(symbol).begin(), transitions.at(state).at(symbol).end());
                }
            }
            currentStates = nextStates;
        }
        for (char state : currentStates)
        {
            if (acceptStates.count(state))
            {
                return true;
            }
        }
        return false;
    }

private:
    std::unordered_map<char, std::unordered_map<char, std::unordered_set<char>>> transitions;
    char startState;
    std::unordered_set<char> acceptStates;
};

int main()
{
    // Example grammar input
    std::unordered_map<char, std::unordered_map<char, std::unordered_set<char>>> transitions = {
        {'A', {{'0', {'A', 'B'}}, {'1', {'A'}}}},
        {'B', {{'1', {'C'}}}},
        {'C', {{'0', {'C'}}, {'1', {'C'}}}}};
    char startState = 'A';
    std::unordered_set<char> acceptStates = {'C'};

    NFA nfa(transitions, startState, acceptStates);

    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    if (nfa.accepts(input))
    {
        std::cout << "The string is accepted by the NFA." << std::endl;
    }
    else
    {
        std::cout << "The string is not accepted by the NFA." << std::endl;
    }

    return 0;
}