#pragma once
#include <iostream>
#include "my_string.h"
#include <cstring>

MyString MyString::CreateAndAppEnd(const char* something) {
    MyString tmp(*this);
    tmp.append(something);
    return tmp;
}

void MyString::Resize(int new_size) {
    if (new_size + longitude < amount_of_memory) {
        longitude += new_size;
        return;
    }
    char* tmp = nullptr;
    if (my_string != nullptr || longitude != 0) {
        tmp = new char[longitude + 1];
        memcpy(tmp, my_string, longitude + 1);
        delete[] my_string;
    }
    longitude += new_size;
    amount_of_memory = longitude + 1;
    my_string = new char[amount_of_memory];
    memset(my_string, '\0', amount_of_memory);
    if (tmp != nullptr) {
        memcpy(my_string, tmp, strlen(tmp) + 1);
        delete[] tmp;
    }
}

void MyString::Replace(const char* something) {
    longitude = strlen(something);
    if (amount_of_memory < longitude) {
        if (my_string != nullptr) {
            delete[] my_string;
        }
        amount_of_memory = longitude + 1;
        my_string = new char[amount_of_memory];
    }
    snprintf(my_string, amount_of_memory, "%s", something);
}


int MyString::Compare(const char* something) { // 0 same 1 bigger -1  smaller
    int min = 0;
    if (longitude > strlen(something))min = strlen(something);
    else min = longitude;
    if (min == 0) return 0;
    for (int i = 0; i < min; i++) {
        if (my_string[i] != something[i]) {
            if ((int)(my_string[i]) > (int)something[i]) return 1;
            else return -1;
        }
    }
    if (longitude == min)return -1;
    return 1;
}
void MyString::init() {
    my_string = NULL;
    longitude = 0;
    amount_of_memory = 0;
}

MyString::MyString() {
    init();
}
MyString::MyString(const char* something) {
    init();
    Replace(something);
}
MyString::MyString(string something) {
    init();
    Replace(something.c_str());
}
MyString::MyString(const char* something, int size) {
    init();
    longitude = size;
    amount_of_memory = longitude + 1;
    my_string = new char[amount_of_memory];
    snprintf(my_string, amount_of_memory, "%s", something);
}
MyString::MyString(int count, char symbol) {
    init();
    longitude = count;
    amount_of_memory = longitude + 1;
    my_string = new char[amount_of_memory];
    my_string = (char*)memset(my_string, symbol, longitude);
    my_string[longitude] = '\0';
}
MyString::MyString(const MyString& something) {
    init();
    Replace(something.my_string);
}
MyString::~MyString() {
    if (my_string != nullptr) {
        delete[] my_string;
        my_string = nullptr;
    }
}
int MyString::size() {
    return(longitude);
}
int MyString::capacity() {
    return(amount_of_memory);
}
int MyString::length() {
    return(longitude);
}
int MyString::empty() {
    if (longitude > 0) {
        return 0;
    }
    return 1;
}
void MyString::shrink_to_fit() {
    if (amount_of_memory == longitude + 1) {
        return;
    }
    char* tmp = new char[longitude + 1];
    memcpy(tmp, my_string, longitude);
    tmp[longitude] = '\0';
    delete[] my_string;
    my_string = tmp;
    amount_of_memory = longitude + 1;
    return;
}
void MyString::clear() {
    if (my_string == nullptr) {
        longitude = 0;
        return;
    }
    delete[] my_string;
    my_string = NULL;
    longitude = 0;
}
std::ostream& operator<<(ostream& out, const MyString& something) {
    if (something.my_string != nullptr)out << something.my_string;
    return out;
}
std::istream& operator>>(istream& is, MyString& something) {
    int next;
    while ((next = is.get()) != is.eof() && !isspace(next)) {
        something.append(1, (const char)next);
    }
    return is;
}
void MyString::operator =(const char* something) {
    Replace(something);
}
void MyString::operator =(string something) {
    Replace(something.c_str());
}
void MyString::operator =(char something) {
    if (my_string != nullptr)delete[] my_string;
    longitude = 1;
    my_string = new char[2];
    my_string[0] = something;
    my_string[1] = '\0';
}
char* MyString::data() {
    return my_string;
}
MyString MyString::operator =(const MyString& something) {
    if (this == &something) return *this;
    Replace(something.my_string);
    return *this;
}
MyString MyString::operator +(const MyString& something) {
    return CreateAndAppEnd(something.my_string);
}
MyString MyString::operator +(const char* something) {
    return CreateAndAppEnd(something);
}
MyString MyString::operator +(string something) {
    return CreateAndAppEnd(something.c_str());
}
void MyString::operator +=(const char* something) {
    this->append(something);
}
void MyString::operator +=(string something) {
    this->append(something.c_str());
}
void MyString::operator +=(const MyString& something) {
    this->append(something.my_string);
}

char MyString::operator[] (const int index) {
    if (index >= 0 && index < this->longitude)return (this->my_string[index]);
    else if (index < 0 && index >= -(this->longitude)) return (this->my_string[this->longitude + index]);
    return '\0';
}

bool MyString::operator>(const  MyString& something) {
    int tmp = Compare(something.my_string);
    if (tmp == 1) {
        return 1;
    }
    return 0;
}
bool MyString::operator<(const  MyString& something) {
    int tmp = Compare(something.my_string);
    if (tmp == -1) {
        return 1;
    }
    return 0;
}
bool MyString::operator>=(const  MyString& something) {
    int tmp = Compare(something.my_string);
    if (tmp == 1 || tmp == 0) {
        return 1;
    }
    return 0;
}
bool MyString::operator<=(const  MyString& something) {
    int tmp = Compare(something.my_string);
    if (tmp == -1 || tmp == 0) {
        return 1;
    }
    return 0;
}
bool MyString::operator!=(const  MyString& something) {
    int tmp = Compare(something.my_string);
    if (tmp == -1 || tmp == 1) {
        return 1;
    }
    return 0;
}
bool MyString::operator==(const  MyString& something) {
    int tmp = Compare(something.my_string);
    if (tmp == 0) {
        return 1;
    }
    return 0;
}
const char* MyString::c_str(void) {
    return (const char*)my_string;
}
void MyString::insert(int index, const char* something, int count) {
    this->Resize(count);
    if (index != longitude - count) {
        memmove(&(my_string[index + count]), &(my_string[index]), longitude - index - count + 1);
    }
    memcpy(&my_string[index], something, count);
}
void MyString::insert(int index, int count, char symbol) {
    char* tmp = new char[count];
    memset(tmp, symbol, count * sizeof(char));
    this->insert(index, tmp, count);
    delete[] tmp;
}
void MyString::insert(int index, const char* something) {
    this->insert(index, something, strlen(something));
}
void MyString::insert(int index, string something) {
    this->insert(index, something.c_str(), something.length());
}
void MyString::insert(int index, string something, int count) {
    this->insert(index, something.c_str(), count);
}
void MyString::append(const char* something) {
    this->insert(longitude, something);
}
void MyString::append(int count, char something) {
    this->insert(longitude, count, something);
}
void MyString::append(const char* something, int index, int count) {
    this->insert(longitude, &something[index], count);
}
void MyString::append(string somestring) {
    this->append(somestring.c_str());
}
void MyString::append(string somestring, int index, int amount) {
    this->append(somestring.c_str(), index, amount);
}
void MyString::replace(int index, int count, string something) {
    this->erase(index, count);
    this->insert(index, something);
}
void MyString::erase(int index, int count) {
    if (count + index > longitude) count = longitude - index;
    memcpy(&my_string[index], &my_string[index + count], longitude - (count + index));
    memset(&my_string[longitude - count], '\0', count);
    longitude -= count;
}
int MyString::find(string something, int start) {
    int tmp = 0, max = strlen(something.c_str());
    for (int i = start; i < this->longitude; i++) {
        if (something[tmp] == my_string[i]) {
            tmp++;
        }
        else {
            tmp = 0;
        }
        if (tmp == max) {
            return i - max + 1;
        }
    }
    return 0;
}
int MyString::find(string something) {
    return this->find(something, 0);
}
MyString MyString::substr(int index) {
    MyString tmp(&my_string[index]);
    return tmp;
}
MyString MyString::substr(int start, int end) {
    MyString tmp = this->substr(start);
    if (tmp.length() - end > 0) {
        tmp.erase(end, tmp.length() - end);
    }
    return tmp;
}