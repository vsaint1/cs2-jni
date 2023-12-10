package com.vsantos1.web.engine;

import java.io.File;

public class CEngine {
     private static String FILE_NAME = "engine.dll";

    static {
        System.load(System.getProperty("user.dir") + File.separatorChar + "build" + File.separatorChar
                + "engine" + File.separatorChar + "Debug" + File.separatorChar + "engine.dll");
    }


    public native long getProcessId(String processName);

    public native long getModuleBase(String moduleName);

    public native void start();
}
