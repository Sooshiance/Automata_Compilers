#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// Tokens(Terminals)
enum Token
{
    ID,
    PLUS,
    STAR,
    LPAREN,
    RPAREN,
    END,
    INVALID
};

// Lexer to tokenize the input string
class Lexer
{
public:
    Lexer(const string &input) : input(input), index(0) {}

    Token nextToken()
    {
        while (index < input.size() && isspace(input[index]))
        {
            index++;
        }

        if (index == input.size())
            return END;

        char current = input[index];
        if (isdigit(current))
        {
            index++;
            return ID; // Simplified: treating any digit as ID
        }
        else if (current == '+')
        {
            index++;
            return PLUS;
        }
        else if (current == '*')
        {
            index++;
            return STAR;
        }
        else if (current == '(')
        {
            index++;
            return LPAREN;
        }
        else if (current == ')')
        {
            index++;
            return RPAREN;
        }

        return INVALID;
    }

private:
    string input;
    size_t index;
};

// LL(1) Parser
class Parser
{
public:
    Parser(Lexer &lexer) : lexer(lexer), currentToken(lexer.nextToken()) {}

    void parse()
    {
        E();
        if (currentToken != END)
        {
            throw runtime_error("Unexpected token at end");
        }
    }

private:
    Lexer &lexer;
    Token currentToken;

    void E()
    {
        T();
        EPrime();
    }

    void EPrime()
    {
        if (currentToken == PLUS)
        {
            currentToken = lexer.nextToken(); // consume +
            T();
            EPrime();
        }
    }

    void T()
    {
        F();
        TPrime();
    }

    void TPrime()
    {
        if (currentToken == STAR)
        {
            currentToken = lexer.nextToken(); // consume *
            F();
            TPrime();
        }
    }

    void F()
    {
        if (currentToken == ID)
        {
            currentToken = lexer.nextToken(); // consume ID
        }

        else if (currentToken == LPAREN)
        {
            currentToken = lexer.nextToken(); // consume (
            E();
            if (currentToken != RPAREN)
            {
                throw runtime_error("Expected )");
            }

            currentToken = lexer.nextToken(); // consume )
        }

        else
        {
            throw runtime_error("Unexpected token in F");
        }
    }
};

int main()
{
    string input;

    cout << "Enter an expression: ";
    getline(cin, input);

    Lexer lexer(input);
    Parser parser(lexer);

    try
    {
        parser.parse();
        cout << "Input is valid!" << endl;
    }

    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
