using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public partial class __PREFIX__Control : MonoBehaviour {
 
    #region manger
    Action<bool> m_curfunc;
    Action<bool> m_nextfunc;
    Action<bool> m_tempfunc;

    bool         m_noWait;
    
    void _update()
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
    // for tempfunc
    void SetNextState(Action<bool> func)
    {
        m_tempfunc = func;
    }
    void GoNextState()
    {
        m_nextfunc = m_tempfunc;
        m_tempfunc = null;
    }
    bool HasNextState()
    {
        return m_tempfunc != null;
    }
    void NoWait()
    {
        m_noWait = true;
    }
    #endregion

    void _start()
    {
        Goto(S_START);
    }
    public bool IsEnd()     
    { 
        return CheckState(S_END); 
    }

	#region    // [SYN-G-GEN OUTPUT START] indent(8) $/./$
    void S_START(bool bFirst) { }
    void S_END(bool bFirst) { }
	#endregion // [SYN-G-GEN OUTPUT END]

	// write your code below

	bool m_bYesNo;
	
	void br_YES(Action<bool> st)
	{
		if (!HasNextState())
		{
			if (m_bYesNo)
			{
				SetNextState(st);
			}
		}
	}

	void br_NO(Action<bool> st)
	{
		if (!HasNextState())
		{
			if (!m_bYesNo)
			{
				SetNextState(st);
			}
		}
	}

    #region Monobehaviour framework
    void Start()
    {
        _start();
    }
    void Update()
    {
        if (!IsEnd()) 
        {
            _update();
        }
    }
    #endregion
}