@echo off
set STACKNUM=0
goto :_main

:::: MACRO START ::::
:psgg-macro-start

; commentline format  {%0} will be replaced to a comment.
commentline=::  {%0}

@branch=@@@
<<<?"{%0}"/^brif$/
if [[brcond:{%N}]]  goto :{%1}
>>>
<<<?"{%0}"/^brifc$/
if [[brcond:{%N}]] (
    goto :{%1}
>>>
<<<?"{%0}"/^brelseif$/
) else if [[brcond:{%N}]]  goto :{%1}
>>>
<<<?"{%0}"/^brelseifc$/
) else if [[brcond:{%N}]] (
    goto :{%1}
>>>
<<<?"{%0}"/^brelse$/
) else goto :{%1}
>>>
<<<?"{%0}"/^br_/
$macro:{%0}({%1})$
>>>
@@@

br_YES=@@@
:: br_YES
 if "%YESNO%"=="YES" GOTO :{%1}
@@@

br_NO=@@@
:: br_NO
if not "%YESNO%"=="YES" GOTO :{%1}
@@@

:psgg-macro-end
:::: MACRO END ::::

:_main
cd /d %~dp0

echo : == START OF BATCH ==

goto :S_START

:: [PSGG OUTPUT START] $/./$
    ::              psggConverterLib.dll converted from psgg-file:MainControl.psgg

    ::
    :S_0001
    ::
    ::
    ::
        echo : we are in A subroutine
        goto :S_RETURN1
        goto :S_0001
    ::
    :S_0002
    ::
    ::
    ::
        echo : EVEN NUMBER = %LOOP%
        goto :S_RETURN2
        goto :S_0002
    ::
    :S_0003
    ::
    ::
    ::
        echo : ODD NUMBER = %LOOP%
        goto :S_RETURN2
        goto :S_0003
    ::
    :S_END
    ::
    ::
    ::
        goto :_end
    ::
    :S_GOSUB1
    ::
    ::
    ::
        set CALLSTACK_%STACKNUM%=S_LOOP1
        set /a STACKNUM=%STACKNUM%+1
        goto :S_SUBSTART1
    ::
    :S_LOOP1
    ::
    :: Loop 10 times
    ::
        set LOOP=0
        goto :S_LOOP1_LoopCheckAndGosub____
    :S_LOOP1_LoopCheckAndGosub____
        if %LOOP% LSS 10 (
            set CALLSTACK_%STACKNUM%=S_LOOP1_LoopNext____
            set /a STACKNUM=%STACKNUM%+1
            goto :S_SUBSTART2
        ) ELSE (
            goto :S_END
        )
    :S_LOOP1_LoopNext____
        set /a LOOP=%LOOP%+1
        goto :S_LOOP1_LoopCheckAndGosub____
    ::
    :S_ODD_OR_EVEN
    ::
    ::
    ::
        set /a b=%LOOP% %% 2
        if %b%==0 (
            goto :S_0002
        ) else goto :S_0003
        goto :S_ODD_OR_EVEN
    ::
    :S_RETURN1
    ::
    ::
    ::
        set /a STACKNUM=%STACKNUM%-1
        set CALLSTACK_%STACKNUM% >~tmp.txt
        set _tmp=
        for /f "tokens=1,2 delims==" %%i in (~tmp.txt) do set _tmp=%%j
        set CALLSTACK_%STACKNUM%=
        del ~tmp.txt 2>nul
        goto :%_tmp%
    ::
    :S_RETURN2
    ::
    ::
    ::
        set /a STACKNUM=%STACKNUM%-1
        set CALLSTACK_%STACKNUM% >~tmp.txt
        set _tmp=
        for /f "tokens=1,2 delims==" %%i in (~tmp.txt) do set _tmp=%%j
        set CALLSTACK_%STACKNUM%=
        del ~tmp.txt 2>nul
        goto :%_tmp%
    ::
    :S_START
    ::
    ::
    ::
        goto :S_GOSUB1
    ::
    :S_SUBSTART1
    ::
    ::
    ::
        goto :S_0001
        goto :S_SUBSTART1
    ::
    :S_SUBSTART2
    ::
    ::
    ::
        goto :S_ODD_OR_EVEN
        goto :S_SUBSTART2


:: [PSGG OUTPUT END]
echo : == END OF BATCH ==
:_end
pause
