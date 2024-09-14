#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

class DPDA
{
public:
    DPDA(const std::set<std::string> &a, const std::set<std::string> &s, const std::string &init, const std::string &accept, const std::vector<std::tuple<std::string, char, std::string, std::string>> &t)
        : alphabet(a), states(s), initial_state(init), accept_state(accept), transitions(t) {}

private:
    std::set<std::string> alphabet;
    std::set<std::string> states;
    std::string initial_state;
    std::string accept_state;
    std::vector<std::tuple<std::string, char, std::string, std::string>> transitions; // Changed char to string for stack_top_symbol
    std::stack<std::string> d_stack;
};

int main()
{
    // Accepted
    DPDA dpda(
        {"a", "b"},
        {"q0", "q1", "q2"},
        "q0",
        "q2",
        {{"q0", 'a', "q0", "q1"}, {"q1", 'b', "q1", "q2"}});

    // Rejected

    return 0;
}