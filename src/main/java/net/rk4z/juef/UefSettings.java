package net.rk4z.juef;

import java.nio.file.Paths;

import static net.rk4z.juef.Uef.uefDir;

public class UefSettings {
    private final String developerName;
    private final String appName;
    private final String fileSystemPath;
    private final boolean loadShadersFromFileSystem;
    private final boolean forceCpuRenderer;

    public UefSettings() {
        this.developerName = "MyCompany";
        this.appName = "MyApp";
        this.fileSystemPath = uefDir + "./assets/";
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

    public String getAppName() {
        return appName;
    }
}
