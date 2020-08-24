#include <jni.h>
#include <string>
#include "dlna.h"

extern "C" JNIEXPORT jstring JNICALL Java_com_fourkgarden_dlanupnp_MainActivity_stringFromJNI(JNIEnv* env,jobject) {
    dlna_t *dlna;
    dlna_profile_t *p;
    dlna_org_flags_t flags;

    flags = static_cast<dlna_org_flags_t>(DLNA_ORG_FLAG_STREAMING_TRANSFER_MODE |
                                          DLNA_ORG_FLAG_BACKGROUND_TRANSFERT_MODE |
                                          DLNA_ORG_FLAG_CONNECTION_STALL |
                                          DLNA_ORG_FLAG_DLNA_V15);

    printf ("Using %s\n", LIBDLNA_IDENT);

    dlna = dlna_init();
    dlna_set_verbosity(dlna,1);
    dlna_register_all_media_profiles (dlna);
    p = dlna_guess_media_profile (dlna, "/sdcard/1.mp3");
    char data[10240];
    if (p)
    {
        char *protocol_info;

        sprintf (data,"ID: %s\n", p->id);
        sprintf (data,"MIME: %s\n", p->mime);
        sprintf (data,"Label: %s\n", p->label);
        sprintf (data,"Class: %d\n", p->clazz);
        sprintf (data,"UPnP Object Item: %s\n", dlna_profile_upnp_object_item (p));

        protocol_info = dlna_write_protocol_info (DLNA_PROTOCOL_INFO_TYPE_HTTP,DLNA_ORG_PLAY_SPEED_NORMAL,DLNA_ORG_CONVERSION_NONE,DLNA_ORG_OPERATION_RANGE,flags, p);
        sprintf (data,"Protocol Info: %s\n", protocol_info);
        free (protocol_info);
    }
    else {
        printf("Unknown format\n");
    }
    dlna_uninit (dlna);
    return env->NewStringUTF(data);
}
