package com.example.jniapp;

public class JNIWrapper {
    public static native void JNIOnSurfaceCreated();
    public static native void JNIOnSurfaceChanged(int width, int height);
    public static native void JNIOnDrawFrame();

    static {
        System.loadLibrary("native-lib");
    }
}