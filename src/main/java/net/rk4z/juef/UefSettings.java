package net.rk4z.juef;

public class UefSettings {
    private String developerName;
    private String appName;
    private String fileSystemPath;
    private boolean loadShadersFromFileSystem;
    private boolean forceCpuRenderer;

    public UefSettings() {
        this.developerName = "MyCompany";
        this.appName = "MyApp";
        this.fileSystemPath = "./assets/";
        this.loadShadersFromFileSystem = false;
        this.forceCpuRenderer = false;
    }

    public UefSettings(String developerName, String appName, String fileSystemPath, boolean loadShadersFromFileSystem, boolean forceCpuRenderer) {
        this.developerName = developerName;
        this.appName = appName;
        this.fileSystemPath = fileSystemPath;
        this.loadShadersFromFileSystem = loadShadersFromFileSystem;
        this.forceCpuRenderer = forceCpuRenderer;
    }

    public String getDeveloperName() {
        return developerName;
    }

    public void setDeveloperName(String developerName) {
        this.developerName = developerName;
    }

    public String getAppName() {
        return appName;
    }

    public void setAppName(String appName) {
        this.appName = appName;
    }

    public String getFileSystemPath() {
        return fileSystemPath;
    }

    public void setFileSystemPath(String fileSystemPath) {
        this.fileSystemPath = fileSystemPath;
    }

    public boolean isLoadShadersFromFileSystem() {
        return loadShadersFromFileSystem;
    }

    public void setLoadShadersFromFileSystem(boolean loadShadersFromFileSystem) {
        this.loadShadersFromFileSystem = loadShadersFromFileSystem;
    }

    public boolean isForceCpuRenderer() {
        return forceCpuRenderer;
    }

    public void setForceCpuRenderer(boolean forceCpuRenderer) {
        this.forceCpuRenderer = forceCpuRenderer;
    }

    @Override
    public String toString() {
        return "Settings{" +
                "developerName='" + developerName + '\'' +
                ", appName='" + appName + '\'' +
                ", fileSystemPath='" + fileSystemPath + '\'' +
                ", loadShadersFromFileSystem=" + loadShadersFromFileSystem +
                ", forceCpuRenderer=" + forceCpuRenderer +
                '}';
    }
}
