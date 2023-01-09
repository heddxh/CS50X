from cs50 import get_string

def main():
    global card_len
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
            card_len = len(card)
            return card

def check_sum(card):
    for i in range(card_len-2, 0, -2):
        sum += card[i] * 2
    for i in range(card_len-1, 0, -2):
        sum += card[i]
    if sum[-1] == '0':
        return True
    else:
        return False

def check_len(card):
    if card_len == 15:
        if is_amex(card):
            return 'amex'
        else:
            return 'invalid'
    elif len == 13:
        if is_visa(card):
            return 'visa'
        else:
            return 'invalid'
    elif len == 16:
        if is_visa(card):
            return 'visa'
        elif is_mast(card):
            return 'mast'
        else:
            return 'invalid'

def is_amex(card):
    start2 = card[0:2]
    if start2 == 34 or start2 == 37:
        return True
    else:
        return False

def is_visa(card):
    start = card[0]
    if start == 4:
        return True
    else:
        return False

def is_mast(card):
    if card[0] == 5 and card[1] in ['1', '2', '3', '4', '5']:
        return True
    else:
        return False

main()