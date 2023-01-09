from cs50 import get_string

def main():
    card = get_card()
    if check_sum(card) == False:
        print('INVALID')
    else:
        len_result = check_len(card)
        if len_result == 'amex':
            print('AMEX')
        elif len_result == 'visa':
            print('VISA')
        elif len_result == 'mast':
            print('MASTERCARD')
        else:
            print('INVALID')

def get_card():
    while True:
        card = get_string('Number: ')
        if card.isdigit():
            return card

def check_sum(card):
    sum = 0
    length = len(card)
    for i in range(length-2, 0, -2):
        temp = int(card[i]) * 2
        if temp > 9:
            sum += temp % 10 + temp // 10
        else:
            sum += temp
    if length % 2 == 0:
        temp = int(card[0]) * 2
        if temp > 9:
            sum += temp % 10 + temp // 10
        else:
            sum += temp
    for i in range(length-1, 0, -2):
        sum += int(card[i])
    if sum % 10 == 0:
        return True
    else:
        return False

def check_len(card):
    length = len(card)
    if length == 15:
        if is_amex(card):
            return 'amex'
        else:
            return 'invalid'
    elif length == 13:
        if is_visa(card):
            return 'visa'
        else:
            return 'invalid'
    elif length == 16:
        if is_visa(card):
            return 'visa'
        elif is_mast(card):
            return 'mast'
        else:
            return 'invalid'

def is_amex(card):
    start2 = card[0:2]
    if start2 in ['34', '37']:
        return True
    else:
        return False

def is_visa(card):
    start = int(card[0])
    if start == 4:
        return True
    else:
        return False

def is_mast(card):
    if int(card[0]) == 5 and card[1] in '12345':
        return True
    else:
        return False

main()