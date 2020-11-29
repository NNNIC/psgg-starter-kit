package game

import (
	"math/rand"
	"strconv"
	"time"
)

type TestControlData struct {
	g    *Game
	bEnd bool
}

func TestControl(d *TestControlData) func(bool, *Game) bool {
	var g *Game

	rand.Seed(time.Now().Unix())

	curfunc := -1
	nextfunc := -1

	nowait := false

	noWait := func() {
		nowait = true
	}

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
	sid := 0
	//[STATEGO OUTPUT START] indent(4) $/^S_./->#setids$
    //             psggConverterLib.dll converted from psgg-file:TestControl.psgg

    funcIds0000 := sid
    sid++
    funcIds0001 := sid
    sid++
    funcIds0005 := sid
    sid++
    funcIds0006 := sid
    sid++
    funcIdsEND := sid
    sid++
    funcIdsGSB000 := sid
    sid++
    funcIdsLOP000 := sid
    sid++
    funcIdsLOP000LoopCheck := sid
    sid++
    funcIdsLOP000LoopNext := sid
    sid++
    funcIdsRET000 := sid
    sid++
    funcIdsRET001 := sid
    sid++
    funcIdsSBS000 := sid
    sid++
    funcIdsSBS001 := sid
    sid++
    funcIdsSTART := sid
    sid++
    funcIdsWAIT1 := sid
    sid++


	//[STATEGO OUTPUT END]

	// [STATEGO OUTPUT START] indent(4) $/^S_./->#memlist$
    //             psggConverterLib.dll converted from psgg-file:TestControl.psgg

    counter := 0
    var timesWAIT1 int64


	//[STATEGO OUTPUT END]
	// [STATEGO OUTPUT START] indent(4) $/^E_./$
    //             psggConverterLib.dll converted from psgg-file:TestControl.psgg



	//[STATEGO OUTPUT END]

	// #
	// #  State Function
	// #
	var endofFuncList = func(bFirst bool) { // for end of function list
	}
	//[STATEGO OUTPUT START] indent(4) $/^S_./$
    //             psggConverterLib.dll converted from psgg-file:TestControl.psgg

    /*
        S_0000
    */
    s0000 := func( bFirst  bool ) {
        if bFirst {
            g.TermPrint("HELLO WORLD")
        }
        if !hasNextState() {
            gotoState(funcIdsGSB000)
        }
    }
    /*
        S_0001
    */
    s0001 := func( bFirst  bool ) {
        if bFirst {
            g.TermPrint("WAIT 2SEC")
        }
        if !hasNextState() {
            gotoState(funcIdsWAIT1)
        }
    }
    /*
        S_0005
    */
    s0005 := func( bFirst  bool ) {
        if bFirst {
            g.TermPrint("In a subroutine!")
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
            g.TermPrint("In a loop subroutine! no." + strconv.Itoa(counter))
        }
        if !hasNextState() {
            gotoState(funcIdsRET001)
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
        gosubState(funcIdsSBS000, funcIdsLOP000)
        noWait()
    }
    /*
        S_LOP000
    */
    sLOP000 := func ( bFirst bool ) {
        counter = 0
        gotoState(funcIdsLOP000LoopCheck)
        noWait()
    }
    sLOP000LoopCheck := func ( bFirst bool ) {
        if counter < 10 {
            gosubState(funcIdsSBS001, funcIdsLOP000LoopNext)
        } else {
            gotoState(funcIds0001)
        }
        noWait()
    }
    sLOP000LoopNext := func(bFirst bool ) {
        counter++
        gotoState(funcIdsLOP000LoopCheck)
        noWait()
    }
    /*
        S_RET000
    */
    sRET000 := func ( bFirst bool ) {
        returnState()
        noWait()
    }
    /*
        S_RET001
    */
    sRET001 := func ( bFirst bool ) {
        returnState()
        noWait()
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
        gotoState(funcIds0000)
    }
    /*
        S_WAIT1
    */
    sWAIT1 := func( bFirst  bool ) {
        if bFirst {
            timesWAIT1 = g.TimeNowMs() + 2000
        }
        if timesWAIT1 > g.TimeNowMs() {
             return
        }
        if !hasNextState() {
            gotoState(funcIdsEND)
        }
    }


	//[STATEGO OUTPUT END]

	var funclist = [...]func(bool){

		//[STATEGO OUTPUT START] indent(8) $/^S_./->#funclist$
        //             psggConverterLib.dll converted from psgg-file:TestControl.psgg

        s0000,
        s0001,
        s0005,
        s0006,
        sEND,
        sGSB000,
        sLOP000,
        sLOP000LoopCheck,
        sLOP000LoopNext,
        sRET000,
        sRET001,
        sSBS000,
        sSBS001,
        sSTART,
        sWAIT1,


		//[STATEGO OUTPUT END]
		endofFuncList}
	/*
																																				var dbgfunclist = [...]string{
																																					//[STATEGO OUTPUT START] indent(8) $/^S_./->#dbgfunclist$
        //             psggConverterLib.dll converted from psgg-file:TestControl.psgg

        "S_0000",
        "S_0001",
        "S_0005",
        "S_0006",
        "S_END",
        "S_GSB000",
        "S_LOP000",
        "S_LOP000_LoopCheck",
        "S_LOP000_LoopNext",
        "S_RET000",
        "S_RET001",
        "S_SBS000",
        "S_SBS001",
        "S_START",
        "S_WAIT1",


																																					//[STATEGO OUTPUT END]
																																					"none"}
	*/
	nextfunc = funcIdsSTART

	update := func() bool {
		if curfunc != funcIdsEND {
			for true {
				var bFirst = false
				if nextfunc != -1 {
					curfunc = nextfunc
					nextfunc = -1
					bFirst = true
					//fmt.Println(dbgfunclist[curfunc])
				}
				if curfunc != -1 {
					nowait = false
					funclist[curfunc](bFirst)
				}
				if nowait == false {
					break
				}
			}
			return false
		} else {
			d.bEnd = true
		}

		return true
	}

	// for avoiding "declared but not used"
	_ = hasNextState()
	gosubState(funcIdsSTART, funcIdsEND)
	returnState()
	noWait()

	// initialize
	curfunc = -1
	nextfunc = funcIdsSTART
	d.bEnd = false
	// return update function     set true -- from start  set flase -- update
	return func(bFirst bool, ig *Game) bool {
		g = ig
		d.g = ig
		if bFirst {
			curfunc = -1
			nextfunc = funcIdsSTART
			d.bEnd = false
		}
		return update()
	}
}

/*  :::: PSGG MACRO ::::
:psgg-macro-start

commentline=// {%0}

#setids=@@@
funcId[[state>>lc]] := sid
sid++
<<<?state-typ/^loop$/
funcId[[state>>lc]]LoopCheck := sid
sid++
funcId[[state>>lc]]LoopNext := sid
sid++
>>>
@@@

#funclist=@@@
[[state>>lc]],
<<<?state-typ/^loop$/
[[state>>lc]]LoopCheck,
[[state>>lc]]LoopNext,
>>>
@@@

#dbgfunclist=@@@
"[[state]]",
<<<?state-typ/^loop$/
"[[state]]_LoopCheck",
"[[state]]_LoopNext",
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
