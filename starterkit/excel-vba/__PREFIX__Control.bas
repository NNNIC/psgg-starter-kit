Option Explicit

Dim g_cur As String

' [SYN-G-GEN OUTPUT START] indent(0) $/^E_/$
' [SYN-G-GEN OUTPUT END]


' 
Dim g_bYesNo As Boolean
Function br_YES(st As String)
    If g_cur = "" Then
        If g_bYesNo=True Then
            g_cur = st
        End If
    End If
End Function

Function br_NO(st As String)
    If g_cur = "" Then
        If g_bYesNo=False Then
            g_cur = st
        End If
    End If
End Function

'
Sub __PREFIX__Control()
    Dim lp As Integer
    g_cur = "S_START"
    For lp = 1 To 10000
        If g_cur = "S_END" Then
            Exit For
        
        ' [SYN-G-GEN OUTPUT START] indent(12) $/^S_/$
        ' [SYN-G-GEN OUTPUT END]
        Else
            'nothing to do
        End If
    Next

End Sub

