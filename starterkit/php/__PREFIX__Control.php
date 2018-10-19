<?php
require('base/StateManager.php');
class __PREFIX__Control extends StateManager {

    function Start() {
        $this->GotoState('S_START');
    }

    function IsEnd() {
        return $this->CheckState('S_END');
    }

    function call_state($state, $bFirst) {
        switch($state) {
            //[SYN-G-GEN OUTPUT START] indent(12) $/^S_/->#case$
            case 'S_START': $this->S_START($bFirst); break;
            case 'S_END':   $this->S_END($bFirst);  break;            
            //[SYN-G-GEN OUTPUT END]
        }
    }

    //[SYN-G-GEN OUTPUT START] indent(4) $/./$
    function S_START($bFirst) {
        $this->GotoState('S_END');
    }
    function S_END($bFirst) {
    }   
    //[SYN-G-GEN OUTPUT END]

    protected $m_bYesNo;

    function br_YES($st) {
        if ($this->HasNextState()==FALSE) {
            if ($this->m_bYesNo==TRUE) {
                $this->GotoState($st);
            }
        }
    }

    function br_NO($st) {
        if ($this->HasNextState()==FALSE) {
            if ($this->m_bYesNo==FALSE) {
                $this->GotoState($st);
            }
        }
    }
}
?>