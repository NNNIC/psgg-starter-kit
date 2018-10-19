// == manager ==
var __PREFIX__Control = function() {
    this.curfunc   = null;
    this.nextfunc  = null;
    this.candfunc  = null;
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
    return this.candfunc === st;
};
__PREFIX__Control.prototype.goto = function(st) {
    this.nextfunc = st;
};
__PREFIX__Control.prototype.setnext = function(st) {
    this.candfunc = st;
}
__PREFIX__Control.prototype.gonext = function() {
    this.nextfunc = this.candfunc;
    this.candfunc = null;
}
__PREFIX__Control.prototype.hasnext = function() {
    return this.candfunc!=null;
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

// [SYN-G-GEN OUTPUT START] $/./$
__PREFIX__Control.prototype.S_STATE = function(first) { this.goto(S_END); }
__PREFIX__Control.prototype.S_END   = function(first) { }
// [SYN-G-GEN OUTPUT END]

// == write your code ==

