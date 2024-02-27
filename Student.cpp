#include "Student.h"
//глобальная инциализация статических полей
int Student::Count = 0;
int Student::Count_ID = 0;
string Last_Name;
string Name;
string Middle_Name;
int Count_Grades = 0;
int* Grades;
float GPA;
//Конструктор с параметрами(Ф,И,О,К_О)
Student::Student(string LN, string N, string MN, int CG) : Last_Name{ LN }, Name{ N }, Middle_Name{ MN }, Count_Grades{ CG }, GPA{ 0.0F }, ID{ ++Count_ID }
{
	Count++; //увеличиваем текущее кол-во студентов
	if (Count_Grades)Grades = new int [Count_Grades] {}; //чтобы можно было при создании студента задать кол-во его оценок
	//и его нельзя будет изменить потом
	else Grades = nullptr; //иначе, кол-во оценок не задано при создании студента, оно будет задаваться позднее
	//cout << "Constructor for ID: " << ID << endl; //тестовый вывод
}
//Конструктор по умолчанию(без параметров) с делегированием
Student::Student() : Student("", "", "")
{
	//cout << "Default constructor for ID: " << ID << endl; //тестовый вывод
}
//Деструктор
Student::~Student()
{
	//cout << "Destructor for ID: " << ID << endl; //тестовый вывод
	Count--; //уменьшаем текущее кол-во студентов
	if (Grades)delete[] Grades;   //если были оценки, то освобождаем память
	Grades = nullptr;			 //если деструктор был вызван явно(вручную)
	Count_Grades = 0;			 //если нунжо то обнуляем кол-во оценок
}
//Задающие метода(сеттеры):
//Метод изменения поля Фамилия
void Student::Set_Last_Name(string LN)
{
	Last_Name = LN;
	//char*
	/*delete[] Last_Name;
	Last_Name = new char[strlen(LN) + 1]{};
	strcpy_s(Last_Name, strlen(LN) + 1, LN);*/
}
//Метод изменения поля Имя
void Student::Set_Name(string N)
{
	Name = N;
}
//Метод изменения поля Отчество
void Student::Set_Middle_Name(string MN)
{
	Middle_Name = MN;
}
//Метод задания оценок
void Student::Set_Grades()
{
	//узнаем текущую кодировку на вывод
	int OCP = GetConsoleOutputCP();
	//если текущая кодировка не подходит, меняем на нужную
	if (OCP != 1251) SetConsoleOutputCP(1251);
	//работа с текстом

	cout << "У студента " << Last_Name << " " << Name << " " << Middle_Name << " " << Count_Grades << " оценок." << endl;
	if (!Count_Grades || !Grades)  //если оценок не было
	{
		if (Grades)delete[] Grades; //освобождение память на случай если кол-во оценок ноль, а память выделена
		cout << "Введите кол-во оценок студента " << Last_Name << " " << Name << " " << Middle_Name << ": ";
		cin >> Count_Grades; //добавить проверку ввода, значения должно быть больше 0
		Grades = new int[Count_Grades] {}; //выделяем память под массив оценок
	}
	GPA = 0.0F; //обнуляем средний балл
	for (int i = 0; i < Count_Grades; i++)
	{
		cout << "Введите " << i + 1 << "-ю оценку: "; cin >> Grades[i]; //добавить проверку ввода
		GPA += Grades[i]; //суммируем оценки
	}
	GPA /= Count_Grades; //вычисляем средний балл

	//если меняли кодировку, возвращаем обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}
//Метод заполнения всего студента с клавиатуры
void Student::Set_Console_Input()
{
	//узнаем текущие кодировки на вывод и ввод
	int OCP = GetConsoleOutputCP();
	int CP = GetConsoleCP();
	//если текущие кодировки не подходят, меняем на нужные
	if (OCP != 1251) SetConsoleOutputCP(1251);
	if (CP != 1251) SetConsoleCP(1251);
	//работа с текстом

	cout << "Введите ФИО через пробелы: ";
	cin >> Last_Name >> Name >> Middle_Name;
	Set_Grades(); //ввод оценок и расчет среднего балла

	//если меняли кодировки, возвращаем обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP);
	if (CP != 1251)SetConsoleCP(CP);
}
//Получающие методы(геттеры):
//Метод получения значения поля Фамилия
string Student::Get_Last_Name() const
{
	return Last_Name;
}
//Метод получения значения поля Имя
string Student::Get_Name() const
{
	return Name;
}
//Метод получения значения поля Отчество
string Student::Get_Middle_Name() const
{
	return Middle_Name;
}
//Метод получения значения поля ID
int Student::Get_ID() const
{
	return ID;
}
//Метод получения текущего кол-ва сдентов(объектов класса)
int Student::Get_Count()
{
	return Count;
}
//Метод получения значения оценок, без возможности их изменения
const int* Student::Get_Grades() const
{
	return Grades; //если оценок нет, вернется nullptr
}
//Метод получения значения среднего балла студента
float Student::Get_GPA() const
{
	return GPA;
}
//Метод вывода данных о студенте на экран
void Student::Show() const
{
	//узнаем текущую кодировку на вывод
	int OCP = GetConsoleOutputCP();
	//если текущая кодировка не подходит, меняем на нужную
	if (OCP != 1251) SetConsoleOutputCP(1251);
	//работа с текстом

	cout << "Идентификатор студента: " << ID << endl;
	cout << "ФИО: " << Last_Name << " " << Name << " " << Middle_Name << endl;
	if (!Count_Grades || !Grades)cout << "Оценок нет!" << endl;
	else
	{
		cout << "Оценки: ";
		for (int i = 0; i < Count_Grades; i++)
			cout << Grades[i] << " ";

		cout << "\nСредний балл: " << GPA << endl;
	}

	//если меняли кодировку, возвращаем обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}
//Метод записи объекта с динамическими полями в файл
void Student::Save(string Path, bool Mode)
{
	fstream Stream; //двунаправленный файловый поток
	//выбор дозаписать или перезаписать
	if (Mode)Stream.open(Path, ios::app, ios::binary); //дозаписать
	else Stream.open(Path, ios::out, ios::binary);  //перезаписать
	if (!Stream.is_open())
	{
		cerr << "Ошибка создания файла!" << endl;
		return;
	}
	cout << "Файл успешно создан!" << endl;
	//записываем в файл размер строки внутри string
	Stream << Last_Name.size();
	Stream.write(Last_Name.c_str(), Last_Name.size()); //записываем строку из string в файл

	//записываем в файл размер строки внутри string
	Stream << Name.size();
	Stream.write(Name.c_str(), Name.size()); //записываем строку из string в файл

	//записываем в файл размер строки внутри string
	Stream << Middle_Name.size();
	Stream.write(Middle_Name.c_str(), Middle_Name.size()); //записываем строку из string в файл
	//запись массива оценок
	Stream << Count_Grades;
	Stream.write((char*)Grades, Count_Grades * sizeof(int));
	Stream << GPA;
	Stream.close();
	cout << "Файл успешно записан!" << endl;
}

//Метод считываения объекта с динамическими полями из файла
void Student::Load(string Path)
{
	fstream Stream; //двунаправленный файловый поток
	Stream.open(Path, ios::in, ios::binary); //открываем на чтение в двоичном режиме
	if (!Stream.is_open())
	{
		cerr << "Ошибка открытия файла!" << endl;
		return;
	}
	cout << "Файл успешно открыт!" << endl;
	Last_Name.clear(); //очистка строки    
	Name.clear(); //очистка строки 
	Middle_Name.clear(); //очистка строки 
	if (Grades) //если есть оценки их нужно удалить
	{
		delete[] Grades;
		Grades = nullptr;
		Count_Grades = 0;
		GPA = 0;
	}

	int Size = 0; //для считывания размеров
	Stream >> Size; //считываем размер строки
	char* Buffer1 = new char[Size + 1] {}; //буфер для считывания строки
	Stream.read(Buffer1, Size);   //считываем строку 
	Last_Name = Buffer1; //сохраняем строку  
	delete[] Buffer1;
	Buffer1 = nullptr;

	Stream >> Size; //считываем размер строки
	char* Buffer2 = new char[Size + 1] {}; //буфер для считывания строки
	Stream.read(Buffer2, Size); //считываем строку 
	Name = Buffer2; //сохраняем строку 
	delete[] Buffer2;
	Buffer2 = nullptr;

	Stream >> Size; //считываем размер строки
	char* Buffer3 = new char[Size + 1] {}; //буфер для считывания строки
	Stream.read(Buffer3, Size);  //считываем строку 
	Middle_Name = Buffer3; //сохраняем строку 
	delete[] Buffer3;
	Buffer3 = nullptr;

	Stream >> Size; //считываем размер массива оценок
	if (Size == 0)
	{
		//выход, если нет оценок
		Stream.close();
		return;
	}
	Count_Grades = Size; //сохраняем кол-во оценок
	Grades = new int[Count_Grades] {}; //выделяем память под массив оценок
	Stream.read((char*)Grades, Count_Grades * sizeof(int)); //считываем оценки в память, где находится массив оценок
	Stream >> GPA;
	Stream.close();
	cout << "Файл успешно считан!" << endl;
}
//для считывания нескольких студентов
long Student::Load(fstream& Stream)
{
	if (!Stream.is_open())
	{
		cerr << "Ошибка открытия файла!" << endl;
		return 0;
	}
	cout << "Файл успешно открыт!" << endl;
	Last_Name.clear(); //очистка строки     
	Name.clear(); //очистка строки 
	Middle_Name.clear(); //очистка строки 
	if (Grades) //если есть оценки их нужно удалить
	{
		delete[] Grades;
		Grades = nullptr;
		Count_Grades = 0;
		GPA = 0;
	}
	int Size = 0; //для считывания размеров

	Stream >> Size; //считываем размер строки
	char* Buffer1 = new char[Size + 1] {}; //буфер для считывания строки
	Stream.read(Buffer1, Size);   //считываем строку 
	Last_Name = Buffer1; //сохраняем строку 
	delete[] Buffer1;
	Buffer1 = nullptr;

	Stream >> Size; //считываем размер строки
	char* Buffer2 = new char[Size + 1] {}; //буфер для считывания строки
	Stream.read(Buffer2, Size);   //считываем строку 
	Name = Buffer2; //сохраняем строку 
	delete[] Buffer2;
	Buffer2 = nullptr;

	Stream >> Size; //считываем размер строки
	char* Buffer3 = new char[Size + 1] {}; //буфер для считывания строки
	Stream.read(Buffer3, Size);   //считываем строку 
	Middle_Name = Buffer3; //сохраняем строку 
	delete[] Buffer3;
	Buffer3 = nullptr;

	Stream >> Size; //считываем размер массива оценок
	if (Size == 0)
	{
		//выход, если нет оценок

		return Stream.tellg(); //возвращает положение курсора в файле
	}
	Count_Grades = Size; //сохраняем кол-во оценок
	Grades = new int[Count_Grades] {}; //выделяем память под массив оценок
	Stream.read((char*)Grades, Count_Grades * sizeof(int)); //считываем оценки в память, где находится массив оценок
	Stream >> GPA;
	cout << "Файл успешно считан!" << endl;

	return Stream.tellg(); //возвращает положение курсора в файле
}