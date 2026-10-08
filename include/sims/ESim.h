#ifndef SIMS_ESIM_H
#define SIMS_ESIM_H

// A sim. The class name is from the header string "ESim" and The Sims 2's symbol map
// (ESimsDataManager::QueueCommand(ESim*, unsigned int)); only this member is known.
struct ESim {
    char unk0[0x550];
    int unk550;              // commands queued with the data manager
};

#endif
