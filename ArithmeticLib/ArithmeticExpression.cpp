#include "ArithmeticExpression.h"

void TArithmeticExpression::toPostfix()
{
  //postfix operands(nulls)
}

void TArithmeticExpression::Parse()
{
  TMap<char, char> lex(1);
  for (size_t i = 0; i < infix.GetLen(); i++)
  {
    char l = infix[i];
    if (isdigit(l) != 0)
      lex.Insert(l, 'c');
    else if (isalpha(l) != 0)
      lex.Insert(l, 'v');
    else if (priority.IsInsertKey(l) || l == '(' || l == ')')
      lex.Insert(l, 'o');
    else
      throw invalid_argument("Expression has invalid arguments");
  }
  lexems = lex;
}

TArithmeticExpression::TArithmeticExpression(TString expr)
{
  infix = expr;
  char opers[4] = { '+', '-', '*', '/' };
  int priors[4] = { 1, 1, 2, 2 };
  TMap<char, int> pri(4, opers, priors);
  priority = pri;
  Parse();
  toPostfix();
}

TString TArithmeticExpression::GetInfix()
{
  return infix;
}

TString TArithmeticExpression::GetPostfix()
{
  return postfix;
}

void TArithmeticExpression::SetOperands()
{
  for (size_t i = 0; i < operands.Count(); i++)
    if (lexems[operands.GetKey(i)] == 'v')
    {
      cout << "Value of key " << operands.GetKey(i) << ":";
      cin >> operands[operands.GetKey(i)];
    }
}