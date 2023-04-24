#include <stdio.h>
#include <stdlib.h>

void wyswietl(const int* poczatek, const int* koniec)
{
    for(int i=0; i<*koniec; i++)
    {
        printf("%d ",*(poczatek + i));
    }
}

int main(void) {
    const int tab[] = {1, 2, 3};
    const int n =sizeof(tab)/sizeof(tab[0]);

    wyswietl(tab, tab + n);
    return EXIT_SUCCESS;
}