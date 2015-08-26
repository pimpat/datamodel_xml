//
//  datamodel.h
//  datamodel_xml
//
//  Created by Pimpat on 8/24/2558 BE.
//  Copyright (c) 2558 Pimpat. All rights reserved.
//

#ifndef __datamodel_xml__datamodel__
#define __datamodel_xml__datamodel__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <uuid/uuid.h>

#include "reqmsg.h"
#include "hiorient.h"
#include "swap_endian.h"
#include "diff_match_patch.h"
#include "ezxml.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;

#define DB_NAME "datamodel_xml"
#define VER_KEEPED (10)

typedef struct CWTimeStamp{
    char* timeStampCode;
} CWTimeStamp;

typedef char* Text;
typedef char Schema;

typedef struct ObjectBinary {
    int schemaCode;
    int byteCount;
    char* data;
} ObjectBinary;

typedef struct DataHolder DataHolder;
typedef int t_bool;
typedef struct DataContent{
    DataHolder* dataHd;
    DataContent* nextVersion;
    DataContent* preVersion;
    char* SHA256hashCode;
    CWTimeStamp* timeStamp;
    ObjectBinary* plusPatch;
    ObjectBinary* minusPatch;
    ObjectBinary* fullContent;
    t_bool isDiff;
} DataContent;

struct DataHolder{
    DataContent* lastestCommon;
    DataContent* head;
    DataContent* current;
    int versionKeeped;
};

typedef struct Data{
    const char* dataID;
    char* dataName;
    int dataType;
    DataHolder* content;
    char* chatRoom;
} Data;

typedef Data Org;
typedef Data User;
typedef Data Category;
typedef Data State;
typedef Data Task;
typedef Data SubTask;

typedef int ReturnErr;

enum DATATYPE {
    _org,       //  0
    _user,      //  1
    _category,  //  2
    _state,     //  3
    _task,      //  4
    _subTask    //  5
};

enum TAGNAME {
    _attachmentFTOLinks,
    _content,   //  temp
    _book_id,   //  temp
    _author,    //  temp
    _title,     //  temp
    _genre,     //  temp
    _price      //  temp
};

/* datamodel function */
const char* _createNewData(Data** data, int dataType);
ObjectBinary* _createNewObjBinary(char* data, int dataType);
int countDataContent(Data* data);

void setDataName(Data* data, char* dataName);
void setChatRoom(Data* data, char* chatRoom);
char* getDataName(Data* data);
char* getChatRoom(Data* data);

ReturnErr setDataNameByID(char* dataID, char* dataName, DTPacket* dtPacket);
ReturnErr setChatRoomByID(char* dataID, char* chatRoom, DTPacket* dtPacket);
char* getDataNameByID(char* dataID, DTPacket* dtPacket);
char* getChatRoomByID(char* dataID, DTPacket* dtPacket);

ObjectBinary* getDataContent(Data* data);
ObjectBinary* getDataContentLastestCommon(Data* data);
ObjectBinary* getDataContentByID(char* dataID, DTPacket* dtPacket);
ObjectBinary* getDataContentLastestCommonByID(char* dataID, DTPacket* dtPacket);

Text getDiffDataAtHead(Data* data);
Text getDiffDataAtLastestCommon(Data* data);
Text getDiffDataAtHeadByID(char* dataID, DTPacket* dtPacket);
Text getDiffDataAtLastestCommonByID(char* dataID, DTPacket* dtPacket);

ObjectBinary* getContentNextVer(Data* data);
ObjectBinary* getContentPreVer(Data* data);
ObjectBinary* getContentNextVerByID(char* dataID, DTPacket* dtPacket);
ObjectBinary* getContentPreVerByID(char* dataID, DTPacket* dtPacket);

Text getDiffDataNextVer(Data* data);
Text getDiffDataPreVer(Data* data);
Text getDiffDataNextVerByID(char* dataID, DTPacket* dtPacket);
Text getDiffDataPreVerByID(char* dataID, DTPacket* dtPacket);

Text getDataContentWithTag(Data* data, char* tagName, char* id);
Text getDataContentWithTagByID(char* dataID, char* tagName, char* id, DTPacket* dtPacket);

ReturnErr setNewDataContent(Data* data, ObjectBinary* content);
ReturnErr setNewDataDiffWithTag(Data* data, char* tagName, char* id, Text diff);
ReturnErr saveNewDataContentByID(char* dataID, char* new_content, DTPacket* dtPacket);

Text getTagContentWithName(ObjectBinary* fullContent, char* tagName, char* id);
Text getTagContent(ObjectBinary* fullContent, int tagNameEnum, char* id);
ReturnErr setTagContent(ObjectBinary* fullContent, Text newTagContent, char* tagName, char* id);

const char* createOrg(Text orgName, Schema* orgSchema, DTPacket* dtPacket);
const char* createUser(Text userName, Schema* userSchema, DTPacket* dtPacket);
const char* createCategory(Text categoryName, Schema* categorySchema, DTPacket* dtPacket);
const char* createState(Text stateName, Schema* stateSchema, DTPacket* dtPacket);
const char* createTask(Text taskName, Schema* taskSchema, DTPacket* dtPacket);
const char* createSubTask(Text subTaskName, Schema* subTaskSchema, DTPacket* dtPacket);

ReturnErr addUser2OrgByID(char* orgID, char* userID, DTPacket* dtPacket);
ReturnErr addCategory2UserByID(char* userID, char* categoryID, DTPacket* dtPacket);
ReturnErr addState2CategoryByID(char* categoryID, char* stateID, DTPacket* dtPacket);
ReturnErr addTask2StateByID(char* stateID, char* taskID, DTPacket* dtPacket);
ReturnErr addTask2CategoryByID(char* categoryID, char* taskID, DTPacket* dtPacket);
ReturnErr addSubTask2TaskByID(char* taskID, char* subTaskID, DTPacket* dtPacket);

ReturnErr addUser2Org(char* orgID, User* user, DTPacket* dtPacket);
ReturnErr addCategory2User(char* userID, Category* category, DTPacket* dtPacket);
ReturnErr addState2Category(char* categoryID, State* state, DTPacket* dtPacket);
ReturnErr addTask2State(char* stateID, Task* task, DTPacket* dtPacket);
ReturnErr addTask2Category(char* categoryID, Task* task, DTPacket* dtPacket);
ReturnErr addSubTask2Task(char* taskID, SubTask *subTask, DTPacket* dtPacket);

//  for test transport only
ReturnErr addData2Data(char* dataID, Data* data, int dType, DTPacket* dtPacket);

ReturnErr removeUserFromOrg(char* orgID, char* userID, DTPacket* dtPacket);
ReturnErr removeCategoryFromUser(char* userID, char* categoryID, DTPacket* dtPacket);
ReturnErr removeStateFromCategory(char* categoryID, char* stateID, DTPacket* dtPacket);
ReturnErr removeTaskFromState(char* stateID, char* taskID, DTPacket* dtPacket);
ReturnErr removeTaskFromCategory(char* categoryID, char* taskID, DTPacket* dtPacket);
ReturnErr removeSubTaskFromTask(char* taskID, char* subTaskID, DTPacket* dtPacket);

ReturnErr deleteObj(char* userID, char* upperID, char* objID, DTPacket* dtPacket);
ReturnErr flushTrash(char* userID, DTPacket* dtPacket);

Org** queryOrgFromData(char* dataID, DTPacket* dtPacket);
User** queryAllUsersFromData(char* dataID, DTPacket* dtPacket);
Category** queryAllCategoriesFromData(char* dataID, DTPacket* dtPacket);
State** queryAllStatesFromData(char* dataID, DTPacket* dtPacket);
Task** queryAllTasksFromData(char* dataID, DTPacket* dtPacket);
SubTask** queryAllSubTasksFromData(char* dataID, DTPacket* dtPacket);

Data* queryDataByID(char* dataID, DTPacket* dtPacket);

char** getOrgID(DTPacket* dtPacket);
char** getUserFromOrgID(char* orgID, DTPacket* dtPacket);
char** getCatFromUserID(char* userID, DTPacket* dtPacket);
char** getStateFromCatID(char* catID, DTPacket* dtPacket);
char** getTaskFromStateID(char* stateID, DTPacket* dtPacket);
char** getSubTaskFromTaskID(char* taskID, DTPacket* dtPacket);
char** getTaskFromCatID(char* catID, DTPacket* dtPacket);

t_bool isObjectOwnedByUser(char* userID, char* objID, DTPacket* dtPacket);
t_bool isObjectUnderCategory(char* categoryID, char* objID, DTPacket* dtPacket);
t_bool isObjectUnderState(char* stateID, char* objID, DTPacket* dtPacket);
t_bool isObjectUnderTask(char* taskID, char* objID, DTPacket* dtPacket);

void freeData(Data* data);
void freeObjBinary(ObjectBinary* obj);

/* diff-patch function */
string getDiff(char* old_str, char* new_str);
string getPatch(char* str, char* str_patch);

/* transport and web function */
//  Pim
char* buildStringFromData(Data* data);
Data* buildDatafromString(char* strPack);
char* readcontent(const char *filename);
//  N'Pla
char* genString(Data* data);
char* genMsg(Data* data);


#endif /* defined(__datamodel_xml__datamodel__) */
