#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//OK Example:
//<ab bc ca> <xy yz zx> </xy> </ab> 
//Stack/array members: ["ab"], ["ab", "xy"] 
//only the first word goes in the array, cause the first word is name


//KO Example:
//<ab bc ca> <xy yz zx> </ab> </xy>
//Stack: ["ab"], ["ab", "xy"]

//In HTML, tags like <img>, <input>, and <br> are void elements (self-closing). 
//They don’t have corresponding closing tags (</img>), so they:
//Don’t need to remain on the stack.
//So Are "removed" immediately after being identified.

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}


//basic structure
//initialize a char **array and a char *temporary string
//initialize 3 int to 0
// 1. for iterating through input str (i)
// 2. iterationg through members of array
// 3. to store the start index of each tag word (`start`)
//malloc for the array
//make a while loop iterating through the input string
//set default return as 0 and write OK outside loop
//in while loop, make one if block and one else if block with condition
//if the str is an opening tag
//else if the string is a closing tag

//inside if block meaning if it is an opening tag
//set start index from after <
//we go to the end of the first word
//make array index plus one for some reason!?
//then malloc and strncpy the word in array[index] that index of the array
//set the last index to null
//check if the array still exists and strncmp img
//free the stack and reduce array index

//inside else if block meaning if the str is closing tag
//set start from after </
//go to the end of the word
//malloc and strncpy for temp
//set the last char to null
//then compare it with whatever we have in the array?
//if it matches with the array thing the free and reduce the array index
//else return 1 and write KO


int tag_validator(char *str)
{
    int i = 0;
    int j = 0;
    int start = 0;
    char **stack;
    char *temp;
    stack = (char**)malloc(sizeof(char*) * 100);
    while (str[i])
    {
        if (str[i] == '<' && str[i + 1] != '/')//it is not a closing part
        {
            start = i + 1; //store index from after <
            while (str[i] != '>' && str[i] != ' ')//go to the end of first word
                i++;//now i holds the end of word
            j++;
            stack[j] = (char*)malloc(sizeof(char) * i - start + 1);
            strncpy(stack[j], &str[start], i - start);//store the first word
            stack[j][i - start] = '\0';
            if (stack[j] && strncmp(stack[j], "img", 3) == 0)//cause in the beginnning
            {
                free(stack[j]);
                j--;
            }

        }
        else if (str[i] == '<' && str[i + 1] == '/')//it is a closing part
        {
            start = i + 2; //start storing from after /
            while (str[i] != '>' && str[i] != '\0')
                i++;//go to the end of the word
            temp = (char *)malloc(sizeof(char) * i - start + 1);
            strncpy(temp, &str[start], i - start);
            temp[i - start] = '\0';
            if (stack[j] && strncmp(stack[j], temp, ft_strlen(temp)) == 0)
            {
                free(stack[j]);
                j--;
            }
             else
            {
                write (1, "KO\n", 3);
                return (1);
            }
        }
        i++;
    }
    write (1, "OK\n", 3);
    return (0);

}

//should return the return value of validator function
//so validator should return an int and it shall take one str as parameter

int main(int argc, char **argv)
{
    if (argc == 1)
         write(1, "\n", 1); 
    return (tag_validator(argv[1]));
}