#include <string.h>

namespace corvine
{

    class Expression
    {
        char *latex;

    public:
        Expression()
        {
            latex = nullptr;
        }

        Expression(char latex[])
        {
            setExpression(latex);
        }

        void setExpression(char latex[])
        {
            this->latex = latex;
        }


    };

}