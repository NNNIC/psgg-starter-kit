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

    FUNCPTR m_curstate;
    FUNCPTR m_nextstate;
    bool   m_bNoWait;
    
    static const int CALL_STACK_MAX = 10;
    FUNCPTR *m_callstack;
    int m_callstack_level;

public :
    Test1Control() : 
    //  construction codes                       [STATE-GO OUTPUT START] indent(8) $/^S_/->#constructlist$
        //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                              // *DoNotEdit*
                                                                            // *DoNotEdit*
        m_i(0),                                                             // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [STATE-GO OUTPUT END]
        m_curstate(nullptr), m_nextstate(nullptr), m_bNoWait(false), m_callstack_level(0), m_callstack(nullptr)
	{
        m_callstack = new FUNCPTR[CALL_STACK_MAX];
             
	}

private:
    void _update();

    inline void Goto(FUNCPTR st)        { m_nextstate = st;              }
    inline bool CheckState(FUNCPTR st)  { return m_curstate == st;       }
    inline bool HasNextState()          { return m_nextstate != nullptr; }
    inline void NoWait()                { m_bNoWait = true;              }
    inline void GoSubState(FUNCPTR sb, FUNCPTR nt)
    {
        if (m_callstack_level >= CALL_STACK_MAX - 1)
        {
            printf("CALL STACK OVER FLOW\n");
            exit(1);
        }
        m_callstack[m_callstack_level++] = nt;
        Goto(sb);
    }
    inline void ReturnState()
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

    //  Embed codes                              [STATE-GO OUTPUT START] indent(4) $/^E_/$
    //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                  // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [STATE-GO OUTPUT END]

    //  Member codes                              [STATE-GO OUTPUT START] indent(4) $/^S_/->#memberlist$
    //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                  // *DoNotEdit*
                                                                            // *DoNotEdit*
    int m_i;                                                                // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [STATE-GO OUTPUT END]


    //  API declaration                          [STATE-GO OUTPUT START] indent(4) $/^S_/->#declare$
    //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                  // *DoNotEdit*
                                                                            // *DoNotEdit*
    void S_0001(bool bFirst);                                               // *DoNotEdit*
    void S_END(bool bFirst);                                                // *DoNotEdit*
    void S_EVEN_OR_ODD(bool bFirst);                                        // *DoNotEdit*
    void S_GOSUB(bool bFirst);                                              // *DoNotEdit*
    void S_LOOP(bool bFirst);                                               // *DoNotEdit*
    void S_LOOP_LoopCheckAndGosub____(bool bFirst);                         // *DoNotEdit*
    void S_LOOP_LoopNext____(bool bFirst);                                  // *DoNotEdit*
    void S_PRINT_EVEN(bool bFirst);                                         // *DoNotEdit*
    void S_PRINT_ODD(bool bFirst);                                          // *DoNotEdit*
    void S_START(bool bFirst);                                              // *DoNotEdit*
    void S_SUBRETURN(bool bFirst);                                          // *DoNotEdit*
    void S_SUBRETURN1(bool bFirst);                                         // *DoNotEdit*
    void S_SUBSTART(bool bFirst);                                           // *DoNotEdit*
    void S_SUBSTART1(bool bFirst);                                          // *DoNotEdit*
    void S_WORK(bool bFirst);                                               // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [STATE-GO OUTPUT END]

public:
    void Start();
    bool IsEnd();
    void Update();
};