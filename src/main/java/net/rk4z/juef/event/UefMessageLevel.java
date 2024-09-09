package net.rk4z.juef.event;

public enum UefMessageLevel {
    Log(1),
    Warning(2),
    Error(3),
    Debug(4),
    Info(5);

    private final int value;

    UefMessageLevel(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public static UefMessageLevel fromValue(int value) {
        for (UefMessageLevel level : UefMessageLevel.values()) {
            if (level.value == value) {
                return level;
            }
        }
        return Log; // デフォルトとしてLogを返す
    }
}

