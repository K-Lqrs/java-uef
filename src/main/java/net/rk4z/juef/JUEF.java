package net.rk4z.juef;

public class JUEF {
    static {
        System.loadLibrary("JUEFNative");
    }

    // Example usage
    public static void main(String[] args) {
        JUEF juef = new JUEF();
        JUEFSettings settings = new JUEFSettings("DeveloperName", "AppName", "./assets/", false, false);
        JUEFConfig config = new JUEFConfig("./cache", "resources/", 1.8, "", false);

        juef.init(settings, config);

        long windowHandle = juef.createWindow(800, 600, "JUEF Window");
        long overlayHandle = juef.createOverlay(windowHandle, 800, 600, 0, 0);

        juef.loadURL(overlayHandle, "file:///path/to/your/local/file.html");

        // Run the update loop
        juef.update();
    }

    public native void init(JUEFSettings settings, JUEFConfig config);

    public native long createWindow(int width, int height, String title);

    public native long createOverlay(long windowHandle, int width, int height, int x, int y);

    public native void loadURL(long overlayHandle, String url);

    public native void loadHTML(long overlayHandle, String html);

    public native void update();
}
