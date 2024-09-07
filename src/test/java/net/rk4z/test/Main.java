package net.rk4z.test;

import net.rk4z.juef.*;

public class Main {
    public static void main(String[] args) {
        Uef instance = new Uef();
        instance.extractLibrariesAndLoad();
        System.load("C:\\Users\\main\\IdeaProjects\\java-uef\\cbuild\\Release\\Uef.dll");

        instance.getApp().createApp(new UefConfig(), new UefSettings());

        instance.getApp().run();
    }
}
