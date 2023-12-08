package test;

import java.io.File;

public class CMemory {
    private static String FILE_NAME = "engine.dll";
 
    static {
        System.load(System.getProperty("user.dir") + File.separatorChar + "build" + File.separatorChar
                + File.separatorChar + "Debug" + File.separatorChar + "engine.dll");
    }

    public native CEntity[] getEntities();

    public native long getProcessId(String processName);

    public native long getModuleBase(String moduleName);

    

}
