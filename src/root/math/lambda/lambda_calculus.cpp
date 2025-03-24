#include "root/util/list.hpp"
#include <string>

namespace corvine::lambda
{
    const unsigned char LAMBDA = 0x00000000;

    const unsigned char LEFT_BRACKET = 0x11111110;
    const unsigned char RIGHT_BRACKET = 0x11111111;

    struct Expression
    {
        List<char> variables = List<char>();
        List<unsigned char> terms = List<unsigned char>();

        Expression() {}

        Expression(std::string expression)
        {

            for (size_t i = 0; i < expression.size(); i++)
            {
                switch (expression.at(i))
                {
                default:
                    if (variables.contains(expression.at(i)))
                    {
                        terms.push((unsigned char)variables.indexOf(expression.at(i)));
                    }
                    else
                    {
                        terms.push((unsigned char)variables.size());
                        variables.push(expression.at(i));
                    }

                    break;

                case 'λ':
                    terms.push(LAMBDA);
                    break;

                case '(':
                    terms.push(LEFT_BRACKET);
                    break;

                case ')':
                    terms.push(RIGHT_BRACKET);
                    break;

                case '.':
                    break;
                }
            }
        }

        std::string toString()
        {
            std::string expression = "";

            for (int i = 0; i < terms.size(); i++)
            {
                switch (terms.get(i))
                {
                default:
                    expression += variables.get((size_t)terms.get(i) - 1);
                    break;

                case LAMBDA:
                    expression += "λ";
                    break;

                case LEFT_BRACKET:
                    expression += "(";
                    break;

                case RIGHT_BRACKET:
                    expression += ")";
                    break;
                }
            }

            for(size_t i = 0; i < expression.size(); i++)
            {
                if(expression.at(i) == 'λ')
                {
                    expression = expression.substr(0, i + 1) + "." + expression.substr(i + 1);
                }
            }

            return expression;
        }
    };

}