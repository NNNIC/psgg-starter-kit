<?php
abstract class StateManager {
    abstract protected function call_state($state, $b);

    private $m_curfunc  = NULL;
    private $m_nextfunc = NULL;

    private $m_noWait   = FALSE;

    public function Update() {
        while(TRUE) {
            $bFirst = FALSE;
            if ($this->m_nextfunc!=NULL) {
                $this->m_curfunc = $this->m_nextfunc;
                $this->m_nextfunc = NULL;
                $bFirst = TRUE;
            }
            $this->m_noWait = FALSE;
            if ($this->m_curfunc!=NULL) {
                $this->call_state($this->m_curfunc, $bFirst);
            }
            if ($this->m_noWait == FALSE) {
                break;
            }
        }
    }

    public function GotoState($st) {
        $this->m_nextfunc = $st;
    }

    public function CheckState($st) {
        return $st == $this->m_curfunc;
    }
 
    public function HasNextState() {
        return $this->m_nextfunc != NULL;
    }

    public function NoWait() {
        $this->m_noWait = TRUE;
    }
}
?>