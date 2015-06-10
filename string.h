class String
{

public :
	String();
        String(char *str);
		~String();
		String (const String &obj);
        int size();
		String &operator = (const String &obj);
        int capacity();// – метод, возвращающий емкость блока памяти;
    bool empty(); // – метод, возвращающий true, если строка пуста;
    void clear(); // – метод, удаляющий все символы из строки, то есть строка становится пустой;
    void push_back(char c); //– метод, добавляющий символ в конец строки;
    void pop_back(); // – метод, удаляющий символ из конца строки;
    void insert(int pos, const char *str); // – метод, вставляющий все символы строки str в текущую строку перед символом с индексом pos;
        void erase(int pos, int len = 1); //– метод, удаляющий из строки len символов, начиная с индекса pos.
        String operator + (String s);
        String operator += (String s);
        char operator [] (int n);
       
		
		String (const String &obj);
		String &operator =(const String &obj);
		private :
    char *my_str;
    int my_size;
	int my_capacity;
};
