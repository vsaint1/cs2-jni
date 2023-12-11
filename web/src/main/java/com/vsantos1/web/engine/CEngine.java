package com.vsantos1.web.engine;

import java.io.File;

public class CEngine {
    private static String FILE_NAME = "engine.dll";

    static {

     

        if (System.getProperty("os.name").toLowerCase().contains("windows")) {
            FILE_NAME = "engine.dll";
        }

        if (System.getProperty("os.name").toLowerCase().contains("linux")) {
            FILE_NAME = "libengine.so";
        }

        if (System.getProperty("os.name").toLowerCase().contains("mac")) {
            FILE_NAME = "libengine.dylib";
        }

        File file = new File(System.getProperty("user.dir") + File.separatorChar  + File.separatorChar + FILE_NAME);

        System.out.println("Loading " + file.getAbsolutePath() + "...");
        if (!file.exists()) {
            System.out.println("File " + file.getAbsolutePath() + " does not exist");

            System.exit(0);
        }

        System.load(file.getAbsolutePath());
        System.out.println("File " + file.getAbsolutePath() + " loaded");
    }

    public native long getProcessId();

    public native long getModuleBase(String moduleName);

    public native void start();
    public native void stop();
}
