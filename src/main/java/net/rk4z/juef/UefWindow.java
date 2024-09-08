package net.rk4z.juef;

import net.rk4z.juef.listener.UefWindowListener;

public class UefWindow implements AutoCloseable {
    private long nativeWindowPtr;

    public UefWindow(String title, String url, int x, int y, int width, int height) {
        nativeWindowPtr = createWindow(title, url, x, y, width, height);
    }

    @Override
    public void close() {
        if (nativeWindowPtr != 0) {
            destroyWindow(nativeWindowPtr);
            nativeWindowPtr = 0;
        }
    }

    private native long createWindow(String title, String url, int x, int y, int width, int height);

    public void setWindowListener(UefWindowListener listener) {
        setNativeWindowListener(nativeWindowPtr, listener);  // nativeWindowPtrを渡す
    }

    private native void setNativeWindowListener(long windowPtr, UefWindowListener listener);

    private native void destroyWindow(long windowPtr);
}
