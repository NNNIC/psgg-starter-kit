@echo off
cd /d %~dp0

echo : == START OF BATCH ==

set YESNO=

goto :S_START

:: [SYN-G-GEN OUTPUT START] $/./$
:S_START

:: [SYN-G-GEN OUTPUT END]
echo : == END OF BATCH ==
:_end
