#!/bin/sh
echo : shell start !!

curfunc=""
nextfunc=""

callstack=()

#[SYN-G-GEN OUTPUT START] $/./$
#  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
    #   E_0001
    declare -i i=0
    #   S_0001
    S_0001()
    {
        if [ $1 -eq 1 ]; then
            echo : Hello StateGo!
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_GOSUB1"
            fi
    }
    #   S_0002  new state
    S_0002()
    {
        declare -i a=$((i%2))
        #echo : ---- a= $a
        # branch
        if [ $a -eq 0 ]; then
            #    SetNextState
                nextfunc="S_0004"
        else
            #    SetNextState
                nextfunc="S_0005"
        fi
    }
    #   S_0003
    S_0003()
    {
        if [ $1 -eq 1 ]; then
            echo : I am in A Subroutine!
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_GOSUB2"
            fi
    }
    #   S_0004
    S_0004()
    {
        if [ $1 -eq 1 ]; then
            echo : In Loop, Number is EVEN i = $i
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_RETURN2"
            fi
    }
    #   S_0005
    S_0005()
    {
        if [ $1 -eq 1 ]; then
            echo : In Loop, Number is ODD   i = $i
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_RETURN2"
            fi
    }
    #   S_0006
    S_0006()
    {
        if [ $1 -eq 1 ]; then
            echo : I am in B Subroutine!
        fi
        #    SetNextStateIf
            if [ "$nextfunc" = "" ]; then
                nextfunc="S_RETURN3"
            fi
    }
    #   S_END
    S_END()
    {
        echo .
    }
    #   S_GOSUB1
    S_GOSUB1()
    {
        callstack+=("S_LOOP1")
        nextfunc="S_SUBSTART1"
    }
    #   S_GOSUB2
    S_GOSUB2()
    {
        callstack+=("S_RETURN1")
        nextfunc="S_SUBSTART3"
    }
    #   S_LOOP1
    S_LOOP1()
    {
        i=0
        #   Goto
            nextfunc="S_LOOP1_LoopCheckAndGosub____"
    }
    S_LOOP1_LoopCheckAndGosub____()
    {
        if [ $i -lt 10 ]; then
            callstack+=("S_LOOP1_LoopNext____")
            nextfunc="S_SUBSTART2"
        else
            #   Goto
                nextfunc="S_END"
        fi
    }
    S_LOOP1_LoopNext____()
    {
        i=$i+1
        #   Goto
            nextfunc="S_LOOP1_LoopCheckAndGosub____"
    }
    #   S_RETURN1
    S_RETURN1()
    {
        declare -i num=${#callstack[@]}-1
        nextfunc=${callstack[num]}
        callstack=("${callstack[@]:0:$num}")
    }
    #   S_RETURN2
    S_RETURN2()
    {
        declare -i num=${#callstack[@]}-1
        nextfunc=${callstack[num]}
        callstack=("${callstack[@]:0:$num}")
    }
    #   S_RETURN3
    S_RETURN3()
    {
        declare -i num=${#callstack[@]}-1
        nextfunc=${callstack[num]}
        callstack=("${callstack[@]:0:$num}")
    }
    #   S_START
    S_START()
    {
        #   Goto
            nextfunc="S_0001"
    }
    #   S_SUBSTART1
    S_SUBSTART1()
    {
        #   Goto
            nextfunc="S_0003"
    }
    #   S_SUBSTART2
    S_SUBSTART2()
    {
        #   Goto
            nextfunc="S_0002"
    }
    #   S_SUBSTART3
    S_SUBSTART3()
    {
        #   Goto
            nextfunc="S_0006"
    }


#[SYN-G-GEN OUTPUT END]

nextfunc="S_START"

echo : request $nextfunc

declare -i _loop=0
max=1000
while  [ $_loop -le $max ]; do
    #echo :  w $nextfunc
    #echo : running $curfunc
    bFirst=0
    if [ "$nextfunc" != "" ]; then
        curfunc=$nextfunc
        nextfunc=""
        bFirst=1
    fi

    #[SYN-G-GEN OUTPUT START] $/^S/->#callfunc$
#  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
    if [ "$curfunc" = "S_0001" ]; then
        S_0001 $bFirst
    fi
    if [ "$curfunc" = "S_0002" ]; then
        S_0002 $bFirst
    fi
    if [ "$curfunc" = "S_0003" ]; then
        S_0003 $bFirst
    fi
    if [ "$curfunc" = "S_0004" ]; then
        S_0004 $bFirst
    fi
    if [ "$curfunc" = "S_0005" ]; then
        S_0005 $bFirst
    fi
    if [ "$curfunc" = "S_0006" ]; then
        S_0006 $bFirst
    fi
    if [ "$curfunc" = "S_END" ]; then
        S_END $bFirst
    fi
    if [ "$curfunc" = "S_GOSUB1" ]; then
        S_GOSUB1 $bFirst
    fi
    if [ "$curfunc" = "S_GOSUB2" ]; then
        S_GOSUB2 $bFirst
    fi
    if [ "$curfunc" = "S_LOOP1" ]; then
        S_LOOP1 $bFirst
    fi
    if [ "$curfunc" = "S_LOOP1_LoopCheckAndGosub____" ]; then
        S_LOOP1_LoopCheckAndGosub____ $bFirst
    fi
    if [ "$curfunc" = "S_LOOP1_LoopNext____" ]; then
        S_LOOP1_LoopNext____ $bFirst
    fi
    if [ "$curfunc" = "S_RETURN1" ]; then
        S_RETURN1 $bFirst
    fi
    if [ "$curfunc" = "S_RETURN2" ]; then
        S_RETURN2 $bFirst
    fi
    if [ "$curfunc" = "S_RETURN3" ]; then
        S_RETURN3 $bFirst
    fi
    if [ "$curfunc" = "S_START" ]; then
        S_START $bFirst
    fi
    if [ "$curfunc" = "S_SUBSTART1" ]; then
        S_SUBSTART1 $bFirst
    fi
    if [ "$curfunc" = "S_SUBSTART2" ]; then
        S_SUBSTART2 $bFirst
    fi
    if [ "$curfunc" = "S_SUBSTART3" ]; then
        S_SUBSTART3 $bFirst
    fi


    #[SYN-G-GEN OUTPUT END]

    if [ "$curfunc" = "S_END" ]; then
        break
    fi
    #echo : loop
    #read a
    _loop=$_loop+1
done

echo : shell end!


<< COMMENTOUT

:::: PSGG MACRO ::::
:psgg-macro-start

; commentline format  {%0} will be replaced to a comment.
commentline=                                                    # {%0}

@branch=@@@
<<<?"{%0}"/^brif$/
if [[brcond:{%N}]]; then
    $macro:SetNextState({%1})$ 
fi
>>>
<<<?"{%0}"/^brifc$/
if [[brcond:{%N}]]; then
    $macro:SetNextState({%1})$ 
>>>
<<<?"{%0}"/^brelseif$/
elif [[brcond:{%N}]]; then
    $macro:SetNextState({%1})$ 
fi
>>>
<<<?"{%0}"/^brelseifc$/
elif [[brcond:{%N}]]; then
    $macro:SetNextState({%1})$
>>>
<<<?"{%0}"/^brelse$/
else 
    $macro:SetNextState({%1})$
fi
>>>
<<<?"{%0}"/^br_/
$macro:{%0}({%1})$
>>>
@@@

#callfunc=@@@
if [ "$curfunc" = "[[state]]" ]; then
    [[state]] $bFirst
fi
<<<?state-typ/^loop$/
if [ "$curfunc" = "[[state]]_LoopCheckAndGosub____" ]; then
    [[state]]_LoopCheckAndGosub____ $bFirst
fi
if [ "$curfunc" = "[[state]]_LoopNext____" ]; then
    [[state]]_LoopNext____ $bFirst
fi
eof>>>
@@@

SetNextState=@@@
#    SetNextState
    nextfunc="{%1}"
@@@

SetNextStateIf=@@@
#    SetNextStateIf
    if [ "$nextfunc" = "" ]; then 
        nextfunc="{%1}"
    fi 
@@@

Goto=@@@
#   Goto
    nextfunc="{%1}"
@@@

Gosub=@@@
callstack+=("{%2}")
nextfunc="{%1}"
@@@

Return=@@@
declare -i num=${#callstack[@]}-1
nextfunc=${callstack[num]}
callstack=("${callstack[@]:0:$num}")
@@@

:psgg-macro-end
COMMENTOUT
