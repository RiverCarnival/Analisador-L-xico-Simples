#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Palavras_reservadas
{
    char palavra[100];
    struct Palavras_reservadas *next;

}PL;

PL *listareservada;

void guardar(char palavra[])
{
    PL *p = (PL *) malloc(sizeof(PL));
    strcpy(p->palavra, palavra);
    p->next = listareservada;
    listareservada = p;

}

void armazenar()
{
    guardar("asm");
    guardar("auto");
    guardar("break");
    guardar("case");
    guardar("char");
    guardar("const"); 
    guardar("continue");
    guardar("default");
    guardar("do");
    guardar("double");
    guardar("else");
    guardar("enum");
    guardar("extern");
    guardar("float");
    guardar("for");
    guardar("goto");
    guardar("if");
    guardar("int");
    guardar("long");
    guardar("register");
    guardar("return");
    guardar("short");
    guardar("signed");
    guardar("sizeof");
    guardar("static");
    guardar("struct");
    guardar("switch");
    guardar("typedef");
    guardar("union");
    guardar("unsigned");
    guardar("void");
    guardar("volatile");
    guardar("while");
}
 
void mostrar(PL *p)
{
    
    if(p != NULL)
    {
        printf("%s\n", p->palavra);
        mostrar(p->next);
    }
    
}
// -------------------------------------------------------------------------------------------------------------------------
PL *listacomparada;

void palavas(char par[])
{
    PL *n = (PL *) malloc(sizeof(PL));
    strcpy(n->palavra, par);
    n->next = listacomparada;
    listacomparada = n;
}

void Read()
{
   
    FILE *ler;
    char x;
    char par[50]; 
    int i = 0;
    int z = 0;   

    // Coloque o arquivo na mesma pasta do codigo e insira o nome do arquivo abaixo
    ler = fopen("text.c", "r");  

    do
    {
        x = fgetc(ler);

        //printf("%c", x);

        while((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
        {
            i = 1;
            par[z] = x; 
            z++;
            x = fgetc(ler);

        }
        if(i == 1)
        {
            palavas(par);
            //printf("\n%s\n", par);
        }
        i = 0;
        z = 0;
        memset(par, 0, 50);  
    }while(x != EOF);

    fclose(ler);

}

void imprimir_encontradas(PL *c)
{
    if(c != NULL)
    {
        printf("%s\n", c->palavra);
        imprimir_encontradas(c->next);
    }
}
// -----------------------------------------------------------------------------------------------------

void comparar(PL *reservado, PL *encontrado)
{
    PL *xreservado = reservado;
    PL *yencontrado = encontrado;
    int encontrei = 0;

    while (yencontrado != NULL)
    {
        while( xreservado != NULL)
        {
            if(strcmp(xreservado->palavra, yencontrado->palavra) == 0)
            {
                printf("\nPalavra reservada encontrada: \n");
                printf("%s\n", xreservado->palavra);
            } 
            xreservado = xreservado->next;
        }
        yencontrado = yencontrado->next;
        xreservado = reservado;
    }
    
}

// ***************************************************************************************************************************

int main (void)
{
  
    armazenar();
    PL *save = listareservada;
    //printf("\n%d\n", save == NULL? 1:0);
    printf("Palavras Reservadas pela Linguagem: \n");
    mostrar(save);

    Read();
    PL *encontrado = listacomparada; 
    //printf("\n%d\n", encontrado == NULL? 1:0);
    printf("Palavras encontradas no Arquivo: \n");
    imprimir_encontradas(encontrado);

    comparar(save, encontrado);

    free(save);
    free(encontrado);
    return 0;
}
