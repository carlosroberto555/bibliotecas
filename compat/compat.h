#ifdef _WIN32 // Quando estiver em windows

// Bibliotecas para windows
#include <fcntl.h>
#include <io.h>

/**
 * Define o tipo string como um wide char,
 * para usar codificação em caracteres especiais
 */
typedef wchar_t* String;

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
 */
void c_gets(String string)
{
	wscanf(L"%[^\n]ls", string);
	fflush(stdin);
}

#elif __linux__ // Quando estiver em linux

// Simula o tipo string com um ponteiro de char
typedef char* String;

// 
void _start_compat();

void c_gets(String string)
{
	scanf("%[^\n]s", string);
	fflush(stdin);
}

#endif

#include <locale.h>

void start_compat (String locale)
{
	setlocale(LC_ALL, locale);
	_start_compat();
}
