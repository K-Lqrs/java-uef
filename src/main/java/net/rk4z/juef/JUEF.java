package net.rk4z.juef;

public class JUEF {
    static {
        System.loadLibrary("JUEFNative");
    }

    private static JUEF instance;

    private JUEF() {
    }

    public static JUEF getInstance() {
        if (instance == null) {
            instance = new JUEF();
        }
        return instance;
    }

    public native void JUEF_init(JUEFSettings settings, JUEFConfig config);

    public native void JUEF_update();
}
