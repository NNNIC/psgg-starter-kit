<?php

class __PREFIX__Control {

    // :::: PSGG MANAGER ::::

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

    function Start() {
        $this->GotoState('S_START');
    }

    function IsEnd() {
        return $this->CheckState('S_END');
    }

    // :::: PSG OUPUT ::::

    function call_state($state, $bFirst) {
        switch($state) {
            //[PSGG OUTPUT START] indent(12) $/^S_/->#case$
            case 'S_START': $this->S_START($bFirst); break;
            case 'S_END':   $this->S_END($bFirst);  break;            
            //[PSGG OUTPUT END]
        }
    }

    //[PSGG OUTPUT START] indent(4) $/./$
    function S_START($bFirst) {
        $this->GotoState('S_END');
    }
    function S_END($bFirst) {
    }   
    //[PSGG OUTPUT END]

    // :::: WRITE YOUR CODE HERE ::::

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

/* :::: PSGG MACRO ::::
:psgg-macro-start

; This section has macro defines for converting.

; commentline format  {%0} will be replaced to a comment.
commentline=// {%0} 

@branch=@@@
<<<?"{%0}"/^brifc{0,1}$/
if ([[brcond:{%N}]]) { $this->GotoState( '{%1}' ); }
>>>
<<<?"{%0}"/^brelseifc{0,1}$/
elseif ([[brcond:{%N}]]) { $this->GotoState( '{%1}' ); }
>>>
<<<?"{%0}"/^brelse$/
else { $this->GotoState( '{%1}' ); }
>>>

<<<?"{%0}"/^br_/
$this->{%0}('{%1}');
>>>
@@@

#case=@@@
case '[[state]]': $this->[[state]]($bFirst); break;
@@@

:psgg-macro-end
*/

?>