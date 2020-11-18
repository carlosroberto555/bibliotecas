# String Compat
Essa biblioteca é um _polyfill_ para habilitar o suporte a acentuações em ambiente windows. Trabalha de forma compatível com ambiente linux e windows.  
O tipo `String` é criado para representar string na linguagem C.  

## How to use

```c
#include "compat.h"

int main()
{
    // É necessário passar o idioma para habilitar o modo de compatibilidade
    start_compat("Portuguese");
    
    // O tipo String fica liberado para criar strings em puro C
    String nome;

    c_gets(nome, 50);
}
```
