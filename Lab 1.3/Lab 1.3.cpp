#include <iostream>
using namespace std;

char* Strchr(char* str, int c)
{
    size_t len = 0;
    char* rest_of_String = NULL;
    while (str[len] != '\0')
    {
        if (str[len] == c) { rest_of_String = str + len; break; }
        len++;
    }
    return rest_of_String;
}
   
int main()
{
    char str[] = "Some Text";
    printf("Find sub-string in: %s\n", str);
    char symbol;
    scanf_s("%c", &symbol);
    char* standard_result = strchr(str, symbol);
    char* my_result = Strchr(str, symbol);
    printf("Initial string: %s\nStandard: %s\nMy version: %s\n", str, standard_result, my_result);
}
