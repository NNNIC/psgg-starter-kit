Public Class TestControl

    ' Manager
    Private m_curstate As String
    Private m_nextstate As String
    Private m_nowait As Boolean
    Private g_cs() As String  ' call stack
    Private g_css As Integer ' call stack size

    Public Sub New()
        m_curstate = ""
        m_nextstate = ""
        g_css = 0
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

        Console.WriteLine("running .." + m_curstate)



        m_nowait = False

        '[SYN-G-GEN OUTPUT START] indent(8) $/^S_/->#select$
'  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
        If m_curstate = "S_0004" Then
            S_0004(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_0005" Then
            S_0005(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_0009" Then
            S_0009(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_A_SUBSTART" Then
            S_A_SUBSTART(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_B_SUBSTART" Then
            S_B_SUBSTART(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_B_SUBSTART1" Then
            S_B_SUBSTART1(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_CHECK_EVEN_OR_ODD" Then
            S_CHECK_EVEN_OR_ODD(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_END" Then
            S_END(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_EVEN" Then
            S_EVEN(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_GOSUB1" Then
            S_GOSUB1(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_GOSUB3" Then
            S_GOSUB3(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_LOOP1" Then
            S_LOOP1(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_LOOP1_LoopCheckAndGosub____" Then
            S_LOOP1_LoopCheckAndGosub____(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_LOOP1_LoopNext____" Then
            S_LOOP1_LoopNext____(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_ODD" Then
            S_ODD(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_RETURN1" Then
            S_RETURN1(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_RETURN3" Then
            S_RETURN3(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_RETURN4" Then
            S_RETURN4(bFirst)
            Goto ExitUpdate
        End If
        If m_curstate = "S_START" Then
            S_START(bFirst)
            Goto ExitUpdate
        End If


        '[SYN-G-GEN OUTPUT END]

ExitUpdate:

        If m_nowait = True Then
            GoTo LoopUpdate
        End If

    End Sub

    Private Sub GotoState(state As String)
        m_nextstate = state
    End Sub

    Private Function CheckState(state As String) As Boolean
        If state = m_curstate Then
            Return True
        Else
            Return False
        End If
    End Function

    Private Function HasNextState()
        If m_nextstate <> "" Then
            Return True
        Else
            Return False
        End If
    End Function

    Private Sub NoWait()
        m_nowait = True
    End Sub

    Public Sub Start()
        GotoState("S_START")
    End Sub

    Public Function IsEnd() As Boolean
        If m_curstate = "S_END" Then
            Return True
        Else
            Return False
        End If
    End Function

    '[SYN-G-GEN OUTPUT START] indent(8) $/./$
'  psggConverterLib.dll converted from TestControl.xlsx.    psgg-file:TestControl.psgg
        '    E_0005
        '
        Dim i As Integer
        '    S_0004
        '
        Sub S_0004(bFirst As Boolean)
            if bFirst = True Then
                Console.WriteLine("I am in A routine.")
            End If
            If HasNextState() = False Then
                GotoState("S_GOSUB3")
            End If
        End Sub
        '    S_0005
        '
        Sub S_0005(bFirst As Boolean)
            if bFirst = True Then
                Console.WriteLine("START")
            End If
            If HasNextState() = False Then
                GotoState("S_GOSUB1")
            End If
        End Sub
        '    S_0009
        '
        Sub S_0009(bFirst As Boolean)
            if bFirst = True Then
                Console.WriteLine("I am in B routine.")
            End If
            If HasNextState() = False Then
                GotoState("S_RETURN3")
            End If
        End Sub
        '    S_A_SUBSTART
        '
        Sub S_A_SUBSTART(bFirst As Boolean)
            GotoState("S_0004")
            NoWait()
        End Sub
        '    S_B_SUBSTART
        '
        Sub S_B_SUBSTART(bFirst As Boolean)
            GotoState("S_0009")
            NoWait()
        End Sub
        '    S_B_SUBSTART1
        '
        Sub S_B_SUBSTART1(bFirst As Boolean)
            GotoState("S_CHECK_EVEN_OR_ODD")
            NoWait()
        End Sub
        '    S_CHECK_EVEN_OR_ODD
        '
        Sub S_CHECK_EVEN_OR_ODD(bFirst As Boolean)
            Dim n As Integer = i Mod 2
            ' branch
            If n = 0 Then
                m_nextstate = "S_EVEN"
            Else
                m_nextstate = "S_ODD"
            End If
        End Sub
        '    S_END
        '
        Sub S_END(bFirst As Boolean)
            ' nothing
        End Sub
        '    S_EVEN
        '
        Sub S_EVEN(bFirst As Boolean)
            if bFirst = True Then
                Console.WriteLine("count = " + i .ToString() + "(EVEN)")
            End If
            If HasNextState() = False Then
                GotoState("S_RETURN4")
            End If
        End Sub
        '    S_GOSUB1
        '
        Sub S_GOSUB1(bFirst As Boolean)
            g_css = g_css + 1
            ReDim Preserve g_cs(g_css)
            g_cs(g_css) = "S_LOOP1"
            GotoState("S_A_SUBSTART")
            NoWait()
        End Sub
        '    S_GOSUB3
        '
        Sub S_GOSUB3(bFirst As Boolean)
            g_css = g_css + 1
            ReDim Preserve g_cs(g_css)
            g_cs(g_css) = "S_RETURN1"
            GotoState("S_B_SUBSTART")
            NoWait()
        End Sub
        '    S_LOOP1
        '
        Sub S_LOOP1(bFirst As Boolean)
            i = 0
            GotoState("S_LOOP1_LoopCheckAndGosub____")
            NoWait()
        End Sub
        Sub S_LOOP1_LoopCheckAndGosub____(bFirst As Boolean)
            if i < 10 Then
                g_css = g_css + 1
                ReDim Preserve g_cs(g_css)
                g_cs(g_css) = "S_LOOP1_LoopNext____"
                GotoState("S_B_SUBSTART1")
            Else
                GotoState("S_END")
            End If
            NoWait()
        End Sub
        Sub S_LOOP1_LoopNext____(bFirst As Boolean)
            i = i + 1
            GotoState("S_LOOP1_LoopCheckAndGosub____")
            NoWait()
        End Sub
        '    S_ODD
        '
        Sub S_ODD(bFirst As Boolean)
            if bFirst = True Then
                Console.WriteLine("count = " + i .ToString() + "(ODD)")
            End If
            If HasNextState() = False Then
                GotoState("S_RETURN4")
            End If
        End Sub
        '    S_RETURN1
        '
        Sub S_RETURN1(bFirst As Boolean)
            GotoState(g_cs(g_css))
            g_css = g_css - 1
            ReDim Preserve g_cs(g_css)
            NoWait()
        End Sub
        '    S_RETURN3
        '
        Sub S_RETURN3(bFirst As Boolean)
            GotoState(g_cs(g_css))
            g_css = g_css - 1
            ReDim Preserve g_cs(g_css)
            NoWait()
        End Sub
        '    S_RETURN4
        '
        Sub S_RETURN4(bFirst As Boolean)
            GotoState(g_cs(g_css))
            g_css = g_css - 1
            ReDim Preserve g_cs(g_css)
            NoWait()
        End Sub
        '    S_START
        '
        Sub S_START(bFirst As Boolean)
            GotoState("S_0005")
            NoWait()
        End Sub


    '[SYN-G-GEN OUTPUT END]

End Class