package test;


public class CEntity {
    
    private String name;
    private float distance;
    private int health;



    public CEntity(String name, float distance, int health) {
        this.name = name;
        this.distance = distance;
        this.health = health;
    }


    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public float getDistance() {
        return distance;
    }
    public void setDistance(float distance) {
        this.distance = distance;
    }
    public int getHealth() {
        return health;
    }
    public void setHealth(int health) {
        this.health = health;
    }

    @Override
    public String toString() {
        return "CEntity [name=" + name + ", distance=" + distance + ", health=" + health + "]";
    }
    
    
    
}
