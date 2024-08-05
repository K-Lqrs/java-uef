package net.rk4z.juef;

public class JUEFFileSystem {
    public native boolean fileExists(String path);
    public native String getFileMimeType(String path);
    public native String getFileCharset(String path);
    public native byte[] openFile(String path);
}
