package net.rk4z.juef;

public class UefView {
    private long viewPtr;

    public UefView(int viewPtr) {
        this.viewPtr = viewPtr;
    }

//>------------------- Native methods --------------------<\\

    public static native void focus();

//>------------------- Native methods --------------------<\\

    /**
     * @deprecated This is a low-level function that directly returns the View's Ptr and should not be used unless really necessary
     *
     * @return The View's Ptr
     */
    public long getViewPtr() {
        return viewPtr;
    }

}
