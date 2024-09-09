package net.rk4z.test;

import net.rk4z.juef.*;
import net.rk4z.juef.event.*;
import net.rk4z.juef.listener.UefViewListener;
import net.rk4z.juef.listener.UefWindowListener;
import net.rk4z.juef.util.IntRect;


public class Main {
    public static void main(String[] args) {
        UefApp app = new UefApp();
        app.getHelper().extractLibrariesAndLoad();
        System.load("C:\\Users\\main\\IdeaProjects\\java-uef\\cbuild\\Release\\Uef.dll");

        app.createApp(new UefConfig(), new UefSettings());

        int flags = WindowFlags.combine(WindowFlags.Titled, WindowFlags.Resizable, WindowFlags.Maximizable);

        // Create a window instance
        try (UefWindow window = new UefWindow("Hello World", "https://google.com", 50, 50, 800, 600, false, flags)) {
            // Set window listener
            window.setWindowListener(new UefWindowListener() {
                @Override
                public void onClose() {
                    System.exit(0);
                    System.out.println("Window closed");
                    app.destroy();
                }

                @Override
                public void onResize(int width, int height) {
                    System.out.println("Window resized: " + width + "x" + height);
                }

                @Override
                public boolean onKeyEvent(UefKeyEvent event) {
                    System.out.println("Key event: " + event.virtualKeyCode);
                    return true;
                }

                @Override
                public boolean onMouseEvent(UefMouseEvent event) {
                    System.out.println("Mouse event: " + event.x + ", " + event.y + ", " + event.button + ", " + event.type);
                    return true;
                }

                @Override
                public boolean onScrollEvent(UefScrollEvent event) {
                    System.out.println("Scroll event: " + event.deltaX + ", " + event.deltaY + ", " + event.type);
                    return true;
                }
            });

            // Set view listener
            window.setViewListener(new UefViewListener() {
                @Override
                public void onChangeTitle(long viewPtr, String title) {
                    System.out.println("Title changed: " + title);
                }

                @Override
                public void onChangeURL(long viewPtr, String url) {
                    System.out.println("URL changed: " + url);
                }

                @Override
                public void onChangeTooltip(long viewPtr, String tooltip) {
                    System.out.println("Tooltip changed: " + tooltip);
                }

                @Override
                public void onChangeCursor(long viewPtr, UefCursor cursor) {
                    System.out.println("Cursor changed: " + cursor);
                }

                @Override
                public void onAddConsoleMessage(long viewPtr, UefMessageSource source, UefMessageLevel level, String message, int lineNumber, int columnNumber, String sourceId) {
                    System.out.println("Console message: " + source + ", " + level + ", " + message + ", " + lineNumber + ", " + columnNumber + ", " + sourceId);
                }

                @Override
                public long onCreateChildView(long viewPtr, String openerUrl, String targetUrl, boolean isPopup, IntRect popupRect) {
                    return 0;
                }

                @Override
                public long onCreateInspectorView(long viewPtr, boolean isLocal, String inspectedUrl) {
                    return 0;
                }

                @Override
                public void onRequestClose(long viewPtr) {
                    System.out.println("Request close");
                }
            });

            app.run();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
