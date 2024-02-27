//#include <iostream> //уже не требуется, так как подключена Student.h
#include "Student.h" //подключаем заголовочный файл, содержащий описание класса Student
//#include "D:\Библиотеки C++\Student.h" //подключение по полному пути

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string Path;
	cout << "Введите имя файла: ";
	getline(cin, Path);

	cout << "Текущее кол-во студентов: " << Student::Get_Count() << endl;
	int Size = 0;
	cout << "Введите кол-во студентов в группе: "; cin >> Size;
	Student* PV322 = new Student[Size]; //для каждого элемента массива(объекта класса Student)
	//вызывается конструктор по умолчанию

	for (int i = 0; i < Size; i++)
	{
		cout << "Введите данные " << i + 1 << "-го студента: " << endl;
		PV322[i].Set_Console_Input();

	}
	for (int i = 0; i < Size; i++)
	{
		PV322[i].Show();
		cout << endl;
	}
	for (int i = 0; i < Size; i++)
	{
		PV322[i].Save(Path);
		cout << endl;
	}
	Student Buffer;
	Buffer.Load(Path);
	cout << endl;
	system("pause");
	Buffer.Show();
	cout << endl;
	/*Student Buffer;
	fstream Stream; //двунаправленный файловый поток
	Stream.open(Path, ios::in, ios::binary);
	while (!Stream.eof())
	{
		long Cursor = Buffer.Load(Stream);
		if (!Cursor)break;
		if (Cursor != EOF)
		{
			//можно сохранить студентов в массив или в динамическую структуру хранения данных
			Buffer.Show();
		}
	}
	Stream.close();*/
	system("pause");
	delete[] PV322;
	PV322 = nullptr;
}