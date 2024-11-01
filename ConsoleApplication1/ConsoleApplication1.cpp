// 1. Разработать программу, B которой используются функции WriteConsoleOutputAttribute И ReadConsoleOutputAttribute для установки и чтения атрибутов текста консоли.
#include <windows.h> 
#include <iostream> 
using namespace std;
int main() 
{
	 HANDLE hStdOut; // дескрипторы буфера экрана 
	 WORD lpAttribute [5]; // массив клеток с атрибутами 
	 DWORD nLength = 5; // количество клеток 
	 COORD dwCoord = {3,1}; // координата первой клетки 
	 DWORD NumberOfAttrs; // количество обработанных клеток 
	 // читаем стандартный дескриптор вывода 
	 hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	 // выводим демо-текст
	 cout << "Console text attributes." << endl; 
	 // ждем команды на изменение атрибутов слова "текст" 
	 cout << "Press any key to change attributes."; 
	 cin.get(); // устанавливаем новые атрибуты 
	 lpAttribute [0] = BACKGROUND_BLUE | BACKGROUND_INTENSITY | 
		 FOREGROUND_GREEN | FOREGROUND_INTENSITY; 
	 lpAttribute [1] = BACKGROUND_GREEN | BACKGROUND_INTENSITY | 
		 FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	 lpAttribute [2] = BACKGROUND_RED | BACKGROUND_INTENSITY |
		 FOREGROUND_GREEN | FOREGROUND_INTENSITY; 
	 lpAttribute [3] = BACKGROUND_GREEN | BACKGROUND_INTENSITY |
		 FOREGROUND_RED | FOREGROUND_INTENSITY;
	 lpAttribute[4] = BACKGROUND_GREEN | BACKGROUND_INTENSITY |
		 FOREGROUND_RED | FOREGROUND_INTENSITY;
	 // записываем новые атрибуты в буфер экрана 
	 if (!WriteConsoleOutputAttribute(hStdOut, lpAttribute, nLength, dwCoord, &NumberOfAttrs))
	 {
		 cout << "Read console output attribute failed." << endl;
		 return GetLastError(); 
	 } 
	 // распечатываем атрибуты слова "текст" 
	 cout << hex; 
	 cout << "Attribute [0] = " << lpAttribute[0] << endl;
	 cout << "Attribute[1] = " << lpAttribute[1] << endl; 
	 cout << "Attribute [2] = " << lpAttribute[2] << endl; 
	 cout << "Attribute[3] = " << lpAttribute[3] << endl; 
	 cout << "Attribute[4] = " << lpAttribute[4] << endl;
	 // ждем команду на завершение программы 
	 cout << "Press any key to exit."; 
	 cin.get(); 
	 return 0; 
}