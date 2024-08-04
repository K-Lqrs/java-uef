package net.rk4z.juef;

public class JUEFConfig {
    public String cachePath;
    public String resourcePathPrefix;
    public double fontGamma;
    public String userStylesheet;
    public boolean forceRepaint;

    public JUEFConfig(String cachePath, String resourcePathPrefix, double fontGamma, String userStylesheet, boolean forceRepaint) {
        this.cachePath = cachePath;
        this.resourcePathPrefix = resourcePathPrefix;
        this.fontGamma = fontGamma;
        this.userStylesheet = userStylesheet;
        this.forceRepaint = forceRepaint;
    }
}
