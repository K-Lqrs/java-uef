package net.rk4z.juef.event;

public enum UefMessageSource {
    XML(0),
    JS(1),
    Network(2),
    ConsoleAPI(3),
    Storage(4),
    AppCache(5),
    Rendering(6),
    CSS(7),
    Security(8),
    ContentBlocker(9),
    Other(10);

    private final int value;

    UefMessageSource(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public static UefMessageSource fromValue(int value) {
        for (UefMessageSource source : UefMessageSource.values()) {
            if (source.value == value) {
                return source;
            }
        }
        return Other;
    }
}
