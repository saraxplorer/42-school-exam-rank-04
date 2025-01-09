#include <unistd.h>
#include <stdbool.h>

bool    is_open(char c)
{
    if (c == '(' || c == '{' || c == '[')
        return (true);
    return (false);
}

bool    is_close(char c)
{
    if (c == ')' || c == '}' || c == ']')
        return (true);
    return (false);
}

bool    is_order_matched(char open, char close)
{
    if ((open == '{' && close == '}') || (open == '[' && close == ']') || (open == '(' && close == ')'))
        return (true);
    return (false);
}

//initialize 2 int to 0
// 1. index to str [i]
// 2. index to stack[stack_index]
// 3. make an int array with 1000 or 100000 ints: stack[10000]
// while looping through the string--
// check if it is an opening bracket
//store it in stack 
//increase stack
//then check for closing bracket
//if found, check if it does not match or stack has already been emptied
//return false
//else meaning if matches, decrease stack
//cause we need to compare the second last with the second


bool my_bracket(char *str)
{
    int i = 0;
    int stack[10000];
    int stack_index = 0;
    while (str[i])
    {
        if (is_open(str[i]) == true)
        {
            stack[stack_index] = str[i];
            stack_index++;
        }
        if (is_close(str[i]) == true)
        {
            if (stack_index == 0 || is_order_matched(stack[stack_index - 1], str[i]) == false)
                return (false);
            else
                stack_index--;
        }
        i++;
    }
    if (stack_index != 0)
        return (false);
    return (true);
}

int main(int argc, char **argv)
{
    int i = 1;
    if (argc == 1)
        write(1, "\n", 1);
    else
    {
        while (i < argc)
        {
            if (my_bracket(argv[i]) == true)
                write(1, "OK\n", 3);
            else
                write(1, "Error\n", 6);
            i++;
        }
    }
    return 0;
}
