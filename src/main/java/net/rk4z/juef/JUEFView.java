package net.rk4z.juef;

public class JUEFView {
    private final long handle;

    public JUEFView(JUEFOverlay overlay) {
        handle = overlay.getHandle();
    }

    public native void JUEF_loadHTML(String html);

    public native void JUEF_evaluateScript(String script);

    public native void JUEF_createInspectorView();

    public native void JUEF_setLoadListener();

    public native void JUEF_setViewListener();

    public native void JUEF_setConfig();
}
