package net.rk4z.juef.util;

public enum EffectQuality {
    /**
     * Fastest effect quality-- uses the lowest quality effects (half-resolution, fewer passes, etc.)
     */
    Low,

    /**
     * Default effect quality-- strikes a good balance between quality and performance.
     */
    Medium,

    /**
     * Highest effect quality-- favors quality over performance.
     */
    High
}
