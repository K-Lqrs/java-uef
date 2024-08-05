package net.rk4z.juef;

public class JUEFOverlay {
    public native long createOverlay(long windowHandle, int width, int height, int x, int y);
    public native void loadURL(long overlayHandle, String url);
}
