#include <string.h>

int main()
{
    char *toto;
    int     i;

    toto = strdup("toto");
    while(42)
    {
        toto[i] = toto[i + 1];
        i++;
    }
}
