// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

//  Embed codes                              [STATE-GO OUTPUT START] indent(0) $/^E_/$
//             psggConverterLib.dll converted from psgg-file:TestActor.psgg // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]

// Sets default values
ATestActor::ATestActor() :
    //  construction codes                       [STATE-GO OUTPUT START] indent(8) $/^S_/->#constructlist$
        //             psggConverterLib.dll converted from psgg-file:TestActor.psgg                                 // *DoNotEdit*
                                                                            // *DoNotEdit*
        m_i(0),                                                             // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]
m_curstate(nullptr), m_nextstate(nullptr), m_bNoWait(false), m_callstack_level(0)
{
    for(int i = 0; i < CALL_STACK_MAX; i++) m_callstack[i] = nullptr;

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
    Start();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!IsEnd()) {
        Update();
    }
}

void ATestActor::_update()
{
    while (true) {
        bool bFirst = false;
        m_bNoWait = false;
        if (m_nextstate != nullptr) {
            m_curstate = m_nextstate;
            m_nextstate = nullptr;
            bFirst = true;
        }
        if (m_curstate != nullptr) {
            (this->*m_curstate)(bFirst);
        }
        if (!m_bNoWait) break;
    }
}

void ATestActor::Start()
{
    Goto(&ATestActor::S_START);
}
bool ATestActor::IsEnd()
{
    return CheckState(&ATestActor::S_END);
}
void ATestActor::Update()
{
    _update();
}

//  states                                   [STATE-GO OUTPUT START] indent(0) $/^S_/$
//             psggConverterLib.dll converted from psgg-file:TestActor.psgg // *DoNotEdit*
                                                                            // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0000                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATestActor::S_0000(bool bFirst)                                        // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        LOG("HELLO STATEGO");                                               // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&ATestActor::S_LOP000);                                        // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0001                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATestActor::S_0001(bool bFirst)                                        // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        LOG("HI!!!");                                                       // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&ATestActor::S_RET000);                                        // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_END                                                                   // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATestActor::S_END(bool bFirst)                                         // *DoNotEdit*
{                                                                           // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_LOP000                                                                // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATestActor::S_LOP000(bool bFirst)                                      // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_i = 0;                                                                // *DoNotEdit*
    Goto(&ATestActor::S_LOP000_LoopCheckAndGosub____);                      // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
void ATestActor::S_LOP000_LoopCheckAndGosub____(bool bFirst)                // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (m_i < 10) GoSubState(&ATestActor::S_SBS000,&ATestActor::S_LOP000_LoopNext____);                             // *DoNotEdit*
    else               Goto(&ATestActor::S_END);                            // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
void ATestActor::S_LOP000_LoopNext____(bool bFirst)                         // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_i++;                                                                  // *DoNotEdit*
    Goto(&ATestActor::S_LOP000_LoopCheckAndGosub____);                      // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_RET000                                                                // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATestActor::S_RET000(bool bFirst)                                      // *DoNotEdit*
{                                                                           // *DoNotEdit*
    ReturnState();                                                          // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SBS000                                                                // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATestActor::S_SBS000(bool bFirst)                                      // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&ATestActor::S_0001);                                              // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_START                                                                 // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATestActor::S_START(bool bFirst)                                       // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&ATestActor::S_0000);                                              // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]
// write your code here!