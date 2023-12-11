package com.vsantos1.web.engine;

public class CMiscConfig {
    private boolean teamCheck = true;
    private boolean watermark = true;

    public CMiscConfig() {
    }

   

    public boolean isTeamCheck() {
        return teamCheck;
    }



    public void setTeamCheck(boolean teamCheck) {
        this.teamCheck = teamCheck;
    }



    public boolean isWatermark() {
        return watermark;
    }



    public void setWatermark(boolean watermark) {
        this.watermark = watermark;
    }



    public native void configure();



    @Override
    public String toString() {
        return "CMiscConfig [teamCheck=" + teamCheck + ", watermark=" + watermark + "]";
    }

  
    
}
