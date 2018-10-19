export class StateManager {

    public curstatename: string;
    public curstatecmt: string;

    public curstate;
    public nextstate;
    public candidatestate;
    public bNoWait;

    public bOutOfDate;

    public constructor() {
        this.bOutOfDate = false;
    }

    public Goto(func) {
        this.nextstate = func;
    }

    public Update() {
        if (this.bOutOfDate) { return; }

        while (true) {
            this.bNoWait = false;
            this._update();
            if (this.bNoWait) {
                continue;
            } else {
                break;
            }
        }
    }
    private _update() {
        if (this.bOutOfDate) { return; }

        let bFirst = false;
        if (this.nextstate != null) {
            this.curstate  = this.nextstate;
            this.nextstate = null;
            bFirst = true;
        }

        if (this.curstate != null) {
            this.curstate(bFirst);
        }

         if (bFirst) {
            console.log(this.curstatename);
         }
         
    }

    public CheckState(func): boolean {
        return this.curstate === func;
    }

    // Candidate and go
    public SetNext(func) {
        this.candidatestate = func;
    }
    public GoNext() {
        this.nextstate = this.candidatestate;
        this.candidatestate = null;
    }
    public HasNextState(): boolean {
        return this.candidatestate != null;
    }

    // non wait update
    public NoWait() {
        this.bNoWait = true;
    }

    // 管理の期限切れ
    public OutOfDate() {
        this.bOutOfDate = true;
    }
}
