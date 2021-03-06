#pragma once
#include "CTaskComplex.h"

class CTaskComplexUseSequence : public CTaskComplex
{
public:
    int m_nSequenceIndex;         // Used in CTaskSequences::ms_taskSequence global array
    int m_nCurrentTaskIndex;      // Used in CTaskComplexSequence::m_aTasks array
    int m_nEndTaskIndex;          // Sequence will stop performing tasks when current index is equal to endTaskIndex
    int m_nSequenceRepeatedCount; // m_nSequenceRepeatedCount simply tells us how many times the sequence has been repeated.
                                  // If CTaskComplexSequence::m_bRepeatSequence is true, this can be greater than 1, 
                                  // otherwise it's set to 1 when the sequence is done executing tasks.

    CTask* Clone() override;
    eTaskType GetId() override;
    bool MakeAbortable(class CPed* ped, eAbortPriority priority, class CEvent* _event) override;
    CTask* CreateNextSubTask(CPed* ped) override;
    CTask* CreateFirstSubTask(CPed* ped) override;
    CTask* ControlSubTask(CPed* ped) override;

    CTaskComplexUseSequence* Constructor(int sequenceIndex);
    CTaskComplexUseSequence* Destructor();
};

VALIDATE_SIZE(CTaskComplexUseSequence, 0x1C);