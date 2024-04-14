// Fill out your copyright notice in the Description page of Project Settings.


#include "Test_Actor.h"

// ========================================== [STATE-GO OUTPUT START] indent(0) $/^[SE]_/->#inccpplist$
//             psggConverterLib.dll converted from psgg-file:Test_Actor.psgg                                        // *DoNotEdit*
                                                                            // *DoNotEdit*
//CPP側インクルード                                                         // *DoNotEdit*
                                                                            // *DoNotEdit*
// ========================================== [STATE-GO OUTPUT END]

// ========================================== [STATE-GO OUTPUT START] indent(0) $/^E_/$
//             psggConverterLib.dll converted from psgg-file:Test_Actor.psgg                                        // *DoNotEdit*
                                                                            // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    E_EMBED                                                                 // *DoNotEdit*
        UPROPERTY(VisibleAnywhere)                                          // *DoNotEdit*
        bool m_test;                                                        // *DoNotEdit*
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)    // *DoNotEdit*
        int m_max;                                                          // *DoNotEdit*
*/                                                                          // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    E_HEADERS                                                               // *DoNotEdit*
        //hpp側インクルール                                                 // *DoNotEdit*
        //参照class羅列                                                     // *DoNotEdit*
        //CPP側インクルード                                                 // *DoNotEdit*
    ヘッダ                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
// ========================================== [STATE-GO OUTPUT END]

// Sets default values
ATest_Actor::ATest_Actor() :
// ========================================== [STATE-GO OUTPUT START] indent(8) $/^[SE]_/->#constructlist$
        //             psggConverterLib.dll converted from psgg-file:Test_Actor.psgg                                // *DoNotEdit*
                                                                            // *DoNotEdit*
        m_i(0),                                                             // *DoNotEdit*
                                                                            // *DoNotEdit*
// ========================================== [STATE-GO OUTPUT END]
m_curstate(nullptr), m_nextstate(nullptr), m_bNoWait(false), m_callstack_level(0)
{
    for(int i = 0; i < CALL_STACK_MAX; i++) m_callstack[i] = nullptr;

    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
}


// Called when the game starts or when spawned
void ATest_Actor::BeginPlay()
{
	Super::BeginPlay();
    Start();
	
}

// Called every frame
void ATest_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (!IsEnd()) {
        Update();
    }
}

void ATest_Actor::_update()
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

void ATest_Actor::Start()
{
    Goto(&ATest_Actor::S_START);
}
bool ATest_Actor::IsEnd()
{
    return CheckState(&ATest_Actor::S_END);
}
void ATest_Actor::Update()
{
    _update();
}

// ========================================== [STATE-GO OUTPUT START] indent(0) $/^S_/$
//             psggConverterLib.dll converted from psgg-file:Test_Actor.psgg                                        // *DoNotEdit*
                                                                            // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0000                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATest_Actor::S_0000(bool bFirst)                                       // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        LOG("HELLO STATEGO");                                               // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&ATest_Actor::S_LOP000);                                       // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_0001                                                                  // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATest_Actor::S_0001(bool bFirst)                                       // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (bFirst)                                                             // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        LOG("HI!!!");                                                       // *DoNotEdit*
    }                                                                       // *DoNotEdit*
    if (!HasNextState())                                                    // *DoNotEdit*
    {                                                                       // *DoNotEdit*
        Goto(&ATest_Actor::S_RET000);                                       // *DoNotEdit*
    }                                                                       // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_END                                                                   // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATest_Actor::S_END(bool bFirst)                                        // *DoNotEdit*
{                                                                           // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_LOP000                                                                // *DoNotEdit*
        m_i(0)                                                              // *DoNotEdit*
        int m_i;                                                            // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATest_Actor::S_LOP000(bool bFirst)                                     // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_i = 0;                                                                // *DoNotEdit*
    Goto(&ATest_Actor::S_LOP000_LoopCheckAndGosub____);                     // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
void ATest_Actor::S_LOP000_LoopCheckAndGosub____(bool bFirst)               // *DoNotEdit*
{                                                                           // *DoNotEdit*
    if (m_i < 10) GoSubState(&ATest_Actor::S_SBS000,&ATest_Actor::S_LOP000_LoopNext____);                           // *DoNotEdit*
    else               Goto(&ATest_Actor::S_END);                           // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
void ATest_Actor::S_LOP000_LoopNext____(bool bFirst)                        // *DoNotEdit*
{                                                                           // *DoNotEdit*
    m_i++;                                                                  // *DoNotEdit*
    Goto(&ATest_Actor::S_LOP000_LoopCheckAndGosub____);                     // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_RET000                                                                // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATest_Actor::S_RET000(bool bFirst)                                     // *DoNotEdit*
{                                                                           // *DoNotEdit*
    ReturnState();                                                          // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_SBS000                                                                // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATest_Actor::S_SBS000(bool bFirst)                                     // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&ATest_Actor::S_0001);                                             // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
/*                                                                          // *DoNotEdit*
    S_START                                                                 // *DoNotEdit*
*/                                                                          // *DoNotEdit*
void ATest_Actor::S_START(bool bFirst)                                      // *DoNotEdit*
{                                                                           // *DoNotEdit*
    Goto(&ATest_Actor::S_0000);                                             // *DoNotEdit*
    NoWait();                                                               // *DoNotEdit*
}                                                                           // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
// ========================================== [STATE-GO OUTPUT END]
// write your code here!

