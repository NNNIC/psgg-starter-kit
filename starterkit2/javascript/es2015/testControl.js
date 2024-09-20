// == manager ==
class testControl {
    constructor() {
        this.curfunc   = null;
        this.nextfunc  = null;
        this.nowait    = false;
        this.callstack = [];
    }

    update()
    {
        while(true)
        {
            this.nowait = false;

            var first = false;
            if (this.nextfunc!=null) {
                this.curfunc  = this.nextfunc;
                this.nextfunc = null;
                first = true;
            }
            if (this.curfunc!=null) {
                this.curfunc(first);
            }

            if (!this.nowait) break;
        }
    }
    
    checkstate(st) {
        return this.curfunc === st;
    }
    goto(st) {
        this.nextfunc = st;
    }
    hasnext = function() {
        return this.nextfunc!=null;
    }
    setnowait = function() {
        this.nowait = true;
    }
    start = function() {
        this.goto(this.S_START);
    }
    is_end = function() {
        return this.checkstate(this.S_END);
    }
    run() {
        var LOOPMAX = 100000;
        this.start();
        for(var loop = 0; loop <= LOOPMAX; loop++)
        {
            if (loop>=LOOPMAX) alert("Unexpected!");
            this.update();
            if (this.is_end()) break;
        }
    }
    gosubstate = function(sb,nt) {
        this.callstack.push(nt);
        this.goto(sb);
    }
    returnstate = function() {
        this.goto(this.callstack.pop());
    }


    // [STATEGO OUTPUT START] indent(4) $/./$
    //             psggConverterLib.dll converted from psgg-file:testControl.psgg

    /*
        S_0007
    */
    c = 0;
    S_0007(first) {
        if (first)
        {
            console.log("Running in A Subroutine.");
        }
        if (!this.hasnext()) {
            this.goto(this.S_RETURN1);
        }
    };
    /*
        S_0009
    */
    S_0009(first) {
        if (first)
        {
            console.log("Count = ." + this.count );
        }
        if (!this.hasnext()) {
            this.goto(this.S_RETURN2);
        }
    };
    /*
        S_END
    */
    S_END(first) {
    }
    /*
        S_GOSUB1
    */
    S_GOSUB1(first) {
        this.gosubstate(this.S_SUBSTART1,this.S_LOOP1);
        this.setnowait();
    }
    /*
        S_LOOP1
        Loop 10 times
    */
    S_LOOP1(first) {
        this.count = 0;
        this.goto(this.S_LOOP1_LoopCheckAndGosub____);
        this.setnowait();
    }
    S_LOOP1_LoopCheckAndGosub____(first) {
        if (this.count < 10) this.gosubstate(this.S_SUBSTART2,this.S_LOOP1_LoopNext____);
        else               this.goto(this.S_END);
        this.setnowait();
    }
    S_LOOP1_LoopNext____(first) {
        this.count ++;
        this.goto(this.S_LOOP1_LoopCheckAndGosub____);
        this.setnowait();
    }
    /*
        S_RETURN1
    */
    S_RETURN1(first) {
        this.returnstate();
        this.setnowait();
    }
    /*
        S_RETURN2
    */
    S_RETURN2(first) {
        this.returnstate();
        this.setnowait();
    }
    /*
        S_START
    */
    S_START(first) {
        this.goto(this.S_GOSUB1);
        this.setnowait();
    }
    /*
        S_SUBSTART1
    */
    S_SUBSTART1(first) {
        this.goto(this.S_0007);
        this.setnowait();
    }
    /*
        S_SUBSTART2
    */
    S_SUBSTART2(first) {
        this.goto(this.S_0009);
        this.setnowait();
    }


    // [STATEGO OUTPUT END]
}
// == write your code ==

let obj = new testControl();
obj.run();

