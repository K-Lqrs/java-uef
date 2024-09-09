package net.rk4z.juef;

public enum FontHinting {
    /**
     * Lighter hinting algorithm-- glyphs are slightly fuzzier but better resemble their original
     * shape. This is achieved by snapping glyphs to the pixel grid only vertically which better
     * preserves inter-glyph spacing.
     */
    Smooth,

    /**
     * Default hinting algorithm-- offers a good balance between sharpness and shape at smaller font
     * sizes.
     */
    Normal,

    /**
     * Strongest hinting algorithm-- outputs only black/white glyphs. The result is usually
     * unpleasant if the underlying TTF does not contain hints for this type of rendering.
     */
    Monochrome,

    /**
     * No hinting is performed-- fonts may be blurry at smaller font sizes.
     */
    None
}