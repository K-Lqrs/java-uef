package net.rk4z.juef;

public enum WindowFlags {
    Borderless(1 << 0),
    Titled(1 << 1),
    Resizable(1 << 2),
    Maximizable(1 << 3),
    Hidden(1 << 4);

    private final int value;

    WindowFlags(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}
