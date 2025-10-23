#include "RPN.hpp"


int RPN::ft_rpn(const std::string &expression)
{
    std::stack<int> values;

    for (std::size_t i = 0; i < expression.size(); ++i)
    {
        char token = expression[i];
        if (std::isspace(static_cast<unsigned char>(token)))
            continue;

        if (std::isdigit(static_cast<unsigned char>(token)))
        {
            values.push(token - '0');
        }
        else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            if (values.size() < 2)
                throw std::runtime_error("Malformed expression");

            int rhs = values.top();
            values.pop();
            int lhs = values.top();
            values.pop();

            int result = 0;
            switch (token)
            {
                case '+':
                    result = lhs + rhs;
                    break;
                case '-':
                    result = lhs - rhs;
                    break;
                case '*':
                    result = lhs * rhs;
                    break;
                case '/':
                    if (rhs == 0)
                        throw std::runtime_error("Division by zero");
                    result = lhs / rhs;
                    break;
            }

            values.push(result);
        }
        else
        {
            throw std::runtime_error("Invalid token");
        }
    }

    if (values.size() != 1)
        throw std::runtime_error("Malformed expression");

    return values.top();
}
