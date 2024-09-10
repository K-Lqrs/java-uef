package net.rk4z.juef;

import static net.rk4z.juef.helper.UefHelper.uefDir;

public class UefSettings {
    /**
     * The name of the developer of this application.
     * This is used to generate a unique path to store local application data on the user's machine.
     */
    private final String developerName;

    /**
     * The name of this application.
     * This is used to generate a unique path to store local application data on the user's machine.
     */
    private final String appName;

    /**
     * The root file path for our file system. You should set this to the relative path where all of your app data is.
     * This will be used to resolve all file URLs, eg file:page. html
     *
     * @apiNote This relative path is resolved using the following logic:
     * <p>
     *  Windows: relative to the executable path
     *  <p>
     *  Linux: relative to the executable path
     *  <p>
     *  macOS: relative to YourApp. app/ Contents/ Resources/
     */
    private static String fileSystemPath = uefDir + "./assets/";

    /**
     * Whether we should load and compile shaders from the file system (eg, from the / shaders/ path, relative to file_system_path).
     * <p>
     * If this is false (the default), we will instead load pre-compiled shaders from memory, which speeds up application startup time.
     */
    private final boolean loadShadersFromFileSystem;

    /**
     * We try to use the GPU renderer when a compatible GPU is detected.
     * <p>
     * Set this to true to force the engine to always use the CPU renderer.
     */
    private final boolean forceCpuRenderer;

    public UefSettings() {
        this.developerName = "MyCompany";
        this.appName = "MyApp";
        this.loadShadersFromFileSystem = false;
        this.forceCpuRenderer = false;
    }

    public UefSettings(String developerName, String appName, String fileSystemPath, boolean loadShadersFromFileSystem, boolean forceCpuRenderer) {
        this.developerName = developerName;
        this.appName = appName;
        UefSettings.fileSystemPath = fileSystemPath;
        this.loadShadersFromFileSystem = loadShadersFromFileSystem;
        this.forceCpuRenderer = forceCpuRenderer;
    }

    public static String getFileSystemPath() {
        return fileSystemPath;
    }
}
