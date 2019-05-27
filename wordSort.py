#!/bin/env python
# coding=UTF-8

################################################################################
# Get Word Len Dict
################################################################################

def get_word_len_dict(text):

    textList = text.split()
    wordLenDict = {}

    for word in textList:

        wordLen = len(word)

        if wordLen in wordLenDict:
            wordLenDict[wordLen].append(word)
        else:
            wordLenDict[wordLen] = [word]

    return wordLenDict


################################################################################
# Print Dict In Key Order
################################################################################

def print_dict_in_key_order(the_dict):

    for key in sorted(the_dict):
        print(key, ':', sorted(set(the_dict[key])))


################################################################################
# Main Program Define
################################################################################

def main():

    text = 'May your coffee be strong and your Monday be short'
    the_dict = get_word_len_dict(text)
    print_dict_in_key_order(the_dict)
    print()

    text = 'why does someone believe you when you say there are four billion stars but they have to check when you say the paint is wet'
    the_dict = get_word_len_dict(text)
    print_dict_in_key_order(the_dict)


if __name__ == '__main__':
    main()