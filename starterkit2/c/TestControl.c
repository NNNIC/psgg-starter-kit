#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//== Declear States  ==

//                                      [STATEGO OUTPUT START] $/^S_/->#static$
//  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
    static void S_0001(bool bFirst);
    static void S_0002(bool bFirst);
    static void S_0003(bool bFirst);
    static void S_END(bool bFirst);
    static void S_GOSUB1(bool bFirst);
    static void S_LOOP1(bool bFirst);
    static void S_LOOP1_LoopCheckAndGosub____(bool bFirst);
    static void S_LOOP1_LoopCheckAndGosub____(bool bFirst);
    static void S_LOOP1_LoopNext____(bool bFirst);
    static void S_RETURN1(bool bFirst);
    static void S_RETURN2(bool bFirst);
    static void S_START(bool bFirst);
    static void S_SUBSTART1(bool bFirst);
    static void S_SUBSTART2(bool bFirst);


//                                      [STATEGO OUTPUT END]

// == manager ==

static void *m_curfunc = NULL;
static void *m_nextfunc= NULL;
static bool  m_bNoWait = false;

const int MAX_CALL_STACK = 10;
static void *m_callstack[10];
static int   m_callstack_level = 0;

static void update() {
    while(true) {
        bool bFirst = false;
        if (m_nextfunc!=NULL) {
            m_curfunc = m_nextfunc;
            m_nextfunc = NULL;
            bFirst = true;
        }

        m_bNoWait = false;
        if (m_curfunc!=NULL) {
            void (*func)(bool);
            func = m_curfunc;
            (*func)(bFirst);
        }
        if (m_bNoWait == false) break;
    }
}

static void Goto(void *st) {
    m_nextfunc = st;
}

static bool CheckState(void *st) {
    return m_curfunc == st;
}

static bool HasNextState() {
    return m_nextfunc != NULL;
}

static void NoWait()
{
    m_bNoWait = true;
}

static void GoSubState(void *sub, void *next)
{
	if (m_callstack_level >= MAX_CALL_STACK-1) 
	{
		printf("CALL STACK OVER FLOW\n");
		exit(1);
	}
	m_callstack[m_callstack_level++] = next;
	Goto(sub);
}

static void ReturnState()
{
	void *st = NULL;

	if (m_callstack_level <= 0)
	{
		printf("CALL STACK UNDER FLOW\n");
		exit(1);
	}
	m_callstack_level--;
	st = m_callstack[m_callstack_level];
	
	Goto(st);
}
//                                      [STATEGO OUTPUT START] $/^E_/$
//  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
    /*
        E_0001
        new embed code
    */
    static int m_I;


//                                      [STATEGO OUTPUT END] 

//                                      [STATEGO OUTPUT START] $/^S_/$
//  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
    /*
        S_0001
    */
    void S_0001(bool bFirst)
    {
        if (bFirst)
        {
            printf("StateGo is running\n");
        }
        if (!HasNextState())
        {
            Goto(S_GOSUB1);
        }
    }
    /*
        S_0002
    */
    void S_0002(bool bFirst)
    {
        if (bFirst)
        {
            printf("A Subroutine is running\n");
        }
        if (!HasNextState())
        {
            Goto(S_RETURN1);
        }
    }
    /*
        S_0003
    */
    void S_0003(bool bFirst)
    {
        if (bFirst)
        {
            printf("Loop Cointer : %d\n", m_I );
        }
        if (!HasNextState())
        {
            Goto(S_RETURN2);
        }
    }
    /*
        S_END
    */
    void S_END(bool bFirst)
    {
    }
    /*
        S_GOSUB1
        Go A Souroutine
    */
    void S_GOSUB1(bool bFirst)
    {
        GoSubState(S_SUBSTART1,S_LOOP1);
        NoWait();
    }
    /*
        S_LOOP1
        Loop 0 to 9
    */
    void S_LOOP1(bool bFirst)
    {
        m_I = 0;
        Goto(S_LOOP1_LoopCheckAndGosub____);
        NoWait();
    }
    void S_LOOP1_LoopCheckAndGosub____(bool bFirst)
    {
        if (m_I < 10) GoSubState(S_SUBSTART2,S_LOOP1_LoopNext____);
        else               Goto(S_END);
        NoWait();
    }
    void S_LOOP1_LoopNext____(bool bFirst)
    {
        m_I ++;
        Goto(S_LOOP1_LoopCheckAndGosub____);
        NoWait();
    }
    /*
        S_RETURN1
        A Subroutine Return
    */
    void S_RETURN1(bool bFirst)
    {
        ReturnState();
        NoWait();
    }
    /*
        S_RETURN2
        Loop Subroutine Return
    */
    void S_RETURN2(bool bFirst)
    {
        ReturnState();
        NoWait();
    }
    /*
        S_START
    */
    void S_START(bool bFirst)
    {
        Goto(S_0001);
        NoWait();
    }
    /*
        S_SUBSTART1
        A Subroutine Start
    */
    void S_SUBSTART1(bool bFirst)
    {
        if (!HasNextState())
        {
            Goto(S_0002);
        }
    }
    /*
        S_SUBSTART2
        Loop Subroutine Start
    */
    void S_SUBSTART2(bool bFirst)
    {
        if (!HasNextState())
        {
            Goto(S_0003);
        }
    }


//                                      [STATEGO OUTPUT END]

// externs
extern void TestControl_start()
{
    Goto(S_START);
}
extern void TestControl_update()
{
    update();
}
extern bool TestControl_is_end()
{
    return CheckState(S_END);
}

