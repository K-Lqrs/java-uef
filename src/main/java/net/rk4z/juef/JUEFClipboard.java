package net.rk4z.juef;

public class JUEFClipboard {
    public native void clear();
    public native String readPlainText();
    public native void writePlainText(String text);
}
