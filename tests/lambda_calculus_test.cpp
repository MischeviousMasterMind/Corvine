#include <gtest/gtest.h>
#include <root/math/lambda/lambda_calculus.hpp>

using namespace corvine;

TEST(LambdaCalculusTest, TestString)
{
    const std::string expression = "λx.(λy.x)n";

    lambda::Expression e = lambda::Expression(expression);

    const std::string newExpression = e.toString();

    std::cout << (signed char)'λ' << std::endl;

    for(int i = 0; i < e.terms.size(); i++)
    {
        printf("Index %3d: %p -> %c (%d)\n", i, e.terms.get(i), newExpression.at(i), newExpression.at(i));
    }
}