Option Explicit

Dim g_cur As String
Dim g_cs() As String  ' call stack
Dim g_css As Integer ' call stack size
' [SYN-G-GEN OUTPUT START] indent(0) $/^E_/$
'  psggConverterLib.dll converted from TestContro.xlsx.    psgg-file:TestContro.psgg
Dim i As Integer

' [SYN-G-GEN OUTPUT END]
' 

'
Sub TestContro()
    Dim lp As Integer
    g_cur = "S_START"
    g_css = 0
    For lp = 1 To 10000
        If g_cur = "S_END" Then
            Exit For
        
        ' [SYN-G-GEN OUTPUT START] indent(12) $/^S_/$
'  psggConverterLib.dll converted from TestContro.xlsx.    psgg-file:TestContro.psgg
            ElseIf g_cur = "S_0003" Then 'S_0003 :
                i = 0
                g_cur = "S_0003_LoopCheckAndGosub____"
            ElseIf g_cur = "S_0003_LoopCheckAndGosub____" Then
                if i < 10 Then
                    g_css = g_css + 1
                    ReDim Preserve g_cs(g_css)
                    g_cs(g_css) = "S_0003_LoopNext____"
                    g_cur = "S_LOOP_SUBSTART"
                Else
                    g_cur = "S_GOSUB1"
                EndIf
            ElseIf g_cur = "S_0003_LoopNext____" Then
                i = i + 1
                g_cur = "S_0003_LoopCheckAndGosub____"
            ElseIf g_cur = "S_0004" Then 'S_0004 :
                g_cur = ""
                '
                Debug.Print "I'm in A Subroutine"
                If g_cur = "" Then
                    g_cur = "S_GOSUB3"
                EndIf
            ElseIf g_cur = "S_0005" Then 'S_0005 :
                g_cur = ""
                '
                Debug.Print "Start"
                If g_cur = "" Then
                    g_cur = "S_0003"
                EndIf
            ElseIf g_cur = "S_0006" Then 'S_0006 :
                g_cur = ""
                '
                Debug.Print "End"
                If g_cur = "" Then
                    g_cur = "S_END"
                EndIf
            ElseIf g_cur = "S_0007" Then 'S_0007 :
                g_cur = ""
                '
                Debug.Print "i = "; i
                If g_cur = "" Then
                    g_cur = "S_LOOP_SUBRETURN"
                EndIf
            ElseIf g_cur = "S_0009" Then 'S_0009 :
                g_cur = ""
                '
                Debug.Print "I'm in B Subroutine"
                If g_cur = "" Then
                    g_cur = "S_RETURN3"
                EndIf
            ElseIf g_cur = "S_A_SUBSTART" Then 'S_A_SUBSTART :
                g_cur = "S_0004"
            ElseIf g_cur = "S_B_SUBSTART" Then 'S_B_SUBSTART :
                g_cur = "S_0009"
            ElseIf g_cur = "S_END" Then 'S_END : END
                g_cur = ""
            ElseIf g_cur = "S_GOSUB1" Then 'S_GOSUB1 : Go A Souroutine
                g_css = g_css + 1
                ReDim Preserve g_cs(g_css)
                g_cs(g_css) = "S_0006"
                g_cur = "S_A_SUBSTART"
            ElseIf g_cur = "S_GOSUB3" Then 'S_GOSUB3 : Go B Souroutine
                g_css = g_css + 1
                ReDim Preserve g_cs(g_css)
                g_cs(g_css) = "S_RETURN1"
                g_cur = "S_B_SUBSTART"
            ElseIf g_cur = "S_LOOP_SUBRETURN" Then 'S_LOOP_SUBRETURN :
                g_cur = g_cs(g_css)
                g_css = g_css - 1
                ReDim Preserve g_cs(g_css)
            ElseIf g_cur = "S_LOOP_SUBSTART" Then 'S_LOOP_SUBSTART :
                g_cur = "S_0007"
            ElseIf g_cur = "S_RETURN1" Then 'S_RETURN1 :
                g_cur = g_cs(g_css)
                g_css = g_css - 1
                ReDim Preserve g_cs(g_css)
            ElseIf g_cur = "S_RETURN3" Then 'S_RETURN3 :
                g_cur = g_cs(g_css)
                g_css = g_css - 1
                ReDim Preserve g_cs(g_css)
            ElseIf g_cur = "S_START" Then 'S_START : START
                g_cur = "S_0005"


        ' [SYN-G-GEN OUTPUT END]
        Else
            'nothing to do
        End If
    Next

End Sub

