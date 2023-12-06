#include <jni.h>
#include <string>
#include <GLES2/gl2.h>
#include <GLES/gl.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jniapp_JNIWrapper_onsurfacecreated(JNIEnv *env, jclass cls) {
    glClearColor(0.21f, 0.43f, 0.71f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glOrthof(-8, 8, -8, 8, -8, 8);
    glEnable(GL_DEPTH_TEST); // подключение теста глубины
    glMatrixMode(GL_MODELVIEW);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_jniapp_JNIWrapper_onsurfacechanged(JNIEnv *env, jclass cls, jint width,
                                                  jint height) {
}

GLfloat vertices[] = { -1.0f, -1.0f,  0.0f, // 0
                        1.0f, -1.0f,  0.0f, // 1
                        1.0f,  1.0f,  0.0f, // 2
                       -1.0f,  1.0f,  0.0f, // 3
                       -1.0f, -1.0f, -0.0f, // 4
                        1.0f, -1.0f, -0.0f, // 5
                        1.0f,  1.0f, -0.0f, // 6
                       -1.0f,  1.0f, -0.0f, // 7
};

GLfloat textureCoords[] = {
        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,

        1.0f, 1.0f,
        0.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 0.0f,
};

int angle = 0;

extern "C"
JNIEXPORT void JNICALL Java_com_example_jniapp_JNIWrapper_ondrawframe(JNIEnv *env, jclass cls) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glScalef(3, 1.5, 3);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);

    angle = (angle == 360) ? 0 : angle + 2;
    glRotatef(angle, 0, 1, 0.25);



    // Face side
    glPushMatrix();
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

    // Back side
    glPushMatrix();
    glTranslatef(0, 0, -2);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

    // Upper side
    glPushMatrix();
    glTranslatef(0, 1, -1);
    glRotatef(90, 1, 0, 0);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

    // Down side
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, -1, 1);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

    // Left side
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(1, 0, -1);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

    // Right side
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(1, 0, 1);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glTexCoordPointer(2, GL_FLOAT, 0, textureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}
