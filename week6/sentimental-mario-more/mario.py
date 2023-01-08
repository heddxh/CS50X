from cs50 import get_int

while True:
    n = get_int('Height: ')
    if 0 < n < 9:
        break
    else:
        print('Please type a int between 1 and 8')

for row in range(n):
    print(' '*(n - row - 1), end='')
    print('#'*(row + 1), end='')
    print('  ', end='')
    print('#'*(row+1))