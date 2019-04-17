import java.util.function.Consumer;

public class __PREFIX__Control extends StateManager {
	
	// [SYN-G-GEN OUTPUT START] indent(4) $/./$
    Consumer<Boolean> S_START=(bFirst)->{
        this.Goto(this.S_END);
    };
    Consumer<Boolean> S_END=(bFirst)->{
    };
	// [SYN-G-GEN OUTPUT END]

	public void Start()
    {
        this.Goto(S_START);
    }
    public Boolean IsEnd()     
    { 
        return this.CheckState(this.S_END);
	}

	Boolean m_bYesNo;
	
	void br_YES(Consumer<Boolean> st)
	{
		if (!this.HasNextState())
		{
			if (this.m_bYesNo)
			{
				this.SetNextState(st);
			}
		}
	}

	void br_NO(Consumer<Boolean> st)
	{
		if (!this.HasNextState())
		{
			if (!this.m_bYesNo)
			{
				this.SetNextState(st);
			}
		}
	}
	
	// write your code 
    
}
