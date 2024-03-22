// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

#define LOG(STR) UE_LOG(LogTemp, Log, TEXT(STR))
#define ERROR(STR) UE_LOG(LogTemp, Error, TEXT(STR))

UCLASS()
class UPROJECT_API ATestActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	// STATEGO FRAMEWORK
	typedef void (ATestActor::* FUNCPTR)(bool);

	FUNCPTR m_curstate;
	FUNCPTR m_nextstate;
	bool   m_bNoWait;

	static const int CALL_STACK_MAX = 10;
	FUNCPTR m_callstack[CALL_STACK_MAX];
	int m_callstack_level;

	void _update();
    inline void Goto(FUNCPTR st) { m_nextstate = st; }
    inline bool CheckState(FUNCPTR st) { return m_curstate == st; }
    inline bool HasNextState() { return m_nextstate != nullptr; }
    inline void NoWait() { m_bNoWait = true; }
    inline void GoSubState(FUNCPTR sb, FUNCPTR nt)
    {
        if (m_callstack_level >= CALL_STACK_MAX - 1)
        {
            LOG("CALL STACK OVER FLOW\n");
            //exit(1);
        }
        m_callstack[m_callstack_level++] = nt;
        Goto(sb);
    }
    inline void ReturnState()
    {
        if (m_callstack_level <= 0)
        {
            LOG("CALL STACK UNDER FLOW\n");
        }
        else {
            m_callstack_level--;
            FUNCPTR st = this->m_callstack[m_callstack_level];
            Goto(st);
        }
    }
public:
	void Start();
	bool IsEnd();
	void Update();

//  Member codes  #1                         [STATE-GO OUTPUT START] indent(4) $/^S_/->#memberlist$
    //             psggConverterLib.dll converted from psgg-file:TestActor.psgg                                     // *DoNotEdit*
                                                                            // *DoNotEdit*
    int m_i;                                                                // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]
//  Member codes  #2                         [STATE-GO OUTPUT START] indent(4) $/^E_/->#memberlist$
    //             psggConverterLib.dll converted from psgg-file:TestActor.psgg                                     // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]


//  API declaration                          [STATE-GO OUTPUT START] indent(4) $/^S_/->#declare$
    //             psggConverterLib.dll converted from psgg-file:TestActor.psgg                                     // *DoNotEdit*
                                                                            // *DoNotEdit*
    void S_0000(bool bFirst);                                               // *DoNotEdit*
    void S_0001(bool bFirst);                                               // *DoNotEdit*
    void S_END(bool bFirst);                                                // *DoNotEdit*
    void S_LOP000(bool bFirst);                                             // *DoNotEdit*
    void S_LOP000_LoopCheckAndGosub____(bool bFirst);                       // *DoNotEdit*
    void S_LOP000_LoopNext____(bool bFirst);                                // *DoNotEdit*
    void S_RET000(bool bFirst);                                             // *DoNotEdit*
    void S_SBS000(bool bFirst);                                             // *DoNotEdit*
    void S_START(bool bFirst);                                              // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
//                                           [STATE-GO OUTPUT END]


};
