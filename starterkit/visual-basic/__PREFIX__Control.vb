Public Class __PREFIX__Control

    ' Manager
    Private m_curstate As String
    Private m_nextstate As String
    Private m_nowait As Boolean

    Public Sub New()
        m_curstate = ""
        m_nextstate = ""
    End Sub

    Public Sub Update()
        Dim bFirst As Boolean

        LoopUpdate:
        
        bFirst = False

        If m_nextstate <> "" Then 
            m_curstate = m_nextstate
            m_nextstate = ""
            bFirst = True
        End If

        m_nowait = False

        '[SYN-G-GEN OUTPUT START] indent(8) $/^S_/->#select$
        If m_curstate = "S_START" Then 
            S_START(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_END" Then 
            S_END(bFirst)
            Goto ExitUpdate
        End If
        '[SYN-G-GEN OUTPUT END]

        ExitUpdate:

        If m_nowait = True Then
            Goto LoopUpdate
        End If

    End Sub

    private Sub GotoState( state As String )
        m_nextstate = state
    End Sub

    private Function CheckState( state As String ) As Boolean
        If state = m_curstate Then
            Return True
        Else
            Return False
        End If
    End Function

    private Function HasNextState()
        If m_nextstate <> "" Then
            Return True
        Else
            Return False
        End If
    End Function

    private Sub SetNoWait()
        m_nowait = True
    End Sub

    public Sub Start()
        GotoState("S_START")
    End Sub

    public Function IsEnd() As Boolean
        If m_curstate = "S_END" Then
            Return True
        Else
            Return False
        End If
    End Function

    '[SYN-G-GEN OUTPUT START] indent(8) $/./$
    private Sub S_START( bFirst As Boolean )
        GotoState("S_END")
    End Sub
    private Sub S_END( bFirst As Boolean )
        '
    End Sub
    '[SYN-G-GEN OUTPUT END]

End Class