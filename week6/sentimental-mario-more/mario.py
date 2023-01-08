from cs50 import get_int

while True:
    n = get_int(Height: )
    if 0 < n < 9:
        break
    else:
        print('Please type a int between 1 and 8')

for col in range(n):
    for raw in range(n):
        print("#", end='')