package net.rk4z.juef;

public class JUEFFontLoader {
    public native void loadFont(String family, int weight, boolean italic);
    public native void fallbackFont();
}
