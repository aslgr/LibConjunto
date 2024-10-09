// Testes para a LibConjunto.c

#include <stdio.h>
#include "LibConjunto.h"
#define TAM 21

int main()
{
    conjunto_t *a, *b, *u, *i, *d, *d1, *copia, *sub;
    int ex;

    // Teste para conjunto vazio.
    printf("\n---> Teste 1 : cria conjunto vazio...\n");
    if (!(a = cria_conjunto(TAM)))
    {
        printf("Falha na criação do conjunto.\n");
        return 1;
    }
    if (!conjunto_vazio(a))
    {
        printf("Criou conjunto não vazio.\n");
        return 1;
    }
    printf("OK: criou conjunto vazio.\n");

    // Teste de inserção de elementos no conjunto.
    printf("\n---> Teste 2 : inserindo elementos no conjunto...\n");
    for (int k = 1; k <= 10; k++)
    {
        ex = insere_conjunto(a, 2*k);

        if (ex == 0)
            printf("Elemento %d repetido e não inserido...\n", 2*k);

        if (ex == -1)
            printf("Acabou o espaço ao tentar inserir o elemento %d\n", 2*k);
    }
    printf("OK: inseriu todos os elementos corretamente no conjunto.\n");

    // Teste de impressão.
    printf("\n---> Teste 3\n");
    if (conjunto_vazio(a))
    {
        printf("Conjunto misteriosamente ficou vazio.\n");
        return 1;
    }
    imprime(a);
    printf("A saída deve ter sido os números pares de 2 a 20.\n");

    // Criando conjunto para testes de união, interseção e diferença.
    printf("\n---> Teste 4\n");
    if (!(b = cria_conjunto(TAM))) 
    {
        printf("Falha na criação do conjunto.\n");
        return 1;
    }
    for (int k = 1; k <= 20; k++)
    {
        ex = insere_conjunto(b, k);
        if (ex == 0)
            printf("Elemento %d repetido e não inserido...\n", k);

        if (ex == -1)
            printf("Acabou o espaço ao tentar inserir o elemento %d\n", k);
    }
    imprime(b);
    printf("A saída deve ter sido todos os números de 1 a 20.\n");

    // Teste para união de dois conjuntos.
    printf("\n---> Teste 5\n");
    if (!(u = cria_uniao(a, b))) 
    {
        printf("Falha na união de dois conjuntos.\n");
        return 1;
    }
    imprime(u);
    printf("A saída deve ter sido todos os números de 1 a 20.\n");

    // Teste para interseção de dois conjuntos.
    printf("\n---> Teste 6\n");
    if (!(i = cria_intersecao(a, b)))
    {
        printf("Falha na interseção de dois conjuntos.\n");
        return 1;
    }
    imprime(i);
    printf("A saída deve ter sido os números pares de 2 a 20.\n");

    // Teste para diferença de dois conjuntos.
    printf("\n---> Teste 7\n");
    if (!(d = cria_diferenca(a, b)))
    {
        printf("Falha na diferença de dois conjuntos.\n");
        return 1;
    }
    imprime(d);
    printf("A saída deve ter sido o conjunto vazio.\n");
    if (!(d1 = cria_diferenca(b, a)))
    {
        printf("Falha na diferença de dois conjuntos.\n");
        return 1;
    }
    imprime(d1);
    printf("A saída deve ter sido os números ímpares de 1 a 19.\n");

    // Teste para verificar se está contido.
    printf("\n---> Teste 8\n");
    if (!contido(a, b))
    {
        printf("Um conjunto ERRONEAMENTE NÃO ESTÁ contido no outro.\n");
        return 1;
    }
    printf("OK: um conjunto está contido no outro.\n");

    if (contido(b, a))
    {
        printf("Um conjunto ERRONEAMENTE ESTÁ contido no outro.\n");
        return 1;
    }
    printf("OK: um conjunto NÃO está contido no outro.\n");

    // Teste de igualdade de conjuntos.
    printf("\n---> Teste 9\n");
    if (!sao_iguais(a, i))
    {
        printf("Os conjuntos foram ERRONEAMENTE considerados diferentes.\n");
        return 1;
    }
    printf("OK: conjuntos iguais.\n");

    if (sao_iguais(a, b))
    {
        printf("Os conjuntos foram ERRONEAMENTE considerados iguais.\n");
        return 1;
    }
    printf("OK: conjuntos diferentes.\n");
    
    // Testes de remoção. Retira do início, do meio e do fim.
    printf("\n---> Teste 10\n");
    if (!retira_conjunto(a, 20))
        printf("Não foi capaz de retirar o último elemento.\n");
    printf("OK: retirou último elemento.\n");

    if (!retira_conjunto(a, 2))
        printf("Não foi capaz de retirar o primeiro elemento.\n");
    printf("OK: retirou primeiro elemento.\n");

    if (!retira_conjunto(a, 10))
        printf("Não foi capaz de retirar o elemento do meio.");
    printf("OK: retirou elemento do meio.\n");

    imprime(a);
    printf("Esta impressão deve ter resultado nos números pares de 4 a 18, menos o 10.\n");

    for (int k = 1; k <= 20; k++)
    {
        if (!retira_conjunto(a, k))
            printf("OK: não retirou %d\n", k);
        else
            printf("OK: retirou %d\n", k);
    }
    printf("Removeu todos os elementos?\n");
    imprime(a);
    printf("Em caso afirmativo a linha anterior contém conjunto vazio.\n");

    // Teste de cópia de conjuntos.
    printf("\n---> Teste 11\n");
    if (!(copia = cria_copia(b)))
    {
        printf("A cópia falhou.\n");
        return 1;
    }
    imprime(copia);
    printf("Se a cópia deu certo, foram impressos os números de 1 a 20.\n");

    // Teste de subconjuntos.
    printf("\n---> Teste 12\n");
    for (int k = 0; k <= cardinalidade(b); k++)
    {
        printf("Subconjunto de cardinalidade %d:\n", k);
        if (!(sub = cria_subconjunto(b, k)))
        {
            printf("Falhou em criar um subconjunto.\n");
            return 1;
        }
        imprime(sub);
        destroi_conjunto(sub);
        printf("Se deu certo, foi impresso um subconjunto dos números de 1 a 20 de tamanho %d\n",k);
    }

    // Teste de redimensionamento.
    printf("\n---> Teste 13\n");
    imprime(u); 
    if (!(redimensiona(u)))
        printf("Falha no redimensionamento do conjunto.\n");
    imprime(u); 
    printf("Redimensionou conjunto! Colocando mais 30 elementos...\n");
    for (int k = 21; k <= 51; k++)
        if (!insere_conjunto(u, k))
            printf("Falha na nova inserção.\n");
    imprime(u);
    printf("Se deu certo, imprimiu todos os números de 1 a 51.\n");

    // Teste do iterador.
    printf("\n---> Teste 14\n");
    iniciar_iterador(b);
    while (incrementar_iterador(b, &ex) != 0)
        printf ("%d ", ex);
    printf("\n");
    printf("Teste do iterador. A saída deve ter sido todos os números de 1 a 20.\n");

    // Teste de retirar elemento.
    printf("\n---> Teste 15\n");
    while (!conjunto_vazio(b))
    {
        ex = retirar_um_elemento(b);
        printf("%d ", ex);
    }
    printf("\n");
    printf("Teste de retirar um elemento aleatório do conjunto.\n");
    printf("A saída deve ter sido todos os números de 1 a 20, aleatoriamente.\n");
    printf("Logo abaixo, deve ser impresso um conjunto vazio.\n");
    imprime(b);

    // Destroi todos os conjuntos criados
    destroi_conjunto(a);
    destroi_conjunto(b);
    destroi_conjunto(u);
    destroi_conjunto(i);
    destroi_conjunto(d);
    destroi_conjunto(d1);
    destroi_conjunto(copia);

    return 0;
}
