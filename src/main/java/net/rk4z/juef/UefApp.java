package net.rk4z.juef;

import net.rk4z.juef.helper.UefHelper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class UefApp {
    public static Logger logger = LoggerFactory.getLogger(UefApp.class.getSimpleName());
    public static UefHelper helper = new UefHelper();

//>------------------- Native methods --------------------<\\

    public native void createApp(UefConfig config, UefSettings settings);

    public native void run();

    public native void stop();

    public native void destroy();

//>------------------- Native methods --------------------<\\

    public UefHelper getHelper() {
        return helper;
    }
}
