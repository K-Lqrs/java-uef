package net.rk4z.juef;

public class JUEF {
    static {
        System.loadLibrary("JUEFNative");
    }

    public native void init(JUEFSettings settings, JUEFConfig config);

    public native void update();

    public native void quit();
}
