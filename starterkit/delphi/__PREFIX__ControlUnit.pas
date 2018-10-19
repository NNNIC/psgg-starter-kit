unit __PREFIX__ControlUnit;

interface

uses StateManagerUnit;

type __PREFIX__Control = class(StateManager)

  protected
    fbYesNo : boolean;
    procedure br_YES(const st: string);
    procedure br_NO(const st: string);

    // [SYN-G-GEN OUTPUT START] indent(4) $/^S_/->#declare$
    procedure S_START(const bFirst : boolean);
    procedure S_END(const bFirst : boolean);
    // [SYN-G-GEN OUTPUT END]

    procedure _execFunc(const st: string; bFirst : boolean); override;


    // For declare part of E_XXXX
    // [SYN-G-GEN OUTPUT START] indent(4) $/^E_/->#embdec$
    // [SYN-G-GEN OUTPUT END]

  public
    procedure Start; override;
    function  IsEnd : boolean; override;

end;

implementation

procedure __PREFIX__Control.br_YES(const st: string);
begin
    if HasNextState() = false then begin
        if fbYesNo = true then SetNextState(st);
    end;
end;

procedure __PREFIX__Control.br_NO(const st: string);
begin
    if HasNextState() = false then begin
        if fbYesNo = false then SetNextState(st);
    end;
end;

// [SYN-G-GEN OUTPUT START] indent(0) $/^S_/$
procedure __PREFIX__Control.S_START(const bFirst : boolean);
begin
  if bFirst=true then WriteLn('S_START');
  GotoState('S_END');
end;
procedure __PREFIX__Control.S_END(const bFirst : boolean);
begin
  if bFirst=true then WriteLn('S_END');
end;
// [SYN-G-GEN OUTPUT END]

// For declare part of E_XXX
// [SYN-G-GEN OUTPUT START] indent(0) $/^E_/$
// [SYN-G-GEN OUTPUT END]

procedure __PREFIX__Control._execFunc(const st: string; bFirst: Boolean);
label end_proc;
begin
  // [SYN-G-GEN OUTPUT START] indent(0) $/^S_/->#exec$
  if st = 'S_START' then begin S_START(bFirst); goto end_proc;  end;
  if st = 'S_END'   then begin S_END(bFirst);   goto end_proc;  end;
  // [SYN-G-GEN OUTPUT END]
  end_proc:
end;

procedure __PREFIX__Control.Start;
begin
  GotoState('S_START');
end;

function __PREFIX__Control.IsEnd;
begin
  Result := CheckState('S_END');
end;

end.
