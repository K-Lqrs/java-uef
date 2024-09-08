package net.rk4z.juef.helper;

import org.jetbrains.annotations.NotNull;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import static net.rk4z.juef.UefApp.logger;

public class UefHelper {
    private static final String roamingDir = Paths.get(System.getenv("APPDATA")).toString();
    public static String uefDir = Paths.get(roamingDir, "Uef").toString();
    public Boolean isLoaded = false;

    @NotNull
    private String getOperatingSystem() {
        return System.getProperty("os.name").toLowerCase();
    }

    private void downloadFile(String fileUrl, @NotNull Path savePath) throws IOException {
        Files.createDirectories(savePath.getParent());
        if (Files.notExists(savePath)) {
            URL url = new URL(fileUrl);
            try (InputStream in = url.openStream()) {
                Files.copy(in, savePath);
                logger.info("Downloaded: {}", savePath.getFileName());
            }
        } else {
            logger.warn("File already exists: {}", savePath.getFileName());
        }
    }

    @NotNull
    private String getLibraryExtension() {
        String os = getOperatingSystem();
        if (os.contains("win")) {
            return ".dll";
        } else if (os.contains("mac")) {
            return ".dylib";
        } else if (os.contains("nux") || os.contains("nix")) {
            return ".so";
        } else {
            throw new UnsupportedOperationException("Unsupported operating system: " + os);
        }
    }

    public void extractLibrariesAndLoad() {
        try {
            String[] libraries = {
                    "UltralightCore",
                    "WebCore",
                    "Ultralight",
                    "AppCore",
            };

            String extension = getLibraryExtension();

            String icudt67l = "https://github.com/KT-Ruxy/java-uef/releases/download/icudt67l/icudt67l.dat";
            Path path = Paths.get(uefDir, "assets/resources/icudt67l.dat");
            downloadFile(icudt67l, path);

            String cacert = "https://github.com/KT-Ruxy/java-uef/releases/download/cacert/cacert.pem";
            Path cacertPath = Paths.get(uefDir, "assets/resources/cacert.pem");
            downloadFile(cacert, cacertPath);

            for (String lib : libraries) {
                String libUrl = "https://github.com/KT-Ruxy/java-uef/releases/download/1.3.0-bin/" + lib + extension;
                Path libPath = Paths.get(uefDir, lib + extension);
                downloadFile(libUrl, libPath);
            }

            for (String lib : libraries) {
                System.load(Paths.get(uefDir, lib + extension).toString());
            }

            isLoaded = true;
        } catch (IOException e) {
            logger.error("Failed to extract libraries and load", e);
            isLoaded = false;
        }
    }
}
