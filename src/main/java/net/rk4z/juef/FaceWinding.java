package net.rk4z.juef;

/**
 * The winding order for front-facing triangles. (Only used when the GPU renderer is used)
 */
public enum FaceWinding {
    /**
     * Clockwise Winding (Direct3D, etc.)
     */
    Clockwise,

    /**
     * Counter-Clockwise Winding (OpenGL, etc.)
     */
    CounterClockwise
}
