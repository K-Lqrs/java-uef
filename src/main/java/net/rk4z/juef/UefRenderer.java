package net.rk4z.juef;

import net.rk4z.juef.configuration.ViewConfig;

public class UefRenderer {

//>------------------- Native methods --------------------<\\

public static native UefView createView(int width, int height, ViewConfig config, UefSession session);

public static native void refreshDisplay(int displayId);

//>------------------- Native methods --------------------<\\

}
