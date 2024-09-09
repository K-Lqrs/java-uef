package net.rk4z.juef.listener;

import net.rk4z.juef.event.UefCursor;
import net.rk4z.juef.event.UefMessageLevel;
import net.rk4z.juef.event.UefMessageSource;
import net.rk4z.juef.util.IntRect;

public interface UefViewListener {
    void onChangeTitle(long viewPtr, String title);

    void onChangeURL(long viewPtr, String url);

    void onChangeTooltip(long viewPtr, String tooltip);

    void onChangeCursor(long viewPtr, UefCursor cursor);

    void onAddConsoleMessage(long viewPtr, UefMessageSource source, UefMessageLevel level, String message, int lineNumber, int columnNumber, String sourceId);

    long onCreateChildView(long viewPtr, String openerUrl, String targetUrl, boolean isPopup, IntRect popupRect);

    long onCreateInspectorView(long viewPtr, boolean isLocal, String inspectedUrl);

    void onRequestClose(long viewPtr);
}
