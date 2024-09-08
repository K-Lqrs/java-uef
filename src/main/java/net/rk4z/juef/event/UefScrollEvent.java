package net.rk4z.juef.event;

public class UefScrollEvent {
    public enum Type {
        ScrollByPixel,
        ScrollByPage
    }

    public Type type;
    public int deltaX;
    public int deltaY;

    public UefScrollEvent(Type type, int deltaX, int deltaY) {
        this.type = type;
        this.deltaX = deltaX;
        this.deltaY = deltaY;
    }

    @Override
    public String toString() {
        return "UefScrollEvent [type=" + type + ", deltaX=" + deltaX + ", deltaY=" + deltaY + "]";
    }
}