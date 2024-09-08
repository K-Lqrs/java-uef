package net.rk4z.juef.event;

public class UefKeyEvent {
    public enum Type {
        KeyDown,
        KeyUp,      // kType_KeyUp
        RawKeyDown, // kType_RawKeyDown
        Char        // kType_Char
    }

    public static class Modifiers {
        public static final int AltKey = 1 << 0;
        public static final int CtrlKey = 1 << 1;
        public static final int MetaKey = 1 << 2;
        public static final int ShiftKey = 1 << 3;
    }

    public Type type;
    public int modifiers;
    public int virtualKeyCode;
    public int nativeKeyCode;
    public String keyIdentifier;
    public String text;
    public String unmodifiedText;
    public boolean isKeypad;
    public boolean isAutoRepeat;
    public boolean isSystemKey;

    public UefKeyEvent(Type type) {
        this.type = type;
    }

    public UefKeyEvent(Type type, int virtualKeyCode, int nativeKeyCode, boolean isSystemKey) {
        this.type = type;
        this.virtualKeyCode = virtualKeyCode;
        this.nativeKeyCode = nativeKeyCode;
        this.isSystemKey = isSystemKey;
    }

    public static native String getKeyIdentifierFromVirtualKeyCode(int virtualKeyCode);

    public static native String getKeyFromVirtualKeyCode(int virtualKeyCode, boolean shift);
}
