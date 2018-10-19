#include <stdio.h>
#include <stdbool.h>


//== Declear States  ==

//                                      [SYN-G-GEN OUTPUT START] $/^S_/->#static$
static void S_START(bool bFirst);
static void S_END(bool bFirst);
//                                      [SYN-G-GEN OUTPUT END]

// == manager ==

static void *m_curfunc = NULL;
static void *m_nextfunc= NULL;
static void *m_tempfunc = NULL;
static bool  m_bNoWait = false;

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

static void SetNextState(void *st) {
    m_tempfunc = st;
}

static void GoNextState() {
    m_nextfunc = m_tempfunc;
    m_tempfunc  = NULL;
}

static bool HasNextState() {
    return m_tempfunc != NULL;
}

static void NoWait()
{
    m_bNoWait = true;
}

//
static bool m_bYesNo = false;
	
static void br_YES(void *st)
{
	if (!HasNextState())
	{
		if (m_bYesNo)
		{
			SetNextState(st);
		}
	}
}

static void br_NO(void *st)
{
	if (!HasNextState())
	{
		if (!m_bYesNo)
		{
			SetNextState(st);
		}
	}
}

//                                      [SYN-G-GEN OUTPUT START] $/^S_/$
static void S_START(bool bFirst) { Goto(S_END); }
static void S_END(bool bFirst)   {}
//                                      [SYN-G-GEN OUTPUT END]

// externs
extern void __PREFIX__Control_start()
{
    Goto(S_START);
}
extern void __PREFIX__Control_update()
{
    update();
}
extern bool __PREFIX__Control_is_end()
{
    return CheckState(S_END);
}

