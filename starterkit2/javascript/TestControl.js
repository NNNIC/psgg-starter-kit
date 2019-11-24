// == manager ==
var TestControl = function() {
    this.curfunc   = null;
    this.nextfunc  = null;
    this.nowait    = false;
    
    this.callstack = [];
};
TestControl.prototype.update = function() {
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
};
TestControl.prototype.checkstate = function(st) {
    return this.curfunc === st;
};
TestControl.prototype.goto = function(st) {
    this.nextfunc = st;
};
TestControl.prototype.hasnext = function() {
    return this.nextfunc!=null;
}
TestControl.prototype.setnowait = function() {
    this.nowait = true;
}
TestControl.prototype.start = function() {
    this.goto(this.S_START);
};
TestControl.prototype.is_end = function() {
    return this.checkstate(this.S_END);
};
TestControl.prototype.run = function() {
    var LOOPMAX = 100000;
    this.start();
    for(var loop = 0; loop <= LOOPMAX; loop++)
    {
        if (loop>=LOOPMAX) alert("Unexpected!");
        this.update();
        if (this.is_end()) break;
    }
};
TestControl.prototype.gosubstate = function(sb,nt) {
    this.callstack.push(nt);
    this.goto(sb);
};
TestControl.prototype.returnstate = function() {
    this.goto(this.callstack.pop());
};

// [STATEGO OUTPUT START] indent(0) $/./$
//  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
/*
    S_0007
*/
TestControl.prototype.S_0007 = function(first) {
    if (first)
    {
        alert("Running in A Subroutine.");
    }
    if (!this.hasnext()) {
        this.goto(this.S_RETURN1);
    }
};
/*
    S_0009
*/
TestControl.prototype.S_0009 = function(first) {
    if (first)
    {
        alert("Count = ." + this.count );
    }
    if (!this.hasnext()) {
        this.goto(this.S_RETURN2);
    }
};
/*
    S_END
*/
TestControl.prototype.S_END = function(first) {
};
/*
    S_GOSUB1
*/
TestControl.prototype.S_GOSUB1 = function(first) {
    this.gosubstate(this.S_SUBSTART1,this.S_LOOP1);
    this.setnowait();
};
/*
    S_LOOP1
    Loop 10 times
*/
TestControl.prototype.S_LOOP1 = function(first) {
    this.count = 0;
    this.goto(this.S_LOOP1_LoopCheckAndGosub____);
    this.setnowait();
};
TestControl.prototype.S_LOOP1_LoopCheckAndGosub____ = function(first) {
    if (this.count < 10) this.gosubstate(this.S_SUBSTART2,this.S_LOOP1_LoopNext____);
    else               this.goto(this.S_END);
    this.setnowait();
};
TestControl.prototype.S_LOOP1_LoopNext____ = function(first) {
    this.count ++;
    this.goto(this.S_LOOP1_LoopCheckAndGosub____);
    this.setnowait();
};
/*
    S_RETURN1
*/
TestControl.prototype.S_RETURN1 = function(first) {
    this.returnstate();
    this.setnowait();
};
/*
    S_RETURN2
*/
TestControl.prototype.S_RETURN2 = function(first) {
    this.returnstate();
    this.setnowait();
};
/*
    S_START
*/
TestControl.prototype.S_START = function(first) {
    this.goto(this.S_GOSUB1);
    this.setnowait();
};
/*
    S_SUBSTART1
*/
TestControl.prototype.S_SUBSTART1 = function(first) {
    this.goto(this.S_0007);
    this.setnowait();
};
/*
    S_SUBSTART2
*/
TestControl.prototype.S_SUBSTART2 = function(first) {
    this.goto(this.S_0009);
    this.setnowait();
};


// [STATEGO OUTPUT END]

// == write your code ==

