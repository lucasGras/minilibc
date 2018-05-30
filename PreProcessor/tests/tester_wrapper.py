# content of test_sample.py

from sys import argv
from class_tester import *

def wrapper(stream, m_Tester):
    inc = 0
    list = m_Tester.GetListDebug()
    flist = m_Tester.GetFuncList()
    for line in stream:
        m_Tester.SetStream(line)
        print("Test running: " + flist[inc] + " ", end="")
        m_Tester.DoTest(list[inc])
        inc += 1

def main(argv):
    stream = open(argv[1], 'r')
    m_Tester = Tester(stream.readline())
    wrapper(stream, m_Tester)
    stream.close()
    return m_Tester.debug_status

if (len(argv) == 2):
    main(argv)
