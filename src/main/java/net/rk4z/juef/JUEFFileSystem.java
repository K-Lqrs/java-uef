package net.rk4z.juef;

public class JUEFFileSystem {
    public native boolean JUEF_fileExists(String path);

    public native String JUEF_getFileMimeType(String path);

    public native String JUEF_getFileCharset(String path);

    public native byte[] JUEF_openFile(String path);
}
