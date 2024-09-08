package net.rk4z.juef;

import org.jetbrains.annotations.Contract;
import org.jetbrains.annotations.NotNull;

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

    @Contract(pure = true)
    public static int combine(@NotNull WindowFlags... flags) {
        int combinedValue = 0;
        for (WindowFlags flag : flags) {
            combinedValue |= flag.getValue();  // ビットORを使ってフラグを組み合わせる
        }
        return combinedValue;
    }
}
