package net.rk4z.juef;

public class JUEFWindow {
    private long handle;

    public JUEFWindow(int width, int height, String title) {
        handle = JUEF_createWindow(width, height, title);
    }

    private native long JUEF_createWindow(int width, int height, String title);

    public long getHandle() {
        return handle;
    }
}
