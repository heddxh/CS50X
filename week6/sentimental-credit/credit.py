from cs50 import get_string

def main():
    len = 0

def get_card():
    while True:
        card = get_string('Number: ')
        if card.isdigit():
            len = len(card)
            return card

def check_sum(card):
    len = len(card)
    for i in range(len-2, 0, -2):
        sum += card[i] * 2
    for i in range(len-1, 0, -2):
        sum += card[i]
    if sum[-1] == '0':
        return True
    else:
        return False

def check_len(card):
    if len == 15:
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
    start2 = card[0:]