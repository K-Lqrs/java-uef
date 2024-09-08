package net.rk4z.test;

import net.rk4z.juef.*;
import net.rk4z.juef.listener.UefWindowListener;
import net.rk4z.juef.event.UefKeyEvent;
import net.rk4z.juef.event.UefMouseEvent;
import net.rk4z.juef.event.UefScrollEvent;

public class Main {
    public static void main(String[] args) {
        Uef instance = new Uef();
        instance.extractLibrariesAndLoad();
        System.load("C:\\Users\\main\\IdeaProjects\\java-uef\\cbuild\\Release\\Uef.dll");

        instance.getApp().createApp(new UefConfig(), new UefSettings());

        try (UefWindow window = new UefWindow("Hello World", "https://google.com", 50, 50, 800, 600)) {

            window.setWindowListener(new UefWindowListener() {
                @Override
                public void onClose() {
                    System.out.println("Window closed");
                    System.exit(0);
                }

                @Override
                public void onResize(int width, int height) {
                    System.out.println("Window resized: " + width + "x" + height);
                }

                @Override
                public boolean onKeyEvent(UefKeyEvent event) {
                    System.out.println("Key event: " + event);
                    return true;
                }

                @Override
                public boolean onMouseEvent(UefMouseEvent event) {
                    System.out.println("Mouse event: " + event);
                    return true;
                }

                @Override
                public boolean onScrollEvent(UefScrollEvent event) {
                    System.out.println("Scroll event: " + event);
                    return true;
                }
            });

            // アプリの実行
            instance.getApp().run();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
