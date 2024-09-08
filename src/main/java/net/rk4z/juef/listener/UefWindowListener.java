package net.rk4z.juef.listener;

import net.rk4z.juef.event.UefKeyEvent;
import net.rk4z.juef.event.UefMouseEvent;
import net.rk4z.juef.event.UefScrollEvent;

public interface UefWindowListener {
    void onClose();

    void onResize(int width, int height);

    boolean onKeyEvent(UefKeyEvent event);

    boolean onMouseEvent(UefMouseEvent event);

    boolean onScrollEvent(UefScrollEvent event);
}
