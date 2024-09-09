package net.rk4z.juef;

import net.rk4z.juef.listener.UefViewListener;
import net.rk4z.juef.listener.UefWindowListener;

import static net.rk4z.juef.UefApp.logger;

public class UefWindow implements AutoCloseable {
    private long nativeWindowPtr;

    public UefWindow(String title, String url, int x, int y, int width, int height, int flags) {
        nativeWindowPtr = createWindow(title, url, x, y, width, height, flags);
    }

    private native long createWindow(String title, String url, int x, int y, int width, int height, int flags);

    public void setWindowListener(UefWindowListener listener) {
        setWindowListener(getNativeWindowPtr(), listener);
    }

    public void setViewListener(UefViewListener listener) {
        setViewListener(getNativeWindowPtr(), listener);
    }

    /**
     * Resize the overlay to match the window size.
     */
    public void resizeOverlay() {
        resizeOverlay(getNativeWindowPtr());
    }

//>---------------- Native methods ----------------<\\

    private native void resizeOverlay(long windowPtr);

    private native void setWindowListener(long windowPtr, UefWindowListener listener);

    private native void setViewListener(long windowPtr, UefViewListener listener);

    private native void destroy(long windowPtr);

//>---------------- Native methods ----------------<\\

    /**
     * @deprecated This is a low-level API that exposes internal native pointers.
     * It should not be used unless absolutely necessary.
     */
    public long getNativeWindowPtr() {
        return nativeWindowPtr;
    }

    @Override
    public void close() {
        if (nativeWindowPtr != 0) {
            logger.info("Closing window");
            destroy(nativeWindowPtr);
            nativeWindowPtr = 0;
        }
    }
}
