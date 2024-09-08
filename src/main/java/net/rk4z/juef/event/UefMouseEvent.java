package net.rk4z.juef.event;

public class UefMouseEvent {
    public enum Type {
        MouseMoved,
        MouseDown,
        MouseUp
    }

    public enum Button {
        None,
        Left,
        Middle,
        Right
    }

    public Type type;
    public int x;
    public int y;
    public Button button;

    public UefMouseEvent(Type type, int x, int y, Button button) {
        this.type = type;
        this.x = x;
        this.y = y;
        this.button = button;
    }

    @Override
    public String toString() {
        return "UefMouseEvent [type=" + type + ", x=" + x + ", y=" + y + ", button=" + button + "]";
    }
}
