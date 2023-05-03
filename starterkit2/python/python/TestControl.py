# coding=utf-8

class TestControl :

    # public
    def Start(self) :
        self.Goto(self.S_START)
        return
    
    def IsEnd(self) :
        return self.CheckState(self.S_END)

    # Manager
    m_curfunc  = None
    m_nextfunc = None

    m_noWait = False

    def Update(self) :
        while(True) :
            bFirst = False
            self.m_noWait = False
            if self.m_nextfunc != None :
                self.m_curfunc = self.m_nextfunc
                self.m_nextfunc = None
                bFirst = True
                #print("start of " + self.m_curfunc.__name__)

            if self.m_curfunc != None :
                self.m_curfunc(bFirst)
            
            if self.m_noWait == False :
                return

    def Goto(self,st) :
        self.m_nextfunc = st
        return

    def CheckState(self, st) :
        return self.m_curfunc == st

    def HasNextState(self) :
        return self.m_nextfunc != None

    def NoWait(self) :
        self.m_noWait = True

    #gosub
    MAX_CALL_STACK = 10
    #              1    2    3    4    5    6    7    8    9    10
    m_callstack = [None,None,None,None,None,None,None,None,None,None]
    m_callstack_level = 0 
    def GoSubState(self,sub,nex) :
        if self.m_callstack_level >= self.MAX_CALL_STACK :
            print("CALL STACK OVER FLOW")
            exit()
        self.m_callstack[self.m_callstack_level] = nex
        self.m_callstack_level = self.m_callstack_level + 1
        self.Goto(sub)

    def ReturnState(self) :
        if self.m_callstack_level <= 0 :
            print("CALL STACK UNDER FLOW")
            exit()
        self.m_callstack_level = self.m_callstack_level - 1
        st = self.m_callstack[self.m_callstack_level]
        self.Goto(st) 

    # [SYN-G-GEN OUTPUT START] indent(4) $/./$
    #             psggConverterLib.dll converted from psgg-file:TestControl.psgg

    #    S_0000
    #
    def S_0000(self,bFirst) :
        if (bFirst) :
            print("Hello World.")
        if self.HasNextState()==False :
            self.Goto(self.S_RET000)
        return
    #    S_0001
    #
    def S_0001(self,bFirst) :
        if (bFirst) :
            print("Loop count." + str(self.m_i) )
        if self.HasNextState()==False :
            self.Goto(self.S_RET001)
        return
    #    S_END
    #
    def S_END(self, bFirst) :
        # nothing to do
        return
    #    S_GSB000
    #
    def S_GSB000(self, bFirst) :
        self.GoSubState(self.S_SBS000,self.S_LOP000)
        self.NoWait()
        return
    #    S_LOP000
    #
    m_i = 0
    def S_LOP000(self, bFirst) :
        self.m_i = 0
        self.Goto(self.S_LOP000_LoopCheckAndGosub____)
        self.NoWait()
        return
    def S_LOP000_LoopCheckAndGosub____(self, bFirst) :
        if  self.m_i < 10 :
            self.GoSubState(self.S_SBS001,self.S_LOP000_LoopNext____)
        else :
            self.Goto(self.S_END)
        self.NoWait()
        return
    def S_LOP000_LoopNext____(self, bFirst) :
        self.m_i = self.m_i + 1
        self.Goto(self.S_LOP000_LoopCheckAndGosub____)
        self.NoWait()
        return
    #    S_RET000
    #
    def S_RET000(self, bFirst) :
        self.ReturnState()
        self.NoWait()
        return
    #    S_RET001
    #
    def S_RET001(self, bFirst) :
        self.ReturnState()
        self.NoWait()
        return
    #    S_SBS000
    #
    def S_SBS000(self,bFirst) :
        if self.HasNextState()==False :
            self.Goto(self.S_0000)
        return
    #    S_SBS001
    #
    def S_SBS001(self,bFirst) :
        if self.HasNextState()==False :
            self.Goto(self.S_0001)
        return
    #    S_START
    #
    def S_START(self, bFirst) :
        self.Goto(self.S_GSB000)
        self.NoWait()
        return


    # [SYN-G-GEN OUTPUT END]

    #m_bYesNo = False
    #def br_YES(self,st) :
    #    if self.HasNextState()==False :
    #        if self.m_bYesNo==True :
    #            self.Goto(st)
    #    return

    #def br_NO(self,st) :
    #    if self.HasNextState()==False :
    #        if self.m_bYesNo==False :
    #            self.Goto(st)

