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

    bool isAccept(const std::string &input)
    {
        // Push initial state to stack.
        d_stack.push(initial_state);

        std::string current_state = initial_state;

        for (char symbol : input)
        {
            bool transition_found = false;
            for (const auto &[from_state, read_symbol, stack_top_symbol, to_state] : transitions)
            {
                if (current_state == from_state && symbol == read_symbol && d_stack.top() == stack_top_symbol)
                {
                    d_stack.pop();            // Pop the stack top.
                    d_stack.push(to_state);   // Push the new state onto the stack.
                    current_state = to_state; // Update current state.
                    transition_found = true;
                    break;
                }
            }
            if (!transition_found)
                return false;
        }
    }

private:
    std::set<std::string> alphabet;
    std::set<std::string> states;
    std::string initial_state;
    std::string accept_state;
    std::vector<std::tuple<std::string, char, std::string, std::string>> transitions;
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

    if (dpda.isAccept("ab"))
    {
        std::cout << "Accepted" << std::endl;
    }
    else
    {
        std::cout << "Rejected" << std ::endl;
    }

    // Rejected
    DPDA dpda2(
        {"a", "b"},
        {"q0", "q1", "q2"},
        "q0",
        "q2",
        {{"q0", 'a', "q0", "q1"}, {"q0", 'b', "q1", "q2"}});

    if (dpda2.isAccept("ab"))
    {
        std::cout << "Accepted" << std::endl;
    }
    else
    {
        std::cout << "Rejected" << std ::endl;
    }

    return 0;
}