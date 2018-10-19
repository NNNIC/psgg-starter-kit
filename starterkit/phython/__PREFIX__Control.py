# coding=utf-8

class __PREFIX__Control :

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

    # [SYN-G-GEN OUTPUT START] indent(4) $/./$
    def S_START(self,bFirst) :
        if (bFirst) :
            print("S_START")
            self.Goto(self.S_END)
        return


    def S_END(self,bFirst) :
        if (bFirst) :
            print("S_END")
        return    
    # [SYN-G-GEN OUTPUT END]

    m_bYesNo = False
    def br_YES(self,st) :
        if self.HasNextState()==False :
            if self.m_bYesNo==True :
                self.Goto(st)
        return

    def br_NO(self,st) :
        if self.HasNextState()==False :
            if self.m_bYesNo==False :
                self.Goto(st)

