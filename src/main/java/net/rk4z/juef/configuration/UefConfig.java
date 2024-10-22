package net.rk4z.juef.configuration;

import net.rk4z.juef.util.EffectQuality;
import net.rk4z.juef.util.FaceWinding;
import net.rk4z.juef.util.FontHinting;

public class UefConfig {
    private final String cachePath;
    private final String resourcePathPrefix;
    private final FaceWinding faceWinding;
    private final FontHinting fontHinting;
    private final double fontGamma;
    private final String userStylesheet;
    private final boolean forceRepaint;
    private final double animationTimerDelay;
    private final double scrollTimerDelay;
    private final double recycleDelay;
    private final long memoryCacheSize;
    private final long pageCacheSize;
    private final long overrideRamSize;
    private final long minLargeHeapSize;
    private final long minSmallHeapSize;
    private final long numRendererThreads;
    private final double maxUpdateTime;
    private final long bitmapAlignment;
    private final EffectQuality effectQuality;

    public UefConfig() {
        this.cachePath = ".cache/";
        this.resourcePathPrefix = "resources/";
        this.faceWinding = FaceWinding.CounterClockwise;
        this.fontHinting = FontHinting.Normal;
        this.fontGamma = 1.8;
        this.userStylesheet = "";
        this.forceRepaint = false;
        this.animationTimerDelay = 1.0 / 60.0;
        this.scrollTimerDelay = 1.0 / 60.0;
        this.recycleDelay = 4.0;
        this.memoryCacheSize = 64 * 1024 * 1024;
        this.pageCacheSize = 0;
        this.overrideRamSize = 0;
        this.minLargeHeapSize = 32 * 1024 * 1024;
        this.minSmallHeapSize = 1 * 1024 * 1024;
        this.numRendererThreads = 0;
        this.maxUpdateTime = 1.0 / 200.0;
        this.bitmapAlignment = 16;
        this.effectQuality = EffectQuality.Medium;
    }

    public UefConfig(String cachePath, String resourcePathPrefix, FaceWinding faceWinding, FontHinting fontHinting,
                     double fontGamma, String userStylesheet, boolean forceRepaint, double animationTimerDelay,
                     double scrollTimerDelay, double recycleDelay, long memoryCacheSize, long pageCacheSize,
                     long overrideRamSize, long minLargeHeapSize, long minSmallHeapSize, long numRendererThreads,
                     double maxUpdateTime, long bitmapAlignment, EffectQuality effectQuality) {
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
        this.effectQuality = effectQuality;
    }
}

