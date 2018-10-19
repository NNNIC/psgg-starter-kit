using System;
public partial class __PREFIX__Control  {

    #region manger
    Action<bool> m_curfunc;
    Action<bool> m_nextfunc;
    Action<bool> m_tempfunc;

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
			if (IsEnd()) break;
			
			Update();
		}
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

}
