#include "sims/SimsApp.h"

// 0x80003708
void SimsApp::Shutdown() {
    lbl_802E6700.Begin();
    fn_801CD9A8(lbl_8037C3D8);
    fn_800FD840();
    unk478->Stop();
    if (unk478) {
        delete unk478;
    }
    unk478 = 0;
    unk2B40 = 0;
    unk2B44 = 0;
    fn_801B8A60(unk2B60);
    unk2B60 = 0;
    lbl_802E6700.End();
    lbl_80340094.Shutdown();
    lbl_802E5E1C.Shutdown();
    if (unk2B3C) {
        delete unk2B3C;
    }
}
