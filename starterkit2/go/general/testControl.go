package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	testControl()
}

func testControl() {

	rand.Seed(time.Now().Unix())

	curfunc := -1
	nextfunc := -1

	gotoState := func(st int) {
		nextfunc = st
	}
	hasNextState := func() bool {
		return nextfunc != -1
	}

	callstack := [...]int{0, 0, 0, 0, 0}
	callstacklevel := 0
	gosubState := func(sub, next int) {
		if callstacklevel >= len(callstack)-1 {
			panic("call stack overflow")
			//return
		}
		callstack[callstacklevel] = next
		callstacklevel++
		gotoState(sub)
	}
	returnState := func() {
		if callstacklevel <= 0 {
			panic("call stack underflow")
			//return
		}
		callstacklevel--
		funcid := callstack[callstacklevel]
		gotoState(funcid)
	}
	// #
	// # Define function ID for state
	// #
	id := 0
	//[STATEGO OUTPUT START] indent(4) $/^S_./->#setids$
    //             psggConverterLib.dll converted from psgg-file:testControl.psgg

    funcIds0001 := id
    id++
    funcIds0002 := id
    id++
    funcIds0003 := id
    id++
    funcIds0004 := id
    id++
    funcIds0005 := id
    id++
    funcIds0006 := id
    id++
    funcIds0007 := id
    id++
    funcIdsEND := id
    id++
    funcIdsGSB000 := id
    id++
    funcIdsHELLOWORLD := id
    id++
    funcIdsLOP000 := id
    id++
    funcIdsLOP000LoopCheck := id
    id++
    funcIdsLOP000LoopNext := id
    id++
    funcIdsNEWERA := id
    id++
    funcIdsPAS000 := id
    id++
    funcIdsPAS001 := id
    id++
    funcIdsRET000 := id
    id++
    funcIdsRET001 := id
    id++
    funcIdsSBS000 := id
    id++
    funcIdsSBS001 := id
    id++
    funcIdsSTART := id
    id++


	//[STATEGO OUTPUT END]

	// [STATEGO OUTPUT START] indent(4) $/^S_./->#memlist$
    //             psggConverterLib.dll converted from psgg-file:testControl.psgg

    counter := 0

	//[STATEGO OUTPUT END]
	// [STATEGO OUTPUT START] indent(4) $/^E_./$
    //             psggConverterLib.dll converted from psgg-file:testControl.psgg

    /*
        E_0001
    */
    msg := "We are in the visual program era."


	//[STATEGO OUTPUT END]
	// #
	// #  State Function
	// #
	var endofFuncList = func(bFirst bool) { // for end of function list
	}
	//[STATEGO OUTPUT START] indent(4) $/^S_./$
    //             psggConverterLib.dll converted from psgg-file:testControl.psgg

    /*
        S_0001
    */
    s0001 := func( bFirst  bool ) {
        var n = rand.Intn(5)
        if n==0 {
            gotoState( funcIds0004 )
        } else if n==1 {
            gotoState( funcIds0002 )
        } else if n==2 {
            gotoState( funcIds0003 )
        } else {
            gotoState( funcIds0007 )
        }
    }
    /*
        S_0002
    */
    s0002 := func( bFirst  bool ) {
        if bFirst {
            fmt.Println("1")
        }
        if !hasNextState() {
            gotoState(funcIdsPAS000)
        }
    }
    /*
        S_0003
    */
    s0003 := func( bFirst  bool ) {
        if bFirst {
            fmt.Println("2")
        }
        if !hasNextState() {
            gotoState(funcIdsPAS000)
        }
    }
    /*
        S_0004
    */
    s0004 := func( bFirst  bool ) {
        if bFirst {
            fmt.Println("0")
        }
        if !hasNextState() {
            gotoState(funcIdsPAS000)
        }
    }
    /*
        S_0005
    */
    s0005 := func( bFirst  bool ) {
        if bFirst {
            fmt.Println("In a subroutine!")
        }
        if !hasNextState() {
            gotoState(funcIdsRET000)
        }
    }
    /*
        S_0006
    */
    s0006 := func( bFirst  bool ) {
        if bFirst {
            fmt.Println("In a loop subroutine! no.",counter)
        }
        if !hasNextState() {
            gotoState(funcIdsRET001)
        }
    }
    /*
        S_0007
    */
    s0007 := func( bFirst  bool ) {
        if bFirst {
            fmt.Println("Other")
        }
        if !hasNextState() {
            gotoState(funcIdsPAS000)
        }
    }
    /*
        S_END
    */
    sEND := func ( bFirst  bool ) {
         // end of state machine
    }
    /*
        S_GSB000
    */
    sGSB000 := func ( bFirst bool ) {
        gosubState(funcIdsSBS000, funcIdsPAS001)
    }
    /*
        S_HELLOWORLD
    */
    sHELLOWORLD := func( bFirst  bool ) {
        if bFirst {
            fmt.Println("Hello World.")
        }
        if !hasNextState() {
            gotoState(funcIdsNEWERA)
        }
    }
    /*
        S_LOP000
    */
    sLOP000 := func ( bFirst bool ) {
        counter = 0
        gotoState(funcIdsLOP000LoopCheck)
    }
    sLOP000LoopCheck := func ( bFirst bool ) {
        if counter < 10 {
            gosubState(funcIdsSBS001, funcIdsLOP000LoopNext)
        } else {
            gotoState(funcIdsEND)
        }
    }
    sLOP000LoopNext := func(bFirst bool ) {
        counter++
        gotoState(funcIdsLOP000LoopCheck)
    }
    /*
        S_NEWERA
    */
    sNEWERA := func( bFirst  bool ) {
        if bFirst {
            fmt.Println(msg)
        }
        if !hasNextState() {
            gotoState(funcIds0001)
        }
    }
    /*
        S_PAS000
    */
    sPAS000 := func( bFirst  bool ) {
        if !hasNextState() {
            gotoState(funcIdsGSB000)
        }
    }
    /*
        S_PAS001
    */
    sPAS001 := func( bFirst  bool ) {
        if !hasNextState() {
            gotoState(funcIdsLOP000)
        }
    }
    /*
        S_RET000
    */
    sRET000 := func ( bFirst bool ) {
        returnState()
    }
    /*
        S_RET001
    */
    sRET001 := func ( bFirst bool ) {
        returnState()
    }
    /*
        S_SBS000
    */
    sSBS000 := func( bFirst  bool ) {
        if !hasNextState() {
            gotoState(funcIds0005)
        }
    }
    /*
        S_SBS001
    */
    sSBS001 := func( bFirst  bool ) {
        if !hasNextState() {
            gotoState(funcIds0006)
        }
    }
    /*
        S_START
    */
    sSTART := func( bFirst  bool ) {
        gotoState(funcIdsHELLOWORLD)
    }


	//[STATEGO OUTPUT END]

	var funclist = [...]func(bool){

		//[STATEGO OUTPUT START] indent(8) $/^S_./->#funclist$
        //             psggConverterLib.dll converted from psgg-file:testControl.psgg

        s0001,
        s0002,
        s0003,
        s0004,
        s0005,
        s0006,
        s0007,
        sEND,
        sGSB000,
        sHELLOWORLD,
        sLOP000,
        sLOP000LoopCheck,
        sLOP000LoopNext,
        sNEWERA,
        sPAS000,
        sPAS001,
        sRET000,
        sRET001,
        sSBS000,
        sSBS001,
        sSTART,


		//[STATEGO OUTPUT END]
		endofFuncList}

	nextfunc = funcIdsSTART

	for curfunc != funcIdsEND {
		var bFirst = false
		if nextfunc != -1 {
			curfunc = nextfunc
			nextfunc = -1
			bFirst = true
		}
		if curfunc != -1 {
			funclist[curfunc](bFirst)
		}
	}
}

/*  :::: PSGG MACRO ::::
:psgg-macro-start

commentline=// {%0}

#setids=@@@
funcId[[state>>lc]] := id
id++
<<<?state-typ/^loop$/
funcId[[state>>lc]]LoopCheck := id
id++
funcId[[state>>lc]]LoopNext := id
id++
>>>
@@@

#funclist=@@@
[[state>>lc]],
<<<?state-typ/^loop$/
[[state>>lc]]LoopCheck,
[[state>>lc]]LoopNext,
>>>
@@@

#memlist=@@@
[[members]]
@@@

@branch=@@@
<<<?"{%0}"/^brif$/
if [[brcond:{%N}]] {
    gotoState( funcId$lc:{%1}$ )
}
>>>
<<<?"{%0}"/^brifc$/
if [[brcond:{%N}]] {
    gotoState( funcId$lc:{%1}$ )
>>>
<<<?"{%0}"/^brelseif$/
} else if [[brcond:{%N}]] {
    gotoState( funcId$lc:{%1}$ )
}
>>>
<<<?"{%0}"/^brelseifc$/
} else if [[brcond:{%N}]] {
    gotoState( funcId$lc:{%1}$ )
>>>
<<<?"{%0}"/^brelse$/
} else {
    gotoState( funcId$lc:{%1}$ )
}
>>>
@@@

:psgg-macro-end

*/
