package com.vsantos1.web.engine;

import java.io.File;

public class CAimbotConfig {

    private boolean aimbot;
    private boolean visibleCheck;
    private float aimFov;
    private boolean fovCircle;
    private int smooth;
    private int selectedHitbox;
    private static String FILE_NAME = "engine.dll";

    static {
        System.load(System.getProperty("user.dir") + File.separatorChar + "build" + File.separatorChar
                + "engine" + File.separatorChar + "Debug" + File.separatorChar + "engine.dll");
    }

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

    public native void configure();

}
