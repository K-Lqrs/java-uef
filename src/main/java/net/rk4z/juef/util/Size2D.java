package net.rk4z.juef.util;

public class Size2D {
    private int width;
    private int height;

    public Size2D(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    @Override
    public String toString() {
        throw new UnsupportedOperationException("This class can not be converted to a string");
    }
}
