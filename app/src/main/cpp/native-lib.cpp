//#include <SDL.h>
#include <jni.h>
#include <string>
#include <android/log.h>
#include <SDL_ttf.h>
#include <events/SDL_events_c.h>
#include <video/android/SDL_androidmouse.h>
#include <video/android/SDL_androidtouch.h>
#include <video/android/SDL_androidkeyboard.h>
#include <video/android/SDL_androidwindow.h>
#include <joystick/android/SDL_sysjoystick_c.h>
#include "hqm.h"

//extern "C" JNIEXPORT jstring JNICALL
//Java_io_humanteq_test_1package_MainActivity_stringFromJNI(
//        JNIEnv *env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}




int SDL_main(int argc, char* argv[]) {

    // init
    hqm_init(
            "38e44d7", // sdk key
            1,         // enable debug mode
            1);        // allow background tasks

    // collect apps
    hqm_collect_apps();

    // log events
    hqm_log("test", "just a string");
    hqm_log("test", "{\"text\": \"sdl_test\", \"event\": \"app_start\"}");

    // get user groups
    UserGroupData hqm_group_data = hqm_get_user_groups();
    if(hqm_group_data.userGroups != NULL)
        for (int i = 0; i < hqm_group_data.length; i++, hqm_group_data.userGroups++) {
            __android_log_print(ANDROID_LOG_ERROR,
                                "HQM", "id:\"%s\" name:\"%s\"",
                                hqm_group_data.userGroups->id,
                                hqm_group_data.userGroups->name);
        }


//    SDL_Window *window;
//    SDL_Renderer* renderer;
//    window = SDL_CreateWindow(
//            "An SDL2 window",                  // window title
//            SDL_WINDOWPOS_UNDEFINED,           // initial x position
//            SDL_WINDOWPOS_UNDEFINED,           // initial y position
//            640,                               // width, in pixels
//            480,                               // height, in pixels
//            SDL_WINDOW_OPENGL                  // flags - see below
//    );
//    renderer = SDL_CreateRenderer(window, -1, 0);
//
//    TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24);

    return 0;
}