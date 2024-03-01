#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <cstdlib>


using namespace std;



class Test1Control 
{
    //region manager 
private:
    
    typedef void (Test1Control::*FUNCPTR)(bool);

    FUNCPTR m_curstate = nullptr;
    FUNCPTR m_nextstate = nullptr;
    bool   m_bNoWait;
    
    static const int CALL_STACK_MAX = 10;
    FUNCPTR m_callstack[CALL_STACK_MAX];
    int m_callstack_level = 0;

    void update() {
        while(true) {
            bool bFirst =false;
            m_bNoWait = false;
            if (m_nextstate != nullptr) {
                m_curstate  = m_nextstate;
                m_nextstate = nullptr;
                bFirst = true;
            }
            if (m_curstate != nullptr) {
                (this->*m_curstate)(bFirst);
            }
            if (!m_bNoWait) break;
        }
    }
    void Goto(FUNCPTR st)        { m_nextstate = st;              }
    bool CheckState(FUNCPTR st)  { return m_curstate == st;       }
    bool HasNextState()          { return m_nextstate != nullptr; }
    void NoWait()                { m_bNoWait = true;              }
    void GoSubState(FUNCPTR sb, FUNCPTR nt)
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
        else {
            m_callstack_level--;
            FUNCPTR st = this->m_callstack[m_callstack_level];
            Goto(st);
        }
    }
    //endregion manager

    //  Embed codes                              [SYN-G-GEN OUTPUT START] indent(4) $/^E_/$
    //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                  // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [SYN-G-GEN OUTPUT END]

    //  states                                   [SYN-G-GEN OUTPUT START] indent(4) $/^S_/$
    //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                  // *DoNotEdit*
                                                                            // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_0001                                                              // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_0001(bool bFirst)                                                // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        if (bFirst)                                                         // *DoNotEdit*
        {                                                                   // *DoNotEdit*
            printf_s("A state-machine is running\n");                       // *DoNotEdit*
        }                                                                   // *DoNotEdit*
        if (!HasNextState())                                                // *DoNotEdit*
        {                                                                   // *DoNotEdit*
            Goto(&Test1Control::S_GOSUB);                                   // *DoNotEdit*
        }                                                                   // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_END                                                               // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_END(bool bFirst)                                                 // *DoNotEdit*
    {                                                                       // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_EVEN_OR_ODD                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_EVEN_OR_ODD(bool bFirst)                                         // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        if (m_i % 2 == 0) { Goto( &Test1Control::S_PRINT_EVEN ); }          // *DoNotEdit*
        else { Goto( &Test1Control::S_PRINT_ODD ); }                        // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_GOSUB                                                             // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_GOSUB(bool bFirst)                                               // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        GoSubState(&Test1Control::S_SUBSTART1,&Test1Control::S_LOOP);       // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_LOOP                                                              // *DoNotEdit*
        Loop 10 times                                                       // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    int m_i;                                                                // *DoNotEdit*
    void S_LOOP(bool bFirst)                                                // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        m_i=0;                                                              // *DoNotEdit*
        Goto(&Test1Control::S_LOOP_LoopCheckAndGosub____);                  // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    void S_LOOP_LoopCheckAndGosub____(bool bFirst)                          // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        if (m_i < 10) GoSubState(&Test1Control::S_SUBSTART,&Test1Control::S_LOOP_LoopNext____);                     // *DoNotEdit*
        else               Goto(&Test1Control::S_END);                      // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    void S_LOOP_LoopNext____(bool bFirst)                                   // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        m_i++;                                                              // *DoNotEdit*
        Goto(&Test1Control::S_LOOP_LoopCheckAndGosub____);                  // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_PRINT_EVEN                                                        // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_PRINT_EVEN(bool bFirst)                                          // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        if (bFirst)                                                         // *DoNotEdit*
        {                                                                   // *DoNotEdit*
            printf_s("Count : %d (EVEN)\n",m_i);                            // *DoNotEdit*
        }                                                                   // *DoNotEdit*
        if (!HasNextState())                                                // *DoNotEdit*
        {                                                                   // *DoNotEdit*
            Goto(&Test1Control::S_SUBRETURN);                               // *DoNotEdit*
        }                                                                   // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_PRINT_ODD                                                         // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_PRINT_ODD(bool bFirst)                                           // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        if (bFirst)                                                         // *DoNotEdit*
        {                                                                   // *DoNotEdit*
            printf_s("Count : %d (ODD)\n",m_i);                             // *DoNotEdit*
        }                                                                   // *DoNotEdit*
        if (!HasNextState())                                                // *DoNotEdit*
        {                                                                   // *DoNotEdit*
            Goto(&Test1Control::S_SUBRETURN);                               // *DoNotEdit*
        }                                                                   // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_START                                                             // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_START(bool bFirst)                                               // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&Test1Control::S_0001);                                        // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_SUBRETURN                                                         // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_SUBRETURN(bool bFirst)                                           // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        ReturnState();                                                      // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_SUBRETURN1                                                        // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_SUBRETURN1(bool bFirst)                                          // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        ReturnState();                                                      // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_SUBSTART                                                          // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_SUBSTART(bool bFirst)                                            // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&Test1Control::S_EVEN_OR_ODD);                                 // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_SUBSTART1                                                         // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_SUBSTART1(bool bFirst)                                           // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&Test1Control::S_WORK);                                        // *DoNotEdit*
        NoWait();                                                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    /*                                                                      // *DoNotEdit*
        S_WORK                                                              // *DoNotEdit*
    */                                                                      // *DoNotEdit*
    void S_WORK(bool bFirst)                                                // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        if (bFirst)                                                         // *DoNotEdit*
        {                                                                   // *DoNotEdit*
            printf_s("A subroutine is running.\n");                         // *DoNotEdit*
        }                                                                   // *DoNotEdit*
        if (!HasNextState())                                                // *DoNotEdit*
        {                                                                   // *DoNotEdit*
            Goto(&Test1Control::S_SUBRETURN1);                              // *DoNotEdit*
        }                                                                   // *DoNotEdit*
    }                                                                       // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [SYN-G-GEN OUTPUT END]
 

    // write your code here!

public:
    void Start()  { Goto(&Test1Control::S_START);            }
    bool IsEnd()  { return CheckState(&Test1Control::S_END); }
    void Update() { update();                   }
};