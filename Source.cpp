#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
int Count(char* str, int i) // !!!!!!!!!!!!!!!!! 1.2 Завдання
{
    if (strlen(str) < 3)
        return 0;
    if (str[i + 1] != 0)
        if (str[i - 1] == 'n' && str[i + 1] == 'o')
            return true;
        else
            return Count(str, i + 1);
    else
        return 0;
}
char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i + 2] != 0)
    {
        if (str[i] == 'n' && str[i + 2] == 'o')
        {
            strcat(t, "**");
            return Change(dest, str, t + 2, i + 3);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        *t++ = str[i++];
        *t++ = str[i++];
        *t = '\0';
        return dest;
    }
}
int main()
{
    char str[101];
    cout << "Enter string:" << endl; //enter divide into parts as example
    cin.getline(str, 100);
    Count(str, 1) ? cout << "Such i exists" : cout << "Such i doesn't exist";
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
    dest2 = Change(dest1, str, dest1, 0);
    cout << "\nModified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;
    return 0;
}