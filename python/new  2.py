# for����α���룺
for item in container:
	// do something
[else:]
	// do something

# ���������1��10
for i in range(1, 11):
	print(i, end = ' ')
else:
	print("Finished.")

# �����
# 1 2 3 4 5 6 7 8 9 10 
# Finished.
	
# ����1+2+...+10�ĺ�
numbers = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
sum = 0
for num in numbers:
	sum += num
else:
	print(sum)
	
# �����
# 55


# ������ͬ���ȵ�bitstring���а�λ�ڲ���
def AND(strA, strB):
    result = ''
    n = len(strA)
    for i in range(0, n):
        if(strA[i] == '1' and strB[i] == '1'):
            result += '1'
        else:
            result += '0'
    return result


# Test data
a = '0101101'
b = '1111111'
c = AND(a, b)
print(c)

# �����
# 0101101


# ���������listԪ�ؼ�������
mylist = [1, 1.0, 1.0j, '1', (1,), [1]]
for item in mylist:
    print (item, "\t", type(item))

# �����
# 1       <type 'int'>
# 1.0     <type 'float'>
# 1j      <type 'complex'>
# 1       <type 'str'>
# (1,)    <type 'tuple'>
# [1]     <type 'list'>

# ��ӡ�žų˷���
for row in range(1, 10):
    for col in range(1, 10):
        print((row * col),'\t', end='')
    print()
# ͬʱ�����±��Ԫ��
string = 'python'
print(string)
for index, item in enumerate(string):
    print('No.{0} item is {1}'.format(index, item))
	
# �����
# python
# No.0 item is p
# No.1 item is y
# No.2 item is t
# No.3 item is h
# No.4 item is o
# No.5 item is n


names = ['Python', 'Perl', 'Java', 'Lisp']
ages = [3, 6, 1, 8]

for name, age in zip(names, ages):
    print("{0} is {1} years old.".format(name, age))
	
# ���
# Python is 3 years old.
# Perl is 6 years old.
# Java is 1 years old.
# Lisp is 8 years old.

dic = {'Python':3, 'Perl':6, 'Java':1, 'Lisp':8}
for name in dic:
    print("{0} is {1} years old.".format(name, dic[name]))
	
# ���
# Python is 3 years old.
# Perl is 6 years old.
# Java is 1 years old.
# Lisp is 8 years old.

