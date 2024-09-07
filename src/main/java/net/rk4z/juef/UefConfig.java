package net.rk4z.juef;

public class UefConfig {
    private String cachePath;
    private String resourcePathPrefix = "resources/";
    private FaceWinding faceWinding = FaceWinding.CounterClockwise;  // Enumを使用
    private FontHinting fontHinting = FontHinting.Normal;  // Enumを使用
    private double fontGamma = 1.8;
    private String userStylesheet;
    private boolean forceRepaint = false;
    private double animationTimerDelay = 1.0 / 60.0;
    private double scrollTimerDelay = 1.0 / 60.0;
    private double recycleDelay = 4.0;
    private long memoryCacheSize = 64 * 1024 * 1024;
    private long pageCacheSize = 0;
    private long overrideRamSize = 0;
    private long minLargeHeapSize = 32 * 1024 * 1024;
    private long minSmallHeapSize = 1 * 1024 * 1024;
    private long numRendererThreads = 0;
    private double maxUpdateTime = 1.0 / 200.0;
    private long bitmapAlignment = 16;

    public UefConfig() {}

    public UefConfig(String cachePath, String resourcePathPrefix, FaceWinding faceWinding, FontHinting fontHinting,
                     double fontGamma, String userStylesheet, boolean forceRepaint, double animationTimerDelay,
                     double scrollTimerDelay, double recycleDelay, long memoryCacheSize, long pageCacheSize,
                     long overrideRamSize, long minLargeHeapSize, long minSmallHeapSize, long numRendererThreads,
                     double maxUpdateTime, long bitmapAlignment) {
        this.cachePath = cachePath;
        this.resourcePathPrefix = resourcePathPrefix;
        this.faceWinding = faceWinding;
        this.fontHinting = fontHinting;
        this.fontGamma = fontGamma;
        this.userStylesheet = userStylesheet;
        this.forceRepaint = forceRepaint;
        this.animationTimerDelay = animationTimerDelay;
        this.scrollTimerDelay = scrollTimerDelay;
        this.recycleDelay = recycleDelay;
        this.memoryCacheSize = memoryCacheSize;
        this.pageCacheSize = pageCacheSize;
        this.overrideRamSize = overrideRamSize;
        this.minLargeHeapSize = minLargeHeapSize;
        this.minSmallHeapSize = minSmallHeapSize;
        this.numRendererThreads = numRendererThreads;
        this.maxUpdateTime = maxUpdateTime;
        this.bitmapAlignment = bitmapAlignment;
    }

    // ゲッターとセッター
    public String getCachePath() {
        return cachePath;
    }

    public void setCachePath(String cachePath) {
        this.cachePath = cachePath;
    }

    public String getResourcePathPrefix() {
        return resourcePathPrefix;
    }

    public void setResourcePathPrefix(String resourcePathPrefix) {
        this.resourcePathPrefix = resourcePathPrefix;
    }

    public FaceWinding getFaceWinding() {
        return faceWinding;
    }

    public void setFaceWinding(FaceWinding faceWinding) {
        this.faceWinding = faceWinding;
    }

    public FontHinting getFontHinting() {
        return fontHinting;
    }

    public void setFontHinting(FontHinting fontHinting) {
        this.fontHinting = fontHinting;
    }

    public double getFontGamma() {
        return fontGamma;
    }

    public void setFontGamma(double fontGamma) {
        this.fontGamma = fontGamma;
    }

    public String getUserStylesheet() {
        return userStylesheet;
    }

    public void setUserStylesheet(String userStylesheet) {
        this.userStylesheet = userStylesheet;
    }

    public boolean isForceRepaint() {
        return forceRepaint;
    }

    public void setForceRepaint(boolean forceRepaint) {
        this.forceRepaint = forceRepaint;
    }

    public double getAnimationTimerDelay() {
        return animationTimerDelay;
    }

    public void setAnimationTimerDelay(double animationTimerDelay) {
        this.animationTimerDelay = animationTimerDelay;
    }

    public double getScrollTimerDelay() {
        return scrollTimerDelay;
    }

    public void setScrollTimerDelay(double scrollTimerDelay) {
        this.scrollTimerDelay = scrollTimerDelay;
    }

    public double getRecycleDelay() {
        return recycleDelay;
    }

    public void setRecycleDelay(double recycleDelay) {
        this.recycleDelay = recycleDelay;
    }

    public long getMemoryCacheSize() {
        return memoryCacheSize;
    }

    public void setMemoryCacheSize(long memoryCacheSize) {
        this.memoryCacheSize = memoryCacheSize;
    }

    public long getPageCacheSize() {
        return pageCacheSize;
    }

    public void setPageCacheSize(long pageCacheSize) {
        this.pageCacheSize = pageCacheSize;
    }

    public long getOverrideRamSize() {
        return overrideRamSize;
    }

    public void setOverrideRamSize(long overrideRamSize) {
        this.overrideRamSize = overrideRamSize;
    }

    public long getMinLargeHeapSize() {
        return minLargeHeapSize;
    }

    public void setMinLargeHeapSize(long minLargeHeapSize) {
        this.minLargeHeapSize = minLargeHeapSize;
    }

    public long getMinSmallHeapSize() {
        return minSmallHeapSize;
    }

    public void setMinSmallHeapSize(long minSmallHeapSize) {
        this.minSmallHeapSize = minSmallHeapSize;
    }

    public long getNumRendererThreads() {
        return numRendererThreads;
    }

    public void setNumRendererThreads(long numRendererThreads) {
        this.numRendererThreads = numRendererThreads;
    }

    public double getMaxUpdateTime() {
        return maxUpdateTime;
    }

    public void setMaxUpdateTime(double maxUpdateTime) {
        this.maxUpdateTime = maxUpdateTime;
    }

    public long getBitmapAlignment() {
        return bitmapAlignment;
    }

    public void setBitmapAlignment(long bitmapAlignment) {
        this.bitmapAlignment = bitmapAlignment;
    }

    @Override
    public String toString() {
        return "UefConfig{" +
                "cachePath='" + cachePath + '\'' +
                ", resourcePathPrefix='" + resourcePathPrefix + '\'' +
                ", faceWinding=" + faceWinding +
                ", fontHinting=" + fontHinting +
                ", fontGamma=" + fontGamma +
                ", userStylesheet='" + userStylesheet + '\'' +
                ", forceRepaint=" + forceRepaint +
                ", animationTimerDelay=" + animationTimerDelay +
                ", scrollTimerDelay=" + scrollTimerDelay +
                ", recycleDelay=" + recycleDelay +
                ", memoryCacheSize=" + memoryCacheSize +
                ", pageCacheSize=" + pageCacheSize +
                ", overrideRamSize=" + overrideRamSize +
                ", minLargeHeapSize=" + minLargeHeapSize +
                ", minSmallHeapSize=" + minSmallHeapSize +
                ", numRendererThreads=" + numRendererThreads +
                ", maxUpdateTime=" + maxUpdateTime +
                ", bitmapAlignment=" + bitmapAlignment +
                '}';
    }
}

