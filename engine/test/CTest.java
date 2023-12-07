package test;

import java.io.File;

public class CTest {

    private static String FILE_NAME = "engine.dll";

    static {
        System.load(System.getProperty("user.dir") + File.separatorChar + "test" + File.separatorChar + "engine.dll");
    }

    public native void hello();

    public native int sumNumber(int a, int b);

    public static void main(String[] args) {

        int test = new CTest().sumNumber(10, 20);


        System.out.println("Test " + test);

        new CTest().hello();
    }
}