from my_string import *

a0 = MyString("0", 1000)
a1 = MyString("123456789")
a1.insert(3, "0000")
print(a1.data())
a0 = a1
print(type(a0))
a0 = "123"
print(type(a0))
