#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main()
{
    /* sub-árvore 'd' */
    NoArv* a1= arv_cria('d',arv_criavazia(),arv_criavazia());
    /* sub-árvore 'b' */
    NoArv* a2= arv_cria('b',arv_criavazia(),a1);
    /* sub-árvore 'e' */
    NoArv* a3= arv_cria('e',arv_criavazia(),arv_criavazia());
    /* sub-árvore 'f' */
    NoArv* a4= arv_cria('f',arv_criavazia(),arv_criavazia());
    /* sub-árvore 'c' */
    NoArv* a5= arv_cria('c',a3,a4);
    /* árvore 'a' */
    NoArv* a = arv_cria('a',a2,a5 );
}
