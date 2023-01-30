#pragma 

void Menu();

class String
{
	char* m_Str;                                 // поле данный
	int m_Size;                                  // поле количество символов

	void StrCopy(const char* in, int size);      // операция копи данный
public:
	String();                                    // конструктор
	String(const char* str);                     // конструктор по константной строке (const char*)
	String(const String& other);                 // конструктор копирования
	~String();                                   // деструктор
	
	int getSize() const;                         // метод получит значение поля m_Size
	const char* c_str();                         // метод получит значение поля m_Str

	String& operator=(const String& other);      // операция присваивания

	operator const char* ();                     // операция преобразование в тип const char*

	String& operator+=(const String& other);     // опрация конкатенация строк

	String& operator-=(const String& other);     // операция удаление подстрок

	friend std::ostream& operator<<(std::ostream& os, const String& s); // операция вывода на консоль структур данных

	friend int Compare(const String& str1, const String& str2);    // операция сравнение строк
	friend bool operator<(const String& str1, const String& str2);
	friend bool operator==(const String& str1, const String& str2);
	friend bool operator>(const String& str1, const String& str2);

	bool Find(const String& source, int& index);                   // операция нахождение подстроки
};