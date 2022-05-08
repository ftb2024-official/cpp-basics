// начнем с директивы препроцессора; ADD_H - произвольное уникальное имя (обычно используется имя заголовочного имя)
#ifndef ADD_H
#define ADD_H

// содержимое заголовочного файла
int add(int, int); // прототип функции add()
int sub(int, int);
int multiply(int, int);
int divide(int, int);

// заканчиваем директивой препроцессора
#endif