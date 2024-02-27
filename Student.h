#pragma once

#include <iostream>
#include <string> //содержит класс string
#include <Windows.h> //для изменения кодировок
#include <fstream>  

using namespace std;

//класс описывающий студента
class Student
{
	//поля
	string Last_Name;						//Фамилия
	string Name;							//Имя
	string Middle_Name;						//Отчество
	int Count_Grades;						//Кол-во оценок
	int* Grades;							//Динамический массив оценок
	float GPA;								//Средний балл оценок
	static int Count;						//Счетчик текущего кол-ва студентов(объектов класса Student)
	static int Count_ID;					//Счетчик для создания уникальных идентификаторов
	const int ID;							//Идентификатор студента
public:
	//прототипы методов:
	Student(string, string, string, int = 0);	//Конутрктор с параметрами(Ф,И,О,К_О)
	Student();								//Конструктор по умолчанию(без парамтеров)
	~Student();								//Деструктор
	//Задающие метода(сеттеры):
	void Set_Last_Name(string);				//Метод изменения поля Фамилия
	void Set_Name(string);					//Метод изменения поля Имя
	void Set_Middle_Name(string);			//Метод изменения поля Отчество
	void Set_Grades();						//Метод задания оценок
	void Set_Console_Input();				//Метод заполнения всего студента с клавиатуры
	//Получающие методы(геттеры):
	string Get_Last_Name()const;			//Метод получения значения поля Фамилия
	string Get_Name()const;					//Метод получения значения поля Имя
	string Get_Middle_Name()const;			//Метод получения значения поля Отчество
	int Get_ID()const;						//Метод получения значения поля ID
	static int Get_Count();					//Метод получения текущего кол-ва сдентов(объектов класса)
	const int* Get_Grades()const;			//Метод получения значения оценок, без возможности их изменения
	float Get_GPA()const;					//Метод получения значения среднего балла студента
	void Show()const;						//Метод вывода данных о студенте на экран

	//Метод записи объекта с динамическими полями в файл
	void Save(string Path, bool Mode = true);
	//Метод считываения объекта с динамическими полями из файла
	void Load(string Path); //принемает имя файла
	long Load(fstream& Stream);

};
