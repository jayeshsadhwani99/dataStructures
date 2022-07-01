# Infix, Prefix and Postfix

## Infix

> \<operand> \<operator> \<operand>

Infix notation is the notation commonly used in arithmetical and logical formulae and statements. It is characterized by the placement of operators between operands

> Example:
>
> 2 + 2
>
> 3 \* 4 + a

We can't use this while programming. This is because this notation has a lot of ambiguity, or doubt that which operation do we apply first. We have better options - Prefix and Postfix

> Order of operations:
>
> 1. Parenthesis
> 2. Exponents (in case of multiple - right to left)
> 3. Multiplication and Division
> 4. Addition and Substraction

## Prefix

> \<operator> \<operand> \<operand>

Also known as **Polish Notion** and was introduced in 1924.

Here, operator is placed operands

> Example:
>
> \+ 2 2
>
> \+ \* 3 4 a

In this type of notation, one operand is only associated with one operator

## Postfix

> \<operand> \<operand> \<operator>

Also known as the **Reverse Polish Notation**

Programaticaly, this expression is the easiest to parse and least time and memory consuming.

Prefix can also be executed in a similar complexity, but the algorithm to evaluate postfix expressions is quite intuitive and easy.

> Example:
>
> 2 2 +
>
> 3 4 a + \*
