#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

class Tape
{
public:
    static const char blank_symbol = ' ';

    Tape(const std::string &tape_string = "")
    {
        for (size_t i = 0; i < tape_string.size(); ++i)
        {
            tape[i] = tape_string[i];
        }
    }

    std::string toString() const
    {
        std::string s;
        int min_used_index = minIndex();
        int max_used_index = maxIndex();
        for (int i = min_used_index; i <= max_used_index; ++i)
        {
            s += get(i);
        }
        return s;
    }

    char get(int index) const
    {
        auto it = tape.find(index);
        if (it != tape.end())
        {
            return it->second;
        }
        else
        {
            return blank_symbol;
        }
    }

    void set(int pos, char ch)
    {
        tape[pos] = ch;
    }

private:
    std::map<int, char> tape;

    int minIndex() const
    {
        if (tape.empty())
            return 0;
        return tape.begin()->first;
    }

    int maxIndex() const
    {
        if (tape.empty())
            return 0;
        return tape.rbegin()->first;
    }
};

class TuringMachine
{
    public:
    TuringMachine(const std::string &tape_str = "",
                  char blank_symbol = ' ',
                  const std::string &initial_state = "",
                  const std::set<std::string> &final_states = {},
                  const std::map<std::pair<std::string, char>, std::tuple<std::string, char, char>> &transition_function = {})
        : tape(tape_str), blank_symbol(blank_symbol), current_state(initial_state),
          final_states(final_states), transition_function(transition_function), head_position(0) {}

    std::string getTape() const
    {
        return tape.toString();
    }

    void step()
    {
        char char_under_head = tape.get(head_position);

        auto x = std::make_pair(current_state, char_under_head);

        auto it = transition_function.find(x);

        if (it != transition_function.end())
        {
            auto y = it->second;

            current_state = std::get<0>(y);
            tape.set(head_position, std::get<1>(y));

            if (std::get<2>(y) == 'R')
            {
                head_position++;
            }
            else if (std::get<2>(y) == 'L')
            {
                head_position--;
            }
        }
        else
        {
            std::cout << "No transition found for state " << current_state << " and symbol " << char_under_head << std::endl;
        }
    }

    bool isFinal() const
    {
        return final_states.find(current_state) != final_states.end();
    }

    void debug() const
    {
        std::cout << "Current state: " << current_state << ", Head position: " << head_position << ", Tape: " << getTape() << std::endl;
    }

private:
    Tape tape;
    int head_position;
    char blank_symbol;
    std::string current_state;
    std::set<std::string> final_states;
    std::map<std::pair<std::string, char>, std::tuple<std::string, char, char>> transition_function;
};