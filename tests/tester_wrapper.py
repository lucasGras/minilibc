# content of tester_wrapper.py

from sys import argv
from class_tester import *

def wrapper(stream, m_Tester):
    inc = 0
    list = m_Tester.content.listDebug
    flist = m_Tester.content.funcList
    for line in stream:
        m_Tester.SetStream(line)
        print("-- Test running: " + flist[inc] + " ", end="")
        m_Tester.DoTest(list[inc])
        inc += 1

def main(argv):
    lib_out = argv[1]
    list_debug = argv[2]
    func_list = argv[3]

    stream = open(argv[1], 'r')
    m_Tester = Tester(stream.readline(), list_debug, func_list)
    wrapper(stream, m_Tester)
    stream.close()
    return m_Tester.debug_status

if (len(argv) == 4):
    main(argv)
