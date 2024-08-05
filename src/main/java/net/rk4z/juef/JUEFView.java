package net.rk4z.juef;

public class JUEFView {
    private long handle;

    public JUEFView(long viewHandle) {
        this.handle = viewHandle;
    }

    public native void loadHTML(long viewHandle, String html);
    public native void evaluateScript(long viewHandle, String script);
    public native void createInspectorView(long viewHandle);

    public long getHandle() {
        return handle;
    }
}
