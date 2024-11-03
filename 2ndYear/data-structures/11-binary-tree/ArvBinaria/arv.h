#ifndef ARV_H_INCLUDED
#define ARV_H_INCLUDED

typedef struct noArv NoArv;

NoArv* arv_criavazia (void);
NoArv* arv_cria (char c, NoArv* e, NoArv* d);
NoArv* arv_libera (NoArv* a);
int arv_vazia (NoArv* a);
int arv_pertence (NoArv* a, char c);
void arv_imprime (NoArv* a);

#endif // ARV_H_INCLUDED
