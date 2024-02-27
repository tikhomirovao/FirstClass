#include "Student.h"
//���������� ������������ ����������� �����
int Student::Count = 0;
int Student::Count_ID = 0;
string Last_Name;
string Name;
string Middle_Name;
int Count_Grades = 0;
int* Grades;
float GPA;
//����������� � �����������(�,�,�,�_�)
Student::Student(string LN, string N, string MN, int CG) : Last_Name{ LN }, Name{ N }, Middle_Name{ MN }, Count_Grades{ CG }, GPA{ 0.0F }, ID{ ++Count_ID }
{
	Count++; //����������� ������� ���-�� ���������
	if (Count_Grades)Grades = new int [Count_Grades] {}; //����� ����� ���� ��� �������� �������� ������ ���-�� ��� ������
	//� ��� ������ ����� �������� �����
	else Grades = nullptr; //�����, ���-�� ������ �� ������ ��� �������� ��������, ��� ����� ���������� �������
	//cout << "Constructor for ID: " << ID << endl; //�������� �����
}
//����������� �� ���������(��� ����������) � ��������������
Student::Student() : Student("", "", "")
{
	//cout << "Default constructor for ID: " << ID << endl; //�������� �����
}
//����������
Student::~Student()
{
	//cout << "Destructor for ID: " << ID << endl; //�������� �����
	Count--; //��������� ������� ���-�� ���������
	if (Grades)delete[] Grades;   //���� ���� ������, �� ����������� ������
	Grades = nullptr;			 //���� ���������� ��� ������ ����(�������)
	Count_Grades = 0;			 //���� ����� �� �������� ���-�� ������
}
//�������� ������(�������):
//����� ��������� ���� �������
void Student::Set_Last_Name(string LN)
{
	Last_Name = LN;
	//char*
	/*delete[] Last_Name;
	Last_Name = new char[strlen(LN) + 1]{};
	strcpy_s(Last_Name, strlen(LN) + 1, LN);*/
}
//����� ��������� ���� ���
void Student::Set_Name(string N)
{
	Name = N;
}
//����� ��������� ���� ��������
void Student::Set_Middle_Name(string MN)
{
	Middle_Name = MN;
}
//����� ������� ������
void Student::Set_Grades()
{
	//������ ������� ��������� �� �����
	int OCP = GetConsoleOutputCP();
	//���� ������� ��������� �� ��������, ������ �� ������
	if (OCP != 1251) SetConsoleOutputCP(1251);
	//������ � �������

	cout << "� �������� " << Last_Name << " " << Name << " " << Middle_Name << " " << Count_Grades << " ������." << endl;
	if (!Count_Grades || !Grades)  //���� ������ �� ����
	{
		if (Grades)delete[] Grades; //������������ ������ �� ������ ���� ���-�� ������ ����, � ������ ��������
		cout << "������� ���-�� ������ �������� " << Last_Name << " " << Name << " " << Middle_Name << ": ";
		cin >> Count_Grades; //�������� �������� �����, �������� ������ ���� ������ 0
		Grades = new int[Count_Grades] {}; //�������� ������ ��� ������ ������
	}
	GPA = 0.0F; //�������� ������� ����
	for (int i = 0; i < Count_Grades; i++)
	{
		cout << "������� " << i + 1 << "-� ������: "; cin >> Grades[i]; //�������� �������� �����
		GPA += Grades[i]; //��������� ������
	}
	GPA /= Count_Grades; //��������� ������� ����

	//���� ������ ���������, ���������� �������
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}
//����� ���������� ����� �������� � ����������
void Student::Set_Console_Input()
{
	//������ ������� ��������� �� ����� � ����
	int OCP = GetConsoleOutputCP();
	int CP = GetConsoleCP();
	//���� ������� ��������� �� ��������, ������ �� ������
	if (OCP != 1251) SetConsoleOutputCP(1251);
	if (CP != 1251) SetConsoleCP(1251);
	//������ � �������

	cout << "������� ��� ����� �������: ";
	cin >> Last_Name >> Name >> Middle_Name;
	Set_Grades(); //���� ������ � ������ �������� �����

	//���� ������ ���������, ���������� �������
	if (OCP != 1251)SetConsoleOutputCP(OCP);
	if (CP != 1251)SetConsoleCP(CP);
}
//���������� ������(�������):
//����� ��������� �������� ���� �������
string Student::Get_Last_Name() const
{
	return Last_Name;
}
//����� ��������� �������� ���� ���
string Student::Get_Name() const
{
	return Name;
}
//����� ��������� �������� ���� ��������
string Student::Get_Middle_Name() const
{
	return Middle_Name;
}
//����� ��������� �������� ���� ID
int Student::Get_ID() const
{
	return ID;
}
//����� ��������� �������� ���-�� �������(�������� ������)
int Student::Get_Count()
{
	return Count;
}
//����� ��������� �������� ������, ��� ����������� �� ���������
const int* Student::Get_Grades() const
{
	return Grades; //���� ������ ���, �������� nullptr
}
//����� ��������� �������� �������� ����� ��������
float Student::Get_GPA() const
{
	return GPA;
}
//����� ������ ������ � �������� �� �����
void Student::Show() const
{
	//������ ������� ��������� �� �����
	int OCP = GetConsoleOutputCP();
	//���� ������� ��������� �� ��������, ������ �� ������
	if (OCP != 1251) SetConsoleOutputCP(1251);
	//������ � �������

	cout << "������������� ��������: " << ID << endl;
	cout << "���: " << Last_Name << " " << Name << " " << Middle_Name << endl;
	if (!Count_Grades || !Grades)cout << "������ ���!" << endl;
	else
	{
		cout << "������: ";
		for (int i = 0; i < Count_Grades; i++)
			cout << Grades[i] << " ";

		cout << "\n������� ����: " << GPA << endl;
	}

	//���� ������ ���������, ���������� �������
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}
//����� ������ ������� � ������������� ������ � ����
void Student::Save(string Path, bool Mode)
{
	fstream Stream; //��������������� �������� �����
	//����� ���������� ��� ������������
	if (Mode)Stream.open(Path, ios::app, ios::binary); //����������
	else Stream.open(Path, ios::out, ios::binary);  //������������
	if (!Stream.is_open())
	{
		cerr << "������ �������� �����!" << endl;
		return;
	}
	cout << "���� ������� ������!" << endl;
	//���������� � ���� ������ ������ ������ string
	Stream << Last_Name.size();
	Stream.write(Last_Name.c_str(), Last_Name.size()); //���������� ������ �� string � ����

	//���������� � ���� ������ ������ ������ string
	Stream << Name.size();
	Stream.write(Name.c_str(), Name.size()); //���������� ������ �� string � ����

	//���������� � ���� ������ ������ ������ string
	Stream << Middle_Name.size();
	Stream.write(Middle_Name.c_str(), Middle_Name.size()); //���������� ������ �� string � ����
	//������ ������� ������
	Stream << Count_Grades;
	Stream.write((char*)Grades, Count_Grades * sizeof(int));
	Stream << GPA;
	Stream.close();
	cout << "���� ������� �������!" << endl;
}

//����� ����������� ������� � ������������� ������ �� �����
void Student::Load(string Path)
{
	fstream Stream; //��������������� �������� �����
	Stream.open(Path, ios::in, ios::binary); //��������� �� ������ � �������� ������
	if (!Stream.is_open())
	{
		cerr << "������ �������� �����!" << endl;
		return;
	}
	cout << "���� ������� ������!" << endl;
	Last_Name.clear(); //������� ������    
	Name.clear(); //������� ������ 
	Middle_Name.clear(); //������� ������ 
	if (Grades) //���� ���� ������ �� ����� �������
	{
		delete[] Grades;
		Grades = nullptr;
		Count_Grades = 0;
		GPA = 0;
	}

	int Size = 0; //��� ���������� ��������
	Stream >> Size; //��������� ������ ������
	char* Buffer1 = new char[Size + 1] {}; //����� ��� ���������� ������
	Stream.read(Buffer1, Size);   //��������� ������ 
	Last_Name = Buffer1; //��������� ������  
	delete[] Buffer1;
	Buffer1 = nullptr;

	Stream >> Size; //��������� ������ ������
	char* Buffer2 = new char[Size + 1] {}; //����� ��� ���������� ������
	Stream.read(Buffer2, Size); //��������� ������ 
	Name = Buffer2; //��������� ������ 
	delete[] Buffer2;
	Buffer2 = nullptr;

	Stream >> Size; //��������� ������ ������
	char* Buffer3 = new char[Size + 1] {}; //����� ��� ���������� ������
	Stream.read(Buffer3, Size);  //��������� ������ 
	Middle_Name = Buffer3; //��������� ������ 
	delete[] Buffer3;
	Buffer3 = nullptr;

	Stream >> Size; //��������� ������ ������� ������
	if (Size == 0)
	{
		//�����, ���� ��� ������
		Stream.close();
		return;
	}
	Count_Grades = Size; //��������� ���-�� ������
	Grades = new int[Count_Grades] {}; //�������� ������ ��� ������ ������
	Stream.read((char*)Grades, Count_Grades * sizeof(int)); //��������� ������ � ������, ��� ��������� ������ ������
	Stream >> GPA;
	Stream.close();
	cout << "���� ������� ������!" << endl;
}
//��� ���������� ���������� ���������
long Student::Load(fstream& Stream)
{
	if (!Stream.is_open())
	{
		cerr << "������ �������� �����!" << endl;
		return 0;
	}
	cout << "���� ������� ������!" << endl;
	Last_Name.clear(); //������� ������     
	Name.clear(); //������� ������ 
	Middle_Name.clear(); //������� ������ 
	if (Grades) //���� ���� ������ �� ����� �������
	{
		delete[] Grades;
		Grades = nullptr;
		Count_Grades = 0;
		GPA = 0;
	}
	int Size = 0; //��� ���������� ��������

	Stream >> Size; //��������� ������ ������
	char* Buffer1 = new char[Size + 1] {}; //����� ��� ���������� ������
	Stream.read(Buffer1, Size);   //��������� ������ 
	Last_Name = Buffer1; //��������� ������ 
	delete[] Buffer1;
	Buffer1 = nullptr;

	Stream >> Size; //��������� ������ ������
	char* Buffer2 = new char[Size + 1] {}; //����� ��� ���������� ������
	Stream.read(Buffer2, Size);   //��������� ������ 
	Name = Buffer2; //��������� ������ 
	delete[] Buffer2;
	Buffer2 = nullptr;

	Stream >> Size; //��������� ������ ������
	char* Buffer3 = new char[Size + 1] {}; //����� ��� ���������� ������
	Stream.read(Buffer3, Size);   //��������� ������ 
	Middle_Name = Buffer3; //��������� ������ 
	delete[] Buffer3;
	Buffer3 = nullptr;

	Stream >> Size; //��������� ������ ������� ������
	if (Size == 0)
	{
		//�����, ���� ��� ������

		return Stream.tellg(); //���������� ��������� ������� � �����
	}
	Count_Grades = Size; //��������� ���-�� ������
	Grades = new int[Count_Grades] {}; //�������� ������ ��� ������ ������
	Stream.read((char*)Grades, Count_Grades * sizeof(int)); //��������� ������ � ������, ��� ��������� ������ ������
	Stream >> GPA;
	cout << "���� ������� ������!" << endl;

	return Stream.tellg(); //���������� ��������� ������� � �����
}