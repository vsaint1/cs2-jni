package com.vsantos1.web.engine;

public class CEspConfig {

    private boolean esp;
    private boolean snapLines;
    private boolean health;
    private boolean box;
    private boolean name;
    private boolean distance;
    private boolean skeleton;
    private boolean weapon;

    public CEspConfig() {
    }

    public boolean isEsp() {
        return esp;
    }

    public void setEsp(boolean esp) {
        this.esp = esp;
    }

    public boolean isSnapLines() {
        return snapLines;
    }

    public void setSnapLines(boolean snapLines) {
        this.snapLines = snapLines;
    }

    public boolean isHealth() {
        return health;
    }

    public void setHealth(boolean health) {
        this.health = health;
    }

    public boolean isBox() {
        return box;
    }

    public void setBox(boolean box) {
        this.box = box;
    }

    public boolean isName() {
        return name;
    }

    public void setName(boolean name) {
        this.name = name;
    }

    public boolean isDistance() {
        return distance;
    }

    public void setDistance(boolean distance) {
        this.distance = distance;
    }

    public boolean isSkeleton() {
        return skeleton;
    }

    public void setSkeleton(boolean skeleton) {
        this.skeleton = skeleton;
    }

    public boolean isWeapon() {
        return weapon;
    }

    public void setWeapon(boolean weapon) {
        this.weapon = weapon;
    }

    public native void configure();

    @Override
    public String toString() {
        return "CEspConfig [esp=" + esp + ", snapLines=" + snapLines + ", health=" + health + ", box=" + box + ", name="
                + name + ", distance=" + distance + ", skeleton=" + skeleton + "]";
    }

}
