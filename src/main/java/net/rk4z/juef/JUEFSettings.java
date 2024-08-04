package net.rk4z.juef;

public class JUEFSettings {
    public String developerName;
    public String appName;
    public String fileSystemPath;
    public boolean loadShadersFromFileSystem;
    public boolean forceCpuRenderer;

    public JUEFSettings(String developerName, String appName, String fileSystemPath, boolean loadShadersFromFileSystem, boolean forceCpuRenderer) {
        this.developerName = developerName;
        this.appName = appName;
        this.fileSystemPath = fileSystemPath;
        this.loadShadersFromFileSystem = loadShadersFromFileSystem;
        this.forceCpuRenderer = forceCpuRenderer;
    }
}
