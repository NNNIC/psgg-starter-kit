#include "Test1Control.hpp"

using namespace std;

void Test1Control::_update()
{
        while(true) {
            bool bFirst =false;
            m_bNoWait = false;
            if (m_nextstate != nullptr) {
                m_curstate  = m_nextstate;
                m_nextstate = nullptr;
                bFirst = true;
            }
            if (m_curstate != nullptr) {
                (this->*m_curstate)(bFirst);
            }
            if (!m_bNoWait) break;
        }	
}

void Test1Control::Start()
{
	 Goto(&Test1Control::S_START);
}
bool Test1Control::IsEnd()
{
	 return CheckState(&Test1Control::S_END);
}
void Test1Control::Update() 
{
	_update();
}

//  states                                   [STATE-GO OUTPUT START] indent(0) $/^S_/$
//             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                      // *DoNotEdit*
                                                                            // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0001                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_0001(bool bFirst)                                      // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        printf_s("A state-machine is running\n");                           // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&Test1Control::S_GOSUB);                                       // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_END                                                                   // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_END(bool bFirst)                                       // *DoNotEdit*
{                                                                           // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_EVEN_OR_ODD                                                           // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_EVEN_OR_ODD(bool bFirst)                               // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (m_i % 2 == 0) { Goto( &Test1Control::S_PRINT_EVEN ); }              // *DoNotEdit*
    else { Goto( &Test1Control::S_PRINT_ODD ); }                            // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_GOSUB                                                                 // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_GOSUB(bool bFirst)                                     // *DoNotEdit*
{                                                                           // *DoNotEdit*
    GoSubState(&Test1Control::S_SUBSTART1,&Test1Control::S_LOOP);           // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_LOOP                                                                  // *DoNotEdit*
    Loop 10 times                                                           // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_LOOP(bool bFirst)                                      // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_i=0;                                                                  // *DoNotEdit*
    Goto(&Test1Control::S_LOOP_LoopCheckAndGosub____);                      // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
void Test1Control::S_LOOP_LoopCheckAndGosub____(bool bFirst)                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (m_i < 10) GoSubState(&Test1Control::S_SUBSTART,&Test1Control::S_LOOP_LoopNext____);                         // *DoNotEdit*
    else               Goto(&Test1Control::S_END);                          // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
void Test1Control::S_LOOP_LoopNext____(bool bFirst)                         // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_i++;                                                                  // *DoNotEdit*
    Goto(&Test1Control::S_LOOP_LoopCheckAndGosub____);                      // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_PRINT_EVEN                                                            // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_PRINT_EVEN(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        printf_s("Count : %d (EVEN)\n",m_i);                                // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&Test1Control::S_SUBRETURN);                                   // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_PRINT_ODD                                                             // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_PRINT_ODD(bool bFirst)                                 // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        printf_s("Count : %d (ODD)\n",m_i);                                 // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&Test1Control::S_SUBRETURN);                                   // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_START                                                                 // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_START(bool bFirst)                                     // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&Test1Control::S_0001);                                            // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SUBRETURN                                                             // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_SUBRETURN(bool bFirst)                                 // *DoNotEdit*
{                                                                           // *DoNotEdit*
    ReturnState();                                                          // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SUBRETURN1                                                            // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_SUBRETURN1(bool bFirst)                                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    ReturnState();                                                          // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SUBSTART                                                              // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_SUBSTART(bool bFirst)                                  // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&Test1Control::S_EVEN_OR_ODD);                                     // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SUBSTART1                                                             // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_SUBSTART1(bool bFirst)                                 // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&Test1Control::S_WORK);                                            // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_WORK                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void Test1Control::S_WORK(bool bFirst)                                      // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        printf_s("A subroutine is running.\n");                             // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&Test1Control::S_SUBRETURN1);                                  // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]


// write your code here!

