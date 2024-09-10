package net.rk4z.juef;

import net.rk4z.juef.listener.UefWindowListener;
import net.rk4z.juef.util.Size2D;

import static net.rk4z.juef.UefApp.logger;

public class UefWindow implements AutoCloseable {
    private long nativeWindowPtr;

    /**
     * Create a new window.
     *
     * @param title The title of the window.
     * @param x pos x
     * @param y pos y
     * @param width The width of the window.
     * @param height The height of the window.
     * @param fullScreen Whether the window should be full screen.
     * @param flags The flags to use when creating the window.
     */
    public UefWindow(String title, int x, int y, int width, int height, boolean fullScreen, int flags) {
        nativeWindowPtr = createWindow(title, x, y, width, height, fullScreen, flags);
    }

    /**
     * Set the window listener for this window.
     * @param listener Instances of ‘UefViewListener’ with written listener behaviour.
     */
    public void setWindowListener(UefWindowListener listener) {
        setWindowListener(getNativeWindowPtr(), listener);
    }

    /**
     * Set the title of the window.
     *
     * @param title The new title.
     */
    public void setTitle(String title) {
        setTitle(getNativeWindowPtr(), title);
    }

    /**
     * Move the window to a new position (in screen coordinates) relative to the top-left of the monitor area.
     *
     * @param x pos x
     * @param y pos y
     */
    public void moveTo(int x, int y) {
        moveTo(getNativeWindowPtr(), x, y);
    }

    /**
     * Get the size of the window.
     *
     * @return The size of the window.
     */
    public Size2D getWindowSize() {
        return getWindowSize(getNativeWindowPtr());
    }

    /**
     * Show the window.
     */
    public void show() {
        show(getNativeWindowPtr());
    }

    /**
     * Hide the window.
     */
    public void hide() {
        hide(getNativeWindowPtr());
    }

    /**
     * Create a new Overlay for this Window.
     *
     * @param x The x-position (offset from the left of the Window), in pixels.
     * @param y The y-position (offset from the top of the Window), in pixels.
     * @param width The width in pixels.
     * @param height The height in pixels.
     * @return The new Overlay instance.
     */
    public UefOverlay createOverlay(int x, int y, int width, int height) {
        long nativeOverlayPtr = createOverlay(getNativeWindowPtr(), x, y, width, height);
        return new UefOverlay(nativeOverlayPtr);
    }

//>------------------- Native methods --------------------<\\

    private native long createWindow(String title, int x, int y, int width, int height, boolean fullScreen, int flags);

    private native void setWindowListener(long windowPtr, UefWindowListener listener);

    private native void moveTo(long windowPtr, int x, int y);

    private native void show(long windowPtr);

    private native void hide(long windowPtr);

    private native void setTitle(long windowPtr, String title);

    private native Size2D getWindowSize(long windowPtr);

    private native long createOverlay(long windowPtr, int x, int y, int width, int height);

    private native void destroy(long windowPtr);

//>------------------- Native methods -------------------<\\

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
            destroy(getNativeWindowPtr());
            nativeWindowPtr = 0;
        }
    }
}
