package net.rk4z.juef;

public class JUEFRenderer {
    private static JUEFRenderer instance;

    private JUEFRenderer() {
    }

    public static JUEFRenderer getInstance() {
        if (instance == null) {
            instance = new JUEFRenderer();
        }
        return instance;
    }

    public native void JUEF_createRenderer();

    public native void JUEF_updateRenderer();

    public native void JUEF_render();
}
