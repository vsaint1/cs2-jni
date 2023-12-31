package test;

public class Main {

    public static void main(String[] args) {

        long pid = new CMemory().getProcessId("cs2.exe");

        System.out.println("[CLIENT] - " + pid);

        long moduleBase = new CMemory().getModuleBase("client.dll");
        System.out.println("[CLIENT] - " + moduleBase);

        CEntity[] entities = new CMemory().getEntities();

        for (CEntity entity : entities) {
            System.out.println(entity.toString());
        }

        new CMemory().start();

    }
}
