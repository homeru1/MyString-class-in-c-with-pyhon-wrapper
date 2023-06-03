#include <iostream>
#include "my_string.cpp"
using namespace std;

int main()
{
	{
		MyString a1;
		std::cout << a1 << " " << a1.size() << " " << a1.capacity() << std::endl;
		MyString a2("Hello world!");
		std::cout << a2 << " " << a2.size() << " " << a2.capacity() << std::endl;
		MyString a3({ 'h','e','l','l','o' });
		std::cout << a3 << " " << a3.size() << " " << a3.capacity() << std::endl;
		std::string s = "hello";
		MyString a4(s);
		std::cout << a4 << " " << a4.size() << " " << a4.capacity() << std::endl;
		MyString a5("hello", 4);
		std::cout << a5 << " " << a5.size() << " " << a5.capacity() << std::endl;
		MyString a6(5, '!');
		std::cout << a6 << " " << a6.size() << " " << a6.capacity() << std::endl;
		MyString a7("hello");
		MyString a8(a7);
		std::cout << a8 << " " << a8.size() << " " << a8.capacity() << std::endl;
	}
	{
		MyString a1("hel"), a2("lo"), a3;
		a3 = a1 + a2;
		std::cout << a1 << " " << a2 << " " << a3 << std::endl;
		MyString a4("hel"), a5;
		a5 = a4 + "lo";
		std::cout << a4 << " " << a5 << std::endl;
		MyString a6("hel"), a7;
		std::string s1 = "lo";
		a7 = a6 + s1;
		std::cout << a6 << " " << a7 << std::endl;

	}
	{
		MyString a1("hel"), a2("lo");
		a1 += a2;
		std::cout << a1 << " " << a2 << std::endl;
		MyString a3("hel");
		std::string s1 = "lo";
		a3 += s1;
		std::cout << a3 << std::endl;

	}
	{
		MyString a1;
		a1 = "hello";
		std::cout << a1 << std::endl;
		MyString a2;
		std::string s1 = "hello";
		a2 = s1;
		std::cout << a2 << std::endl;
		MyString a3;
		a3 = '!';
		std::cout << a3 << std::endl;
		MyString a4;
		a4 = "hello";
		std::cout << a4[2] << std::endl;
		MyString a, b;
		a = "abcd";
		b = "abce";
		std::cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b) << std::endl;

	}
	{
		MyString a1("Hello world!");
		std::string s1;
		s1 = a1.data();
		std::cout << s1 << std::endl;

	}
	{
		MyString a1("Hello world!");
		std::cout << a1.size() << std::endl;

	}
	{
		MyString a1("Hello world!"); //check
		std::cout << a1.empty() << std::endl;

	}
	{
		MyString a1("Hello world!");
		std::cout << a1.capacity() << std::endl;

	}
	{
		MyString a1("Hello world!"); // error
		a1.erase(5, 6);
		std::cout << a1 << " " << a1.size() << " " << a1.capacity() << std::endl;
		a1.shrink_to_fit();
		std::cout << a1 << " " << a1.size() << " " << a1.capacity() << std::endl;
	}
	{
		MyString a1("Hello world!");
		std::cout << a1 << std::endl;
		a1.clear();
		std::cout << a1 << std::endl;
	}
	{
		MyString a1("Hello world!");
		std::cout << a1 << std::endl;
	}
	{
		MyString a1 = "aaaaa";
		a1.insert(0, 1, '!');
		std::cout << a1 << std::endl;
		a1.insert(3, 2, '@');
		std::cout << a1 << std::endl;
		MyString a2 = "aaaaa";
		a2.insert(1, "@@@@@");
		std::cout << a2 << std::endl;
		MyString a3 = "aaaaa";
		a3.insert(1, "@@@@@", 2);
		std::cout << a3 << std::endl;
		MyString a4 = "aaaaa";
		std::string s1 = "@@@@@";
		a4.insert(1, s1);
		std::cout << a4 << std::endl;
		MyString a5 = "aaaaa";
		std::string s2 = "@@@@@";
		a5.insert(1, s2, 2);
		std::cout << a5 << std::endl;
	}
	{
		MyString a1("Hello world!");
		a1.erase(5, 6);
		std::cout << a1 << std::endl;
	}
	{
		MyString a1;
		a1.clear();
		a1.append(3, '!');
		std::cout << a1 << std::endl;
		a1.append(3, '@');
		std::cout << a1 << std::endl;
		MyString a2;
		a2.clear();
		a2.append("Hello ");
		std::cout << a2 << std::endl;
		a2.append("world");
		std::cout << a2 << std::endl;
		MyString a3;
		a3.clear();
		a3.append("Hello world", 0, 6);
		std::cout << a3 << std::endl;
		a3.append("Hello world", 6, 5);
		std::cout << a3 << std::endl;
		MyString a4;
		std::string s1 = "Hello ", s2 = "world";
		a4.clear();
		a4.append(s1);
		std::cout << a4 << std::endl;
		a4.append(s2);
		std::cout << a4 << std::endl;
		MyString a5;
		std::string s3 = "Hello world";
		a5.clear();
		a5.append(s3, 0, 6);
		std::cout << a5 << std::endl;
		a5.append(s3, 6, 5);
		std::cout << a5 << std::endl;
	}
	{
		MyString a1 = "hello amazing world";
		a1.replace(6, 7, "wonderful");
		std::cout << a1 << std::endl;
		MyString a2 = "hello amazing world";
		std::string s1 = "wonderful";
		a2.replace(6, 7, s1);
		std::cout << a2 << std::endl;
	}
	{
		MyString a1 = "hello amazing world", a2;
		a2 = a1.substr(6);
		std::cout << a2 << std::endl;
		MyString a3 = "hello amazing world", a4;
		a4 = a3.substr(6, 7);
		std::cout << a4 << std::endl;
	}
	{
		MyString a = "hello amazing world amazing";
		int i;
		i = a.find("amazing");
		std::cout << i << std::endl;
		a = "hello amazing world amazing";
		i = a.find("amazing", 7);
		std::cout << i << std::endl;
		a = "hello amazing world amazing";
		std::string s = "amazing";
		i = a.find(s);
		std::cout << i << std::endl;
		a = "hello amazing world amazing";
		s = "amazing";
		i = a.find(s, 7);
		std::cout << i << std::endl;

	}
	MyString a(1000, 'a');
	MyString a1 = "123456789";
	a1.insert(3, "0000", 3);
	a1 += "***";
	a = a1;
	cout << a.size() << " " << a.capacity() << " " << a<<endl;
	a.shrink_to_fit();
	cout << a.size() << " " << a.capacity() << " " << a;
}