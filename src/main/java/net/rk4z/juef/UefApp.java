package net.rk4z.juef;

import net.rk4z.juef.helper.UefHelper;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class UefApp {
    public static Logger logger = LoggerFactory.getLogger(UefApp.class.getSimpleName());
    public static UefHelper helper = new UefHelper();
    private final UefConfig config;
    private final UefSettings settings;

    public UefApp(UefConfig config, UefSettings settings) {
        this.config = config;
        this.settings = settings;
    }

    /**
     * Create the new app
     * <p>
     * The app is singleton, so only one instance can be created.
     * <p>
     * Do not call this method more than once.
     */
    public void createApp() {
        createApp(config, settings);
    }

//>------------------- Native methods --------------------<\\

    private native void createApp(UefConfig config, UefSettings settings);

    /**
     * Run the application
     */
    public native void run();

    /**
     * Stop the application
     */
    public native void stop();

    /**
     * Destroy the application
     * <p>
     * If, after executing this method, you want to execute a method related to the App, you need to create the App again.
     */
    public native void destroy();

//>------------------- Native methods --------------------<\\

    /**
     * @return UefHelper instance
     */
    public UefHelper getHelper() {
        return helper;
    }
}
