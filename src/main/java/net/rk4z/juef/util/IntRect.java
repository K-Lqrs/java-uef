package net.rk4z.juef.util;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

public class IntRect {
    public int left, top, right, bottom;

    public IntRect(int left, int top, int right, int bottom) {
        this.left = left;
        this.top = top;
        this.right = right;
        this.bottom = bottom;
    }

    @NotNull
    @Contract(" -> new")
    public static IntRect makeEmpty() {
        return new IntRect(0, 0, 0, 0);
    }

    public int width() {
        return right - left;
    }

    public int height() {
        return bottom - top;
    }

    public int x() {
        return left;
    }

    public int y() {
        return top;
    }

    public int centerX() {
        return (int) Math.round((left + right) * 0.5f);
    }

    public int centerY() {
        return (int) Math.round((top + bottom) * 0.5f);
    }

    public Vec2 origin() {
        return new Vec2((float) left, (float) top);
    }

    public void setEmpty() {
        this.left = 0;
        this.top = 0;
        this.right = 0;
        this.bottom = 0;
    }

    public boolean isEmpty() {
        return this.equals(makeEmpty());
    }

    public boolean isValid() {
        return width() > 0 && height() > 0;
    }

    public void inset(int dx, int dy) {
        left += dx;
        top += dy;
        right -= dx;
        bottom -= dy;
    }
}
