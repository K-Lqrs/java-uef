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

    /**
     * This method is called when a new child view is requested by the current view.
     * It is usually triggered when a user clicks a link with `target="_blank"` or
     * when JavaScript calls `window.open(url)`. The method is responsible for creating
     * a new view to display the content.
     * <p>
     * If a new view is created, it returns the native pointer to the new view.
     * Otherwise, returning 0 will indicate that the view was not created and the
     * default behavior will be used (handled by the C++ side).
     *
     * @deprecated This method is not implemented yet.
     *
     * @param viewPtr The native pointer to the view that triggered this event.
     * @param openerUrl The URL of the page that initiated the request.
     * @param targetUrl The URL that the new view will navigate to.
     * @param isPopup Indicates whether this was triggered by `window.open()` (true if it was).
     * @param popupRect The requested dimensions and coordinates for the new view (if specified).
     *                  This can be respected or ignored based on your implementation.
     * @return The native pointer to the new view, or 0 if the view was not created.
     */
    @Deprecated
    long onCreateChildView(long viewPtr, String openerUrl, String targetUrl, boolean isPopup, IntRect popupRect);

    /**
     * This method is called when the current view requests to create a new view
     * to display the local inspector (Developer Tools).
     * <p>
     * The inspector view allows the user to inspect and debug the content of the
     * current page (HTML, CSS, JavaScript). It is typically used to open Developer Tools.
     * <p>
     * If a new inspector view is created, the native pointer to the new view is returned.
     * If the view is not created, returning 0 will indicate that the request is not handled
     * and the default behavior will be applied (handled by the C++ side).
     *
     * @deprecated This method is not implemented yet.
     *
     * @param viewPtr The native pointer to the view that requested the inspector.
     * @param isLocal Indicates whether the inspected content is local (true for local content).
     * @param inspectedUrl The URL of the content that is being inspected.
     * @return The native pointer to the new inspector view, or 0 if the view was not created.
     */
    @Deprecated
    long onCreateInspectorView(long viewPtr, boolean isLocal, String inspectedUrl);

    void onRequestClose(long viewPtr);
}
