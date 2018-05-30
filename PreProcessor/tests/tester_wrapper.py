# content of test_sample.py

from sys import argv

DEBUG_SUCCESS=(1)
DEBUG_FAILURE=(-1)

test_debug = lambda stream, expected: DEBUG_SUCCESS if (stream == expected) else DEBUG_FAILURE

def list_debug():
    list = ["t\n", "This is a test\n", "strlen=12\n", "strcpy=test strcpy\n", "is_duped\n"]
    return list

def func_list():
    list = ["putc", "putstr", "strlen", "strcpy", "strdup"]
    return list

def test(stream, expected):
    if (test_debug(stream, expected) == DEBUG_SUCCESS):
        print("[OK]")
    else:
        print("KO")

def main(argv):
    inc = 0
    stream = open(argv[1], 'r')
    stream.readline()
    list = list_debug()
    flist = func_list()
    for line in stream:
        print("Test running: " + flist[inc] + " ", end="")
        test(line, list[inc])
        inc += 1
    stream.close()
    return 0

if (len(argv) == 2):
    main(argv)
