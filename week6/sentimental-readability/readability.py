from cs50 import get_string


def main():
    text = get_string('Text:')
    words = text.split()
    count_word = len(words)

    for i in range(count_word):
        count_letters += len(words[i])

    
