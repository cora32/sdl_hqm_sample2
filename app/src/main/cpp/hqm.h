//
// Created by back on 31.07.19.
//

#ifndef SDL2_HQM_TEST_HQM_H
#define SDL2_HQM_TEST_HQM_H

typedef struct _UserGroup {
    const char *id;
    const char *name;
} UserGroup;

typedef struct _UserGroupData {
    const UserGroup *userGroups;
    const int length;
} UserGroupData;

void hqm_init(char *key_string, int enable_debug, int enable_background_tasks);
void hqm_collect_apps();
void hqm_log(char *event_name, char *event_data);
UserGroupData hqm_get_user_groups();


#endif //SDL2_HQM_TEST_HQM_H
