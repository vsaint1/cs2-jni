package test;

import java.io.File;

public class CTest {

    private static String FILE_NAME = "engine.dll";

    static {
        System.load(System.getProperty("user.dir") + File.separatorChar + "test" + File.separatorChar + "engine.dll");
    }

    public native void hello();

    public native int sumNumber(int a, int b);

    public native int jniSum(int a, int b);

    public static void main(String[] args) {

        int test = new CTest().sumNumber(10, 20);
        int jniTest = new CTest().jniSum(20, 30);

        System.out.println("Test sum " + test);
        System.out.println("Jni sum " + jniTest);

        new CTest().hello();
    }
}