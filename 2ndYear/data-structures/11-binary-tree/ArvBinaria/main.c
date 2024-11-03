#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

int main()
{
    /* sub-�rvore 'd' */
    NoArv* a1= arv_cria('d',arv_criavazia(),arv_criavazia());
    /* sub-�rvore 'b' */
    NoArv* a2= arv_cria('b',arv_criavazia(),a1);
    /* sub-�rvore 'e' */
    NoArv* a3= arv_cria('e',arv_criavazia(),arv_criavazia());
    /* sub-�rvore 'f' */
    NoArv* a4= arv_cria('f',arv_criavazia(),arv_criavazia());
    /* sub-�rvore 'c' */
    NoArv* a5= arv_cria('c',a3,a4);
    /* �rvore 'a' */
    NoArv* a = arv_cria('a',a2,a5 );
}
