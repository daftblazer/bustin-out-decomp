#ifndef ENGINE_STATEMACHINE_H
#define ENGINE_STATEMACHINE_H

#include <deque>
#include <vector>

// State machine classes. Class and method names come from The Sims 2's symbol
// map; member names and the base class name are provisional.

class StateMachineState;
class StateMachineManager;

// 0x18 bytes
class StateMachineStatus {
public:
    StateMachineStatus() : mCurState(0), unk14(0.0f), unk4(0), unk8(0), unkC(0), unk10(0.0f) {}

    StateMachineState* mCurState; // 0x0
    int unk4;
    int unk8;
    int unkC;
    float unk10;
    float unk14;
};

// Polymorphic base of StateMachine: 0x10 bytes of data, then the vtable pointer.
class StateMachineBase {
public:
    StateMachineBase() : unk8(-1), unk0(0), unk4(0), unkC(1) {}
    virtual ~StateMachineBase();
    virtual void Startup(); // slot 2

    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

// 0x7C bytes
class StateMachine : public StateMachineBase {
public:
    StateMachine(int id) : mId(id), mManager(0), unk1C(0), unk20(0.0f) {}
    virtual ~StateMachine();
    virtual void Startup();

    int mId;                                   // 0x14
    StateMachineManager* mManager;             // 0x18
    int unk1C;
    float unk20;
    std::vector<StateMachineState*> mStates;   // 0x24
    StateMachineStatus mStatus;                // 0x34
    std::deque<StateMachineStatus*> mStack;    // 0x4C
};

class StateMachineManager {
public:
    static void Startup();
    static void Shutdown();
    StateMachine* FindMachine(StateMachine* machine);

    // The original reloads the global manager pointer inside this function
    // rather than using `this`, which is only used for mManager.
    void AddMachine(StateMachine* machine);

    std::vector<StateMachine*> mMachines; // 0x0
};

extern StateMachineManager* lbl_8037D93C;

inline void StateMachineManager::AddMachine(StateMachine* machine) {
    if (machine && !lbl_8037D93C->FindMachine(machine)) {
        lbl_8037D93C->mMachines.push_back(machine);
        machine->mManager = this;
        machine->Startup();
    }
}

#endif
