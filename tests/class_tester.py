# content of class_tester.py

class TesterContent(object):

    def __init__(self, _file, _func):
        self.listDebug = []
        self.funcList = []
        self.SetListDebug(_file)
        self.SetListFunc(_func)

    def SetListDebug(self, _file):
        stream = open(_file, 'r')
        for line in stream:
            self.listDebug.append(line)

    def SetListFunc(self, _file):
        stream = open(_file, 'r')
        for line in stream:
            line = line[:-1]
            self.funcList.append(line)

class Tester(object):

    def __init__(self, _stream, _fileContent, _funcContent):
        self.content = TesterContent(_fileContent, _funcContent)
        self.debug_success = 0
        self.debug_failure = 1
        self.debug_status = self.debug_success
        self.stream = _stream

    def SetStream(self, _in):
        self.stream = _in

    def TestDebug(self, _exp):
        if (self.stream == _exp):
            return self.debug_success
        return self.debug_failure

    def DoTest(self, _exp):
        if (self.TestDebug(_exp) == self.debug_success):
            print("\033[32m[OK]\033[m")
        else:
            print("\033[31m[KO]\033[m Invalid output: " + _exp)
            self.debug_status = self.debug_failure
