/**************************************************\
 * Biblioteca para compatibilidade de codificação *
 * Para Windows e Linux                           *
 * ---------------------------------------------- *
 * Autor: Carlos Roberto                          *
 * Data: 29/11/2016                               *
 * Link: https://goo.gl/AKwg6j                    *
\**************************************************/

/**
 * Simula o tipo string com um ponteiro de char
 */
typedef char* String;

#ifdef _WIN32 // Quando estiver em windows

// Bibliotecas para windows
#include <stdlib.h> 
#include <fcntl.h>
#include <io.h>

/**
 * Executa tarefas específicas do windows
 */
void _start_compat()
{
	// Troca a leitura da entrada para wide char
	_setmode(_fileno(stdin), _O_WTEXT);
	
	// Limpa o buffer
	fflush(stdin);
}

/**
 * Faz a leitura do stdin em wide char
 * E converte para ponteiro de char
 */
void c_gets(String string, int size)
{
	wchar_t *buffer;

	wscanf(L"%[^\n]ls", buffer);
	fflush(stdin);
	
	// Aloca no máximo o passado por parametro size
	int size_in = wcslen(buffer) <= size ? wcslen(buffer) : size;
	
	// Faz a conversão
	for(int i=0; i<size_in; i++)
	{
		*(string + i) = (int) buffer[i];
	}
	
	if (size_in <= size)
	{
		*(string + size_in) = '\0';
	}
}

#elif __linux__ // Quando estiver em linux

/**
 * Executa tarefas específicas do linux
 */
void _start_compat(){}

/**
 * Faz a leitura do stdin em char
 */
void c_gets(String string, int size)
{
	scanf("%[^\n]", string);
	fflush(stdin);
}

#endif

#include <locale.h>

/**
 * Inicia a biblioteca, de acordo com o locale inserido
 */
void start_compat (String locale)
{
	setlocale(LC_ALL, locale);
	_start_compat();
}

String string_alloc(int size)
{
    return (String) malloc(sizeof(String) * size);
}
