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

private:
    Tape tape;
    int head_position;
    char blank_symbol;
    std::string current_state;
    std::set<std::string> final_states;
    std::map<std::pair<std::string, char>, std::tuple<std::string, char, char>> transition_function;
};