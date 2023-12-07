package test;

import java.io.File;

public class CMemory {
    private static String FILE_NAME = "engine.dll";

    static {
        System.load(System.getProperty("user.dir") + File.separatorChar + "test" + File.separatorChar + "engine.dll");
    }

    public native long getProcessId(String processName);

   
}
