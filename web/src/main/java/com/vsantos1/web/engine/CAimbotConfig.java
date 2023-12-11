package com.vsantos1.web.engine;

import java.io.File;

public class CAimbotConfig {

    private boolean aimbot = true;
    private boolean visibleCheck = true;
    private float aimFov = 30.0f;
    private boolean fovCircle = true;
    private int smooth = 0;
    private int selectedHitbox = 0; // 0 - HEAD  | 1 - CHEST
    private int selectedKey = 6; // 6 - MOUSE 4 | 5 - MOUSE 5 


    public CAimbotConfig() {
    }

    public boolean isAimbot() {
        return aimbot;
    }

    public void setAimbot(boolean aimbot) {
        this.aimbot = aimbot;
    }

    public boolean isVisibleCheck() {
        return visibleCheck;
    }

    public void setVisibleCheck(boolean visibleCheck) {
        this.visibleCheck = visibleCheck;
    }

    public float getAimFov() {
        return aimFov;
    }

    public void setAimFov(float aimFov) {
        this.aimFov = aimFov;
    }

    public boolean isFovCircle() {
        return fovCircle;
    }

    public void setFovCircle(boolean fovCircle) {
        this.fovCircle = fovCircle;
    }

    public int getSmooth() {
        return smooth;
    }

    public void setSmooth(int smooth) {
        this.smooth = smooth;
    }

    public int getSelectedHitbox() {
        return selectedHitbox;
    }

    public void setSelectedHitbox(int selectedHitbox) {
        this.selectedHitbox = selectedHitbox;
    }

    
    public int getSelectedKey() {
        return selectedKey;
    }

    public void setSelectedKey(int selectedKey) {
        this.selectedKey = selectedKey;
    }

    public native void configure();

    @Override
    public String toString() {
        return "CAimbotConfig [aimbot=" + aimbot + ", visibleCheck=" + visibleCheck + ", aimFov=" + aimFov
                + ", fovCircle=" + fovCircle + ", smooth=" + smooth + ", selectedHitbox=" + selectedHitbox
                + ", selectedKey=" + selectedKey + "]";
    }

   

    
    
}
