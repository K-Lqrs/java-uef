package net.rk4z.juef.configuration;

import net.rk4z.juef.UefApp;
import net.rk4z.juef.UefPlatform;
import net.rk4z.juef.UefRenderer;
import net.rk4z.juef.UefView;

/**
 * View-specific configuration settings.
 *
 * @see UefRenderer#createView
 */
public class ViewConfig {

    /**
     * A user-generated id for the display (monitor, TV, or screen) that this View will be shown on.
     *
     * Animations are driven based on the physical refresh rate of the display. Multiple Views can
     * share the same display.
     *
     * <p>Note: This is automatically managed for you when {@link UefApp#create()} is used.</p>
     *
     * @see UefRenderer#refreshDisplay
     */
    public int displayId = 0;

    /**
     * Whether to render using the GPU renderer (accelerated) or the CPU renderer (unaccelerated).
     *
     * <p>When true, the View will be rendered to an offscreen GPU texture using the GPU driver set in
     * {@link UefPlatform#setGpuDriver}. You can fetch details for the texture via {@link UefView#renderTarget}.</p>
     *
     * <p>When false (the default), the View will be rendered to an offscreen pixel buffer using the
     * multithreaded CPU renderer. This pixel buffer can optionally be provided by the user—
     * for more info see {@link UefPlatform#setSurfaceFactory} and {@link UefView#surface}.</p>
     *
     * <p>Note: This is automatically managed for you when {@link UefApp#create()} is used.</p>
     */
    public boolean isAccelerated = false;

    /**
     * The initial device scale, i.e., the amount to scale page units to screen pixels. This should
     * be set to the scaling factor of the device that the View is displayed on.
     *
     * <p>Note: 1.0 is equal to 100% zoom (no scaling), 2.0 is equal to 200% zoom (2x scaling).</p>
     *
     * <p>Note: This is automatically managed for you when {@link UefApp#create()} is used.</p>
     */
    public double initialDeviceScale = 1.0;

    /**
     * Whether or not this View should support transparency.
     *
     * <p>Note: Make sure to also set the following CSS on the page:</p>
     * <pre>
     * html, body { background: transparent; }
     * </pre>
     */
    public boolean isTransparent = false;

    /**
     * Whether or not the View should initially have input focus, see {@link UefView#focus()}.
     */
    public boolean initialFocus = true;

    /**
     * Whether or not images should be enabled.
     */
    public boolean enableImages = true;

    /**
     * Whether or not JavaScript should be enabled.
     */
    public boolean enableJavaScript = true;

    /**
     * Whether or not compositing should be enabled.
     */
    public boolean enableCompositor = false;

    /**
     * Default font-family to use.
     */
    public String fontFamilyStandard = "Times New Roman";

    /**
     * Default font-family to use for fixed fonts (e.g., pre/code elements).
     */
    public String fontFamilyFixed = "Courier New";

    /**
     * Default font-family to use for serif fonts.
     */
    public String fontFamilySerif = "Times New Roman";

    /**
     * Default font-family to use for sans-serif fonts.
     */
    public String fontFamilySansSerif = "Arial";

    /**
     * Default user-agent string.
     */
    public String userAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
            + "AppleWebKit/615.1.18.100.1 (KHTML, like Gecko) "
            + "Ultralight/1.4.0 Version/16.4.1 Safari/615.1.18.100.1";
}
