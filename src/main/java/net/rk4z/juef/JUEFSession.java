package net.rk4z.juef;

public class JUEFSession {
    private long handle;

    public JUEFSession(boolean isPersistent, String path) {
        if (isPersistent) {
            handle = JUEF_createSessionFromDisk(path);
        } else {
            handle = JUEF_createSession();
        }
    }

    private native long JUEF_createSession();

    private native long JUEF_createSessionFromDisk(String path);

    public native String JUEF_getPersistentPath();

    public native void JUEF_clearCache();
}
