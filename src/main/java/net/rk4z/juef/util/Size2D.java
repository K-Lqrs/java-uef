package net.rk4z.juef.util;

import org.jetbrains.annotations.NotNull;

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

    public void plus(@NotNull Size2D size) {
        this.width += size.width;
        this.height += size.height;
    }

    public void subtract(@NotNull Size2D size) {
        this.width -= size.width;
        this.height -= size.height;
    }

    public void multiply(@NotNull Size2D size) {
        this.width *= size.width;
        this.height *= size.height;
    }

    public void divide(@NotNull Size2D size) {
        this.width /= size.width;
        this.height /= size.height;
    }

    public void mod(@NotNull Size2D size) {
        this.width %= size.width;
        this.height %= size.height;
    }

    public void and(@NotNull Size2D size) {
        this.width &= size.width;
        this.height &= size.height;
    }

    public void or(@NotNull Size2D size) {
        this.width |= size.width;
        this.height |= size.height;
    }

    public void xor(@NotNull Size2D size) {
        this.width ^= size.width;
        this.height ^= size.height;
    }

    @Override
    public String toString() {
        throw new UnsupportedOperationException("This class can not be converted to a string");
    }
}
