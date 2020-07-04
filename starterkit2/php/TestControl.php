<?php

class TestControl {

    // :::: PSGG MANAGER ::::

    private $m_curfunc  = NULL;
    private $m_nextfunc = NULL;
    private $m_noWait   = FALSE;

    private const MAX_CALL_STACK = 10;
    private $m_callstack = array();
    private $m_callstack_level = 0;

    function __construct() {
        $m_callstack = array_fill(0,self::MAX_CALL_STACK,'');
    }

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

    public function GoSubState($sub, $next) {
        if ($this->m_callstack_level >= self::MAX_CALL_STACK - 1) {
            echo 'CALL STACK OVER FLOW<br>';
            exit();
        }
        $this->m_callstack[$this->m_callstack_level++] = $next;
        $this->GotoState($sub);
    }

    public function ReturnState()
    {
        if ($this->m_callstack_level <= 0) {
            echo 'CALL STACK UNDER FLOW<br>';
            exit();
        }
        $this->m_callstack_level--;
        $st = $this->m_callstack[$this->m_callstack_level];
        
        $this->GotoState($st);        
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
            //             psggConverterLib.dll converted from psgg-file:TestControl.psgg

            case 'S_0008': $this->S_0008($bFirst); break;
            case 'S_END': $this->S_END($bFirst); break;
            case 'S_GSB000': $this->S_GSB000($bFirst); break;
            case 'S_GSB001': $this->S_GSB001($bFirst); break;
            case 'S_LOP000': $this->S_LOP000($bFirst); break;
            case 'S_LOP000_LoopCheckAndGosub____': $this->S_LOP000_LoopCheckAndGosub____($bFirst); break;
            case 'S_LOP000_LoopNext____': $this->S_LOP000_LoopNext____($bFirst); break;
            case 'S_RET000': $this->S_RET000($bFirst); break;
            case 'S_SBS000': $this->S_SBS000($bFirst); break;
            case 'S_START': $this->S_START($bFirst); break;


            //[PSGG OUTPUT END]
        }
    }

    //[PSGG OUTPUT START] indent(4) $/./$
    //             psggConverterLib.dll converted from psgg-file:TestControl.psgg

    /*
        S_0008
    */
    function S_0008($bFirst) {
        if ($bFirst)
        {
            echo 'Hello Subroutine.<br>';
        }
        if ($this->HasNextState()==FALSE)
        {
            $this->GotoState('S_RET000');
        }
    }
    /*
        S_END
    */
    function S_END($bFirst)
    {
    }
    /*
        S_GSB000
    */
    function S_GSB000($bFirst)
    {
        $this->GoSubState('S_SBS000','S_GSB001');
        $this->NoWait();
    }
    /*
        S_GSB001
    */
    function S_GSB001($bFirst)
    {
        $this->GoSubState('S_SBS000','S_END');
        $this->NoWait();
    }
    /*
        S_LOP000
    */
    private $index = 0;
    function S_LOP000($bFirst)
    {
        $this->index = 0;
        $this->GotoState('S_LOP000_LoopCheckAndGosub____');
        $this->NoWait();
    }
    function S_LOP000_LoopCheckAndGosub____($bFirst)
    {
        if ($this->index < 10) $this->GoSubState('S_SBS000','S_LOP000_LoopNext____');
        else               $this->GotoState('S_GSB000');
        $this->NoWait();
    }
    function S_LOP000_LoopNext____($bFirst)
    {
        $this->index ++;
        $this->GotoState('S_LOP000_LoopCheckAndGosub____');
        $this->NoWait();
    }
    /*
        S_RET000
    */
    function S_RET000($bFirst)
    {
        $this->ReturnState();
        $this->NoWait();
    }
    /*
        S_SBS000
    */
    function S_SBS000($bFirst) {
        if ($this->HasNextState()==FALSE)
        {
            $this->GotoState('S_0008');
        }
    }
    /*
        S_START
    */
    function S_START($bFirst)
    {
        $this->GotoState('S_LOP000');
        $this->NoWait();
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
<<<?state-typ/^loop$/
case '[[state]]_LoopCheckAndGosub____': $this->[[state]]_LoopCheckAndGosub____($bFirst); break;
case '[[state]]_LoopNext____': $this->[[state]]_LoopNext____($bFirst); break;
>>>
@@@

:psgg-macro-end
*/

?>