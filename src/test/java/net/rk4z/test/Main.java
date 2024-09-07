package net.rk4z.test;

import net.rk4z.juef.*;

public class Main {
    public static void main(String[] args) {
        System.load("C:\\Users\\main\\IdeaProjects\\java-uef\\bin\\win\\UltralightCore.dll");
        System.load("C:\\Users\\main\\IdeaProjects\\java-uef\\bin\\win\\WebCore.dll");
        System.load("C:\\Users\\main\\IdeaProjects\\java-uef\\bin\\win\\Ultralight.dll");
        System.load("C:\\Users\\main\\IdeaProjects\\java-uef\\bin\\win\\AppCore.dll");
        System.load("C:\\Users\\main\\IdeaProjects\\java-uef\\cbuild\\Release\\Uef.dll");

        UefApp app = new UefApp();
        UefSettings settings = new UefSettings();
        UefConfig config = new UefConfig(settings);

        app.createApp(config, settings);
    }
}
