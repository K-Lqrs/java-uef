package net.rk4z.juef;

import org.jetbrains.annotations.NotNull;

public class UefApp {
    private static native void createApp(UefConfig config, UefSettings settings);

    public native void createWindow(int width, int height, boolean fullscreen, int flags);

    public void createWindowWithFlags(int width, int height, boolean fullscreen, @NotNull WindowFlags... flags) {
        int flagValue = 0;
        for (WindowFlags flag : flags) {
            flagValue |= flag.getValue();
        }
        createWindow(width, height, fullscreen, flagValue);
    }
}
