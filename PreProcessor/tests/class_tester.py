# content of class_tester.py

class Tester(object):

    def __init__(self, _stream):
        self.debug_success = 0
        self.debug_failure = 1
        self.debug_status = self.debug_success
        self.stream = _stream

    def GetListDebug(self):
        list = ["t\n", "This is a test\n", "strlen=12\n", "strcpy=test strcpy\n",
                "is_duped\n", "This is a test\n", "a test\n", "0 1\n", "tset a si sihT\n"]
        return list

    def GetFuncList(self):
        list = ["putc", "putstr", "strlen", "strcpy", "strdup", "memstrcat", "index",
                "strcmp", "memrevstr"]
        return list

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
