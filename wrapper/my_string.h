using namespace std;

class MyString {
private:
    char* my_string;
    int longitude;
    int amount_of_memory;

    MyString CreateAndAppEnd(const char* something);

    void Resize(int new_size);

    void Replace(const char* something);

    int Compare(const char* something);

    void init();

public:
    MyString();
    MyString(const char* something);
    MyString(string something);
    MyString(const char* something, int size);
    MyString(int count, char symbol);
    MyString(const MyString& something);
    ~MyString();
    int size();
    int capacity();
    int length();
    int empty();
    void shrink_to_fit();
    void clear();
    friend ostream& operator<<(ostream& out, const MyString& something);
    friend istream& operator>>(istream& is, MyString& something);
    void operator =(const char* something);
    void operator =(string something);
    void operator =(char something);
    char* data();
    MyString operator =(const MyString& something);
    MyString operator +(const MyString& something);
    MyString operator +(const char* something);
    MyString operator +(string something);
    void operator +=(const char* something);
    void operator +=(string something);
    void operator +=(const MyString& something);

    char operator[] (const int index);

    bool operator>(const  MyString& something);
    bool operator<(const  MyString& something);
    bool operator>=(const  MyString& something);
    bool operator<=(const  MyString& something);
    bool operator!=(const  MyString& something);
    bool operator==(const  MyString& something);
    const char* c_str(void);
    void insert(int index, const char* something, int count);
    void insert(int index, int count, char symbol);
    void insert(int index, const char* something);
    void insert(int index, string something);
    void insert(int index, string something, int count);
    void append(const char* something);
    void append(int count, char something);
    void append(const char* something, int index, int count);
    void append(string somestring);
    void append(string somestring, int index, int amount);
    void replace(int index, int count, string something);
    void erase(int index, int count);
    int find(string something, int start);
    int find(string something);
    MyString substr(int index);
    MyString substr(int start, int end);
};

