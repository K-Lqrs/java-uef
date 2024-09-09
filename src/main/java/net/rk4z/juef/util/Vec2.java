package net.rk4z.juef.util;

public class Vec2 {
    public float x, y;

    public Vec2() {
        this.x = 0.0f;
        this.y = 0.0f;
    }

    public Vec2(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public Vec2(float x) {
        this.x = x;
        this.y = x;
    }

    public Vec2 yx() {
        return new Vec2(y, x);
    }

    public Vec2 xx() {
        return new Vec2(x, x);
    }

    public Vec2 yy() {
        return new Vec2(y, y);
    }

    public Vec2 add(Vec2 other) {
        return new Vec2(this.x + other.x, this.y + other.y);
    }

    public Vec2 subtract(Vec2 other) {
        return new Vec2(this.x - other.x, this.y - other.y);
    }

    public Vec2 multiply(Vec2 other) {
        return new Vec2(this.x * other.x, this.y * other.y);
    }

    public Vec2 divide(Vec2 other) {
        return new Vec2(this.x / other.x, this.y / other.y);
    }

    public Vec2 add(float value) {
        return new Vec2(this.x + value, this.y + value);
    }

    public Vec2 subtract(float value) {
        return new Vec2(this.x - value, this.y - value);
    }

    public Vec2 multiply(float value) {
        return new Vec2(this.x * value, this.y * value);
    }

    public Vec2 divide(float value) {
        return new Vec2(this.x / value, this.y / value);
    }

    public boolean equals(Vec2 other) {
        return this.x == other.x && this.y == other.y;
    }

    public static Vec2 min(Vec2 a, Vec2 b) {
        return new Vec2(Math.min(a.x, b.x), Math.min(a.y, b.y));
    }

    public static Vec2 max(Vec2 a, Vec2 b) {
        return new Vec2(Math.max(a.x, b.x), Math.max(a.y, b.y));
    }

    public static Vec2 clamp(Vec2 x, Vec2 minVal, Vec2 maxVal) {
        return max(min(x, minVal), maxVal);
    }

    public static Vec2 mix(Vec2 a, Vec2 b, float t) {
        return a.multiply(1.0f - t).add(b.multiply(t));
    }

    public static float length(Vec2 a) {
        return (float) Math.sqrt(a.x * a.x + a.y * a.y);
    }

    public static float lengthSquared(Vec2 a) {
        return dot(a, a);
    }

    public static float distance(Vec2 a, Vec2 b) {
        return length(a.subtract(b));
    }

    public static float distanceSquared(Vec2 a, Vec2 b) {
        return lengthSquared(a.subtract(b));
    }

    public static Vec2 normalize(Vec2 a) {
        return a.divide(length(a));
    }

    public static float dot(Vec2 a, Vec2 b) {
        return a.x * b.x + a.y * b.y;
    }
}
