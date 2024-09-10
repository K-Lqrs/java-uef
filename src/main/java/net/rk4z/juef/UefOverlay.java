package net.rk4z.juef;

import static net.rk4z.juef.UefApp.logger;

public class UefOverlay implements AutoCloseable{
    private long nativeOverlayPtr;

    public UefOverlay(long nativeOverlayPtr) {
        this.nativeOverlayPtr = nativeOverlayPtr;
    }

    public void moveTo(int x, int y) {
        moveOverlay(getNativeOverlayPtr(), x, y);
    }

    public void resize(int width, int height) {
        resize(getNativeOverlayPtr(), width, height);
    }

    public void loadUrl(String url) {
        loadUrl(getNativeOverlayPtr(), url);
    }

    public void destroy() {
        destroy(getNativeOverlayPtr());
        nativeOverlayPtr = 0;
    }

//>------------------- Native methods -------------------<\\

    private native void moveOverlay(long overlayPtr, int x, int y);

    private native void resize(long overlayPtr, int width, int height);

    private native void loadUrl(long overlayPtr, String url);

    private native void destroy(long overlayPtr);

//>------------------- Native methods -------------------<\\

    /**
     * @deprecated This is a low-level API that exposes internal native pointers.
     * <p>
     * @return The native pointer of the overlay.
     */
    public long getNativeOverlayPtr() {
        return nativeOverlayPtr;
    }

    @Override
    public void close() {
        if (nativeOverlayPtr != 0) {
            logger.info("Closing overlay");
            destroy();
            nativeOverlayPtr = 0;
        }
    }
}
