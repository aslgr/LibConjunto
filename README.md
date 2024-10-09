# LibConjunto
This project implements a set library in C, providing basic set operations such as union, intersection, difference, element insertion and removal.

## Introduction
The project consists of a C library that implements fundamental operations for manipulating sets ("Conjuntos" in Portuguese) of integers. The primary objective of this library is to provide an efficient way to perform common set operations, such as union and intersection, while ensuring that sets maintain their properties. In addition to the library, a test suite is implemented to ensure the correctness and robustness of the functions, aiming for effective memory management without leaks.

### Implemented Functions
1. conjunto_t *cria_conjunto(int max): This function allocates memory for a new set with a specified maximum size.
2. conjunto_t *destroi_conjunto(conjunto_t *c): This function frees the memory occupied by the set.
3. int conjunto_vazio(conjunto_t *c): This function checks if the set is empty.
4. int cardinalidade(conjunto_t *c): This function returns the number of elements in the set.
5. int insere_conjunto(conjunto_t *c, int elemento): This function inserts an element into the set, ensuring no duplicates.
6. int retira_conjunto(conjunto_t *c, int elemento): This function removes an element from the set, if it exists.
7. int pertence(conjunto_t *c, int elemento): This function checks if an element is part of the set.
8. int contido(conjunto_t *c1, conjunto_t *c2): This function determines if set c1 is a subset of c2.
9. int sao_iguais(conjunto_t *c1, conjunto_t *c2): This function checks if two sets are equal.
10. conjunto_t *cria_diferenca(conjunto_t *c1, conjunto_t *c2): This function creates a new set containing elements that are in c1 but not in c2.
11. conjunto_t *cria_intersecao(conjunto_t *c1, conjunto_t *c2): This function creates a new set containing elements that are both in c1 and in c2.
12. conjunto_t *cria_uniao(conjunto_t *c1, conjunto_t *c2): This function creates a new set containing all elements from both sets.
13. conjunto_t *cria_copia(conjunto_t *c): This function creates a copy of the set.
14. conjunto_t *cria_subconjunto(conjunto_t *c, int n): This function creates a random subset, of a specified size, from the set.
15. void imprime(conjunto_t *c): This function prints the elements of the set in ascending order.
16. int redimensiona(conjunto_t *c): This function doubles the maximum size of the set.
17. void iniciar_iterador(conjunto_t *c): This function initializes an iterator for the set.
18. int incrementar_iterador(conjunto_t *c, int *elemento): This function advances the iterator and returns the current element being pointed.
19. int retirar_um_elemento(conjunto_t *c): This function removes and returns a random element from the set.

## Results
The library was tested using the testa_conjunto.c file, which validated the correctness of the implemented functions through various scenarios. Besides that, the code handles memory allocation and deallocation without errors. Memory management was verified through a tool called Valgrind.

## Conclusing
This project successfully implements a set library in C, offering essential set operations while maintaining efficient memory handling. The tests confirmed that the library functions as intended, and the methodology used ensures a reliable and reusable codebase for future applications.
