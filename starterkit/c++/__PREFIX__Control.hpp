#pragma once
#include <cstdio>
#include <string>
using namespace std;

class __PREFIX__Control 
{
    //region manager 
private:
    string m_curstate;
    string m_nextstate;
    string m_tempstate;
    bool   m_bNoWait;

    void update() {
        while(true) {
            bool bFirst;
            m_bNoWait = false;
            if (m_nextstate.size()!=0) {
                m_curstate = m_nextstate;
                m_nextstate.clear();
                bFirst = true;
            }
            if (m_curstate.size()!=0) {
                execute_state(m_curstate, bFirst);
            }
            if (!m_bNoWait) break;
        }
    }
    void Goto(const char* st)        { m_nextstate = st;                                 }
    bool CheckState(const char *st)  { return m_curstate == st;                          }
    void SetNextState(const char *st){ m_tempstate = st;                                 }
    bool HasNextState()              { return m_tempstate.size()!=0;                     }
    void GoNextState()               { m_nextstate = m_tempstate; m_tempstate.clear();   }
    void NoWait()                    { m_bNoWait = true;                                 }
    //endregion manager

    //  Embed codes                              [SYN-G-GEN OUTPUT START] indent(4) $/^E_/$
    //                                           [SYN-G-GEN OUTPUT END]

    //  states                                   [SYN-G-GEN OUTPUT START] indent(4) $/^S_/$
    void S_START(bool bFirst) { Goto("S_END");  }
    void S_END(bool bFirst)   { }
    //                                           [SYN-G-GEN OUTPUT END]
 
	void execute_state(string &st, bool bFirst)
    {
        //                                       [SYN-G-GEN OUTPUT START] indent(8) $/^S_/->#execute_state$
        if (st == "S_START") { S_START(bFirst); return; }
        if (st == "S_END")   { S_END(bFirst);   return; }
        //                                       [SYN-G-GEN OUTPUT END]
    }

    // write your code here!
    bool m_bYesNo;
    void br_YES(const char *st)
    {
        if (!HasNextState())
        {
            if (m_bYesNo)
            {
                SetNextState(st);
            }
        }
    }
    void br_NO(const char *st)
    {
        if (!HasNextState())
        {
            if (!m_bYesNo)
            {
                SetNextState(st);
            }
        }
    }
public:
    void Start()  { Goto("S_START");            }
    bool IsEnd()  { return CheckState("S_END"); }
    void Update() { update();                   }
};