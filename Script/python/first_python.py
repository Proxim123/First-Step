#!/usr/bin/python3

#import libraries
import math
print('pi: ' + repr(math.pi))

#Notes 9/2=4.5, 9//2=4

myint = 8

print ("Hello" + " World")
print ('Hi' + ' Pete, ' + repr(myint) + ' ' + "is the chinese favorite number")
print (5 + 15)

print (type(int(50) + int('10')))
print (type("hello"))
print (type('hello'))

total=90

x,y,z = total, 30, "Pete"

print (z,', the total value is: ', x, y, 'is the number of students')

del x, y, z

my_name = input('what is your name?\n')
print('My name is: ' + my_name)

print('Let\' add two numbers')
a = input('first number:')
b = input('second number:')

print('The sum is: ' + repr(int(a) + int(b)))

#format output
name1='Pierre'
name2='Roolmich'
num1=52
num2=42
bin1=9

print(name1, name2, sep=' <---> ')
print('%s,%10s,%5d,%d' % (name1, name2, num1, num2))
print('{1} {0}' .format(num1, num2))

if (name1 == name2):
    print('Same name')
elif (name1 != name2):
    print('The two names are different')

if (num1 > num2):
    print('num1 is greater than num2')
elif (num == num2):
    print('num1 is equal to num2')
else:
    print('num1 is less than num2')

print(bin(bin1))

#while-loop
