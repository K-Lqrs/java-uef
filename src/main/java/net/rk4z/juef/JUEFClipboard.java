package net.rk4z.juef;

public class JUEFClipboard {
    public native void JUEF_clear();

    public native String JUEF_readPlainText();

    public native void JUEF_writePlainText(String text);
}
