#ifndef SIMS_OBJSELECTOR_H
#define SIMS_OBJSELECTOR_H

// An object as the data manager sees it. The class name is from The Sims 2's symbol
// map (collectResInfoForSel(ObjSelector*, ...)); only these members are known.
struct ObjSelectorMaterial {
    char unk0[0x44];
    unsigned int unk44;      // resource id
};
struct ObjSelectorExtra {
    char unk0[0x10];
    unsigned int unk10;      // resource id
};
struct ObjSelectorDefinition {
    char unk0[0x14];
    short unk14;             // kind
    char unk16[0xC0 - 0x16];
    ObjSelectorExtra* unkC0;
};
struct ObjSelector {
    char unk0[0x18];
    ObjSelectorDefinition* unk18;
    char unk1C[0x34 - 0x1C];
    ObjSelectorMaterial* unk34;
    char unk38[0x78 - 0x38];
    int unk78;               // 1: its resources are wanted
    int unk7C;               // 1: its resources are loaded
};

#endif
