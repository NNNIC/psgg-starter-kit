// == manager ==
var __PREFIX__Control = function() {
    this.curfunc   = null;
    this.nextfunc  = null;
    this.nowait    = false;    
};
__PREFIX__Control.prototype.update = function() {
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
__PREFIX__Control.prototype.checkstate = function(st) {
    return this.curfunc === st;
};
__PREFIX__Control.prototype.goto = function(st) {
    this.nextfunc = st;
};
__PREFIX__Control.prototype.hasnext = function() {
    return this.nextfunc!=null;
}
__PREFIX__Control.prototype.setnowait = function() {
    this.nowait = true;
}
__PREFIX__Control.prototype.start = function() {
    this.goto(this.S_START);
};
__PREFIX__Control.prototype.is_end = function() {
    return this.checkstate(this.S_END);
};
__PREFIX__Control.prototype.run = function() {
    var LOOPMAX = 100000;
    this.start();
    for(var loop = 0; loop <= LOOPMAX; loop++)
    {
        if (loop>=LOOPMAX) alert("Unexpected!");
        this.update();
        if (this.is_end()) break;
    }
};

// == yesno set ==
__PREFIX__Control.yesno=false;
__PREFIX__Control.prototype.br_yes = function(st) {
    if (!this.hasnext(st)) {
        if (this.yesno) {
            this.setnext(st);
        }
    }
};
__PREFIX__Control.prototype.br_no = function(st) {
    if (!this.hasnext(st)) {
        if (!this.yesno) {
            this.setnext(st);
        }
    }
};

// [SYN-G-GEN OUTPUT START] indent(0) $/./$
__PREFIX__Control.prototype.S_STATE = function(first) { this.goto(S_END); }
__PREFIX__Control.prototype.S_END   = function(first) { }
// [SYN-G-GEN OUTPUT END]

// == write your code ==

