unit StateManagerUnit;

interface

type StateManager = class
  private
    fCurState : string;
    fNextState: string;
    fTempState: string;

  public
    constructor Create;
    procedure Update();
    procedure GotoState(const st : string);
    function  CheckState(const st : string) : boolean;

    procedure SetNextState(const st : string);
    procedure GoNextState;
    function  HasNextState : boolean;

    procedure Start; virtual;
    function  IsEnd : boolean; virtual;

  protected
    procedure _execFunc(const st : string;  bFirst : boolean); virtual;


end;

implementation

constructor StateManager.Create;
begin
  fCurState  := '';
  fNextState := '';
  fTempState := '';
end;

procedure StateManager.Update;
var bFirst : boolean;
begin
  bFirst := false;

  if fNextState <> '' then
  begin
   fCurState  := fNextState;
   fNextState := '';
   bFirst    := true;
  end;
  if fCurState <> '' then
  begin
    _execFunc(fCurState, bFirst);
  end;
end;

procedure StateManager.GotoState(const st: string);
begin
  fNextState := st;
end;

function StateManager.CheckState(const st: string) : boolean;
begin
  Result := st = fCurState;
end;


procedure StateManager.SetNextState(const st: string);
begin
  fTempState := st;
end;

procedure StateManager.GoNextState;
begin
    fNextState := fTempState;
    fTempState := '';
end;

function StateManager.HasNextState;
begin
  Result := fTempState <> '';
end;

procedure StateManager.Start;
begin
end;

function StateManager.IsEnd : boolean;
begin
  Result := True;
end;


procedure StateManager._execFunc(const st: string; bFirst: Boolean);
begin
end;




end.
