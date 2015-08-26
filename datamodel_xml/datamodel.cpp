//
//  datamodel.cpp
//  datamodel_xml
//
//  Created by Pimpat on 8/24/2558 BE.
//  Copyright (c) 2558 Pimpat. All rights reserved.
//

#include "datamodel.h"

#define MAX_SQL_SIZE (10000)
#define TRUE 1
#define FALSE 0

enum EDGETYPE {
    _toUser,
    _toCategory,
    _toState,
    _toTask,
    _toSubTask,
};

/* datamodel function */
const char* stringUUID();
//const char* _createNewData(Data** data, int dataType);
DataHolder* createNewDataHolder();
//ObjectBinary* _createNewObjBinary(char* data, int dataType);
//int countDataContent(Data* data);

//void setDataName(Data* data, char* dataName);
//void setChatRoom(Data* data, char* chatRoom);
//char* getDataName(Data* data);
//char* getChatRoom(Data* data);
//
//ReturnErr setDataNameByID(char* dataID, char* dataName, DTPacket* dtPacket);
//ReturnErr setChatRoomByID(char* dataID, char* chatRoom, DTPacket* dtPacket);
//char* getDataNameByID(char* dataID, DTPacket* dtPacket);
//char* getChatRoomByID(char* dataID, DTPacket* dtPacket);
//
//ObjectBinary* getDataContent(Data* data);
//ObjectBinary* getDataContentLastestCommon(Data* data);
//ObjectBinary* getDataContentByID(char* dataID, DTPacket* dtPacket);
//ObjectBinary* getDataContentLastestCommonByID(char* dataID, DTPacket* dtPacket);
//
//Text getDiffDataAtHead(Data* data);
//Text getDiffDataAtLastestCommon(Data* data);
//Text getDiffDataAtHeadByID(char* dataID, DTPacket* dtPacket);
//Text getDiffDataAtLastestCommonByID(char* dataID, DTPacket* dtPacket);
//
//ObjectBinary* getContentNextVer(Data* data);
//ObjectBinary* getContentPreVer(Data* data);
//ObjectBinary* getContentNextVerByID(char* dataID, DTPacket* dtPacket);
//ObjectBinary* getContentPreVerByID(char* dataID, DTPacket* dtPacket);
//
//Text getDiffDataNextVer(Data* data);
//Text getDiffDataPreVer(Data* data);
//Text getDiffDataNextVerByID(char* dataID, DTPacket* dtPacket);
//Text getDiffDataPreVerByID(char* dataID, DTPacket* dtPacket);
//
//Text getDataContentWithTag(Data* data, char* tagName, char* id);
//Text getDataContentWithTagByID(char* dataID, char* tagName, char* id, DTPacket* dtPacket);
//
//ReturnErr setNewDataContent(Data* data, ObjectBinary* content);
//ReturnErr setNewDataDiffWithTag(Data* data, char* tagName, char* id, Text diff);
//ReturnErr saveNewDataContentByID(char* dataID, char* new_content, DTPacket* dtPacket);
//
//Text getTagContentWithName(ObjectBinary* fullContent, char* tagName, char* id);
//Text getTagContent(ObjectBinary* fullContent, int tagNameEnum, char* id);
//ReturnErr setTagContent(ObjectBinary* fullContent, Text newTagContent, char* tagName, char* id);

Text* getAttachmentFTOLinks(Data* data);

//const char* createOrg(Text orgName, Schema* orgSchema, DTPacket* dtPacket);
//const char* createUser(Text userName, Schema* userSchema, DTPacket* dtPacket);
//const char* createCategory(Text categoryName, Schema* categorySchema, DTPacket* dtPacket);
//const char* createState(Text stateName, Schema* stateSchema, DTPacket* dtPacket);
//const char* createTask(Text taskName, Schema* taskSchema, DTPacket* dtPacket);
//const char* createSubTask(Text subTaskName, Schema* subTaskSchema, DTPacket* dtPacket);
const char* createData(Text dataName, Schema* dataSchema, int dType, DTPacket* dtPacket);

//ReturnErr addUser2OrgByID(char* orgID, char* userID, DTPacket* dtPacket);
//ReturnErr addCategory2UserByID(char* userID, char* categoryID, DTPacket* dtPacket);
//ReturnErr addState2CategoryByID(char* categoryID, char* stateID, DTPacket* dtPacket);
//ReturnErr addTask2StateByID(char* stateID, char* taskID, DTPacket* dtPacket);
//ReturnErr addTask2CategoryByID(char* categoryID, char* taskID, DTPacket* dtPacket);
//ReturnErr addSubTask2TaskByID(char* taskID, char* subTaskID, DTPacket* dtPacket);
ReturnErr addData2DataByID(char* f_dataID, char* t_dataID, int dType, DTPacket* dtPacket);

//ReturnErr addUser2Org(char* orgID, User* user, DTPacket* dtPacket);
//ReturnErr addCategory2User(char* userID, Category* category, DTPacket* dtPacket);
//ReturnErr addState2Category(char* categoryID, State* state, DTPacket* dtPacket);
//ReturnErr addTask2State(char* stateID, Task* task, DTPacket* dtPacket);
//ReturnErr addTask2Category(char* categoryID, Task* task, DTPacket* dtPacket);
//ReturnErr addSubTask2Task(char* taskID, SubTask *subTask, DTPacket* dtPacket);
//ReturnErr addData2Data(char* dataID, Data* data, int dType, DTPacket* dtPacket);

//ReturnErr removeUserFromOrg(char* orgID, char* userID, DTPacket* dtPacket);
//ReturnErr removeCategoryFromUser(char* userID, char* categoryID, DTPacket* dtPacket);
//ReturnErr removeStateFromCategory(char* categoryID, char* stateID, DTPacket* dtPacket);
//ReturnErr removeTaskFromState(char* stateID, char* taskID, DTPacket* dtPacket);
//ReturnErr removeTaskFromCategory(char* categoryID, char* taskID, DTPacket* dtPacket);
//ReturnErr removeSubTaskFromTask(char* taskID, char* subTaskID, DTPacket* dtPacket);
ReturnErr removeDataFromData(char* f_dataID, char* t_dataID, DTPacket* dtPacket);

//ReturnErr deleteObj(char* userID, char* upperID, char* objID, DTPacket* dtPacket);
//ReturnErr flushTrash(char* userID, DTPacket* dtPacket);

//Org** queryOrgFromData(char* dataID, DTPacket* dtPacket);
//User** queryAllUsersFromData(char* dataID, DTPacket* dtPacket);
//Category** queryAllCategoriesFromData(char* dataID, DTPacket* dtPacket);
//State** queryAllStatesFromData(char* dataID, DTPacket* dtPacket);
//Task** queryAllTasksFromData(char* dataID, DTPacket* dtPacket);
//SubTask** queryAllSubTasksFromData(char* dataID, DTPacket* dtPacket);
Data** queryDataFromData(char* dataID, int dType, DTPacket* dtPacket);

Data* queryDataByRid(char* rid, DTPacket* dtPacket);
//Data* queryDataByID(char* dataID, DTPacket* dtPacket);

//char** getOrgID(DTPacket* dtPacket);
//char** getUserFromOrgID(char* orgID, DTPacket* dtPacket);
//char** getCatFromUserID(char* userID, DTPacket* dtPacket);
//char** getStateFromCatID(char* catID, DTPacket* dtPacket);
//char** getTaskFromStateID(char* stateID, DTPacket* dtPacket);
//char** getSubTaskFromTaskID(char* taskID, DTPacket* dtPacket);
//char** getTaskFromCatID(char* catID, DTPacket* dtPacket);
char** getDataFromDataID(char* dataID, int dType, DTPacket* dtPacket);

//t_bool isObjectOwnedByUser(char* userID, char* objID, DTPacket* dtPacket);
//t_bool isObjectUnderCategory(char* categoryID, char* objID, DTPacket* dtPacket);
//t_bool isObjectUnderState(char* stateID, char* objID, DTPacket* dtPacket);
//t_bool isObjectUnderTask(char* taskID, char* objID, DTPacket* dtPacket);
t_bool isObjectUnderData(char* dataID, char* objID, DTPacket* dtPacket);

int checkDeleted(char* dataID, DTPacket* dtPacket);

//void freeData(Data* data);
//void freeObjBinary(ObjectBinary* obj);

std::string& replace(std::string& s, const std::string& from, const std::string& to);

/* diff-patch function */
//string getDiff(char* old_str, char* new_str);
//string getPatch(char* str, char* str_patch);

/* transport and web function */
//  Pim
//char* buildStringFromData(Data* data);
//Data* buildDatafromString(char* strPack);
//char* readcontent(const char *filename);
//  N'Pla
//char* genString(Data* data);
//char* genMsg(Data* data);

//--------------------------------------------------------------------------------------------------------

const char *stringUUID(){
    char hex_char [] = "0123456789ABCDEF";
    char *uuidstr = (char*) malloc (sizeof (uuid_t) * 2 + 1);
    
    uuid_t uuid;
    uuid_generate (uuid);
    //    int i;
    //    for (i = 0; i < sizeof uuid; i ++) {
    //        printf("%02x ", uuid[i]);
    //    }
    //    printf("\n\n");
    int byte_nbr;
    for (byte_nbr = 0; byte_nbr < sizeof (uuid_t); byte_nbr++) {
        uuidstr [byte_nbr * 2 + 0] = hex_char [uuid [byte_nbr] >> 4];
        uuidstr [byte_nbr * 2 + 1] = hex_char [uuid [byte_nbr] & 15];
    }
    uuidstr[32]='\0';
    return uuidstr;
}

const char* _createNewData(Data** data, int dataType){
    *data = (Data*)malloc(sizeof(Data));
    Data* dt = *data;
    dt->dataID = stringUUID();
    printf("dataID: %s\n",dt->dataID);
    dt->dataName = NULL;
    dt->dataType = dataType;
    dt->content = createNewDataHolder();
    //    dt->attachmentFTOLinks = NULL;
    dt->chatRoom = NULL;
    return dt->dataID;
}

DataHolder* createNewDataHolder(){
    DataHolder* dh = (DataHolder*)malloc(sizeof(DataHolder));
    dh->versionKeeped = VER_KEEPED;
    dh->head = NULL;
    dh->lastestCommon = NULL;
    dh->current = NULL;
    return dh;
}

ObjectBinary* _createNewObjBinary(char* data, int dataType){
    ObjectBinary* obj = (ObjectBinary*)malloc(sizeof(ObjectBinary));
    obj->schemaCode = dataType;
    obj->byteCount = (int)strlen(data);
    obj->data = strdup(data);
    return obj;
}

int countDataContent(Data* data){
    //    printf("\n'countDataContent'\n");
    DataContent* dc = data->content->lastestCommon;
    if(dc==NULL){
        printf("\n!!! Not found DataContent !!!\n");
    }
    
    int i=1;
    while(dc!=NULL){
        //        printf("dc-SHA: %s\n",dc->SHA256hashCode);
        i++;
        if(dc->nextVersion!=NULL)
            dc = dc->nextVersion;
        else{
            break;
        }
    }
    //    printf("i: %d\n",i);
    return i;
}

void setDataName(Data* data, char* dataName){
    if(data->dataName == NULL){
        data->dataName = strdup(dataName);
    }
    else{
        free(data->dataName);
        data->dataName = strdup(dataName);
    }
}

char* getDataName(Data* data){
    if(data->dataName != NULL){
        char* result = strdup(data->dataName);
        return result;
    }
    else{
        return NULL;
    }
}

void setChatRoom(Data* data, char* chatRoom){
    if(data->chatRoom == NULL){
        data->chatRoom = strdup(chatRoom);
    }
    else{
        free(data->chatRoom);
        data->chatRoom = strdup(chatRoom);
    }
}

char* getChatRoom(Data* data){
    if(data->chatRoom != NULL){
        char* result = strdup(data->chatRoom);
        return result;
    }
    else{
        return NULL;
    }
}

ReturnErr setDataNameByID(char* dataID, char* dataName, DTPacket* dtPacket){
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        return -1;
    }
    
    char sql[MAX_SQL_SIZE];
    printf("--------------------------------------------------[update_dataName]\n");
    sprintf(sql,"update Data set dataName='%s' where dataID='%s'",dataName,dataID);
    int ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("setDataNameByID..FAILED(update_dataName)\n");
        return -1;
    }
    return 0;
}

ReturnErr setChatRoomByID(char* dataID, char* chatRoom, DTPacket* dtPacket){
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        return -1;
    }
    
    char sql[MAX_SQL_SIZE];
    printf("--------------------------------------------------[update_chatRoom]\n");
    sprintf(sql,"update Data set chatRoom='%s' where dataID='%s'",chatRoom,dataID);
    int ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("setChatRoomByID..FAILED(update_chatRoom)\n");
        return -1;
    }
    return 0;
}

char* getDataNameByID(char* dataID, DTPacket* dtPacket){
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    printf("--------------------------------------------------[get_dataName]\n");
    sprintf(sql,"select dataName from Data where dataID='%s'",dataID);
    char* result = getContent(sql,dtPacket);
    printf("result: %s\n",result);
    if(result == NULL){
        return NULL;
    }
    char *token, *dataName, *ptr;
//    token=strtok(result, "\"");
    token=strtok_r(result, "\"",&ptr);
//    token=strtok(NULL, "\"");
    token=strtok_r(NULL, "\"",&ptr);
    //    printf("token: %s\n",token);
    dataName = strdup(token);
    free(result);
    return dataName;
}

char* getChatRoomByID(char* dataID, DTPacket* dtPacket){
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    printf("--------------------------------------------------[get_chatRoom]\n");
    sprintf(sql,"select chatRoom from Data where dataID='%s'",dataID);
    char* result = getContent(sql,dtPacket);
    printf("result: %s\n",result);
    if(result == NULL){
        return NULL;
    }
    char *token, *chatRoom, *ptr;
//    token=strtok(result, "\"");
    token=strtok_r(result, "\"",&ptr);
//    token=strtok(NULL, "\"");
    token=strtok_r(NULL, "\"",&ptr);
    //    printf("token: %s\n",token);
    if(token != NULL){
        chatRoom = strdup(token);
        free(result);
        return chatRoom;
    }
    else{
        printf("'%s' not found chatRoom\n",dataID);
        free(result);
        return NULL;
    }
}

ObjectBinary* getDataContent(Data* data){
    if(data->content->head != NULL){
        ObjectBinary* obj_h = data->content->head->fullContent;
        //        ObjectBinary* result = createNewObjBinary(obj_h->data);
        ObjectBinary* result = _createNewObjBinary(obj_h->data,data->dataType);
        return result;
    }
    else
        return NULL;
}

ObjectBinary* getDataContentLastestCommon(Data* data){
    //  for test
    //    data->content->lastestCommon = data->content->lastestCommon->nextVersion;
    //    data->content->lastestCommon->preVersion = NULL;
    if(data->content->head != NULL){
        if(data->content->lastestCommon->fullContent != NULL && data->content->lastestCommon->plusPatch == NULL){
            //            ObjectBinary* result = createNewObjBinary(data->content->lastestCommon->fullContent->data);
            ObjectBinary* result = _createNewObjBinary(data->content->lastestCommon->fullContent->data, data->dataType);
            return result;
        }
        else{
            char* init_str = strdup(data->content->head->fullContent->data);
            string s;
            DataContent *mydc, *prev_mydc;
            for(mydc=data->content->head->preVersion;mydc!=NULL;mydc=prev_mydc){
                prev_mydc = mydc->preVersion;
                s = getPatch(init_str, mydc->minusPatch->data);
                free(init_str);
                init_str = strdup(s.c_str());
            }
            //            ObjectBinary* result = createNewObjBinary(init_str);
            ObjectBinary* result = _createNewObjBinary(init_str,data->dataType);
            free(init_str);
            return result;
        }
    }
    else
        return NULL;
}

ObjectBinary* getDataContentByID(char* dataID, DTPacket* dtPacket){
    printf(">> getDataContentByID\n");
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        //        printf("'%s' not found data or data is deleted\n",dataID);
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    char* result;
    printf("--------------------------------------------------[get_DataContent]\n");
    sprintf(sql,"select full_schemaCode,full_byteCount,full_data from (select expand(out('toDataHolder').outE('toDataContent')[type='head'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    printf("\nresult: %s\n",result);
    if(result==NULL){
        printf("'%s' not found fullContent\n",dataID);
        return NULL;
    }
    else{
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        ObjectBinary* obj =(ObjectBinary*)malloc(sizeof(ObjectBinary));
        
        char *token, *br, *pt_data;
        //  schemaCode
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("schemaCode: %s\n",token);
        obj->schemaCode = atoi(token);
        
        //  byteCount
        token = strtok_r(NULL,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        obj->byteCount = atoi(token);
        
        printf("br: %s\n",br);
        pt_data = br+11;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        obj->data = (char*)calloc(b_count+1,sizeof(char));
        memcpy(obj->data,pt_data,b_count);
        printf("obj_data: %s\n",obj->data);
        
        free(result);
        return obj;
    }
}

ObjectBinary* getDataContentLastestCommonByID(char* dataID, DTPacket* dtPacket){
    printf(">> getDataContentLastestCommonByID\n");
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        //        printf("'%s' not found data or data is deleted\n",dataID);
        return NULL;
    }
    
//    char sql[MAX_SQL_SIZE];
//    char* result;
    printf("--------------------------------------------------[get_DataContent]\n");
    Data* dt = queryDataByID(dataID,dtPacket);
    if(dt==NULL){
        return NULL;
    }
    else{
        ObjectBinary* obj = getDataContentLastestCommon(dt);
        freeData(dt);
        return obj;
    }
}

Text getDiffDataAtHead(Data* data){
    if(data->content->head != NULL && data->content->head->plusPatch != NULL){
        char* result = strdup(data->content->head->plusPatch->data);
        return result;
    }
    else
        return NULL;
}

Text getDiffDataAtLastestCommon(Data* data){
    //  for test
    //    data->content->lastestCommon = data->content->lastestCommon->nextVersion;
    if(data->content->lastestCommon != NULL && data->content->lastestCommon->plusPatch != NULL){
        char* result = strdup(data->content->lastestCommon->plusPatch->data);
        return result;
    }
    else
        return NULL;
}

Text getDiffDataAtHeadByID(char* dataID, DTPacket* dtPacket){
    printf(">> getDiffDataAtHeadByID\n");
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        //        printf("'%s' not found data or data is deleted\n",dataID);
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    char* result;
    printf("--------------------------------------------------[get_DiffData]\n");
    sprintf(sql,"select plus_byteCount,plus_data from (select expand(out('toDataHolder').outE('toDataContent')[type='head'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        printf("'%s' not found DiffData\n",dataID);
        return NULL;
    }
    else{
        printf("\nresult: %s\n",result);
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        char *token, *br, *pt_data, *diff;
        //  byteCount
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        
        printf("br: %s\n",br);
        pt_data = br+11;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        diff= (char*)calloc(b_count+1,sizeof(char));
        memcpy(diff,pt_data,b_count);
        printf("diff_data: %s\n",diff);
        
        free(result);
        return diff;
    }
}

Text getDiffDataAtLastestCommonByID(char* dataID, DTPacket* dtPacket){
    printf(">> getDiffDataAtLastestCommonByID\n");
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        //        printf("'%s' not found data or data is deleted\n",dataID);
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    char* result;
    printf("--------------------------------------------------[get_DiffData]\n");
    sprintf(sql,"select plus_byteCount,plus_data from (select expand(out('toDataHolder').outE('toDataContent')[type='lastestCommon'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        printf("'%s' not found DiffData\n",dataID);
        return NULL;
    }
    else{
        printf("\nresult: %s\n",result);
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        char *token, *br, *pt_data, *diff;
        //  byteCount
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        
        printf("br: %s\n",br);
        pt_data = br+11;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        diff= (char*)calloc(b_count+1,sizeof(char));
        memcpy(diff,pt_data,b_count);
        printf("diff_data: %s\n",diff);
        
        free(result);
        return diff;
    }
}

ObjectBinary* getContentNextVer(Data* data){
    if(data->content->current != NULL && data->content->current->nextVersion != NULL){
        if(data->content->current->nextVersion->fullContent!= NULL){
            //            ObjectBinary* result = createNewObjBinary(data->content->current->nextVersion->fullContent->data);
            ObjectBinary* result = _createNewObjBinary(data->content->current->nextVersion->fullContent->data,data->dataType);
            return result;
        }
        else{
            DataContent* dc = data->content->current;
            int i=0;
            while(dc!=NULL){
                i++;
                dc = dc->nextVersion;
            }
            i=i-1;
            
            char* init_str = strdup(data->content->head->fullContent->data);
            string s;
            DataContent *mydc, *prev_mydc;
            for(mydc=data->content->head->preVersion;mydc!=NULL;mydc=prev_mydc){
                if(i==0)
                    break;
                prev_mydc = mydc->preVersion;
                s = getPatch(init_str, mydc->minusPatch->data);
                free(init_str);
                init_str = strdup(s.c_str());
                i--;
            }
            //            ObjectBinary* result = createNewObjBinary(init_str);
            ObjectBinary* result = _createNewObjBinary(init_str,data->dataType);
            free(init_str);
            return result;
        }
    }
    else{
        printf("\n*** Now current is pointing to head\n");
        return NULL;
    }
}

ObjectBinary* getContentPreVer(Data* data){
    if(data->content->current != NULL && data->content->current->preVersion != NULL){
        if(data->content->current->preVersion->fullContent!= NULL){
            //            ObjectBinary* result = createNewObjBinary(data->content->current->preVersion->fullContent->data);
            ObjectBinary* result = _createNewObjBinary(data->content->current->preVersion->fullContent->data,data->dataType);
            return result;
        }
        else{
            DataContent* dc = data->content->current;
            int i=0;
            while(dc!=NULL){
                i++;
                dc = dc->nextVersion;
            }
            //            printf("i: %d\n",i);
            
            char* init_str = strdup(data->content->head->fullContent->data);
            string s;
            DataContent *mydc, *prev_mydc;
            for(mydc=data->content->head->preVersion;mydc!=NULL;mydc=prev_mydc){
                if(i==0)
                    break;
                prev_mydc = mydc->preVersion;
                s = getPatch(init_str, mydc->minusPatch->data);
                free(init_str);
                init_str = strdup(s.c_str());
                i--;
            }
            //            ObjectBinary* result = createNewObjBinary(init_str);
            ObjectBinary* result = _createNewObjBinary(init_str,data->dataType);
            free(init_str);
            return result;
        }
    }
    else{
        printf("\n*** Now current is pointing to lastestCommon\n");
        return NULL;
    }
}

ObjectBinary* getContentNextVerByID(char* dataID, DTPacket* dtPacket){
    printf(">> getContentNextVerByID\n");
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        //        printf("'%s' not found data or data is deleted\n",dataID);
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    char* result;
    printf("--------------------------------------------------[get_plus_next]\n");
    sprintf(sql,"select plus_byteCount,plus_data from (select expand(out('toDataHolder').outE('toDataContent')[type='current'].inV().outE('toContent')[type='next'].inV()) from Data where dataID='%s')",dataID);
    //  for test only
    //    sprintf(sql,"select plus_byteCount,plus_data from (select expand(out('toDataHolder').outE('toDataContent')[type='current'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    char *plus_diff, *full;
    
    if(result==NULL){
        printf("'%s' not found DiffData\n",dataID);
        return NULL;
    }
    else{
        printf("\nresult: %s\n",result);
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        char *token, *br, *pt_data;
        //  byteCount
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        
        printf("br: %s\n",br);
        pt_data = br+11;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        plus_diff= (char*)calloc(b_count+1,sizeof(char));
        memcpy(plus_diff,pt_data,b_count);
        printf("plus_diff: %s\n",plus_diff);
        
        free(result);
    }
    
    //  for test only
    /*
     ObjectBinary *obj =getContentPreVerByID(dataID,dtPacket);
     string s;
     printf("\n\n\n\n\n--- string ---\n");
     printf("full: %s\n",obj->data);
     printf("patch: %s\n",plus_diff);
     
     s = getPatch(obj->data, plus_diff);
     obj->data = strdup(s.c_str());
     obj->byteCount = strlen(obj->data);
     printf("content_next: %s\n",obj->data);
     */
    
    printf("--------------------------------------------------[get_full_current]\n");
    sprintf(sql,"select full_schemaCode,full_byteCount,full_data from (select expand(out('toDataHolder').outE('toDataContent')[type='current'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    printf("\nresult: %s\n",result);
    ObjectBinary* obj ;
    
    if(result==NULL){
        printf("'%s' not found fullContent\n",dataID);
        free(plus_diff);
        return NULL;
    }
    else{
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        char *token, *br, *pt_data;
        obj =(ObjectBinary*)malloc(sizeof(ObjectBinary));
        
        //  schemaCode
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("schemaCode: %s\n",token);
        obj->schemaCode = atoi(token);
        
        //  byteCount
        token = strtok_r(NULL,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        
        printf("br: %s\n",br);
        pt_data = br+11;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        full = (char*)calloc(b_count+1,sizeof(char));
        memcpy(full,pt_data,b_count);
        printf("full: %s\n\n",full);
        
        free(result);
    }
    
    string s;
    //    printf("\n\n\n\n\n--- string ---\n");
    //    printf("full: %s\n",full);
    //    printf("patch: %s\n",plus_diff);
    
    s = getPatch(full, plus_diff);
    obj->data = strdup(s.c_str());
    obj->byteCount = (int)strlen(obj->data);
    //    printf("content_next: %s\n",obj->data);
    
    free(full);
    free(plus_diff);
    
    return obj;
    
    return NULL;
}

ObjectBinary* getContentPreVerByID(char* dataID, DTPacket* dtPacket){
    printf(">> getContentPreVerByID\n");
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        //        printf("'%s' not found data or data is deleted\n",dataID);
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    char* result;
    printf("--------------------------------------------------[get_minus_pre]\n");
    sprintf(sql,"select minus_byteCount,minus_data from (select expand(out('toDataHolder').outE('toDataContent')[type='current'].inV().outE('toContent')[type='pre'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    char *minus_diff, *full;
    
    if(result==NULL){
        printf("'%s' not found DiffData\n",dataID);
        return NULL;
    }
    else{
        printf("\nresult: %s\n",result);
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        char *token, *br, *pt_data;
        //  byteCount
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        
        printf("br: %s\n",br);
        pt_data = br+12;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        minus_diff= (char*)calloc(b_count+1,sizeof(char));
        memcpy(minus_diff,pt_data,b_count);
        printf("minus_diff: %s\n",minus_diff);
        
        free(result);
    }
    
    printf("--------------------------------------------------[get_full_current]\n");
    sprintf(sql,"select full_schemaCode,full_byteCount,full_data from (select expand(out('toDataHolder').outE('toDataContent')[type='current'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    printf("\nresult: %s\n",result);
    ObjectBinary* obj ;
    
    if(result==NULL){
        printf("'%s' not found fullContent\n",dataID);
        free(minus_diff);
        return NULL;
    }
    else{
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        char *token, *br, *pt_data;
        obj =(ObjectBinary*)malloc(sizeof(ObjectBinary));
        
        //  schemaCode
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("schemaCode: %s\n",token);
        obj->schemaCode = atoi(token);
        
        //  byteCount
        token = strtok_r(NULL,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        
        printf("br: %s\n",br);
        pt_data = br+11;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        full = (char*)calloc(b_count+1,sizeof(char));
        memcpy(full,pt_data,b_count);
        printf("full: %s\n\n",full);
        
        free(result);
    }
    
    string s;
    //    printf("\n\n\n\n\n--- string ---\n");
    //    printf("full: %s\n",full);
    //    printf("patch: %s\n",minus_diff);
    
    s = getPatch(full, minus_diff);
    obj->data = strdup(s.c_str());
    obj->byteCount = (int)strlen(obj->data);
    //    printf("content_pre: %s\n",obj->data);
    
    free(full);
    free(minus_diff);
    
    return obj;
}

Text getDiffDataNextVer(Data* data){
    if(data->content->current != NULL && data->content->current->nextVersion != NULL){
        char* result = strdup(data->content->current->nextVersion->plusPatch->data);
        return result;
    }
    else{
        printf("\n*** Now current is pointing to head\n");
        return NULL;
    }
}

Text getDiffDataPreVer(Data* data){
    if(data->content->current != NULL && data->content->current->preVersion != NULL){
        if(data->content->current->preVersion->plusPatch != NULL){
            char* result = strdup(data->content->current->preVersion->plusPatch->data);
            return result;
        }
        else{
            printf("\n*** PreVersion is initial xml\n");
            return NULL;
        }
    }
    else{
        printf("\n*** Now current is pointing to lastestCommon\n");
        return NULL;
    }
}

Text getDiffDataNextVerByID(char* dataID, DTPacket* dtPacket){
    printf(">> getDiffDataNextVerByID\n");
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        //        printf("'%s' not found data or data is deleted\n",dataID);
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    char* result;
    printf("--------------------------------------------------[get_plus_next]\n");
    //  fix 'lastestCommon' --> 'current'
    sprintf(sql,"select plus_byteCount,plus_data from (select expand(out('toDataHolder').outE('toDataContent')[type='current'].inV().outE('toContent')[type='next'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    printf("\nresult: %s\n",result);
    char* plus_diff;
    
    if(result==NULL){
        printf("'%s' not found DiffData\n",dataID);
        return NULL;
    }
    else{
        printf("\nresult: %s\n",result);
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        char *token, *br, *pt_data;
        //  byteCount
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        
        printf("br: %s\n",br);
        pt_data = br+11;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        plus_diff= (char*)calloc(b_count+1,sizeof(char));
        memcpy(plus_diff,pt_data,b_count);
        printf("plus_diff: %s\n",plus_diff);
        
        free(result);
        return plus_diff;
    }
}

Text getDiffDataPreVerByID(char* dataID, DTPacket* dtPacket){
    printf(">> getDiffDatatPreVerByID\n");
    int count = checkDeleted(dataID,dtPacket);
    if(count==-1){
        //        printf("'%s' not found data or data is deleted\n",dataID);
        return NULL;
    }
    
    char sql[MAX_SQL_SIZE];
    char* result;
    printf("--------------------------------------------------[get_plus_pre]\n");
    sprintf(sql,"select plus_byteCount,plus_data from (select expand(out('toDataHolder').outE('toDataContent')[type='current'].inV().outE('toContent')[type='pre'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    printf("\nresult: %s\n",result);
    char* plus_diff;
    
    if(result==NULL){
        printf("'%s' not found DiffData\n",dataID);
        return NULL;
    }
    else{
        printf("\nresult: %s\n",result);
        string init;
        init.assign(result);
        printf("before: %s\n",result);
        string res = replace(init,"\\'","'");
        res = replace(res,"\\\"","\"");
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        printf("replace: %s\n",res.c_str());
        printf("\n------------------------------------------------------------------------------------------------------------\n\n");
        
        free(result);
        result = strdup(res.c_str());
        
        char *token, *br, *pt_data;
        //  byteCount
        token = strtok_r(result,":",&br);
        token = strtok_r(NULL,",",&br);
        printf("bytecount: %s\n",token);
        
        printf("br: %s\n",br);
        pt_data = br+11;
        printf("pt_data: %s\n",pt_data);
        
        int b_count = atoi(token);
        printf("b_count: %d\n",b_count);
        
        plus_diff= (char*)calloc(b_count+1,sizeof(char));
        memcpy(plus_diff,pt_data,b_count);
        printf("plus_diff: %s\n",plus_diff);
        
        free(result);
        return plus_diff;
    }
}

Text getDataContentWithTag(Data* data, char* tagName, char* id){
    char* full_xml = strdup(data->content->head->fullContent->data);
    ezxml_t root = ezxml_parse_str(full_xml,strlen(full_xml));
    ezxml_t partial_data = ezxml_get(root,tagName,-1);
    
    if(partial_data==NULL) {
        printf("FAILED >> incorrect tag\n");
        free(full_xml);
        ezxml_free(root);
        return NULL;
    }
    
    ezxml_t link;
    char* link_id;
    int exist = 0;
    
    if(strcmp(tagName,"attachmentFTOLinks")==0){
        for(link = ezxml_child(partial_data, "link");link;link=link->next){
            link_id = (char*)ezxml_attr(link, "id");
            printf("link_id: %s\n",link_id);
            if(strcmp(link_id,id)==0){
                exist=1;
                break;
            }
        }
        if(exist==1){
            partial_data = link;
        }
        else{
            printf("FAILED >> incorrect id\n");
            free(full_xml);
            ezxml_free(root);
            return NULL;
        }
    }
    
    printf("val: %s\n",partial_data->txt);
    char* result = strdup(partial_data->txt);
    free(full_xml);
    ezxml_free(root);
    return result;
}

Text getDataContentWithTagByID(char* dataID, char* tagName, char* id, DTPacket* dtPacket){
    printf(">> getDataContentWithTagByID\n");
    ObjectBinary* obj = getDataContentByID(dataID,dtPacket);
    if(obj == NULL){
        return NULL;
    }
    char* res = getTagContentWithName(obj,tagName,id);
    freeObjBinary(obj);
    return res;
}

ReturnErr setNewDataContent(Data* data, ObjectBinary* content){
    int total = countDataContent(data);
    printf("\n[ DATA #%d ]\n",total);
    if(data->content->head==NULL && data->content->lastestCommon==NULL && data->content->current==NULL){
        DataContent* dc0 = (DataContent*)malloc(sizeof(DataContent));
        
        DataHolder* dh = data->content;
        dh->lastestCommon = dc0;
        dh->head = dc0;
        dh->current = dc0;
        
        dc0->preVersion = NULL;
        dc0->nextVersion = NULL;
        
        //  dc0 ------------------------------------------------------------
        dc0->dataHd = dh;
        dc0->SHA256hashCode = strdup("default_hashcode");
        dc0->timeStamp = NULL;
        dc0->isDiff = FALSE;
        
        //  dc0->fullContent
        ObjectBinary* obj0 = (ObjectBinary*)malloc(sizeof(ObjectBinary));
        dc0->fullContent = obj0;
        obj0->schemaCode = content->schemaCode;
        obj0->data = strdup(content->data);
        obj0->byteCount = content->byteCount;
        
        //  dc0->minusPatch
        dc0->minusPatch = NULL;
        
        //  dc0->plusPatch
        dc0->plusPatch = NULL;
        
        printf("full: %s\n",obj0->data);
        return obj0->byteCount;
    }
    else{
        DataContent* dc0 = data->content->head;                             //  old
        DataContent* dc1 = (DataContent*)malloc(sizeof(DataContent));       //  new
        
        DataHolder* dh = data->content;
        dh->head = dc1;
        dh->current = dc1;
        
        printf("old: %s\n",dc0->fullContent->data);
        printf("new: %s\n",content->data);
        
        string s_plus = getDiff(dc0->fullContent->data,content->data);
        string s_minus = getDiff(content->data,dc0->fullContent->data);
        printf("s_plus: %s\n",s_plus.c_str());
        printf("s_minus: %s\n",s_minus.c_str());
        
        dc0->nextVersion = dc1;
        dc1->preVersion = dc0;
        dc1->nextVersion = NULL;
        
        //  dc0 ------------------------------------------------------------
        dc0->isDiff = TRUE;
        
        //  dc0->fullContent
        free(dc0->fullContent->data);
        free(dc0->fullContent);
        dc0->fullContent = NULL;
        
        //  dc0->minusPatch
        ObjectBinary* obj0_minus = (ObjectBinary*)malloc(sizeof(ObjectBinary));
        dc0->minusPatch = obj0_minus;
        obj0_minus->schemaCode = content->schemaCode;
        obj0_minus->data = strdup(s_minus.c_str());
        obj0_minus->byteCount = (int)strlen(obj0_minus->data);
        
        //  dc0->plusPatch (not change)
        
        //  dc1 ------------------------------------------------------------
        dc1->dataHd = dh;
        dc1->SHA256hashCode = strdup("default_hashcode");
        dc1->timeStamp = NULL;
        dc1->isDiff = FALSE;
        
        //  dc1->fullContent
        ObjectBinary* obj1_full = (ObjectBinary*)malloc(sizeof(ObjectBinary));
        dc1->fullContent = obj1_full;
        obj1_full->schemaCode = content->schemaCode;
        obj1_full->data = strdup(content->data);
        obj1_full->byteCount = content->byteCount;
        
        //  dc1->minusPatch
        dc1->minusPatch = NULL;
        
        //  dc1->plusPatch
        ObjectBinary* obj1_plus = (ObjectBinary*)malloc(sizeof(ObjectBinary));
        dc1->plusPatch = obj1_plus;
        obj1_plus->schemaCode = content->schemaCode;
        obj1_plus->data = strdup(s_plus.c_str());
        obj1_plus->byteCount = (int)strlen(obj1_plus->data);
        
        printf("\n--- Check old/new data ---\n");
        if(dc0->minusPatch != NULL)
            printf("minus_old: %s\n",dc0->minusPatch->data);
        if(dc0->plusPatch != NULL)
            printf("plus_old: %s\n",dc0->plusPatch->data);
        if(dc0->fullContent != NULL)
            printf("full_old: %s\n",dc0->fullContent->data);
        if(dc1->minusPatch != NULL)
            printf("minus_new: %s\n",dc1->minusPatch->data);
        if(dc1->plusPatch != NULL)
            printf("plus_new: %s\n",dc1->plusPatch->data);
        if(dc1->fullContent != NULL)
            printf("full_new: %s\n",dc1->fullContent->data);
        
        return obj1_plus->byteCount;
    }
}

ReturnErr setNewDataDiffWithTag(Data* data, char* tagName, char* id, Text diff){
    printf("\n--- setNewDataDiffWithTag ---\n");
    DataContent* dc_old = data->content->head;
    char* old_xml = strdup(dc_old->fullContent->data);
    
    ezxml_t root = ezxml_parse_str(old_xml,strlen(old_xml));
    ezxml_t link, partial_data;
    
    int exist = 0;
    char *link_id, *val_after, *new_xml;
    string s;
    
    if(strcmp(tagName,"attachmentFTOLinks")==0){
        //  find tag "attachmentFTOLinks"
        partial_data = ezxml_get(root,tagName,-1);
        for(link = ezxml_child(partial_data, "link");link;link=link->next){
            link_id = (char*)ezxml_attr(link, "id");
            printf("link_id: %s\n",link_id);
            if(strcmp(link_id,id)==0){
                exist = 1;
                break;
            }
        }
        if(exist==1){
            printf("val_before: %s\n",link->txt);
            printf("val_diff: %s\n",diff);
            
            s = getPatch(link->txt,diff);
            val_after = strdup(s.c_str());
            printf("val_after: %s\n",val_after);
            
            ezxml_set_txt(link,val_after);
            new_xml = ezxml_toxml(root);
            printf("new_xml: %s\n", new_xml);
        }
        else{
            link = ezxml_add_child(partial_data,"link",0);
            ezxml_set_attr(link,"id",id);
            ezxml_set_txt(link, diff);
            new_xml = ezxml_toxml(root);
            val_after = NULL;
            printf("val_diff(full): %s\n",diff);
            printf("new_xml: %s\n", new_xml);
        }
    }
    else{
        partial_data = ezxml_get(root,tagName,-1);
        
        if(partial_data==NULL) {
            printf("FAILED >> incorrect tag\n");
            free(old_xml);
            ezxml_free(root);
            return -1;
        }
        
        printf("val_before: %s\n",partial_data->txt);
        printf("val_diff: %s\n",diff);
        
        s = getPatch(partial_data->txt,diff);
        val_after = strdup(s.c_str());
        printf("val_after: %s\n",val_after);
        
        ezxml_set_txt(partial_data,val_after);
        new_xml = ezxml_toxml(root);
        printf("new_xml: %s\n", new_xml);
    }
    
    //    ObjectBinary* objB = createNewObjBinary(new_xml);
    ObjectBinary* objB = _createNewObjBinary(new_xml,data->dataType);
    int ret = setNewDataContent(data, objB);
    
    free(objB->data);
    free(objB);
    free(old_xml);
    if(val_after != NULL)
        free(val_after);
    free(new_xml);
    ezxml_free(root);
    return ret;
}

ReturnErr saveNewDataContentByID(char* dataID, char* new_content, DTPacket* dtPacket){
    printf(">> saveNewDataContentByID\n");
    ObjectBinary* obj = getDataContentByID(dataID,dtPacket);
    if(obj == NULL){
        return -1;
    }
    
    printf("old: %s\n",obj->data);
    printf("new: %s\n",new_content);
    
    string s_plus = getDiff(obj->data,new_content);
    string s_minus = getDiff(new_content,obj->data);
    printf("s_plus: %s\n",s_plus.c_str());
    printf("s_minus: %s\n",s_minus.c_str());
    freeObjBinary(obj);
    
    char* minus_content = strdup(s_minus.c_str());
    char* plus_content = strdup(s_plus.c_str());
    //  full_content = new_content
    int minus_len = (int)strlen(minus_content);
    int plus_len = (int)strlen(plus_content);
    int full_len = (int)strlen(new_content);
    
    char sql[MAX_SQL_SIZE];
    char* result;
    
    printf("--------------------------------------------------[get_@rid-head,schemaCode]\n");
    sprintf(sql,"select @rid,full_schemaCode from (select expand(out('toDataHolder').outE('toDataContent')[type='head'].inV()) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        free(minus_content);
        free(plus_content);
        return -1;
    }
    printf("\nresult: %s\n",result);
    
    char *token, *ptr;
//    char* token = strtok(result,":");
    token = strtok_r(result,":",&ptr);
//    token = strtok(NULL,",");
    token = strtok_r(NULL,",",&ptr);
    printf("head_@rid: %s\n",token);
    char* rid_head = strdup(token);
    
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
//    token = strtok(NULL,",");
    token = strtok_r(NULL,",",&ptr);
    printf("schemaCode: %s\n\n",token);
    int schemaCode = atoi(token);
    
    free(result);
    
    string init_plus, init_minus, init_full;
    init_plus.assign(plus_content,plus_len);
    printf("before: %s\n",plus_content);
    string result_plus = replace(init_plus,"'","\\'");
    result_plus = replace(result_plus,"\"","\\\"");
    printf("replace(plus): %s\n",result_plus.c_str());
    char* res_plus = strdup(result_plus.c_str());
    
    init_minus.assign(minus_content,minus_len);
    printf("before: %s\n",minus_content);
    string result_minus = replace(init_minus,"'","\\'");
    result_minus = replace(result_minus,"\"","\\\"");
    printf("replace(minus): %s\n",result_minus.c_str());
    char* res_minus = strdup(result_minus.c_str());
    
    free(minus_content);
    free(plus_content);
    
    init_full.assign(new_content,full_len);
    printf("before: %s\n",new_content);
    string result_full = replace(init_full,"'","\\'");
    result_full = replace(result_full,"\"","\\\"");
    printf("replace(full): %s\n",result_full.c_str());
    char* res_full = strdup(result_full.c_str());
    
    //  update (add minus + remove full)
    //  create new dc (add plus + add full)
    //  move head, current
    //  add next(old head), pre(new head)
    
    //  old head
    int ret;
    printf("--------------------------------------------------[update_old_head]\n");
    sprintf(sql,"update %s set isDiff=%d, full_data=null, full_byteCount=null, full_schemaCode=null, minus_data='%s', minus_byteCount=%d, minus_schemaCode=%d",rid_head,TRUE,res_minus,minus_len,schemaCode);
    printf("SQL: %s\n",sql);
    ret = sendCommand(sql,dtPacket);
    
    if (ret!=0){
        printf("saveNewDataContentByID..FAILED(update_old_head)\n");
        free(rid_head);
        free(res_plus);
        free(res_minus);
        free(res_full);
        return -1;
    }
    
    //  new head
    short nhead_cltid;
    long nhead_rid;
    printf("--------------------------------------------------[create_new_vertex]\n");
    sprintf(sql,"CREATE VERTEX DataContent set isDiff=%d, SHA256hashCode='default-hash', full_data='%s', full_byteCount=%d, full_schemaCode=%d, plus_data='%s', plus_byteCount=%d, plus_schemaCode=%d",FALSE,res_full,full_len,schemaCode,res_plus,plus_len,schemaCode);
    printf("SQL: %s\n",sql);
    ret = createVertex(sql,&nhead_cltid,&nhead_rid,dtPacket);
    
    if (ret!=0){
        printf("saveNewDataContentByID..FAILED(create_new_vertex)\n");
        free(rid_head);
        free(res_plus);
        free(res_minus);
        free(res_full);
        return -1;
    }
    
    free(res_plus);
    free(res_minus);
    free(res_full);
    
    //  delete edge (head/current)
    printf("--------------------------------------------------[delete_edge_head/current]\n");
    sprintf(sql,"delete EDGE toDataContent from (select from (select expand(out('toDataHolder')) from Data where dataID='%s')) to %s where type='head' or type='current'",dataID,rid_head);
    printf("SQL: %s\n",sql);
    ret = sendCommand(sql,dtPacket);
    
    if (ret!=0){
        printf("saveNewDataContentByID..FAILED(delete_edge_head/current)\n");
        free(rid_head);
        return -1;
    }
    
    //  create edge (head/current)
    printf("--------------------------------------------------[create_edge_toDataContent_head]\n");
    sprintf(sql,"CREATE EDGE toDataContent from (select from (select expand(out('toDataHolder')) from Data where dataID='%s')) to #%d:%lu set type='head'",dataID,nhead_cltid,nhead_rid);
    printf("SQL: %s\n",sql);
    ret = sendCommand(sql,dtPacket);
    
    if (ret!=0){
        printf("saveNewDataContentByID..FAILED(edge_toDataContent_head)\n");
        free(rid_head);
        return -1;
    }
    
    printf("--------------------------------------------------[create_edge_toDataContent_current]\n");
    sprintf(sql,"CREATE EDGE toDataContent from (select from (select expand(out('toDataHolder')) from Data where dataID='%s')) to #%d:%lu set type='current'",dataID,nhead_cltid,nhead_rid);
    printf("SQL: %s\n",sql);
    ret = sendCommand(sql,dtPacket);
    
    if (ret!=0){
        printf("saveNewDataContentByID..FAILED(edge_toDataContent_current)\n");
        free(rid_head);
        return -1;
    }
    
    //  create edge (next/pre)
    printf("--------------------------------------------------[create_edge_toContent_Pre]\n");
    sprintf(sql,"CREATE EDGE toContent from #%d:%lu to %s set type='pre'",nhead_cltid,nhead_rid,rid_head);
    printf("SQL: %s\n",sql);
    ret = sendCommand(sql,dtPacket);
    
    if (ret!=0){
        printf("saveNewDataContentByID..FAILED(edge_toContent_Pre)\n");
        free(rid_head);
        return -1;
    }
    
    printf("--------------------------------------------------[create_edge_toContent_Next]\n");
    sprintf(sql,"CREATE EDGE toContent from %s to #%d:%lu set type='next'",rid_head,nhead_cltid,nhead_rid);
    printf("SQL: %s\n",sql);
    ret = sendCommand(sql,dtPacket);
    
    if (ret!=0){
        printf("saveNewDataContentByID..FAILED(edge_toContent_Next)\n");
        free(rid_head);
        return -1;
    }
    
    //  toDataHolder_fromDC
    printf("--------------------------------------------------[create_edge_toDataHolder_fromDC]\n");
    sprintf(sql,"CREATE EDGE toDataHolder_fromDC from #%d:%lu to (select from (select expand(out('toDataHolder')) from Data where dataID='%s'))",nhead_cltid,nhead_rid,dataID);
    printf("SQL: %s\n",sql);
    ret = sendCommand(sql,dtPacket);
    
    if (ret!=0){
        printf("saveNewDataContentByID..FAILED(edge_toDataHolder_fromDC)\n");
        free(rid_head);
        return -1;
    }
    
    free(rid_head);
    return 0;
}

Text getTagContentWithName(ObjectBinary* fullContent, char* tagName, char* id){
    char* full_xml = strdup(fullContent->data);
    ezxml_t root = ezxml_parse_str(full_xml,strlen(full_xml));
    ezxml_t partial_data = ezxml_get(root,tagName,-1);
    
    if(partial_data==NULL) {
        printf("FAILED >> incorrect tag\n");
        free(full_xml);
        ezxml_free(root);
        return NULL;
    }
    
    ezxml_t link;
    char* link_id;
    int exist = 0;
    
    if(strcmp(tagName,"attachmentFTOLinks")==0){
        for(link = ezxml_child(partial_data, "link");link;link=link->next){
            link_id = (char*)ezxml_attr(link, "id");
            printf("link_id: %s\n",link_id);
            if(strcmp(link_id,id)==0){
                exist=1;
                break;
            }
        }
        if(exist==1){
            partial_data = link;
        }
        else{
            printf("FAILED >> incorrect id\n");
            free(full_xml);
            ezxml_free(root);
            return NULL;
        }
    }
    
    printf("val: %s\n",partial_data->txt);
    char* result = strdup(partial_data->txt);
    free(full_xml);
    ezxml_free(root);
    return result;
}

Text getTagContent(ObjectBinary* fullContent, int tagNameEnum, char* id){
    char* full_xml = strdup(fullContent->data);
    ezxml_t root = ezxml_parse_str(full_xml,strlen(full_xml));
    ezxml_t partial_data;
    
    switch(tagNameEnum){
        case _attachmentFTOLinks:
            partial_data = ezxml_get(root,"attachmentFTOLinks",-1);
            break;
        case _content:
            partial_data = ezxml_get(root,"content",-1);
            break;
        case _book_id:
            partial_data = ezxml_get(root,"book_id",-1);
            break;
        case _author:
            partial_data = ezxml_get(root,"author",-1);
            break;
        case _title:
            partial_data = ezxml_get(root,"title",-1);
            break;
        case _genre:
            partial_data = ezxml_get(root,"genre",-1);
            break;
        case _price:
            partial_data = ezxml_get(root,"price",-1);
            break;
        default:
            partial_data = NULL;
            break;
    }
    
    if(partial_data==NULL) {
        printf("FAILED >> incorrect tag\n");
        free(full_xml);
        ezxml_free(root);
        return NULL;
    }
    
    ezxml_t link;
    char* link_id;
    int exist = 0;
    
    if(tagNameEnum==_attachmentFTOLinks){
        for(link = ezxml_child(partial_data, "link");link;link=link->next){
            link_id = (char*)ezxml_attr(link, "id");
            printf("link_id: %s\n",link_id);
            if(strcmp(link_id,id)==0){
                exist=1;
                break;
            }
        }
        if(exist==1){
            partial_data = link;
        }
        else{
            printf("FAILED >> incorrect id\n");
            free(full_xml);
            ezxml_free(root);
            return NULL;
        }
    }
    
    printf("val: %s\n",partial_data->txt);
    char* result = strdup(partial_data->txt);
    free(full_xml);
    ezxml_free(root);
    return result;
}

ReturnErr setTagContent(ObjectBinary* fullContent, Text newTagContent, char* tagName, char* id){
    char* full_xml = strdup(fullContent->data);
    ezxml_t root = ezxml_parse_str(full_xml,strlen(full_xml));
    
    ezxml_t link, partial_data;
    
    int exist = 0;
    char *link_id, *new_xml;
    string s;
    
    if(strcmp(tagName,"attachmentFTOLinks")==0){
        //  find tag "attachmentFTOLinks"
        partial_data = ezxml_get(root,tagName,-1);
        for(link = ezxml_child(partial_data, "link");link;link=link->next){
            link_id = (char*)ezxml_attr(link, "id");
            printf("link_id: %s\n",link_id);
            if(strcmp(link_id,id)==0){
                exist = 1;
                break;
            }
        }
        if(exist==1){
            ezxml_set_txt(link,newTagContent);
        }
        else{
            link = ezxml_add_child(partial_data,"link",0);
            ezxml_set_attr(link,"id",id);
            ezxml_set_txt(link, newTagContent);
        }
    }
    else{
        partial_data = ezxml_get(root,tagName,-1);
        
        if(partial_data==NULL) {
            printf("FAILED >> incorrect tag\n");
            free(full_xml);
            ezxml_free(root);
            return -1;
        }
        
        ezxml_set_txt(partial_data,newTagContent);
    }
    new_xml = ezxml_toxml(root);
    printf("new_xml: %s\n", new_xml);
    
    free(fullContent->data);
    fullContent->data = new_xml;
    fullContent->byteCount = (int)strlen(new_xml);
    
    free(full_xml);
    ezxml_free(root);
    return fullContent->byteCount;
}

Text* getAttachmentFTOLinks(Data* data){
    char* full_xml = strdup(data->content->head->fullContent->data);
    ezxml_t root = ezxml_parse_str(full_xml,strlen(full_xml));
    ezxml_t partial_data = ezxml_get(root,"attachmentFTOLinks",-1);
    
    ezxml_t link;
    char* link_id;
    int count = 0;
    
    for(link = ezxml_child(partial_data, "link");link;link=link->next){
        link_id = (char*)ezxml_attr(link, "id");
        printf("link_id: %s\n",link_id);
        count++;
    }
    
    if(count==0){
        printf("not found link in TAG 'attachmentFTOLinks'\n");
        free(full_xml);
        ezxml_free(root);
        return NULL;
    }
    
    Text* att_link = (Text*)malloc((count+1)*sizeof(Text));
    int i=0;
    for(link = ezxml_child(partial_data, "link");link;link=link->next){
        //        link_id = (char*)ezxml_attr(link, "id");
        printf("link_txt: %s\n",link->txt);
        att_link[i] = strdup(link->txt);
        i++;
    }
    att_link[i]=NULL;
    
    free(full_xml);
    ezxml_free(root);
    return att_link;
}

const char* createOrg(Text orgName, Schema* orgSchema, DTPacket* dtPacket){
    const char* uuidstr = createData(orgName,orgSchema,_org,dtPacket);
    return uuidstr;
}

const char* createUser(Text userName, Schema* userSchema, DTPacket* dtPacket){
    const char* uuidstr = createData(userName,userSchema,_user,dtPacket);
    return uuidstr;
}

const char* createCategory(Text categoryName, Schema* categorySchema, DTPacket* dtPacket){
    const char* uuidstr = createData(categoryName,categorySchema,_category,dtPacket);
    return uuidstr;
}

const char* createState(Text stateName, Schema* stateSchema, DTPacket* dtPacket){
    const char* uuidstr = createData(stateName,stateSchema,_state,dtPacket);
    return uuidstr;
}

const char* createTask(Text taskName, Schema* taskSchema, DTPacket* dtPacket){
    const char* uuidstr = createData(taskName,taskSchema,_task,dtPacket);
    return uuidstr;
}

const char* createSubTask(Text subTaskName, Schema* subTaskSchema, DTPacket* dtPacket){
    const char* uuidstr = createData(subTaskName,subTaskSchema,_subTask,dtPacket);
    return uuidstr;
}

const char* createData(Text dataName, Schema* dataSchema, int dType, DTPacket* dtPacket){
    //  schema isn't used
    const char* uuidstr = stringUUID();
    printf("uuid: %s\n",uuidstr);
    int ret;
    char sql[MAX_SQL_SIZE];
    
    short dt_cltid, dh_cltid, dl_cltid, dc_cltid;
    long dt_rid, dh_rid, dl_rid, dc_rid;
    
    //  Data
    printf("--------------------------------------------------[create_vertex_Data]\n");
    // chatRoom use setChatRoomByID
    sprintf(sql,"CREATE VERTEX Data set dataID='%s', dataType=%d, dataName='%s'",uuidstr,dType,dataName);
    ret = createVertex(sql,&dt_cltid,&dt_rid,dtPacket);
    if (ret!=0){
        printf("createData..FAILED(vertex_Data)\n");
        free((char*)uuidstr);
        return NULL;
    }
    
    //  DataHolder
    printf("--------------------------------------------------[create_vertex_DataHolder]\n");
    sprintf(sql,"CREATE VERTEX DataHolder set versionKeeped=%d",VER_KEEPED);
    ret = createVertex(sql,&dh_cltid,&dh_rid,dtPacket);
    if (ret!=0){
        printf("createData..FAILED(vertex_DataHolder)\n");
        free((char*)uuidstr);
        return NULL;
    }
    
    //  toDataHolder
    printf("--------------------------------------------------[create_edge_toDataHolder]\n");
    sprintf(sql,"CREATE EDGE toDataHolder from #%d:%lu to #%d:%lu",dt_cltid,dt_rid,dh_cltid,dh_rid);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("createData..FAILED(edge_toDataHolder)\n");
        free((char*)uuidstr);
        return NULL;
    }
    
    //  Delete (for User only)
    if(dType==_user){
        printf("--------------------------------------------------[create_vertex_DeleteNode]\n");
        sprintf(sql,"CREATE VERTEX DeleteNode set userID='%s'",uuidstr);
        ret = createVertex(sql,&dl_cltid,&dl_rid,dtPacket);
        if (ret!=0){
            printf("createData..FAILED(vertex_DeleteNode)\n");
            free((char*)uuidstr);
            return NULL;
        }
        
        //  toDelete
        printf("--------------------------------------------------[create_edge_toDelete]\n");
        sprintf(sql,"CREATE EDGE toDelete from #%d:%lu to #%d:%lu",dt_cltid,dt_rid,dl_cltid,dl_rid);
        ret = sendCommand(sql,dtPacket);
        if (ret!=0){
            printf("createData..FAILED(edge_toDelete)\n");
            free((char*)uuidstr);
            return NULL;
        }
    }
    
    //  DataContent
    printf("--------------------------------------------------[create_vertex_DataContent]\n");
    sprintf(sql,"CREATE VERTEX Datacontent set isDiff=%d, SHA256hashCode='%s', full_schemaCode=%d, full_byteCount=%d, full_data='%s'",FALSE,"h-a-s-h",dType,(int)strlen(dataSchema),dataSchema);
    //    printf("SQL: %s\n",sql);
    ret = createVertex(sql,&dc_cltid,&dc_rid,dtPacket);
    if (ret!=0){
        printf("createData..FAILED(vertex_DataContent)\n");
        free((char*)uuidstr);
        return NULL;
    }
    
    //  toDataContent(head)
    printf("--------------------------------------------------[create_edge_toDataContent_head]\n");
    sprintf(sql,"CREATE EDGE toDataContent from #%d:%lu to #%d:%lu set type='head'",dh_cltid,dh_rid,dc_cltid,dc_rid);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("createData..FAILED(edge_toDataContent_head)\n");
        free((char*)uuidstr);
        return NULL;
    }
    
    //  toDataContent(current)
    printf("--------------------------------------------------[create_edge_toDataContent_current]\n");
    sprintf(sql,"CREATE EDGE toDataContent from #%d:%lu to #%d:%lu set type='current'",dh_cltid,dh_rid,dc_cltid,dc_rid);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("createData..FAILED(edge_toDataContent_current)\n");
        free((char*)uuidstr);
        return NULL;
    }
    
    //  toDataContent(lastestCommon)
    printf("--------------------------------------------------[create_edge_toDataContent_lastestCommon]\n");
    sprintf(sql,"CREATE EDGE toDataContent from #%d:%lu to #%d:%lu set type='lastestCommon'",dh_cltid,dh_rid,dc_cltid,dc_rid);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("createData..FAILED(edge_toDataContent_lastestCommon)\n");
        free((char*)uuidstr);
        return NULL;
    }
    
    //  toDataHolder_fromDC
    printf("--------------------------------------------------[create_edge_toDataHolder_fromDC]\n");
    sprintf(sql,"CREATE EDGE toDataHolder_fromDC from #%d:%lu to #%d:%lu",dc_cltid,dc_rid,dh_cltid,dh_rid);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("createData..FAILED(edge_toDataHolder_fromDC)\n");
        free((char*)uuidstr);
        return NULL;
    }
    
    return uuidstr;
}

ReturnErr addUser2OrgByID(char* orgID, char* userID, DTPacket* dtPacket){
    int ret = addData2DataByID(orgID, userID, _toUser,dtPacket);
    return ret;
}

ReturnErr addCategory2UserByID(char* userID, char* categoryID, DTPacket* dtPacket){
    int ret = addData2DataByID(userID, categoryID, _toCategory,dtPacket);
    return ret;
}

ReturnErr addState2CategoryByID(char* categoryID, char* stateID, DTPacket* dtPacket){
    int ret = addData2DataByID(categoryID, stateID, _toState,dtPacket);
    return ret;
}

ReturnErr addTask2StateByID(char* stateID, char* taskID, DTPacket* dtPacket){
    int ret = addData2DataByID(stateID, taskID, _toTask,dtPacket);
    return ret;
}

ReturnErr addTask2CategoryByID(char* categoryID, char* taskID, DTPacket* dtPacket){
    int ret = addData2DataByID(categoryID, taskID, _toTask,dtPacket);
    return ret;
}

ReturnErr addSubTask2TaskByID(char* taskID, char* subTaskID, DTPacket* dtPacket){
    int ret = addData2DataByID(taskID, subTaskID, _toSubTask,dtPacket);
    return ret;
}

ReturnErr addData2DataByID(char* f_dataID, char* t_dataID, int dType, DTPacket* dtPacket){
    int ret;
    char sql[MAX_SQL_SIZE];
    
    switch(dType){
        case _toUser:
            printf("--------------------------------------------------[create_edge_toUser]\n");
            sprintf(sql,"create edge toUser from (select from Data where dataID='%s') to (select from Data where dataID='%s')",f_dataID,t_dataID);
            break;
        case _toCategory:
            printf("--------------------------------------------------[create_edge_toCategory]\n");
            sprintf(sql,"create edge toCategory from (select from Data where dataID='%s') to (select from Data where dataID='%s')",f_dataID,t_dataID);
            break;
        case _toState:
            printf("--------------------------------------------------[create_edge_toState]\n");
            sprintf(sql,"create edge toState from (select from Data where dataID='%s') to (select from Data where dataID='%s')",f_dataID,t_dataID);
            break;
        case _toTask:
            printf("--------------------------------------------------[create_edge_toTask]\n");
            sprintf(sql,"create edge toTask from (select from Data where dataID='%s') to (select from Data where dataID='%s')",f_dataID,t_dataID);
            break;
        case _toSubTask:
            printf("--------------------------------------------------[create_edge_toSubTask]\n");
            sprintf(sql,"create edge toSubTask from (select from Data where dataID='%s') to (select from Data where dataID='%s')",f_dataID,t_dataID);
            break;
        default:
            return -1;
            break;
    }
    
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("addData2DataByID..FAILED\n");
        return -1;
    }
    
    return 0;
}

ReturnErr addUser2Org(char* orgID, User* user, DTPacket* dtPacket){
    int ret = addData2Data(orgID, user, _toUser,dtPacket);
    return ret;
}

ReturnErr addCategory2User(char* userID, Category* category, DTPacket* dtPacket){
    int ret = addData2Data(userID, category, _toCategory,dtPacket);
    return ret;
    
}

ReturnErr addState2Category(char* categoryID, State* state, DTPacket* dtPacket){
    int ret = addData2Data(categoryID, state, _toState,dtPacket);
    return ret;
}

ReturnErr addTask2State(char* stateID, Task* task, DTPacket* dtPacket){
    int ret = addData2Data(stateID, task, _toTask,dtPacket);
    return ret;
}

ReturnErr addTask2Category(char* categoryID, Task* task, DTPacket* dtPacket){
    int ret = addData2Data(categoryID, task, _toTask,dtPacket);
    return ret;
}

ReturnErr addSubTask2Task(char* taskID, SubTask *subTask, DTPacket* dtPacket){
    int ret = addData2Data(taskID, subTask, _toSubTask,dtPacket);
    return ret;
}

ReturnErr addData2Data(char* dataID, Data* data, int dType, DTPacket* dtPacket){
    int ret;
    char sql[MAX_SQL_SIZE];
    
    short dt_cltid, dh_cltid, dl_cltid;
    long dt_rid, dh_rid, dl_rid;
    
    //  Data
    printf("--------------------------------------------------[create_vertex_Data]\n");
    sprintf(sql,"CREATE VERTEX Data set dataID='%s', dataType=%d, dataName='%s', chatRoom='%s'",data->dataID,data->dataType,data->dataName,data->chatRoom);
    ret = createVertex(sql,&dt_cltid,&dt_rid,dtPacket);
    if (ret!=0){
        printf("addData2Data..FAILED(vertex_Data)\n");
        return -1;
    }
    
    //  DataHolder
    printf("--------------------------------------------------[create_vertex_DataHolder]\n");
    sprintf(sql,"CREATE VERTEX DataHolder set versionKeeped=%d",data->content->versionKeeped);
    ret = createVertex(sql,&dh_cltid,&dh_rid,dtPacket);
    if (ret!=0){
        printf("addData2Data..FAILED(vertex_DataHolder)\n");
        return -1;
    }
    
    //  toDataHolder
    printf("--------------------------------------------------[create_edge_toDataHolder]\n");
    sprintf(sql,"CREATE EDGE toDataHolder from #%d:%lu to #%d:%lu",dt_cltid,dt_rid,dh_cltid,dh_rid);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("addData2Data..FAILED(edge_toDataHolder)\n");
        return -1;
    }
    
    //  Delete (for User only)
    if(dType==_toUser){
        printf("--------------------------------------------------[create_vertex_DeleteNode]\n");
        sprintf(sql,"CREATE VERTEX DeleteNode set userID='%s'",data->dataID);
        ret = createVertex(sql,&dl_cltid,&dl_rid,dtPacket);
        if (ret!=0){
            printf("addData2Data..FAILED(vertex_DeleteNode)\n");
            return -1;
        }
        
        //  toDelete
        printf("--------------------------------------------------[create_edge_toDelete]\n");
        sprintf(sql,"CREATE EDGE toDelete from #%d:%lu to #%d:%lu",dt_cltid,dt_rid,dl_cltid,dl_rid);
        ret = sendCommand(sql,dtPacket);
        if (ret!=0){
            printf("addData2Data..FAILED(edge_toDelete)\n");
            return -1;
        }
    }
    
    //  DataContent
    int count = countDataContent(data);
    count--;
    short dc_cltid[count];
    long dc_rid[count];
    //    printf("count: %d\n",count);
    int i=0;
    DataContent *dc, *next_dc;
    for(dc=data->content->lastestCommon;dc!=NULL;dc=next_dc){
        printf("--------------------------------------------------[create_vertex_DataContent #%d]\n",i);
        if(dc->fullContent != NULL && dc->minusPatch == NULL && dc->plusPatch == NULL){
            printf("case1\n");
            
            string init;
            init.assign(dc->fullContent->data,strlen(dc->fullContent->data));
            printf("before: %s\n",dc->fullContent->data);
            string result = replace(init,"'","\\'");
            result = replace(result,"\"","\\\"");
            printf("replace: %s\n",result.c_str());
            
            sprintf(sql,"CREATE VERTEX Datacontent set isDiff=%d, SHA256hashCode='%s', full_schemaCode=%d, full_byteCount=%d, full_data='%s'",dc->isDiff,dc->SHA256hashCode,dc->fullContent->schemaCode,dc->fullContent->byteCount,result.c_str());
        }
        else if(dc->plusPatch != NULL && dc->minusPatch != NULL && dc->fullContent == NULL){
            printf("case2\n");
            
            string init;
            init.assign(dc->plusPatch->data,strlen(dc->plusPatch->data));
            printf("before: %s\n",dc->plusPatch->data);
            string result = replace(init,"'","\\'");
            result = replace(result,"\"","\\\"");
            printf("replace: %s\n",result.c_str());
            
            string init2;
            init2.assign(dc->minusPatch->data,strlen(dc->minusPatch->data));
            printf("before: %s\n",dc->minusPatch->data);
            string result2 = replace(init2,"'","\\'");
            result2 = replace(result2,"\"","\\\"");
            printf("replace: %s\n",result2.c_str());
            
            sprintf(sql,"CREATE VERTEX Datacontent set isDiff=%d, SHA256hashCode='%s', plus_schemaCode=%d, plus_byteCount=%d, plus_data='%s', minus_schemaCode=%d, minus_byteCount=%d, minus_data='%s'",dc->isDiff,dc->SHA256hashCode,dc->plusPatch->schemaCode,dc->plusPatch->byteCount,result.c_str(),dc->minusPatch->schemaCode,dc->minusPatch->byteCount,result2.c_str());
        }
        else if(dc->plusPatch != NULL && dc->fullContent != NULL && dc->minusPatch == NULL){
            printf("case3\n");
            string init;
            init.assign(dc->fullContent->data,strlen(dc->fullContent->data));
            printf("before: %s\n",dc->fullContent->data);
            string result = replace(init,"'","\\'");
            result = replace(result,"\"","\\\"");
            printf("replace: %s\n",result.c_str());
            
            //  normal
            sprintf(sql,"CREATE VERTEX Datacontent set isDiff=%d, SHA256hashCode='%s', plus_schemaCode=%d, plus_byteCount=%d, plus_data='%s', full_schemaCode=%d, full_byteCount=%d, full_data='%s'",dc->isDiff,dc->SHA256hashCode,dc->plusPatch->schemaCode,dc->plusPatch->byteCount,dc->plusPatch->data,dc->fullContent->schemaCode,dc->fullContent->byteCount,result.c_str());
            
            //  json format
            //            sprintf(sql,"CREATE VERTEX Datacontent content {'isDiff':%d, 'plus_schemaCode':%d, 'plus_byteCount':%d, 'plus_data':'%s', 'full_schemaCode':%d, 'full_byteCount':%d, 'full_data':'%s'}",dc->isDiff,dc->plusPatch->schemaCode,dc->plusPatch->byteCount,dc->plusPatch->data,dc->fullContent->schemaCode,dc->fullContent->byteCount,dc->fullContent->data);
        }
        else{
            //  minusPatch
            printf("case4\n");
            
            string init;
            init.assign(dc->minusPatch->data,strlen(dc->minusPatch->data));
            printf("before: %s\n",dc->minusPatch->data);
            string result = replace(init,"'","\\'");
            result = replace(result,"\"","\\\"");
            printf("replace: %s\n",result.c_str());
            
            sprintf(sql,"CREATE VERTEX Datacontent set isDiff=%d, SHA256hashCode='%s', minus_schemaCode=%d, minus_byteCount=%d, minus_data='%s'",dc->isDiff,dc->SHA256hashCode,dc->minusPatch->schemaCode,dc->minusPatch->byteCount,result.c_str());
        }
        printf("SQL: %s\n",sql);
        ret = createVertex(sql,&dc_cltid[i],&dc_rid[i],dtPacket);
        if (ret!=0){
            printf("addData2Data..FAILED(vertex_DataContent)\n");
            return -1;
        }
        printf("@rid #%d:%lu\n",dc_cltid[i],dc_rid[i]);
        next_dc = dc->nextVersion;
        i++;
    }
    
    //  head/lastestCommon/current
    printf("--------------------------------------------------[create_edge_toDataContent_head]\n");
    sprintf(sql,"CREATE EDGE toDataContent from #%d:%lu to #%d:%lu set type='head'",dh_cltid,dh_rid,dc_cltid[count-1],dc_rid[count-1]);
    //    printf("SQL: %s\n",sql);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("addData2Data..FAILED(edge_toDataContent_head)\n");
        return -1;
    }
    
    printf("--------------------------------------------------[create_edge_toDataContent_current]\n");
    sprintf(sql,"CREATE EDGE toDataContent from #%d:%lu to #%d:%lu set type='current'",dh_cltid,dh_rid,dc_cltid[count-1],dc_rid[count-1]);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("addData2Data..FAILED(edge_toDataContent_current)\n");
        return -1;
    }
    
    printf("--------------------------------------------------[create_edge_toDataContent_lastestCommon]\n");
    sprintf(sql,"CREATE EDGE toDataContent from #%d:%lu to #%d:%lu set type='lastestCommon'",dh_cltid,dh_rid,dc_cltid[0],dc_rid[0]);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("addData2Data..FAILED(edge_toDataContent_lastestCommon)\n");
        return -1;
    }
    
    //  next/pre/toDataHolder_fromDC
    for(i=0;i<count;i++){
        printf("--------------------------------------------------[create_edge_toDataHolder_fromDC #%d]\n",i);
        sprintf(sql,"CREATE EDGE toDataHolder_fromDC from #%d:%lu to #%d:%lu",dc_cltid[i],dc_rid[i],dh_cltid,dh_rid);
        ret = sendCommand(sql,dtPacket);
        if (ret!=0){
            printf("addData2Data..FAILED(edge_toDataHolder_fromDC)\n");
            return -1;
        }
        
        // pre
        if(i != 0){
            printf("--------------------------------------------------[create_edge_toContent_Pre]\n");
            sprintf(sql,"CREATE EDGE toContent from #%d:%lu to #%d:%lu set type='pre'",dc_cltid[i],dc_rid[i],dc_cltid[i-1],dc_rid[i-1]);
            ret = sendCommand(sql,dtPacket);
            if (ret!=0){
                printf("addData2Data..FAILED(edge_toContent_Pre)\n");
                return -1;
            }
        }
        // next
        if(i != count-1){
            printf("--------------------------------------------------[create_edge_toContent_Next]\n");
            sprintf(sql,"CREATE EDGE toContent from #%d:%lu to #%d:%lu set type='next'",dc_cltid[i],dc_rid[i],dc_cltid[i+1],dc_rid[i+1]);
            ret = sendCommand(sql,dtPacket);
            if (ret!=0){
                printf("addData2Data..FAILED(edge_toContent_Next)\n");
                return -1;
            }
        }
    }
    
    if(dataID!=NULL){
        // create Edge from Data to Data
        switch(dType){
            case _toUser:
                printf("--------------------------------------------------[create_edge_toUser]\n");
                sprintf(sql,"create edge toUser from (select from Data where dataID='%s') to #%d:%lu",dataID,dt_cltid,dt_rid);
                break;
            case _toCategory:
                printf("--------------------------------------------------[create_edge_toCategory]\n");
                sprintf(sql,"create edge toCategory from (select from Data where dataID='%s') to #%d:%lu",dataID,dt_cltid,dt_rid);
                break;
            case _toState:
                printf("--------------------------------------------------[create_edge_toState]\n");
                sprintf(sql,"create edge toState from (select from Data where dataID='%s') to #%d:%lu",dataID,dt_cltid,dt_rid);
                break;
            case _toTask:
                printf("--------------------------------------------------[create_edge_toTask]\n");
                sprintf(sql,"create edge toTask from (select from Data where dataID='%s') to #%d:%lu",dataID,dt_cltid,dt_rid);
                break;
            case _toSubTask:
                printf("--------------------------------------------------[create_edge_toSubTask]\n");
                sprintf(sql,"create edge toSubTask from (select from Data where dataID='%s') to #%d:%lu",dataID,dt_cltid,dt_rid);
                break;
            default:
                return -1;
                break;
        }
        //    printf("SQL: %s\n",sql);
        ret = sendCommand(sql,dtPacket);
        if (ret!=0){
            printf("addData2Data..FAILED(edge_toData)\n");
            return -1;
        }
    }
    return 0;
}

ReturnErr removeUserFromOrg(char* orgID, char* userID, DTPacket* dtPacket){
    int ret = removeDataFromData(orgID, userID,dtPacket);
    return ret;
}

ReturnErr removeCategoryFromUser(char* userID, char* categoryID, DTPacket* dtPacket){
    int ret = removeDataFromData(userID, categoryID,dtPacket);
    return ret;
}

ReturnErr removeStateFromCategory(char* categoryID, char* stateID, DTPacket* dtPacket){
    int ret = removeDataFromData(categoryID, stateID,dtPacket);
    return ret;
}

ReturnErr removeTaskFromState(char* stateID, char* taskID, DTPacket* dtPacket){
    int ret = removeDataFromData(stateID, taskID,dtPacket);
    return ret;
}

ReturnErr removeTaskFromCategory(char* categoryID, char* taskID, DTPacket* dtPacket){
    int ret = removeDataFromData(categoryID, taskID,dtPacket);
    return ret;
}

ReturnErr removeSubTaskFromTask(char* taskID, char* subTaskID, DTPacket* dtPacket){
    int ret = removeDataFromData(taskID, subTaskID,dtPacket);
    return ret;
}

ReturnErr removeDataFromData(char* f_dataID, char* t_dataID, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    printf("--------------------------------------------------[delete_edge(from..to)]\n");
    sprintf(sql,"DELETE EDGE from (select from Data where dataID='%s') to (select from Data where dataID='%s')",f_dataID,t_dataID);
    int ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("removeDataFromData..FAILED(delete_edge(from..to))\n");
        return -1;
    }
    return 0;
}

ReturnErr deleteObj(char* userID, char* upperID, char* objID, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    
    //  delete edge
    printf("--------------------------------------------------[delete_edge(from..to)]\n");
    sprintf(sql,"DELETE EDGE from (select from Data where dataID='%s') to (select from Data where dataID='%s')",upperID,objID);
    int ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("deleteObj..FAILED(delete_edge(from..to))\n");
        return -1;
    }
    
    //  create edge + set dataID
    printf("--------------------------------------------------[create_edge_toDeletedData]\n");
    sprintf(sql,"create edge toDeletedData from (select from DeleteNode where userID='%s') to (select from Data where dataID='%s') set  dataID='%s'",userID,objID,upperID);
    ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("deleteObj..FAILED(create_edge_toDeletedData)\n");
        return -1;
    }
    return 0;
}

ReturnErr flushTrash(char* userID, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    
    //  delete edge toDeletedData
    printf("--------------------------------------------------[delete_edge_toDeletedData(by userID)]\n");
    
    sprintf(sql,"delete edge from (select from DeleteNode where userID='%s')",userID);
    int ret = sendCommand(sql,dtPacket);
    if (ret!=0){
        printf("deleteObj..FAILED(delete_edge(from..to))\n");
        return -1;
    }
    return 0;
}

Org** queryOrgFromData(char* dataID, DTPacket* dtPacket){
    Org** org = queryDataFromData(dataID, _org,dtPacket);
    return org;
}

User** queryAllUsersFromData(char* dataID, DTPacket* dtPacket){
    User** user = queryDataFromData(dataID, _user,dtPacket);
    return user;
}

Category** queryAllCategoriesFromData(char* dataID, DTPacket* dtPacket){
    Category** cat = queryDataFromData(dataID, _category,dtPacket);
    return  cat;
}

State** queryAllStatesFromData(char* dataID, DTPacket* dtPacket){
    State** state = queryDataFromData(dataID, _state,dtPacket);
    return  state;
}

Task** queryAllTasksFromData(char* dataID, DTPacket* dtPacket){
    Task** task = queryDataFromData(dataID, _task,dtPacket);
    return task;
}

SubTask** queryAllSubTasksFromData(char* dataID, DTPacket* dtPacket){
    SubTask** subTask = queryDataFromData(dataID, _subTask,dtPacket);
    return subTask;
}

Data** queryDataFromData(char* dataID, int dType, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    
    switch(dType){
        case _org:
            printf("--------------------------------------------------[get @rid_org]\n");
            break;
        case _user:
            printf("--------------------------------------------------[get @rid_user]\n");
            break;
        case _category:
            printf("--------------------------------------------------[get @rid_category]\n");
            break;
        case _state:
            printf("--------------------------------------------------[get @rid_state]\n");
            break;
        case _task:
            printf("--------------------------------------------------[get @rid_task]\n");
            break;
        case _subTask:
            printf("--------------------------------------------------[get @rid_subTask]\n");
            break;
        default:
            return NULL;
            break;
            
    }
    
    sprintf(sql,"select distinct(rid) from (select expand($f) let $a = (select @rid from (select expand(in().in().in().in().in()) from (select from Data where dataID='%s')) where dataType=%d), $c = (select @rid from (select expand(in().in().in()) from (select from Data where dataID='%s')) where dataType=%d), $d = (select @rid from (select expand(in().in()) from (select from Data where dataID='%s')) where dataType=%d), $e = (select @rid from (select expand(in()) from (select from Data where dataID='%s')) where dataType=%d), $f = unionall($a, $b, $c, $d, $e))",dataID,dType,dataID,dType,dataID,dType,dataID,dType);
    printf("SQL: %s\n",sql);
    
    int i,j;
    char** result_rid = getArrayDistinctRid(sql,dtPacket);
    if(result_rid==NULL){
        printf("no result_rid\n");
        return NULL;
    }
    else{
        for(i=0;result_rid[i]!=NULL;i++)
            printf("result_rid[%d]: %s\n",i,result_rid[i]);
    }
    
    sprintf(sql,"select distinct(rid) from (select expand($l) let $h = (select @rid from (select expand(in()) from (select expand(in().in().in().in()) from (select from Data where dataID='%s')) where @class='DeleteNode')), $i = (select @rid from (select expand(in()) from (select expand(in().in().in()) from (select from Data where dataID='%s')) where @class='DeleteNode')), $j = (select @rid from (select expand(in()) from (select expand(in().in()) from (select from Data where dataID='%s')) where @class='DeleteNode')), $k = (select @rid from (select expand(in()) from (select expand(in()) from (select from Data where dataID='%s')) where @class='DeleteNode')), $l = unionall($h, $i, $j, $k))",dataID,dataID,dataID,dataID);
    printf("SQL: %s\n",sql);
    
    char** dup_rid = getArrayDistinctRid(sql,dtPacket);
    
    if(dup_rid!=NULL){
        //  show duplicate rid
        for(i=0;dup_rid[i]!=NULL;i++)
            printf("dup_rid[%d]: %s\n",i,dup_rid[i]);
        // filter rid
        for(i=0;dup_rid[i]!=NULL;i++){
            for(j=0;result_rid[j]!=NULL;j++){
                if(strcmp(result_rid[j],dup_rid[i])==0){
                    sprintf(result_rid[j],"%s","-");
                    break;
                }
            }
        }
    }
    else{
        printf("no dup_id\n");
        
    }
    
    int count=0;
    //  show filtered id
    for(j=0;result_rid[j]!=NULL;j++){
        if(strcmp(result_rid[j],"-")!=0){
            printf("filter_rid: %s\n",result_rid[j]);
            count++;
        }
    }
    printf("\nnum(distinct+filter): %d\n",count);
    if(count==0){
        printf("no result_rid\n");
        return NULL;
    }
    
    Data** dt = (Data**)malloc(sizeof(Data*)*(count+1));
    //    for(i=0;i<count;i++){
    //        dt[i] = (Data*)malloc(sizeof(Data));
    //    }
    for(j=0;result_rid[j]!=NULL;j++){
        if(strcmp(result_rid[j],"-")!=0){
            dt[j] = queryDataByRid(result_rid[j],dtPacket);
        }
    }
    //    printf("j: %d\n",j);
    dt[count]=NULL;
    
    if(dup_rid!=NULL){
        for(i=0;dup_rid[i]!=NULL;i++){
            free(dup_rid[i]);
        }
        free(dup_rid);
    }
    
    if(result_rid!=NULL){
        for(i=0;result_rid[i]!=NULL;i++){
            free(result_rid[i]);
        }
        free(result_rid);
    }
    
    return dt;
    //    return NULL;
}

Data* queryDataByRid(char* rid, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    char *token, *ptr;
    
    //  Data
    printf("--------------------------------------------------[get_info_Data]\n");
    sprintf(sql,"SELECT dataID,dataName,dataType,chatRoom from %s",rid);
    printf("SQL: %s\n",sql);
    char* result = getContent(sql,dtPacket);
    
    if(result==NULL){
        return NULL;
    }
    printf("result: %s\n\n\n\n\n",result);
    printf("--- Data ---\n");
    Data* dt = (Data*)malloc(sizeof(Data));
    
//    token = strtok(result,"\"");
    token = strtok_r(result,"\"",&ptr);
//    token = strtok(NULL,"\"");
    token = strtok_r(NULL,"\"",&ptr);
    printf("dataID: %s\n",token);
    dt->dataID = strdup(token);
    
//    token = strtok(NULL,"\"");
    token = strtok_r(NULL,"\"",&ptr);
//    token = strtok(NULL,"\"");
    token = strtok_r(NULL,"\"",&ptr);
    printf("dataName: %s\n",token);
    dt->dataName = strdup(token);
    
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
//    token = strtok(NULL,",");
    token = strtok_r(NULL,",",&ptr);
    printf("dataType: %s\n",token);
    dt->dataType = atoi(token);
    
//    token = strtok(NULL,"\"");
    token = strtok_r(NULL,"\"",&ptr);
    if(token!=NULL){
//        token = strtok(NULL,"\"");
        token = strtok_r(NULL,"\"",&ptr);
        printf("chatRoom: %s\n\n",token);
        dt->chatRoom = strdup(token);
    }
    else{
        dt->chatRoom = NULL;
    }
    
    free(result);
    
    //  DataHolder
    printf("--------------------------------------------------[get_info_DataHolder]\n");
    sprintf(sql,"SELECT @rid,versionKeeped from (select expand(out('toDataHolder')) from %s)",rid);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        free((char*)dt->dataID);
        free(dt->dataName);
        if(dt->chatRoom != NULL)
            free(dt->chatRoom);
        free(dt);
        return NULL;
    }
    printf("result: %s\n\n\n\n\n",result);
    printf("--- DataHolder ---\n");
    DataHolder* dh = (DataHolder*)malloc(sizeof(DataHolder));
    dt->content = dh;
    
//    token = strtok(result,":");
    token = strtok_r(result,":",&ptr);
//    token = strtok(NULL,",");
    token = strtok_r(NULL,",",&ptr);
    printf("dh_@rid: %s\n",token);
    char* rid_dh = strdup(token);
    
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
//    token = strtok(NULL,",");
    token = strtok_r(NULL,",",&ptr);
    printf("versionKeeped: %s\n\n",token);
    dh->versionKeeped = atoi(token);
    dh->head = NULL;
    dh->lastestCommon = NULL;
    dh->current = NULL;
    
    free(result);
    
    //  count DataContent
    printf("--------------------------------------------------[get_count_DataContent]\n");
    sprintf(sql,"select count(*) from (select expand(in('toDataHolder_fromDC')) from %s)",rid_dh);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        free(rid_dh);
        free(dh);
        free((char*)dt->dataID);
        free(dt->dataName);
        if(dt->chatRoom != NULL)
            free(dt->chatRoom);
        free(dt);
        return NULL;
    }
    printf("result: %s\n\n\n\n\n",result);
//    token = strtok(result,":");
    token = strtok_r(result,":",&ptr);
//    token = strtok(NULL,"l");
    token = strtok_r(NULL,"l",&ptr);
    printf("count: %s\n\n",token);
    int count = atoi(token);
    
    free(result);
    
    //  next/pre/dataHd
    //  isDiff SHA256hashCode timeStamp(NULL) minus/plus/full
    
    //  DataContent
    printf("--------------------------------------------------[get_DataContent]\n");
    sprintf(sql,"select isDiff,SHA256hashCode,timeStamp,plus_schemaCode,plus_byteCount,plus_data,minus_schemaCode,minus_byteCount,minus_data,full_schemaCode,full_byteCount,full_data from (select expand(in('toDataHolder_fromDC')) from %s)",rid_dh);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        free(rid_dh);
        free(dh);
        free((char*)dt->dataID);
        free(dt->dataName);
        if(dt->chatRoom != NULL)
            free(dt->chatRoom);
        free(dt);
        return NULL;
    }
    printf("result: %s\n\n\n\n\n",result);
    DataContent** dc = (DataContent**)malloc(sizeof(DataContent*)*(count+1));
    int i;
    for(i=0;i<count;i++){
        dc[i] = (DataContent*)malloc(sizeof(DataContent));
    }
    dh->head = dc[count-1];
    dh->lastestCommon = dc[0];
    dh->current = dc[count-1];
    dc[count] = NULL;
    
    string init;
    init.assign(result);
    printf("before: %s\n",result);
    string res = replace(init,"\\'","'");
    res = replace(res,"\\\"","\"");
    printf("\n------------------------------------------------------------------------------------------------------------\n\n");
    printf("replace: %s\n",res.c_str());
    printf("\n------------------------------------------------------------------------------------------------------------\n\n");
    
    free(result);
    result = strdup(res.c_str());
    
//    char* tmp_tok = strtok(result,"#");
    char* tmp_tok = strtok_r(result,"#",&ptr);
    char **dc_str = (char**)malloc(sizeof(char*)*count);
    
    for(i=0;i<count;i++){
        printf("--- DataContent[%d] ---\n",i);
        printf("tmp_tok: %s\n",tmp_tok);
        //        printf("len: %d\n",strlen(tmp_tok));
        
        dc_str[i]= strdup(tmp_tok);
        printf("\ndc_str: %s\n",dc_str[i]);
        
        dc[i]->timeStamp = NULL;
        dc[i]->minusPatch = NULL;
        dc[i]->plusPatch = NULL;
        dc[i]->fullContent = NULL;
        dc[i]->dataHd = dh;
        
        if(i!=0){
            dc[i]->preVersion = dc[i-1];
        }
        if(i!=count-1){
            dc[i]->nextVersion = dc[i+1];
        }
        
//        tmp_tok = strtok(NULL, "#");
        tmp_tok = strtok_r(NULL, "#",&ptr);
    }
    dc[0]->preVersion = NULL;
    dc[count-1]->nextVersion = NULL;
    free(result);
    
    char* br;
    char* pt_data;
    
    for(i=0;i<count;i++){
        printf("\n[%d]\n",i);
        
        //  isDiff
        token = strtok_r(dc_str[i],":",&br);
        token = strtok_r(NULL,",",&br);
        printf("isDiff: %s\n",token);
        
        if(strcmp(token,"true")==0){
            dc[i]->isDiff = TRUE;
        }
        else{
            dc[i]->isDiff = FALSE;
        }
        
        //  SHA256hashCode
        token = strtok_r(NULL,"\"",&br);
        token = strtok_r(NULL,"\"",&br);
        printf("SHA256hashCode: %s\n",token);
        dc[i]->SHA256hashCode = strdup(token);
        
        //  timeStamp(NULL)
        
        //  minusPatch/plusPatch/fullContent
        result = br+1;
        printf("result: %s\n",result);
        token = strtok_r(result, ":", &br);
        
        while(token!=NULL){
            printf("key: %s\n",token);
            if(token == NULL)
                break;
            if(strcmp(token,"minus_schemaCode")==0){
                printf("\n[minus]\n");
                dc[i]->minusPatch = (ObjectBinary*)malloc(sizeof(ObjectBinary));
                
                //  schemaCode
                token = strtok_r(NULL,",",&br);
                printf("schemaCode: %s\n",token);
                dc[i]->minusPatch->schemaCode = atoi(token);
                
                //  byteCount
                token = strtok_r(NULL,":",&br);
                token = strtok_r(NULL,",",&br);
                printf("bytecount: %s\n",token);
                dc[i]->minusPatch->byteCount = atoi(token);
                
                printf("br: %s\n",br);
                pt_data = br+12;
                
                int b_count = atoi(token);
                dc[i]->minusPatch->data = (char*)calloc(b_count+1,sizeof(char));
                memcpy(dc[i]->minusPatch->data,pt_data,b_count);
                printf("dc_data: %s\n",dc[i]->minusPatch->data);
                //                strcat(dc[i]->minusPatch->data,"1");
                //                printf("len: %d\n",strlen(dc[i]->minusPatch->data));
                //                printf("--- %c\n",dc[i]->minusPatch->data[b_count]);
                pt_data = br+12+b_count+1;
                if(pt_data[0] == '\0'){
                    printf("data is NULL\n");
                    break;
                }
                else{
                    pt_data = br+11+b_count+2;
                    printf("pt_data: %s\n",pt_data);
                    token = strtok_r(pt_data,":",&br);
                }
            }
            //            token = NULL;
            else if(strcmp(token,"plus_schemaCode")==0){
                printf("\n[plus]\n");
                dc[i]->plusPatch = (ObjectBinary*)malloc(sizeof(ObjectBinary));
                
                //  schemaCode
                token = strtok_r(NULL,",",&br);
                printf("schemaCode: %s\n",token);
                dc[i]->plusPatch->schemaCode = atoi(token);
                
                //  byteCount
                token = strtok_r(NULL,":",&br);
                token = strtok_r(NULL,",",&br);
                printf("bytecount: %s\n",token);
                dc[i]->plusPatch->byteCount = atoi(token);
                
                printf("br: %s\n",br);
                pt_data = br+11;
                printf("pt_data: %s\n",pt_data);
                
                int b_count = atoi(token);
                printf("b_count: %d\n",b_count);
                
                dc[i]->plusPatch->data = (char*)calloc(b_count+1,sizeof(char));
                memcpy(dc[i]->plusPatch->data,pt_data,b_count);
                printf("dc_data: %s\n",dc[i]->plusPatch->data);
                pt_data = br+11+b_count+1;
                if(pt_data[0] == '\0'){
                    printf("data is NULL\n");
                    break;
                }
                else{
                    pt_data = br+11+b_count+2;
                    printf("pt_data: %s\n",pt_data);
                    token = strtok_r(pt_data,":",&br);
                }
            }
            //            if(strcmp(token,"full_schemaCode")==0){
            else{
                printf("\n[full]\n");
                dc[i]->fullContent = (ObjectBinary*)malloc(sizeof(ObjectBinary));
                
                //  schemaCode
                token = strtok_r(NULL,",",&br);
                printf("schemaCode: %s\n",token);
                dc[i]->fullContent->schemaCode = atoi(token);
                
                //  byteCount
                token = strtok_r(NULL,":",&br);
                token = strtok_r(NULL,",",&br);
                printf("bytecount: %s\n",token);
                dc[i]->fullContent->byteCount = atoi(token);
                
                printf("br: %s\n",br);
                pt_data = br+11;
                printf("pt_data: %s\n",pt_data);
                
                int b_count = atoi(token);
                printf("b_count: %d\n",b_count);
                
                dc[i]->fullContent->data = (char*)calloc(b_count+1,sizeof(char));
                memcpy(dc[i]->fullContent->data,pt_data,b_count);
                printf("dc_data: %s\n",dc[i]->fullContent->data);
                pt_data = br+11+b_count+1;
                if(pt_data[0] == '\0'){
                    printf("data is NULL\n");
                    break;
                }
                else{
                    pt_data = br+11+b_count+2;
                    printf("pt_data: %s\n",pt_data);
                }
            }
        }
        free(dc_str[i]);
    }
    free(rid_dh);
    free(dc_str);
    free(dc);
    return dt;
}

Data* queryDataByID(char* dataID, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    char *token, *ptr;
    
    //  Data
    printf("--------------------------------------------------[get_info_Data]\n");
    sprintf(sql,"SELECT dataID,dataName,dataType,chatRoom from Data where dataID='%s'",dataID);
    printf("SQL: %s\n",sql);
    char* result = getContent(sql,dtPacket);
    
    if(result==NULL){
        return NULL;
    }
    printf("result: %s\n\n\n\n\n",result);
    printf("--- Data ---\n");
    Data* dt = (Data*)malloc(sizeof(Data));
    
//    token = strtok(result,"\"");
    token = strtok_r(result,"\"",&ptr);
//    token = strtok(NULL,"\"");
    token = strtok_r(NULL,"\"",&ptr);
    printf("dataID: %s\n",token);
    dt->dataID = strdup(token);
    
//    token = strtok(NULL,"\"");
    token = strtok_r(NULL,"\"",&ptr);
//    token = strtok(NULL,"\"");
    token = strtok_r(NULL,"\"",&ptr);
    printf("dataName: %s\n",token);
    dt->dataName = strdup(token);
    
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
//    token = strtok(NULL,",");
    token = strtok_r(NULL,",",&ptr);
    printf("dataType: %s\n",token);
    dt->dataType = atoi(token);
    
//    token = strtok(NULL,"\"");
    token = strtok_r(NULL,"\"",&ptr);
    if(token!=NULL){
//        token = strtok(NULL,"\"");
        token = strtok_r(NULL,"\"",&ptr);
        printf("chatRoom: %s\n\n",token);
        dt->chatRoom = strdup(token);
    }
    else{
        dt->chatRoom = NULL;
    }
    
    free(result);
    
    //  DataHolder
    printf("--------------------------------------------------[get_info_DataHolder]\n");
    sprintf(sql,"SELECT @rid,versionKeeped from (select expand(out('toDataHolder')) from Data where dataID='%s')",dataID);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        free((char*)dt->dataID);
        free(dt->dataName);
        if(dt->chatRoom != NULL)
            free(dt->chatRoom);
        free(dt);
        return NULL;
    }
    printf("result: %s\n\n\n\n\n",result);
    printf("--- DataHolder ---\n");
    DataHolder* dh = (DataHolder*)malloc(sizeof(DataHolder));
    dt->content = dh;
    
//    token = strtok(result,":");
    token = strtok_r(result,":",&ptr);
//    token = strtok(NULL,",");
    token = strtok_r(NULL,",",&ptr);
    printf("dh_@rid: %s\n",token);
    char* rid_dh = strdup(token);
    
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
//    token = strtok(NULL,",");
    token = strtok_r(NULL,",",&ptr);
    printf("versionKeeped: %s\n\n",token);
    dh->versionKeeped = atoi(token);
    dh->head = NULL;
    dh->lastestCommon = NULL;
    dh->current = NULL;
    
    free(result);
    
    //  count DataContent
    printf("--------------------------------------------------[get_count_DataContent]\n");
    sprintf(sql,"select count(*) from (select expand(in('toDataHolder_fromDC')) from %s)",rid_dh);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        free(rid_dh);
        free(dh);
        free((char*)dt->dataID);
        free(dt->dataName);
        if(dt->chatRoom != NULL)
            free(dt->chatRoom);
        free(dt);
        return NULL;
    }
    printf("result: %s\n\n\n\n\n",result);
//    token = strtok(result,":");
    token = strtok_r(result,":",&ptr);
//    token = strtok(NULL,"l");
    token = strtok_r(NULL,"l",&ptr);
    printf("count: %s\n\n",token);
    int count = atoi(token);
    
    free(result);
    
    //  next/pre/dataHd
    //  isDiff SHA256hashCode timeStamp(NULL) minus/plus/full
    
    //  DataContent
    printf("--------------------------------------------------[get_DataContent]\n");
    sprintf(sql,"select isDiff,SHA256hashCode,timeStamp,plus_schemaCode,plus_byteCount,plus_data,minus_schemaCode,minus_byteCount,minus_data,full_schemaCode,full_byteCount,full_data from (select expand(in('toDataHolder_fromDC')) from %s)",rid_dh);
    printf("SQL: %s\n",sql);
    result = getContent(sql,dtPacket);
    
    if(result==NULL){
        free(rid_dh);
        free(dh);
        free((char*)dt->dataID);
        free(dt->dataName);
        if(dt->chatRoom != NULL)
            free(dt->chatRoom);
        free(dt);
        return NULL;
    }
    printf("result: %s\n\n\n\n\n",result);
    DataContent** dc = (DataContent**)malloc(sizeof(DataContent*)*(count+1));
    int i;
    for(i=0;i<count;i++){
        dc[i] = (DataContent*)malloc(sizeof(DataContent));
    }
    dh->head = dc[count-1];
    dh->lastestCommon = dc[0];
    dh->current = dc[count-1];
    dc[count] = NULL;
    
    string init;
    init.assign(result);
    printf("before: %s\n",result);
    string res = replace(init,"\\'","'");
    res = replace(res,"\\\"","\"");
    printf("\n------------------------------------------------------------------------------------------------------------\n\n");
    printf("replace: %s\n",res.c_str());
    printf("\n------------------------------------------------------------------------------------------------------------\n\n");
    
    free(result);
    result = strdup(res.c_str());
    
//    char* tmp_tok = strtok(result,"#");
    char* tmp_tok = strtok_r(result,"#",&ptr);
    char **dc_str = (char**)malloc(sizeof(char*)*count);
    
    for(i=0;i<count;i++){
        printf("--- DataContent[%d] ---\n",i);
        printf("tmp_tok: %s\n",tmp_tok);
        //        printf("len: %d\n",strlen(tmp_tok));
        
        dc_str[i]= strdup(tmp_tok);
        printf("\ndc_str: %s\n",dc_str[i]);
        
        dc[i]->timeStamp = NULL;
        dc[i]->minusPatch = NULL;
        dc[i]->plusPatch = NULL;
        dc[i]->fullContent = NULL;
        dc[i]->dataHd = dh;
        
        if(i!=0){
            dc[i]->preVersion = dc[i-1];
        }
        if(i!=count-1){
            dc[i]->nextVersion = dc[i+1];
        }
        
//        tmp_tok = strtok(NULL, "#");
        tmp_tok = strtok_r(NULL, "#",&ptr);
    }
    dc[0]->preVersion = NULL;
    dc[count-1]->nextVersion = NULL;
    free(result);
    
    char* br;
    char* pt_data;
    
    for(i=0;i<count;i++){
        printf("\n[%d]\n",i);
        
        //  isDiff
        token = strtok_r(dc_str[i],":",&br);
        token = strtok_r(NULL,",",&br);
        printf("isDiff: %s\n",token);
        
        if(strcmp(token,"true")==0){
            dc[i]->isDiff = TRUE;
        }
        else{
            dc[i]->isDiff = FALSE;
        }
        
        //  SHA256hashCode
        token = strtok_r(NULL,"\"",&br);
        token = strtok_r(NULL,"\"",&br);
        printf("SHA256hashCode: %s\n",token);
        dc[i]->SHA256hashCode = strdup(token);
        
        //  timeStamp(NULL)
        
        //  minusPatch/plusPatch/fullContent
        result = br+1;
        printf("result: %s\n",result);
        token = strtok_r(result, ":", &br);
        
        while(token!=NULL){
            printf("key: %s\n",token);
            if(token == NULL)
                break;
            if(strcmp(token,"minus_schemaCode")==0){
                printf("\n[minus]\n");
                dc[i]->minusPatch = (ObjectBinary*)malloc(sizeof(ObjectBinary));
                
                //  schemaCode
                token = strtok_r(NULL,",",&br);
                printf("schemaCode: %s\n",token);
                dc[i]->minusPatch->schemaCode = atoi(token);
                
                //  byteCount
                token = strtok_r(NULL,":",&br);
                token = strtok_r(NULL,",",&br);
                printf("bytecount: %s\n",token);
                dc[i]->minusPatch->byteCount = atoi(token);
                
                printf("br: %s\n",br);
                pt_data = br+12;
                
                int b_count = atoi(token);
                dc[i]->minusPatch->data = (char*)calloc(b_count+1,sizeof(char));
                memcpy(dc[i]->minusPatch->data,pt_data,b_count);
                printf("dc_data: %s\n",dc[i]->minusPatch->data);
                //                strcat(dc[i]->minusPatch->data,"1");
                //                printf("len: %d\n",strlen(dc[i]->minusPatch->data));
                //                printf("--- %c\n",dc[i]->minusPatch->data[b_count]);
                pt_data = br+12+b_count+1;
                if(pt_data[0] == '\0'){
                    printf("data is NULL\n");
                    break;
                }
                else{
                    pt_data = br+11+b_count+2;
                    printf("pt_data: %s\n",pt_data);
                    token = strtok_r(pt_data,":",&br);
                }
            }
            //            token = NULL;
            else if(strcmp(token,"plus_schemaCode")==0){
                printf("\n[plus]\n");
                dc[i]->plusPatch = (ObjectBinary*)malloc(sizeof(ObjectBinary));
                
                //  schemaCode
                token = strtok_r(NULL,",",&br);
                printf("schemaCode: %s\n",token);
                dc[i]->plusPatch->schemaCode = atoi(token);
                
                //  byteCount
                token = strtok_r(NULL,":",&br);
                token = strtok_r(NULL,",",&br);
                printf("bytecount: %s\n",token);
                dc[i]->plusPatch->byteCount = atoi(token);
                
                printf("br: %s\n",br);
                pt_data = br+11;
                printf("pt_data: %s\n",pt_data);
                
                int b_count = atoi(token);
                printf("b_count: %d\n",b_count);
                
                dc[i]->plusPatch->data = (char*)calloc(b_count+1,sizeof(char));
                memcpy(dc[i]->plusPatch->data,pt_data,b_count);
                printf("dc_data: %s\n",dc[i]->plusPatch->data);
                pt_data = br+11+b_count+1;
                if(pt_data[0] == '\0'){
                    printf("data is NULL\n");
                    break;
                }
                else{
                    pt_data = br+11+b_count+2;
                    printf("pt_data: %s\n",pt_data);
                    token = strtok_r(pt_data,":",&br);
                }
            }
            //            if(strcmp(token,"full_schemaCode")==0){
            else{
                printf("\n[full]\n");
                dc[i]->fullContent = (ObjectBinary*)malloc(sizeof(ObjectBinary));
                
                //  schemaCode
                token = strtok_r(NULL,",",&br);
                printf("schemaCode: %s\n",token);
                dc[i]->fullContent->schemaCode = atoi(token);
                
                //  byteCount
                token = strtok_r(NULL,":",&br);
                token = strtok_r(NULL,",",&br);
                printf("bytecount: %s\n",token);
                dc[i]->fullContent->byteCount = atoi(token);
                
                printf("br: %s\n",br);
                pt_data = br+11;
                printf("pt_data: %s\n",pt_data);
                
                int b_count = atoi(token);
                printf("b_count: %d\n",b_count);
                
                dc[i]->fullContent->data = (char*)calloc(b_count+1,sizeof(char));
                memcpy(dc[i]->fullContent->data,pt_data,b_count);
                printf("dc_data: %s\n",dc[i]->fullContent->data);
                pt_data = br+11+b_count+1;
                if(pt_data[0] == '\0'){
                    printf("data is NULL\n");
                    break;
                }
                else{
                    pt_data = br+11+b_count+2;
                    printf("pt_data: %s\n",pt_data);
                }
            }
        }
        free(dc_str[i]);
    }
    free(rid_dh);
    free(dc_str);
    free(dc);
    return dt;
}

char** getOrgID(DTPacket* dtPacket){
    char** list = getDataFromDataID(NULL, _org,dtPacket);
    return list;
}

char** getUserFromOrgID(char* orgID, DTPacket* dtPacket){
    char** list = getDataFromDataID(orgID, _user,dtPacket);
    return list;
}

char** getCatFromUserID(char* userID, DTPacket* dtPacket){
    char** list = getDataFromDataID(userID, _category,dtPacket);
    return list;
}

char** getStateFromCatID(char* catID, DTPacket* dtPacket){
    char** list = getDataFromDataID(catID, _state,dtPacket);
    return list;
}

char** getTaskFromStateID(char* stateID, DTPacket* dtPacket){
    char** list = getDataFromDataID(stateID, _task,dtPacket);
    return list;
    
}

char** getSubTaskFromTaskID(char* taskID, DTPacket* dtPacket){
    char** list = getDataFromDataID(taskID, _subTask,dtPacket);
    return list;
}

char** getTaskFromCatID(char* catID, DTPacket* dtPacket){
    char** list = getDataFromDataID(catID, _task,dtPacket);
    return list;
}

char** getDataFromDataID(char* dataID, int dType, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    char *token, *result;
    switch(dType){
        case _org:
            printf("--------------------------------------------------[get dataID,dataName_user]\n");
            sprintf(sql,"select dataID,dataName from data where dataType=%d)",_org);
            printf("SQL: %s\n",sql);
            result = getContent(sql,dtPacket);
            if(result==NULL){
                printf("not found any org\n");
                return NULL;
            }
            break;
        case _user:
            printf("--------------------------------------------------[get dataID,dataName_user]\n");
            sprintf(sql,"select dataID,dataName from (select expand(out('toUser')) from data where dataID='%s')",dataID);
            printf("SQL: %s\n",sql);
            result = getContent(sql,dtPacket);
            if(result==NULL){
                printf("not found any user\n");
                return NULL;
            }
            break;
        case _category:
            printf("--------------------------------------------------[get dataID,dataName_category]\n");
            sprintf(sql,"select dataID,dataName from (select expand(out('toCategory')) from data where dataID='%s')",dataID);
            printf("SQL: %s\n",sql);
            result = getContent(sql,dtPacket);
            if(result==NULL){
                printf("not found any category\n");
                return NULL;
            }
            break;
        case _state:
            printf("--------------------------------------------------[get dataID,dataName_state]\n");
            sprintf(sql,"select dataID,dataName from (select expand(out('toState')) from data where dataID='%s')",dataID);
            printf("SQL: %s\n",sql);
            result = getContent(sql,dtPacket);
            if(result==NULL){
                printf("not found any state\n");
                return NULL;
            }
            break;
        case _task:
            printf("--------------------------------------------------[get dataID,dataName_task]\n");
            sprintf(sql,"select dataID,dataName from (select expand(out('toTask')) from data where dataID='%s')",dataID);
            printf("SQL: %s\n",sql);
            result = getContent(sql,dtPacket);
            if(result==NULL){
                printf("not found any task\n");
                return NULL;
            }
            break;
        case _subTask:
            printf("--------------------------------------------------[get dataID,dataName_subTask]\n");
            sprintf(sql,"select dataID,dataName from (select expand(out('toSubTask')) from data where dataID='%s')",dataID);
            printf("SQL: %s\n",sql);
            result = getContent(sql,dtPacket);
            if(result==NULL){
                printf("not found any subTask\n");
                return NULL;
            }
            break;
        default:
            return NULL;
            break;
    }
    
    printf("result: %s\n",result);
    char* res=strdup(result);
    int count=0;
    char* ptr;
    
//    token=strtok(result,"#");
    token=strtok_r(result,"#",&ptr);
    while(token!=NULL){
        count++;
//        token=strtok(NULL, "#");
        token=strtok_r(NULL, "#",&ptr);
    }
    free(result);
    
    char** list = (char**)malloc(sizeof(char*)*(count+1));
    list[count] = NULL;
    printf("count: %d\n",count);
    int i,len_str;
    char *tmp_id, *tmp_name;
//    token = strtok(res,"\"");
    token = strtok_r(res,"\"",&ptr);
    for(i=0;i<count;i++){
        //        printf("\n\ntoken: %s\n",token);
//        token=strtok(NULL, "\"");
        token=strtok_r(NULL, "\"",&ptr);
        printf("dataID: %s\n",token);
        len_str = (int)strlen(token);
        tmp_id = strdup(token);
        
//        token=strtok(NULL, "\"");
        token=strtok_r(NULL, "\"",&ptr);
//        token=strtok(NULL, "\"");
        token=strtok_r(NULL, "\"",&ptr);
        printf("dataName: %s\n",token);
        len_str = len_str + (int)strlen(token);
        tmp_name = strdup(token);
        
//        token=strtok(NULL, "\"");
        token=strtok_r(NULL, "\"",&ptr);
        
        list[i] = (char*) malloc(sizeof(char)*(len_str+2));
        sprintf(list[i],"%s:%s",tmp_id,tmp_name);
        //        printf("len(m): %d\n",len_str+2);
        //        printf("len: %d\n",strlen(list[i]));
        printf("list[%d]: %s\n",i,list[i]);
        len_str=0;
        free(tmp_id);
        free(tmp_name);
    }
    free(res);
    
    return list;
}

t_bool isObjectOwnedByUser(char* userID, char* objID, DTPacket* dtPacket){
    t_bool bl = isObjectUnderData(userID,objID,dtPacket);
    return bl;
}

t_bool isObjectUnderCategory(char* categoryID, char* objID, DTPacket* dtPacket){
    t_bool bl = isObjectUnderData(categoryID,objID,dtPacket);
    return bl;
}

t_bool isObjectUnderState(char* stateID, char* objID, DTPacket* dtPacket){
    t_bool bl = isObjectUnderData(stateID,objID,dtPacket);
    return bl;
}

t_bool isObjectUnderTask(char* taskID, char* objID, DTPacket* dtPacket){
    t_bool bl = isObjectUnderData(taskID,objID,dtPacket);
    return bl;
}

t_bool isObjectUnderData(char* dataID, char* objID, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    printf("--------------------------------------------------[get_count_path]\n");
    
    //  for ordb 2.0
    sprintf(sql,"select count(*) from (traverse in() from (select from Data where dataID='%s')) where dataID = '%s'",objID,dataID);
    
    //  for ordb 2.1
    //    sprintf(sql,"select count(*) from(select expand(path) from(select shortestPath((select from Data where dataID='%s'),(select from Data where dataID='%s'),'IN') as path))",objID,dataID);
    printf("SQL: %s\n",sql);
    char* result = getContent(sql,dtPacket);
    if(result==NULL){
        printf("not found dataID/objID\n");
        return FALSE;
    }
    printf("result: %s\n",result);
    
    char* ptr;
//    char* token = strtok(result,":");
    char* token = strtok_r(result,":",&ptr);
//    token = strtok(NULL,"l");
    token = strtok_r(NULL,"l",&ptr);
    printf("count: %s\n",token);
    
    if(strcmp(token,"0")!=0){
        printf("object is under data.\n");
        free(result);
        return TRUE;
    }
    else{
        printf("object isn't under data.\n");
        free(result);
        return FALSE;
    }
}

int checkDeleted(char* dataID, DTPacket* dtPacket){
    char sql[MAX_SQL_SIZE];
    
    //  check edge toDeletedData exist
    printf("--------------------------------------------------[check_toDeletedData_exist]\n");
    sprintf(sql,"select count(*) from (select expand(out('toDeletedData')) from DeleteNode) where dataID = '%s'",dataID);
    printf("SQL: %s\n",sql);
    char* result = getContent(sql,dtPacket);
    printf("\nresult: %s\n",result);
    
    char* ptr;
//    char* token = strtok(result,":");
    char* token = strtok_r(result,":",&ptr);
//    token = strtok(NULL,"l");
    token = strtok_r(NULL,"l",&ptr);
    printf("count: %s\n\n",token);
    int count = atoi(token);
    free(result);
    
    if(count!=0){
        printf("'%s' not found data or data is deleted\n",dataID);
        return -1;
    }
    else{
        return count;
    }
}

void freeData(Data* data){
    int i=0;
    DataContent *mydc, *next_mydc;
    for(mydc=data->content->lastestCommon;mydc!=NULL;mydc=next_mydc){
        printf("-- %d --\n",i);
        next_mydc = mydc->nextVersion;
        if(mydc->SHA256hashCode != NULL)
            free(mydc->SHA256hashCode);
        if(mydc->timeStamp != NULL)
            free(mydc->timeStamp->timeStampCode);
        if(mydc->minusPatch != NULL){
            printf("minus: %s\n",mydc->minusPatch->data);
            free(mydc->minusPatch->data);
            free(mydc->minusPatch);
        }
        if(mydc->plusPatch != NULL){
            printf("plus: %s\n",mydc->plusPatch->data);
            free(mydc->plusPatch->data);
            free(mydc->plusPatch);
        }
        if(mydc->fullContent != NULL){
            printf("full: %s\n",mydc->fullContent->data);
            free(mydc->fullContent->data);
            free(mydc->fullContent);
        }
        free(mydc);
        i++;
    }
    
    free(data->content);
    free((char*)data->dataID);
    if(data->dataName!=NULL)
        free(data->dataName);
    if(data->chatRoom!=NULL)
        free(data->chatRoom);
    free(data);
}

void freeObjBinary(ObjectBinary* obj){
    free(obj->data);
    free(obj);
}

std::string& replace(std::string& s, const std::string& from, const std::string& to)
{
    if(!from.empty())
        for(size_t pos = 0; (pos = s.find(from, pos)) != std::string::npos; pos += to.size())
            s.replace(pos, from.size(), to);
    return s;
}

string getDiff(char* old_str, char* new_str){
    diff_match_patch<wstring> dmp;
    string s;
    wstring strPatch;
    wstring str1 = wstring(new_str,new_str+strlen(new_str));
    //    wcout << str1 << endl;
    wstring str0 = wstring(old_str,old_str+strlen(old_str));
    //    wcout << str0 << endl;
    strPatch = dmp.patch_toText(dmp.patch_make(str0, str1));
    s.assign(strPatch.begin(),strPatch.end());
    //    wcout << strPatch << endl;
    return s;
}

string getPatch(char* str, char* str_patch){
    diff_match_patch<wstring> dmp;
    string s;
    wstring strResult;
    strResult = wstring(str,str+strlen(str));
    pair<wstring, vector<bool> > out
    = dmp.patch_apply(dmp.patch_fromText(wstring(str_patch,str_patch+strlen(str_patch))), strResult);
    strResult = out.first;
    return s.assign(strResult.begin(),strResult.end());
}

//---- transport ----------------------------------------------------------

char* buildStringFromData(Data* data){
    printf("--- buildStringFromData ---\n");
    
    char* strPack = (char*)malloc(sizeof(char)*20000);
    char temp[10];
    
    //  dataID
    strcat(strPack,data->dataID);
    strcat(strPack,":");
    
    //  dataName
    strcat(strPack,data->dataName);
    strcat(strPack,":");
    
    //  dataType
    sprintf(temp,"%d:",data->dataType);
    strcat(strPack,temp);
    
    //  chatRoom
    if(data->chatRoom!=NULL){
        strcat(strPack, data->chatRoom);
    }
    else{
        strcat(strPack,"NULL");
    }
    strcat(strPack,":");
    
    //  versionKeeped
    sprintf(temp,"%d:",data->content->versionKeeped);
    strcat(strPack,temp);
    
    //  num content
    int count = countDataContent(data);
    count--;
    printf("count: %d\n",count);
    sprintf(temp,"%d:",count);
    strcat(strPack,temp);
    
    int i=1;
    DataContent *mydc, *next_mydc;
    for(mydc=data->content->lastestCommon;mydc!=NULL;mydc=next_mydc){
        next_mydc = mydc->nextVersion;
        
        //  ver content
        sprintf(temp,"%d:",i);
        strcat(strPack,temp);
        
        //  isDiff
        if(mydc->isDiff == TRUE){
            strcat(strPack,"T:");
        }
        else{
            strcat(strPack,"F:");
        }
        
        //  SHA256hashCode
        if(mydc->SHA256hashCode != NULL){
            //            printf("hash: %s\n",mydc->SHA256hashCode);
            strcat(strPack,mydc->SHA256hashCode);
            strcat(strPack,":");
        }
        else{
            strcat(strPack,"NULL:");
        }
        
        //  timeStamp
        strcat(strPack,"NULL:");
        
        //  minus
        if(mydc->minusPatch != NULL){
            sprintf(temp,"%d:",mydc->minusPatch->byteCount);
            strcat(strPack,temp);
            
            sprintf(temp,"%d:",mydc->minusPatch->schemaCode);
            strcat(strPack,temp);
            
            //            printf("data: %s\n",mydc->minusPatch->data);
            strcat(strPack,mydc->minusPatch->data);
            strcat(strPack,":");
        }
        else{
            strcat(strPack,"NULL:");
        }
        
        //  plus
        if(mydc->plusPatch != NULL){
            sprintf(temp,"%d:",mydc->plusPatch->byteCount);
            strcat(strPack,temp);
            
            sprintf(temp,"%d:",mydc->plusPatch->schemaCode);
            strcat(strPack,temp);
            
            strcat(strPack,mydc->plusPatch->data);
            strcat(strPack,":");
        }
        else{
            strcat(strPack,"NULL:");
        }
        
        //  full
        if(mydc->fullContent != NULL){
            sprintf(temp,"%d:",mydc->fullContent->byteCount);
            strcat(strPack,temp);
            
            sprintf(temp,"%d:",mydc->fullContent->schemaCode);
            strcat(strPack,temp);
            
            strcat(strPack,mydc->fullContent->data);
            strcat(strPack,":");
        }
        else{
            strcat(strPack,"NULL:");
        }
        
        i++;
    }
    strPack[strlen(strPack)-1] ='\0';
    printf("len: %d\n",(int)strlen(strPack));
    printf("\n\n%s\n\n\n",strPack);
    
    return strPack;
}

Data* buildDatafromString(char* strPack){
    printf("--- buildDatafromString ---\n");
    
    char *token, *ptr;
    Data* dt = (Data*)malloc(sizeof(Data));
    
    //  dataID
//    token = strtok(strPack,":");
    token = strtok_r(strPack,":",&ptr);
    if(strcmp(token,"failed")==0){
        free(dt);
        return NULL;
    }
    printf("dataID: %s\n",token);
    dt->dataID = strdup(token);
    
    //  dataName
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
    printf("dataName: %s\n",token);
    dt->dataName = strdup(token);
    
    //  dataType
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
    printf("dataType: %s\n",token);
    dt->dataType = atoi(token);
    
    //  chatRoom
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
    printf("chatRoom: %s\n",token);
    dt->chatRoom = strdup(token);
    
    DataHolder* dh = (DataHolder*)malloc(sizeof(DataHolder));
    dt->content = dh;
    
    //  versionKeeped
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
    printf("versionKeeped: %s\n",token);
    dh->versionKeeped = atoi(token);
    
    dh->head = NULL;
    dh->lastestCommon = NULL;
    dh->current = NULL;
    
    //  num content
//    token = strtok(NULL,":");
    token = strtok_r(NULL,":",&ptr);
    int count = atoi(token);
    printf("count: %d\n",count);
    
    DataContent** dc = (DataContent**)malloc(sizeof(DataContent*)*(count+1));
    int i;
    for(i=0;i<count;i++){
        dc[i] = (DataContent*)malloc(sizeof(DataContent));
    }
    
    dh->head = dc[count-1];
    dh->lastestCommon = dc[0];
    dh->current = dc[count-1];
    dc[count] = NULL;
    
    for(i=0;i<count;i++){
        printf("--- DataContent[%d] ---\n",i);
//        token = strtok(NULL, ":");
        token = strtok_r(NULL,":",&ptr);
        printf("ver: %s\n",token);
        
        dc[i]->dataHd = dh;
        if(i!=0){
            dc[i]->preVersion = dc[i-1];
        }
        if(i!=count-1){
            dc[i]->nextVersion = dc[i+1];
        }
        
        //  isDiff
//        token = strtok(NULL, ":");
        token = strtok_r(NULL,":",&ptr);
        if(strcmp(token,"T")==0){
            dc[i]->isDiff = TRUE;
        }
        else{
            dc[i]->isDiff = FALSE;
        }
        
        //  SHA256hashCode
//        token = strtok(NULL, ":");
        token = strtok_r(NULL,":",&ptr);
        printf("SHA256hashCode: %s\n",token);
        dc[i]->SHA256hashCode = strdup(token);
        
        //  timeStamp
//        token = strtok(NULL, ":");
        token = strtok_r(NULL,":",&ptr);
        printf("timeStamp: %s\n",token);
        dc[i]->timeStamp = NULL;
        
//        token = strtok(NULL, ":");
        token = strtok_r(NULL,":",&ptr);
        if(strcmp(token,"NULL")!=0){
            dc[i]->minusPatch = (ObjectBinary*)malloc(sizeof(ObjectBinary));
            printf("byteCount: %s\n",token);
            dc[i]->minusPatch->byteCount = atoi(token);
            
//            token = strtok(NULL, ":");
            token = strtok_r(NULL,":",&ptr);
            printf("schemaCode: %s\n",token);
            dc[i]->minusPatch->schemaCode = atoi(token);
            
//            token = strtok(NULL, ":");
            token = strtok_r(NULL,":",&ptr);
            printf("minus: %s\n",token);
            dc[i]->minusPatch->data = strdup(token);
        }
        else{
            dc[i]->minusPatch = NULL;
        }
        
//        token = strtok(NULL, ":");
        token = strtok_r(NULL,":",&ptr);
        if(strcmp(token,"NULL")!=0){
            dc[i]->plusPatch = (ObjectBinary*)malloc(sizeof(ObjectBinary));
            printf("byteCount: %s\n",token);
            dc[i]->plusPatch->byteCount = atoi(token);
            
//            token = strtok(NULL, ":");
            token = strtok_r(NULL,":",&ptr);
            printf("schemaCode: %s\n",token);
            dc[i]->plusPatch->schemaCode = atoi(token);
            
//            token = strtok(NULL, ":");
            token = strtok_r(NULL,":",&ptr);
            printf("plus: %s\n",token);
            dc[i]->plusPatch->data = strdup(token);
        }
        else{
            dc[i]->plusPatch = NULL;
        }
        
//        token = strtok(NULL, ":");
        token = strtok_r(NULL,":",&ptr);
        if(strcmp(token,"NULL")!=0){
            dc[i]->fullContent = (ObjectBinary*)malloc(sizeof(ObjectBinary));
            printf("byteCount: %s\n",token);
            dc[i]->fullContent->byteCount = atoi(token);
            
//            token = strtok(NULL, ":");
            token = strtok_r(NULL,":",&ptr);
            printf("schemaCode: %s\n",token);
            dc[i]->fullContent->schemaCode = atoi(token);
            
//            token = strtok(NULL, ":");
            token = strtok_r(NULL,":",&ptr);
            printf("full: %s\n",token);
            dc[i]->fullContent->data = strdup(token);
        }
        else{
            dc[i]->fullContent = NULL;
        }
    }
    dc[0]->preVersion = NULL;
    dc[count-1]->nextVersion = NULL;
    free(dc);
    
    return dt;
}

char* readcontent(const char *filename){
    char *fcontent = NULL;
    int fsize = 0;
    FILE *fp;
    
    fp = fopen(filename, "r");
    if(fp) {
        fseek(fp, 0, SEEK_END);
        fsize = (int)ftell(fp);
        rewind(fp);
        
        fcontent = (char*) malloc(sizeof(char) * fsize);
        fread(fcontent, 1, fsize, fp);
        
        fclose(fp);
    }
    return fcontent;
}

char* genString(Data* data){
    DataContent* cont = data->content->lastestCommon;
    char* allVer_str = (char*)malloc(sizeof(char)*20000);
    char temp[10];
    
    strcat(allVer_str, data->dataName);
    strcat(allVer_str, ":");
    strcat(allVer_str, data->dataID);
    strcat(allVer_str, ":");
    sprintf(temp,"%d:",data->dataType);
    strcat(allVer_str,temp);
    if(data->chatRoom != NULL){
        strcat(allVer_str, data->chatRoom);
    }
    else{
        strcat(allVer_str, "(NULL)");
    }
    strcat(allVer_str, ":");
    sprintf(temp,"%d:",data->content->versionKeeped);
    strcat(allVer_str,temp);
    
    while (cont != NULL){
        strcat(allVer_str, cont->SHA256hashCode);
        strcat(allVer_str, ":");
        if(cont->timeStamp != NULL){
            strcat(allVer_str, cont->timeStamp->timeStampCode);
            strcat(allVer_str, ":");
        }
        else{
            strcat(allVer_str, "(NULL):");
        }
        sprintf(temp,"%d:",cont->isDiff);
        strcat(allVer_str,temp);
        
        //  full
        if (cont->fullContent != NULL){
            sprintf(temp,"%d:",cont->fullContent->schemaCode);
            strcat(allVer_str,temp);
            
            sprintf(temp,"%d:",cont->fullContent->byteCount);
            strcat(allVer_str,temp);
            
            strcat(allVer_str, cont->fullContent->data);
            strcat(allVer_str, ":");
        }
        else{
            strcat(allVer_str, "(NULL):(NULL):(NULL):");
        }
        
        //  minus
        if (cont->minusPatch != NULL){
            sprintf(temp,"%d:",cont->minusPatch->schemaCode);
            strcat(allVer_str,temp);
            
            sprintf(temp,"%d:",cont->minusPatch->byteCount);
            strcat(allVer_str,temp);
            
            strcat(allVer_str, cont->minusPatch->data);
            strcat(allVer_str, ":");
        }
        else{
            strcat(allVer_str, "(NULL):(NULL):(NULL):");
        }
        
        //  plus
        if (cont->plusPatch != NULL){
            sprintf(temp,"%d:",cont->plusPatch->schemaCode);
            strcat(allVer_str,temp);
            
            sprintf(temp,"%d:",cont->plusPatch->byteCount);
            strcat(allVer_str,temp);
            
            strcat(allVer_str, cont->plusPatch->data);
            strcat(allVer_str, ":");
        }
        else{
            strcat(allVer_str, "(NULL):(NULL):(NULL):");
        }
        
        cont = cont->nextVersion;
    }
    return allVer_str;
}

char* genMsg(Data* data){
    if (data->dataType == 0){return strdup("Org");}
    else if (data->dataType == 1){return strdup("User");}
    else if (data->dataType == 2){return strdup("Category");}
    else if (data->dataType == 3){return strdup("State");}
    else if (data->dataType == 4){return strdup("Task");}
    else if (data->dataType == 5){return strdup("Subtask");}
    else return NULL;
}

//-------------------------------------------------------------------------

