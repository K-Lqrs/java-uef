package net.rk4z.juef;

public class JUEFBitmap {
    public native long createBitmap(int width, int height);
    public native void lockPixels(long bitmapHandle);
    public native void unlockPixels(long bitmapHandle);
    public native void writePNG(long bitmapHandle, String path);
}
