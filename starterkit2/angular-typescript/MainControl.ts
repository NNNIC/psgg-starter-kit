import { StateManager } from "../state-manager";
import { StateProgramService } from './../state-program.service';

export class MainControl implements StateManager{

    sp: StateProgramService;
    public SetupSp(svc : any) { this.sp = svc; }

    //#region start of manager part
    public curstatename: string;
    public curstatecmt: string;

    public curstate : any;
    public nextstate : any;
    public candidatestate : any;
    public bNoWait : boolean;

    public bOutOfDate: boolean;

    public Goto(func: any) {
        this.nextstate = func;
    }

    public Update() : void {
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

    public CheckState(func:any): boolean {
        return this.curstate === func;
    }

    // Candidate and go
    public HasNextState(): boolean {
        return this.nextstate != null;
    }

    // non wait update
    public NoWait() : void {
        this.bNoWait = true;
    }

    // go subroutine
    private m_callstack : Array<any> = new Array<any>();
    public GoSubState(subst : any, nexst: any) : void {
        this.m_callstack.push(nexst);
        this.Goto(subst);
    }
    // subroutine return
    public ReturnState() : void {
        this.Goto(this.m_callstack.pop());
    }

    //#endregion  end of manager part

    public start() : void {
        this.Goto(this.S_START);
    }
    public is_end() : boolean {
        return this.CheckState(this.S_END);
    }
    //                             [PSGG OUTPUT START]   $/^[SE]_/$
//  psggConverterLib.dll converted from MainControl.xlsx.    psgg-file:MainControl.psgg
    /*
        S_ALERT
    */
    S_ALERT(bFirst: boolean) : void {
        if (bFirst) {
            this.curstatename = 'S_ALERT';
            // this.curstatecmt  = '';
            alert(" Calling from subroutine.");
        }
        if (!this.HasNextState()) {
            this.Goto(this.S_RETURN1);
        }
    }
    /*
        S_ALERT1
    */
    S_ALERT1(bFirst: boolean) : void {
        if (bFirst) {
            this.curstatename = 'S_ALERT1';
            // this.curstatecmt  = '';
            alert(" Calling from subroutine.\n Couny="+ this.m_count);
        }
        if (!this.HasNextState()) {
            this.Goto(this.S_RETURN2);
        }
    }
    /*
        S_END
    */
    S_END(bFirst: boolean) : void {
    }
    /*
        S_LOOP1
        ５回ループ
    */
    private m_count = 0;
    S_LOOP1(bFirst: boolean) : void {
        this.m_count = 0;
        this.Goto(this.S_LOOP1_LoopCheckAndGosub____);
        this.NoWait();
    }
    S_LOOP1_LoopCheckAndGosub____(bFirst: boolean) : void {
        if (this.m_count < 5) this.GoSubState(this.S_SUBSTART2,this.S_LOOP1_LoopNext____);
        else               this.Goto(this.S_END);
        this.NoWait();
    }
    S_LOOP1_LoopNext____(bFirst: boolean)  : void {
        this.m_count++;
        this.Goto(this.S_LOOP1_LoopCheckAndGosub____);
        this.NoWait();
    }
    /*
        S_RETURN1
    */
    S_RETURN1(bFirst: boolean) : void
    {
        this.ReturnState();
        this.NoWait();
    }
    /*
        S_RETURN2
    */
    S_RETURN2(bFirst: boolean) : void
    {
        this.ReturnState();
        this.NoWait();
    }
    /*
        S_START
    */
    S_START(bFirst: boolean) : void {
        this.Goto(this.S_TEST0011);
        this.NoWait();
    }
    /*
        S_SUBSTART1
    */
    S_SUBSTART1(bFirst: boolean) : void {
        this.Goto(this.S_ALERT);
        this.NoWait();
    }
    /*
        S_SUBSTART2
    */
    S_SUBSTART2(bFirst: boolean) : void {
        this.Goto(this.S_ALERT1);
        this.NoWait();
    }
    /*
        S_TEST0011
        サブルーチン
    */
    S_TEST0011(bFirst: boolean) : void {
        this.GoSubState(this.S_SUBSTART1,this.S_LOOP1);
        this.NoWait();
    }


    //                             [PSGG OUTPUT END]
}
