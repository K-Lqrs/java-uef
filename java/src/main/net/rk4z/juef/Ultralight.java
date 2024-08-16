package net.rk4z.juef;

public class Ultralight {
    static {
        try {
            String basePath = "C:\\Users\\main\\CLionProjects\\Java-UEF\\native\\lib\\";

            String[] libs = {
                    "UltralightCore.dll",
                    "WebCore.dll",
                    "Ultralight.dll",
                    "AppCore.dll",
            };

            for (String lib : libs) {
                System.load(new java.io.File(basePath + lib).getAbsolutePath());
            }

            System.load("C:/Users/main/CLionProjects/Java-UEF/cbuild/Debug/JavaUEF.dll");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Failed to load JavaUEF.dll: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private long windowPtr;
    private long viewPtr;

    private native long createWindow(int width, int height);
    private native long createView(long windowPtr, int width, int height);
    private native void loadHTMLFile(long viewPtr, String filePath);
    private native void render(long windowPtr);

    public Ultralight(int width, int height) {
        windowPtr = createWindow(width, height);
        if (windowPtr == 0) {
            throw new IllegalStateException("Failed to create window.");
        }
        viewPtr = createView(windowPtr, width, height);
        if (viewPtr == 0) {
            throw new IllegalStateException("Failed to create view.");
        }
    }

    public void loadHTMLFileContent(String filePath) {
        loadHTMLFile(viewPtr, filePath);
    }

    public void startRenderLoop() {
        System.out.println("Starting render loop...");
        render(windowPtr);
    }
}
