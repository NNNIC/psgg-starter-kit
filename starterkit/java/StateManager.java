import java.util.function.Consumer;

public class StateManager {
    Consumer<Boolean> m_curfunc;
    Consumer<Boolean> m_nextfunc;
    Consumer<Boolean> m_tempfunc;

    Boolean           m_noWait;

    public void Update() {
        while(true) {
            Boolean bFirst = false;
            if (m_nextfunc != null) {
                m_curfunc = m_nextfunc;
                m_nextfunc = null;
                bFirst = true;
            }
            m_noWait = false;
            if (m_curfunc!=null) {
                m_curfunc.accept(bFirst);
            }
            if (!m_noWait) break;
        }
    }

    public void Goto(Consumer<Boolean> func) {
        m_nextfunc = func;
    }

    public Boolean CheckState(Consumer<Boolean> func) {
        return (m_curfunc == func);
    }

    public void SetNextState(Consumer<Boolean> func) {
        m_tempfunc = func;
    }
    public void GoNextState() {
        m_nextfunc = m_tempfunc;
        m_tempfunc = null;
    }
    public Boolean HasNextState() {
        return m_tempfunc != null;
    }
    public void NoWait()
    {
        m_noWait = true;
    }
}