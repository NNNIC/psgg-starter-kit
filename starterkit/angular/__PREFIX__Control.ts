import { StateManager } from './base/state-manager';

export class __PREFIX__Control extends StateManager {

    public start() {
        this.Goto(this.S_START);
    }
    public is_end() {
        return this.CheckState(this.S_END);
    }
    //                             [SYN-G-GEN OUTPUT START]   $/^[SE]_/$
    S_START(bFirst: boolean) {
        this.Goto(this.S_END);
    }
    S_END(bFirst : boolean) {        
    }
    //                             [SYN-G-GEN OUTPUT END]
    b_yesno: boolean;

    br_yes(st) {
      if (!this.HasNextState()) {
        if (this.b_yesno) {
          this.SetNext(st);
        }
      }
    }
    
    br_no(st) {
      if (!this.HasNextState()) {
        if (!this.b_yesno) {
          this.SetNext(st);
        }
      }
    }
  
    br_notAbove(st) {
      if (!this.HasNextState()) {
        this.SetNext(st);
      }
    }  
}
