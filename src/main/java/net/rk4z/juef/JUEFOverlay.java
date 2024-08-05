package net.rk4z.juef;

public class JUEFOverlay {
    private long handle;

    public JUEFOverlay(JUEFWindow window, int width, int height, int x, int y) {
        handle = JUEF_createOverlay(window.getHandle(), width, height, x, y);
    }

    private native long JUEF_createOverlay(long windowHandle, int width, int height, int x, int y);

    public void loadURL(String url) {
        JUEF_loadURL(handle, url);
    }

    private native void JUEF_loadURL(long overlayHandle, String url);

    public long getHandle() {
        return handle;
    }
}
