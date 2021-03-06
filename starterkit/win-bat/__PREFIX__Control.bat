@echo off
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

set YESNO=

goto :S_START

:: [PSGG OUTPUT START] $/./$
:S_START

:: [PSGG OUTPUT END]
echo : == END OF BATCH ==
:_end
