package net.rk4z.juef;

import org.jetbrains.annotations.NotNull;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Uef {
    private static final String roamingDir = Paths.get(System.getenv("APPDATA")).toString();
    public static String uefDir = Paths.get(roamingDir, "Uef").toString();
    public static Logger logger = LoggerFactory.getLogger(Uef.class.getSimpleName());

    @NotNull
    public static String getOperatingSystem() {
        return System.getProperty("os.name").toLowerCase();
    }

    public static void downloadFile(String fileUrl, @NotNull Path savePath) throws IOException {
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
    public static String getLibraryExtension() {
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

    public static void extractLibrariesAndLoad() {
        try {
            String[] libraries = {
                    "UltralightCore",
                    "WebCore",
                    "Ultralight",
                    "AppCore",
            };

            String extension = getLibraryExtension();

            for (String lib : libraries) {
                String libUrl = "https://github.com/KT-Ruxy/java-uef/releases/download/1.3.0-bin/" + lib + extension;
                Path libPath = Paths.get(uefDir, lib + extension);
                downloadFile(libUrl, libPath);
            }

            String url = "https://github.com/KT-Ruxy/java-uef/releases/download/icudt67l/icudt67l.dat";
            Path path = Paths.get(uefDir, "assets/resources/icudt67l.dat");
            downloadFile(url, path);

            for (String lib : libraries) {
                System.load(Paths.get(uefDir, lib + extension).toString());
            }

        } catch (IOException e) {
            logger.error("Failed to extract libraries and load", e);
        }
    }
}
