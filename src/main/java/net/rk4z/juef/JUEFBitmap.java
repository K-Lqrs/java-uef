package net.rk4z.juef;

public class JUEFBitmap {
    private final long handle;

    public JUEFBitmap(int width, int height) {
        handle = JUEF_createBitmap(width, height);
    }

    private native long JUEF_createBitmap(int width, int height);

    public native void JUEF_lockPixels();

    public native void JUEF_unlockPixels();

    public native void JUEF_writePNG(String path);
}
