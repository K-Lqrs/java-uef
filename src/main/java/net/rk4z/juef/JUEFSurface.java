package net.rk4z.juef;

public class JUEFSurface {
    public native void JUEF_lockPixels();

    public native void JUEF_unlockPixels();

    public native void JUEF_resize(int width, int height);

    public native void JUEF_setDirtyBounds(int x, int y, int width, int height);

    public native void JUEF_clearDirtyBounds();
}
