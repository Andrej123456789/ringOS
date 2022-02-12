#include "string.hpp"
#include "../../memory/heap.hpp"

int atoi(char* str)
{
    int integer = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        integer = integer * 10 + str[i] - '0';
    return integer;
}

size_t strlen(const char *str)
{
    if (str == nullptr) return 0;
    size_t length = 0;
    while(str[length]) length++;
    return length;
}

char *strcpy(char *destination, const char *source)
{
    if (destination == nullptr) return nullptr;
    char *ptr = destination;
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

char *strncpy(char *destination, const char *source, size_t n)
{
    if (destination == nullptr) return nullptr;
    char *ptr = destination;
    for (size_t i = 0; i < n && *source != '\0'; i++)
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

char *strcat(char *destination, const char *source)
{
    if (destination == nullptr) return nullptr;
    char *ptr = destination + strlen(destination);
    while (*source != '\0') *ptr++ = *source++;
    return destination;
}

char *strchr(const char *str, char ch)
{
    if (str == nullptr || ch == 0) return nullptr;
    while (*str && *str != ch ) ++str;
    return const_cast<char*>(ch == *str ? str : nullptr);
}

int strcmp(const char *a, const char *b)
{
    if (a == nullptr || b == nullptr) return 1;
    while (*a && *a == *b) { ++a; ++b; }
    return *a - *b;
}

int strncmp(const char *a, const char *b, size_t n)
{
    if (a == nullptr || b == nullptr) return 1;
    for (size_t i = 0; i < n; i++)
    {
        if (a[i] != b[i]) return 1;
    }
    return 0;
}

char *getline(const char *str, const char *substr, char *buffer, int skip)
{
    int i = 0;
    const char *strbck = str;
    const char *a = str, *b = substr;
    while (true)
    {
        if (!*b)
        {
            if (skip == 0)
            {
                int t = i;
                while (strbck[i - 1] != '\n') i--;
                while (strbck[t] != '\n') t++;
                int size = t - i;
                memcpy(buffer, const_cast<void*>(reinterpret_cast<const void*>(&strbck[i])), size);
                buffer[size] = 0;
                return buffer;
            }
            else skip--;
        }
        if (!*a) return 0;
        if (*a++ != *b++)
        {
            a = ++str;
            b = substr;
            i++;
        }
    }
    return 0;
}

char *reverse(char s[])
{
    size_t c, j, i;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

uint16_t strlength(char* ch)
{
    uint16_t i = 1;
    while(ch[i++]);  
    return --i;
}

uint8_t strEql(char* ch1, char* ch2)                     
{
    uint8_t result = 1;
    uint8_t size = strlength(ch1);
    if(size != strlength(ch2)) result =0;
    else 
    {
        uint8_t i = 0;
        for(i;i<=size;i++)
        {
                if(ch1[i] != ch2[i]) result = 0;
        }
    }
    return result;
}

char tolower(char c)
{
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

char toupper(char c)
{
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

int tonum(char c)
{
    c = toupper(c);
    return (c) ? c - 64 : -1;
}

char str[2];
char *tostr(char c)
{
    str[0] = c;
    return str;
}

char char2low(char c)
{
    return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

char char2up(char c)
{
    return (c >= 'a' && c <= 'z') ? c - 32 : c;
}

int char2num(char c)
{
    c = char2up(c);
    return (c) ? c - 64 : -1;
}

char str2[2];
char *char2str(char c)
{
    str2[0] = c;
    return str2;
}

int string2int(const char* str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        res = res * 10 + str[i] - '0';
    }
    return res;
}