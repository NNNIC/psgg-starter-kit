using System;
using System.Collections.Generic;
public partial class HogeControl  {
   
    #region manager
    Action<bool> m_curfunc;
    Action<bool> m_nextfunc;

    bool         m_noWait;
    
    public void Update()
    {
        while(true)
        {
            var bFirst = false;
            if (m_nextfunc!=null)
            {
                m_curfunc = m_nextfunc;
                m_nextfunc = null;
                bFirst = true;
            }
            m_noWait = false;
            if (m_curfunc!=null)
            {   
                m_curfunc(bFirst);
            }
            if (!m_noWait) break;
        }
    }
    void Goto(Action<bool> func)
    {
        m_nextfunc = func;
    }
    bool CheckState(Action<bool> func)
    {
        return m_curfunc == func;
    }
    bool HasNextState()
    {
        return m_nextfunc != null;
    }
    void NoWait()
    {
        m_noWait = true;
    }
    #endregion
    #region gosub
    List<Action<bool>> m_callstack = new List<Action<bool>>();
    void GoSubState(Action<bool> nextstate, Action<bool> returnstate)
    {
        m_callstack.Insert(0,returnstate);
        Goto(nextstate);
    }
    void ReturnState()
    {
        var nextstate = m_callstack[0];
        m_callstack.RemoveAt(0);
        Goto(nextstate);
    }
    #endregion 

    public void Start()
    {
        Goto(S_START);
    }
    public bool IsEnd()     
    { 
        return CheckState(S_END); 
    }
    
    public void Run()
    {
		int LOOPMAX = (int)(1E+5);
		Start();
		for(var loop = 0; loop <= LOOPMAX; loop++)
		{
			if (loop>=LOOPMAX) throw new SystemException("Unexpected.");
			Update();
			if (IsEnd()) break;
		}
	}

	#region    // [PSGG OUTPUT START] indent(8) $/./$
//  psggConverterLib.dll converted from HogeControl.xlsx.    psgg-file:HogeControl.psgg
        /*
            S_END
        */
        void S_END(bool bFirst)
        {
        }
        /*
            S_LOOPPROC
        */
        void S_LOOPPROC(bool bFirst)
        {
            //
            if (!HasNextState())
            {
                Goto(S_SUBRETURN);
            }
        }
        /*
            S_LOOPTEST
        */
        int m_i;
        void S_LOOPTEST(bool bFirst)
        {
            m_i = 0;
            Goto(S_LOOPTEST____loopcheck);
            NoWait();
        }
        void S_LOOPTEST____loopcheck(bool bFirst)
        {
            if (m_i < 10;) Goto(S_LOOPTEST____loopproc);
            else               Goto(S_END);
            NoWait();
        }
        void S_LOOPTEST____loopproc(bool bFirst)
        {
            GoSubState(S_SUBSTART,S_LOOPTEST____loopnext);
            NoWait();
        }
        void S_LOOPTEST____loopnext(bool bFirst)
        {
            m_i++;
            Goto(S_LOOPTEST____loopcheck);
            NoWait();
        }
        /*
            S_START
        */
        void S_START(bool bFirst)
        {
            Goto(S_LOOPTEST);
            NoWait();
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
            S_SUBSTART
        */
        void S_SUBSTART(bool bFirst)
        {
            Goto(S_LOOPPROC);
            NoWait();
        }


	#endregion // [PSGG OUTPUT END]

	// write your code below

	bool m_bYesNo;
	
	void br_YES(Action<bool> st)
	{
		if (!HasNextState())
		{
			if (m_bYesNo)
			{
				Goto(st);
			}
		}
	}

	void br_NO(Action<bool> st)
	{
		if (!HasNextState())
		{
			if (!m_bYesNo)
			{
				Goto(st);
			}
		}
	}
}

/*  :::: PSGG MACRO ::::
:psgg-macro-start

commentline=// {%0}

@branch=@@@
<<<?"{%0}"/^brifc{0,1}$/
if ([[brcond:{%N}]]) { Goto( {%1} ); }
>>>
<<<?"{%0}"/^brelseifc{0,1}$/
else if ([[brcond:{%N}]]) { Goto( {%1} ); }
>>>
<<<?"{%0}"/^brelse$/
else { Goto( {%1} ); }
>>>
<<<?"{%0}"/^br_/
{%0}({%1});
>>>
@@@

:psgg-macro-end
*/

