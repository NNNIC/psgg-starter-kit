#pragma once
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;

class TestControl 
{
    //region manager 
private:
    string m_curstate;
    string m_nextstate;
    bool   m_bNoWait;
    
    static const int CALL_STACK_MAX = 10;
    const char* m_callstack[CALL_STACK_MAX];
    int m_callstack_level = 0;

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
    bool HasNextState()              { return m_nextstate.size()!=0;                     }
    void NoWait()                    { m_bNoWait = true;                                 }
    void GoSubState(const char *sb, const char *nt)
    {
        if (m_callstack_level >= CALL_STACK_MAX - 1)
        {
            printf("CALL STACK OVER FLOW\n");
            exit(1);
        }
        m_callstack[m_callstack_level++] = nt;
        Goto(sb);
    }
    void ReturnState()
    {
        if (m_callstack_level <= 0)
        {
            printf("CALL STACK UNDER FLOW\n");
        }
        m_callstack_level--;
        const char *st = m_callstack[m_callstack_level];
        Goto(st);
    }
    //endregion manager

    //  Embed codes                              [SYN-G-GEN OUTPUT START] indent(4) $/^E_/$
//  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg


    //                                           [SYN-G-GEN OUTPUT END]

    //  states                                   [SYN-G-GEN OUTPUT START] indent(4) $/^S_/$
//  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
    /*
        S_0001
    */
    void S_0001(bool bFirst)
    {
        if (bFirst)
        {
            printf("A state-machine is running\n");
        }
        if (!HasNextState())
        {
            Goto("S_GOSUB");
        }
    }
    /*
        S_END
    */
    void S_END(bool bFirst)
    {
    }
    /*
        S_EVEN_OR_ODD
    */
    void S_EVEN_OR_ODD(bool bFirst)
    {
        if (m_i % 2 == 0) { Goto( "S_PRINT_EVEN" ); }
        else { Goto( "S_PRINT_ODD" ); }
    }
    /*
        S_GOSUB
    */
    void S_GOSUB(bool bFirst)
    {
        GoSubState("S_SUBSTART1","S_LOOP");
        NoWait();
    }
    /*
        S_LOOP
    */
    int m_i;
    void S_LOOP(bool bFirst)
    {
        m_i=0;
        Goto("S_LOOP_LoopCheckAndGosub____");
        NoWait();
    }
    void S_LOOP_LoopCheckAndGosub____(bool bFirst)
    {
        if (m_i < 10) GoSubState("S_SUBSTART","S_LOOP_LoopNext____");
        else               Goto("S_END");
        NoWait();
    }
    void S_LOOP_LoopNext____(bool bFirst)
    {
        m_i++;
        Goto("S_LOOP_LoopCheckAndGosub____");
        NoWait();
    }
    /*
        S_PRINT_EVEN
    */
    void S_PRINT_EVEN(bool bFirst)
    {
        if (bFirst)
        {
            printf("Count : %d (EVEN)\n",m_i);
        }
        if (!HasNextState())
        {
            Goto("S_SUBRETURN");
        }
    }
    /*
        S_PRINT_ODD
    */
    void S_PRINT_ODD(bool bFirst)
    {
        if (bFirst)
        {
            printf("Count : %d (ODD)\n",m_i);
        }
        if (!HasNextState())
        {
            Goto("S_SUBRETURN");
        }
    }
    /*
        S_START
    */
    void S_START(bool bFirst)
    {
        if (!HasNextState())
        {
            Goto("S_0001");
        }
    }
    /*
        S_SUBRETURN
    */
    void S_SUBRETURN(bool bFirst)
    {
        ReturnState();
        NoWait();
    }
    /*
        S_SUBRETURN1
    */
    void S_SUBRETURN1(bool bFirst)
    {
        ReturnState();
        NoWait();
    }
    /*
        S_SUBSTART
    */
    void S_SUBSTART(bool bFirst)
    {
        Goto("S_EVEN_OR_ODD");
        NoWait();
    }
    /*
        S_SUBSTART1
    */
    void S_SUBSTART1(bool bFirst)
    {
        Goto("S_WORK");
        NoWait();
    }
    /*
        S_WORK
    */
    void S_WORK(bool bFirst)
    {
        if (bFirst)
        {
            printf("A subroutine is running.\n");
        }
        if (!HasNextState())
        {
            Goto("S_SUBRETURN1");
        }
    }


    //                                           [SYN-G-GEN OUTPUT END]
 
	void execute_state(string &st, bool bFirst)
    {
        //                                       [SYN-G-GEN OUTPUT START] indent(8) $/^S_/->#execute_state$
//  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
        if (st == "S_0001") { S_0001(bFirst); return; }
        if (st == "S_END") { S_END(bFirst); return; }
        if (st == "S_EVEN_OR_ODD") { S_EVEN_OR_ODD(bFirst); return; }
        if (st == "S_GOSUB") { S_GOSUB(bFirst); return; }
        if (st == "S_LOOP") { S_LOOP(bFirst); return; }
        if (st == "S_LOOP_LoopCheckAndGosub____") { S_LOOP_LoopCheckAndGosub____(bFirst); return; }
        if (st == "S_LOOP_LoopNext____")          { S_LOOP_LoopNext____(bFirst); return; }
        if (st == "S_PRINT_EVEN") { S_PRINT_EVEN(bFirst); return; }
        if (st == "S_PRINT_ODD") { S_PRINT_ODD(bFirst); return; }
        if (st == "S_START") { S_START(bFirst); return; }
        if (st == "S_SUBRETURN") { S_SUBRETURN(bFirst); return; }
        if (st == "S_SUBRETURN1") { S_SUBRETURN1(bFirst); return; }
        if (st == "S_SUBSTART") { S_SUBSTART(bFirst); return; }
        if (st == "S_SUBSTART1") { S_SUBSTART1(bFirst); return; }
        if (st == "S_WORK") { S_WORK(bFirst); return; }


        //                                       [SYN-G-GEN OUTPUT END]
    }

    // write your code here!

public:
    void Start()  { Goto("S_START");            }
    bool IsEnd()  { return CheckState("S_END"); }
    void Update() { update();                   }
};