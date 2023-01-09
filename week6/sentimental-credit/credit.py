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
        is_amex(card)
    elif len == 13:
        is_visa(card)
    elif len == 16:
        if is_visa
