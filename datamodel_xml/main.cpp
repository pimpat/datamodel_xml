#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>

#include <uuid/uuid.h>
#include <jansson.h>
#include "reqmsg.h"
#include "swap_endian.h"
#include "diff_match_patch.h"
#include "ezxml.h"

#define SERVER_IP "0.0.0.0"
#define SERVER_PORT 2424

#define DB_NAME "datamodel_xml"
#define MAX_SQL_SIZE (2000)
#define MAX_DIFF_SIZE (1000)
#define MAX_CONTENT_SIZE (1000)
#define VER_KEEPED (10)

#define TRUE 1
#define FALSE 0

using namespace std;

int Sockfd;
typedef struct Packet {
    char opType;
    char ssid[4];
    char msg[20000];
} Packet;
Packet GPacket;

typedef struct Addr{
    short cltid;
    long rid;
} Addr;
Addr addr;

//----------------------------------

typedef struct ChatRef{
    const char* chatRefURL;
} ChatRef;

typedef struct CWTimeStamp{
    char* timeStampCode;
} CWTimeStamp;

typedef char* Text;
typedef char* Schema;

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
    int dataType;
    DataHolder* content;
    Text* attachmentFTOLinks;   //  NULL
    ChatRef* chatRoom;          //  NULL
} Data;

typedef Data Org;
typedef Data User;
typedef Data Category;
typedef Data State;
typedef Data Task;
typedef Data SubTask;

typedef int ReturnErr;

extern Data* mydata;
Data* mydata = NULL;

enum DATATYPE {
    _attachmentFTOLinks,
    _subTask,
    _task,
    _state,
    _category,
    _user,
    _org
};

/* binary protocol */
int connectSocket();
int connectServer();
int disconnectServer();
int createDatabase(char *dbName);
int createClass(char *myclass, char *extend);
int prepareDB();
int openDatabase(char *dbName);
int sendCommand(char *command);
int queryRecord(char *query);
int loadRecord(short clusterId, long clusterPos);
int createVertex(char *command);

char* getRid(char *query);
char* getContent(char *query);
char** getArrayRid(char* query);

/* datamodel function */
const char* stringUUID();
const char* createNewData(int dataType);
DataHolder* createNewDataHolder();
ObjectBinary* createNewObjBinary(char* data);
int countDataContent(Data* data);

ObjectBinary* getDataContent(Data* data);
ObjectBinary* getDataContentLastestCommon(Data* data);
ObjectBinary* getDataContentByID(char* dataID);
ObjectBinary* getDataContentLastestCommonByID(char* dataID);

Text getDiffDataAtHead(Data* data);
Text getDiffDataAtLastestCommon(Data* data);
Text getDiffDataAtHeadByID(char* dataID);
Text getDiffDataAtLastestCommonByID(char* dataID);

ObjectBinary* getContentNextVer(Data* data);
ObjectBinary* getContentPreVer(Data* data);
ObjectBinary* getContentNextVerByID(char* dataID);
ObjectBinary* getContentPreVerByID(char* dataID);

Text getDiffDataNextVer(Data* data);
Text getDiffDataPreVer(Data* data);
Text getDiffDataNextVerByID(char* dataID);
Text getDiffDataPreVerByID(char* dataID);

Text getDataContentWithTag(Data* data, char* tagName);
Text getDataContentWithTagByID(char* dataID, char* tagName);

ReturnErr setNewDataContent(Data* data, ObjectBinary* content);
ReturnErr setNewDataDiffWithTag(Data* data, char* tagName, Text diff);

Text getTagContentWithName(ObjectBinary* fullContent, char* tagName);
Text getTagContent(ObjectBinary* fullContent, int tagNameEnum);
ReturnErr setTagContent(ObjectBinary* fullContent, Text newTagContent, char* tagName);

const char* createOrg(Text orgName, Schema* orgSchema);
const char* createUser(Text userName, Schema* userSchema);
const char* createCategory(Text categoryName, Schema* categorySchema);
const char* createState(Text stateName, Schema* stateSchema);
const char* createTask(Text taskName, Schema* );
const char* createSubTask(Text subTaskName);
const char* createData(Text dataName, Schema* dataSchema);

Text getDataContentForKey(Schema* schema, uuid_t objID, char* keyName);

ReturnErr addData2Category(char* categoryID, Data* data);
ReturnErr addTask2Category(char* categoryID, Task *task);
ReturnErr addSubTask2Task(char* taskID, SubTask *subTask);
ReturnErr addState2Category(char* categoryID, State *state);
ReturnErr addCategory2User(char* userID, char* categoryID);
ReturnErr addUser2Org(char* orgID, char* userID);
//  addTaskToState ???

ReturnErr removeDataFromCategory(char* categoryID, char* dataID);
ReturnErr removeTaskFromCategory(char* categoryID, char* taskID);
ReturnErr removeSubTaskFromTask(char* taskID, char* subTaskID);
ReturnErr removeStateFromCategory(char* categoryID, char* stateID);
ReturnErr removeCategoryFromUser(char* userID, char* categoryID);
ReturnErr removeUserFromOrg(char* orgID, char* userID);
//  removeTaskFromState ???

Data* queryDataByID(char* dataID);
State** queryAllStatesFromData(char* dataID);
Category** queryAllCategoriesFromData(char* dataID);
User** queryAllUsersFromData(char* dataID);
//  queryOrg/Task/SubTask ???

t_bool isObjectUnderState(char* stateID, char* objID);
t_bool isObjectUnderCategory(char* categoryID, char* objID);
t_bool isObjectOwnedByUser(char* userID, char* objID);

ReturnErr deleteObj(char* userID, char* objID);
ReturnErr flushTrash(char* userID);
//  delete flag / delete edge

/* diff-patch function */
string getDiff(char* old_str, char* new_str);
string getPatch(char* str, char* str_patch);

//char* getDataContentFirst(Data* data);
//char* getDataContentLast(Data* data);
//char* getDataContentVer(Data* data,int ver);

void testDiffPatchXML();

int main() {
    testDiffPatchXML();
    return 0;
}

int connectSocket() {
    int sockfd;
    struct sockaddr_in serv_addr;
    
    sockfd=socket(AF_INET, SOCK_STREAM, 0);
    if ((sockfd) < 0) {
        printf("Error: Could net create socket\n");
        return sockfd;
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        printf("inet_pton error occured\n");
        return -1;
    }
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connect Failed\n");
        return -1;
    }
    read(sockfd, &GPacket, 256);
    
    printf("Connect Socket OK\n");
    
    return sockfd;
}

int connectServer() {
    int ret, size;
    GPacket.opType = REQUEST_CONNECT;
    *(int *)GPacket.ssid = -1;
    size = reqConnectMsg(GPacket.msg, NULL, NULL, 28, NULL, "root", "pimpat");
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5+sizeof(int));
    if (ret<0 || GPacket.opType!=0) return 1;
    
    // copy ssid
    memcpy(GPacket.ssid, GPacket.msg, 4);
    int ssid = *(int *)GPacket.ssid;
    swapEndian(&ssid, INT);
    printf("ssid: %d\n", ssid);
    
    //  for version 28
    int token;
    ret = read(Sockfd, &token, 4);
    
    return 0;
}

int disconnectServer() {
    int ret, size;
    GPacket.opType = 5;
    size = reqDBCloseMsg(GPacket.msg);
    ret = write(Sockfd, &GPacket, 5+size);
    return 0;
}

int createDatabase(char *dbName) {
    int ret, size;
    GPacket.opType = REQUEST_DB_CREATE;
    size = reqDBCreateMsg(GPacket.msg, dbName, "graph", "plocal");
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5+0);
    if (ret<0 || GPacket.opType!=0) return 1;
    
    printf("CREATE DATABASE '%s' plocal: OK!\n", dbName);
    return 0;
}

int createClass(char *myclass, char *extend) {
    int ret;
    char command[256];
    sprintf(command, "CREATE CLASS %s EXTENDS %s", myclass, extend);
    ret = sendCommand(command);
    if (ret!=0) return 1;
    
    printf("%s: OK!\n", command);
    return 0;
}

int createRecord(int cltId, char* recContent){
    int ret, size;
    GPacket.opType = REQUEST_RECORD_CREATE;
    size = reqRecCreateMsg(GPacket.msg, cltId, recContent);
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5+0);
    if (ret<0 || GPacket.opType!=0) return 1;
    
    short clusterId;
    read(Sockfd, &clusterId, sizeof(short));
    swapEndian(&clusterId, SHORT);
    printf("clusterId: %d\n", clusterId);
    
    long clusterPos;
    read(Sockfd, &clusterPos, sizeof(long));
    swapEndian(&clusterPos, LONG);
    printf("clusterPos: %d\n", clusterPos);
    
    int recVersion;
    read(Sockfd, &recVersion, sizeof(int));
    swapEndian(&recVersion, INT);
    printf("record-version: %d\n", recVersion);
    
    int count_of_changes;
    read(Sockfd, &count_of_changes, sizeof(int));
    swapEndian(&count_of_changes, INT);
    printf("count_of_changes: %d\n", count_of_changes);
    
    return 0;
}

int prepareDB() {
    int ret;
    
    Sockfd = connectSocket();
    if (Sockfd < 0) return Sockfd;
    printf("connectSocket..PASS\n");
    ret = connectServer();
    if (ret!=0) return 1;
    printf("connectServer...PASS\n");
    
    ret = createDatabase(DB_NAME);
    if (ret!=0) return 1;
    printf("createDB...PASS\n");
    
    /* Edge toUser */
    ret = createClass("toUser","E");
    if (ret!=0) return 1;
    
    /* Edge toCategory */
    ret = createClass("toCategory","E");
    if (ret!=0) return 1;
    
    /* Edge toState */
    ret = createClass("toState","E");
    if (ret!=0) return 1;
    
    /* Edge toTask */
    ret = createClass("toTask","E");
    if (ret!=0) return 1;
    
    /* Edge toSubTask */
    ret = createClass("toSubTask","E");
    if (ret!=0) return 1;
    
    /* Edge toAttachmentFTOLinks */
    ret = createClass("toAttachmentFTOLinks","E");
    if (ret!=0) return 1;
    
    /* Data */
    ret = createClass("Data","V");
    if (ret!=0) return 1;
    
    ret = sendCommand("CREATE PROPERTY Data.dataID STRING");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY Data.dataID STRING: OK!\n");
    
    ret = sendCommand("CREATE PROPERTY Data.dataType INTEGER");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY Data.dataType INTEGER: OK!\n");
    
    ret = sendCommand("CREATE PROPERTY Data.attachmentFTOLinks EMBEDDEDLIST STRING");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY Data.attachmentFTOLinks EMBEDDEDLIST STRING: OK!\n");
    
    ret = sendCommand("CREATE PROPERTY Data.chatRoom STRING");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY Data.chatRoom STRING: OK!\n");
    
    /* Edge toDataHolder */
    ret = createClass("toDataHolder","E");
    if (ret!=0) return 1;
    
    /* DataHolder */
    ret = createClass("DataHolder","V");
    if (ret!=0) return 1;
    
    ret = sendCommand("CREATE PROPERTY DataHolder.versionKeeped INTEGER");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY DataHolder.versionKeeped INTEGER: OK!\n");
    
    /* Edge toDataContent */
    ret = createClass("toDataContent","E");
    if (ret!=0) return 1;
    
    ret = sendCommand("CREATE PROPERTY toDataContent.type STRING");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY toDataContent.type STRING: OK!\n");
    
    /* DataContent */
    ret = createClass("DataContent","V");
    if (ret!=0) return 1;
    
    ret = sendCommand("CREATE PROPERTY DataContent.SHA256hashCode STRING");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY DataContent.SHA256hashCode STRING: OK!\n");
    
    ret = sendCommand("CREATE PROPERTY DataContent.timeStamp STRING");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY DataContent.timeStamp STRING: OK!\n");
    
    ret = sendCommand("CREATE PROPERTY DataContent.isDiff BOOLEAN");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY DataContent.isDiff BOOLEAN: OK!\n");
    
    //  minusPatch
    ret = sendCommand("CREATE PROPERTY DataContent.minus_schemaCode INTEGER");
    if (ret!=0) return 1;
    ret = sendCommand("CREATE PROPERTY DataContent.minus_byteCount INTEGER");
    if (ret!=0) return 1;
    ret = sendCommand("CREATE PROPERTY DataContent.minus_data STRING");
    if (ret!=0) return 1;
    
    //  plusPatch
    ret = sendCommand("CREATE PROPERTY DataContent.plus_schemaCode INTEGER");
    if (ret!=0) return 1;
    ret = sendCommand("CREATE PROPERTY DataContent.plus_byteCount INTEGER");
    if (ret!=0) return 1;
    ret = sendCommand("CREATE PROPERTY DataContent.plus_data STRING");
    if (ret!=0) return 1;
    
    //  fullContent
    ret = sendCommand("CREATE PROPERTY DataContent.full_schemaCode INTEGER");
    if (ret!=0) return 1;
    ret = sendCommand("CREATE PROPERTY DataContent.full_byteCount INTEGER");
    if (ret!=0) return 1;
    ret = sendCommand("CREATE PROPERTY DataContent.full_data STRING");
    if (ret!=0) return 1;
    
    /* Edge toObjectBinary */
    ret = createClass("toObjectBinary","E");
    if (ret!=0) return 1;
    
    ret = sendCommand("CREATE PROPERTY toObjectBinary.type STRING");
    if (ret!=0) return 1;
    //printf("CREATE PROPERTY toObjectBinary.type STRING: OK!\n");
    
    /* Edge toDataHolder_fromDC */
    ret = createClass("toDataHolder_fromDC","E");
    if (ret!=0) return 1;
    
    //  alter class
    ret = sendCommand("ALTER DATABASE CUSTOM useLightweightEdges=false");
    if (ret!=0) return 1;
    printf("ALTER DATABASE CUSTOM useLightweightEdges=false: OK!\n");
    
    disconnectServer();
    close(Sockfd);
    
    printf("prepareDB...PASS\n");
    return 0;
}

int openDatabase(char *dbName) {
    printf("Opening Database...\n");
    int ret, size, i;
    GPacket.opType = REQUEST_DB_OPEN;
    *(int *)GPacket.ssid = -1;
    size = reqDBOpenMsg(GPacket.msg, NULL, NULL, 28, NULL, dbName, "graph", "root", "pimpat");
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5+sizeof(int));
    printf("resSize: %d\n", ret);
    printf("resCode: %d\n", GPacket.opType);
    if (ret<0 || GPacket.opType!=0) return 1;
    
    // copy ssid
    memcpy(GPacket.ssid, GPacket.msg, 4);
    int ssid = *(int *)GPacket.ssid;
    swapEndian(&ssid, INT);
    printf("ssid: %d\n", ssid);
    
    //  for version 28
    int token;
    ret = read(Sockfd, &token, 4);
    
    //  copy num-of-clusters
    short nCluster;
    ret = read(Sockfd, &nCluster, sizeof(short));
    swapEndian(&nCluster, SHORT);
    printf("num-of-clusters: %hd\n", nCluster);
    
    for (i=0; i<nCluster; i++) {
        char name[128];
        //char type[32];
        short id;//, dataSeg;
        
        //  read info classes
        read(Sockfd, &size, sizeof(int));
        swapEndian(&size, INT);
        read(Sockfd, name, size);
        name[size] = '\0';
        read(Sockfd, &id, sizeof(short));
        swapEndian(&id, SHORT);
        
        //        read(Sockfd, &size, sizeof(int));
        //        swapEndian(&size, INT);
        //        read(Sockfd, type, size);
        //        type[size] = '\0';
        //        read(Sockfd, &dataSeg, sizeof(short));
        //        swapEndian(&dataSeg, SHORT);
        //        printf("name:'%s'\t id:%hd\t type:%s\t dataSeg:%hd\n", name, id, type, dataSeg);
        
        //  for version 28
        printf("name:'%s'\t id:%hd\n", name, id);
    }
    
    read(Sockfd, &size, sizeof(int));
    swapEndian(&size, INT);
    if (size > 0) {
        char clusterConfig[size];
        read(Sockfd, clusterConfig, size);
        //clusterConfig[size]='\0';
    }
    
    read(Sockfd, &size, sizeof(int));
    swapEndian(&size, INT);
    if (size > 0) {
        char orientRelease[size+1];
        read(Sockfd, orientRelease, size);
        orientRelease[size] = '\0';
        printf("%s\n", orientRelease);
    }
    return 0;
}

int sendCommand(char *command) {
    int ret, size;
    GPacket.opType = REQUEST_COMMAND;
    size = reqCommandMsg(GPacket.msg, "c", command);
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5+256);
    //printf("opType:%d\n", GPacket.opType);
    if (ret<0 || GPacket.opType!=0)
        return 1;
    else
        return 0;
}

int queryRecord(char *query) {
    int i, ret, size, total;
    GPacket.opType = REQUEST_COMMAND;
    size = reqQueryMsg(GPacket.msg, "q", query);
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5);
    //printf("ret:%d\n", ret);
    printf("opType:%d\n", GPacket.opType);
    if (ret<0 || GPacket.opType!=0) return 1;
    
    read(Sockfd, &GPacket.msg, 1);
    read(Sockfd, &total, 4);
    swapEndian(&total, INT);
    printf("total: %d\n",total);    // total record
    read(Sockfd, &GPacket.msg, 2+1+2+8+4);
    //read(Sockfd, &GPacket.msg, 1+4+2+1+2+8+4);
    
    for(i=0;i<total;i++){
        read(Sockfd, &size, 4);
        swapEndian(&size, INT);
        printf("[%d]--------------------------------------------------\n",i);
        printf("size: %d\t",size);
        
        //  read content
        read(Sockfd, GPacket.msg, size);
        GPacket.msg[size]='\0';
        printf("msg: %.*s\n",size,GPacket.msg);
        //printf("len: %d\n", strlen(GPacket.msg));
        read(Sockfd, &GPacket.msg, 2+1+2+8+4);
    }
    
    return 0;
}

int loadRecord(short clusterId, long clusterPos) {
    int ret, size;
    GPacket.opType = REQUEST_RECORD_LOAD;
    size = reqRecLoadMsg(GPacket.msg, clusterId, clusterPos);
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5);
    //printf("ret:%d\n", ret);
    printf("opType:%d\n", GPacket.opType);
    if (ret<0 || GPacket.opType!=0) return 1;
    
    char payloadStatus;
    read(Sockfd, &payloadStatus, sizeof(char));
    printf("status:%hhu\n", payloadStatus);
    
    char recType;
    read(Sockfd, &recType, sizeof(char));
    printf("record-type: %c\n", recType);
    
    int recVersion;
    read(Sockfd, &recVersion, sizeof(int));
    swapEndian(&recVersion, INT);
    printf("record-version: %d\n", recVersion);
    
    //  read content
    read(Sockfd, &size, sizeof(int));
    swapEndian(&size, INT);
    printf("size: %d\n",size);
    
    char content[size+1];
    read(Sockfd, content, size);
    content[size] = '\0';
    printf("content:'%s'\n", content);
    
    return 0;
}

int createVertex(char *command){
    int ret, size;
    int in_size;
    GPacket.opType = REQUEST_COMMAND;
    size = reqCommandMsg(GPacket.msg, "c", command);
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5+1+2+1);
    if (ret<0 || GPacket.opType!=0){
        //printf("createVertex..FAILED\n");
        return 1;
    }
    else{
        ret = read(Sockfd, &addr.cltid, 2);
        if (ret<0) return 1;
        swapEndian(&addr.cltid, SHORT);
        ret = read(Sockfd, &addr.rid, 8);
        if (ret<0) return 1;
        swapEndian(&addr.rid, LONG);
        printf("@rid #%d:%lu\n",addr.cltid,addr.rid);
        
        read(Sockfd, &in_size, 4);
        read(Sockfd, &in_size, 4);
        swapEndian(&in_size, INT);
        //printf("in_size: %d\n",in_size);
        
        ret = read(Sockfd,&GPacket.msg,in_size+1);
        if (ret<0) return 1;
        return 0;
    }
}

char* getRid(char *query) {
    int i, ret, size, total;
    GPacket.opType = REQUEST_COMMAND;
    size = reqQueryMsg(GPacket.msg, "q", query);
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5);
    //printf("ret:%d\n", ret);
    printf("opType:%d\n", GPacket.opType);
    if (ret<0 || GPacket.opType!=0){
        printf("getRid error\n");
        return NULL;
    }
    
    read(Sockfd, &GPacket.msg, 1);
    read(Sockfd, &total, 4);
    swapEndian(&total, INT);
    printf("total: %d\n",total);    // total record
    read(Sockfd, &GPacket.msg, 2+1+2+8+4);
    //read(Sockfd, &GPacket.msg, 1+4+2+1+2+8+4);
    
    if(total==0){
        printf("FAILED >> data not found\n");
        return NULL;
    }
    
    char myResult[20];
    char* str;
    char* token;
    char delim[2] = "#";
    //char* str = (char*)malloc(sizeof(char)*10);   (fix)
    
    for(i=0;i<total;i++){
        read(Sockfd, &size, 4);
        swapEndian(&size, INT);
        //printf("[%d]--------------------------------------------------\n",i);
        //printf("size: %d\t",size);
        
        //  read content
        read(Sockfd, GPacket.msg, size);
        GPacket.msg[size]='\0';
        sprintf(myResult,"%s",GPacket.msg);
        printf("size: %lu\t",strlen(myResult));
        printf("msg: %s\n", myResult);
        token = strtok(myResult, delim);
        token = strtok(NULL, delim);
        //printf("result_token: %s\n", token);
        str = strdup(token);
        //sprintf(str,"%s",token);  (fix)
        read(Sockfd, &GPacket.msg, 2+1+2+8+4);
    }
    printf("@rid #%s\n",str);
    return str;
}

char* getContent(char *query) {
    int i, ret, size, total;
    GPacket.opType = REQUEST_COMMAND;
    size = reqQueryMsg(GPacket.msg, "q", query);
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5);
    printf("opType:%d\n", GPacket.opType);
    if (ret<0 || GPacket.opType!=0) {
        printf("getContent error\n");
        return NULL;
    }
    
    read(Sockfd, &GPacket.msg, 1);
    read(Sockfd, &total, 4);
    swapEndian(&total, INT);
    printf("total: %d\n",total);    // total record
    read(Sockfd, &GPacket.msg, 2+1+2+8+4);
    
    if(total==0)
        return NULL;
    
    char* str = (char*)malloc(sizeof(char)*MAX_CONTENT_SIZE);
    
    //for(i=0;i<total;i++){
    read(Sockfd, &size, 4);
    swapEndian(&size, INT);
    printf("size: %d\n",size);
    read(Sockfd, str, size);
    str[size]='\0';
    printf("msg: %s\n",str);
    read(Sockfd, &GPacket.msg, 2+1+2+8+4);
    printf("[result from getContent]---------------\n",i);
    //}
    //printf("result(in): %s\n",str);
    return str;
}

char** getArrayRid(char* query){
    int i, ret, size, total;
    GPacket.opType = REQUEST_COMMAND;
    size = reqQueryMsg(GPacket.msg, "q", query);
    ret = write(Sockfd, &GPacket, 5+size);
    
    ret = read(Sockfd, &GPacket, 5);
    //printf("ret:%d\n", ret);
    printf("opType:%d\n", GPacket.opType);
    if (ret<0 || GPacket.opType!=0) {
        printf("FAILED >> getArrayRid\n");
        return NULL;
    }
    
    read(Sockfd, &GPacket.msg, 1);
    read(Sockfd, &total, 4);
    swapEndian(&total, INT);
    printf("total: %d\n",total);    // total record
    read(Sockfd, &GPacket.msg, 2+1+2+8+4);
    
    if(total==0)
        return NULL;
    
    char **result_rid = (char**)malloc(sizeof(char*)*total+1);
    
    for(i=0;i<total;i++){
        read(Sockfd, &size, 4);
        swapEndian(&size, INT);
        printf("[%d]--------------------------------------------------\n",i);
        printf("size: %d\t",size);
        result_rid[i] = (char*)malloc(sizeof(char)*size-3);
        
        //  read content
        read(Sockfd, &GPacket.msg, 4);
        read(Sockfd, &GPacket.msg, size-4);
        GPacket.msg[size-4]='\0';
        printf("msg: %s\n", GPacket.msg);
        sprintf(result_rid[i],"%s",GPacket.msg);
        //printf("len: %d\n",strlen(result_rid[i]));
        printf("myrid: %s\n",result_rid[i]);
        read(Sockfd, &GPacket.msg, 2+1+2+8+4);
    }
    result_rid[i] = NULL;
    
    //    for(i=0;result_rid[i]!=NULL;i++) {
    //        printf("TEST_rid: %s\n",result_rid[i]);
    //    }
    
    return result_rid;
}

//----------------------------------------------------------------------------------------------------------

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

const char* createNewData(int dataType){
    mydata = (Data*)malloc(sizeof(Data));
    mydata->dataID = stringUUID();
    printf("dataID: %s\n",mydata->dataID);
    mydata->dataType = dataType;   // fix
    mydata->content = createNewDataHolder();
    mydata->attachmentFTOLinks = NULL;
    mydata->chatRoom = NULL;
    return mydata->dataID;
}

DataHolder* createNewDataHolder(){
    DataHolder* dh = (DataHolder*)malloc(sizeof(DataHolder));
    dh->versionKeeped = VER_KEEPED;
    dh->head = NULL;
    dh->lastestCommon = NULL;
    dh->current = NULL;
    return dh;
}

ObjectBinary* createNewObjBinary(char* data){
    ObjectBinary* obj = (ObjectBinary*)malloc(sizeof(ObjectBinary));
    obj->schemaCode = 0;    // fix
    obj->byteCount = (int)strlen(data);
    obj->data = strdup(data);
    return obj;
}

int countDataContent(Data* data){
    DataContent* dc = data->content->lastestCommon;
    int i=0;
    while(dc!=NULL){
        i++;
        dc = dc->nextVersion;
    }
    return i;
}

int setNewDataContent(Data* data, ObjectBinary* content){
    if(data->content->head==NULL && data->content->lastestCommon==NULL){
        printf("\n[ DATA #1 ]\n");
        //  <root></root>
        DataContent* dc0 = (DataContent*)malloc(sizeof(DataContent));
        
        //  (none) +A <root>A</root>
        DataContent* dc1 = (DataContent*)malloc(sizeof(DataContent));
        
        DataHolder* dh = data->content;
        dh->lastestCommon = dc0;
        dh->head = dc1;
        dh->current = dc1;
        
        dc0->preVersion = NULL;
        dc0->nextVersion = dc1;
        dc1->preVersion = dc0;
        dc1->nextVersion = NULL;
        
        //  dc0 ------------------------------------------------------------
        dc0->dataHd = dh;
        dc0->SHA256hashCode = strdup("default");
        dc0->timeStamp = NULL;
        dc0->isDiff = FALSE;
        
        //  dc0->fullContent
        ObjectBinary* obj0 = (ObjectBinary*)malloc(sizeof(ObjectBinary));
        dc0->fullContent = obj0;
        obj0->schemaCode = content->schemaCode;
        obj0->data = "<root></root>";
        
        obj0->byteCount = (int)strlen(obj0->data);
        
        //  dc0->minusPatch
        dc0->minusPatch = NULL;
        
        //  dc0->plusPatch
        dc0->plusPatch = NULL;
        
        //  dc1 ------------------------------------------------------------
        dc1->dataHd = dh;
        dc1->SHA256hashCode = strdup("default");
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
        
        string s = getDiff(obj0->data,obj1_full->data);
        obj1_plus->data = strdup(s.c_str());
        obj1_plus->byteCount = (int)strlen(obj1_plus->data);
        
        printf("init: %s\n",obj0->data);
        printf("new: %s\n",obj1_full->data);
        printf("diff: %s\n",obj1_plus->data);
        
        return obj1_plus->byteCount;
        
    }
    else{
        int total = countDataContent(data);
        printf("\n[ DATA #%d ]\n",total);
        
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
        
        //  dc0->fullPatch
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
        dc1->SHA256hashCode = strdup("default");
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
        
        return obj1_plus->byteCount;
    }
}

ReturnErr setNewDataDiffWithTag(Data* data, char* tagName, Text diff){
    printf("\n--- setNewDataDiffWithTag ---\n");
    DataContent* dc_old = data->content->head;
    char* old_xml = strdup(dc_old->fullContent->data);
    
    ezxml_t root = ezxml_parse_str(old_xml,strlen(old_xml));
    ezxml_t partial_data = ezxml_get(root,tagName,-1);
    if(partial_data==NULL) {
        printf("FAILED >> incorrect tag\n");
        ezxml_free(root);
        return -1;
    }

    printf("val_before: %s\n",partial_data->txt);
    printf("val_diff: %s\n",diff);
    
    string s = getPatch(partial_data->txt,diff);
    char* val_after = strdup(s.c_str());
    printf("val_after: %s\n",val_after);

    ezxml_set_txt(partial_data,val_after);
    char* new_xml = ezxml_toxml(root);
    printf("new_xml: %s\n", new_xml);
    
    ObjectBinary* objB = createNewObjBinary(new_xml);
    int ret = setNewDataContent(data, objB);

    free(old_xml);
    free(val_after);
    free(new_xml);
    ezxml_free(root);
    return ret;
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

void testDiffPatchXML(){
    const char* uuid_data;
    uuid_data = createNewData(_user);
    
    printf("uuid: %s\n",mydata->dataID);
    printf("dataType: %d\n",mydata->dataType);
    printf("ver_keeped: %d\n\n",mydata->content->versionKeeped);
    
    ezxml_t root = ezxml_parse_file("/Users/pimpat/Desktop/datamodel_xml/file_xml/root.xml");
    char* root_xml = ezxml_toxml(root);
    
    ezxml_t book0 = ezxml_parse_file("/Users/pimpat/Desktop/datamodel_xml/file_xml/book0.xml");
    char* book0_xml = ezxml_toxml(book0);
    char* bk0_xml = strdup(book0_xml);
    
    ezxml_t book1 = ezxml_parse_file("/Users/pimpat/Desktop/datamodel_xml/file_xml/book1.xml");
    char* book1_xml = ezxml_toxml(book1);
    char* bk1_xml = strdup(book1_xml);
    
//    char* content0 = "<root><book_id>bk100</book_id><author>Gambardella, Matthew</author><title>XML Developer's Guide</title><genre>Computer</genre><price>44.95</price></root>";
//    char* content1 = "<root><book_id>bk100</book_id><author>Pim</author><title>XML Developer's Guide</title><genre>Computer</genre><price>44.95</price></root>";

    ObjectBinary* obj0 = createNewObjBinary(book0_xml);
    ObjectBinary* obj1 = createNewObjBinary(book1_xml);
    
    setNewDataContent(mydata,obj0);

    string s = getDiff("44.95", "1000");
    char* diff_price = strdup(s.c_str());
    
    setNewDataDiffWithTag(mydata, "price", diff_price);
    setNewDataContent(mydata,obj1);
    
//    /* Test Diff-Patch */
//    printf("Test Diff-Patch --------------------------------\n\n");
//    
//    char* temp_xml = "<root>1234</root>";
//    printf("init0: %s\n",root_xml);
//    printf("diff0: %s\n\n",temp_xml);
//    
//    string diff = getDiff(root_xml, temp_xml);
//    char* res_diff = strdup(diff.c_str());
//    printf("res_diff: %s\n\n",res_diff);
//    
//    string patch = getPatch(root_xml, res_diff);
//    char* res_patch = strdup(patch.c_str());
//    printf("res_patch: %s\n\n",res_patch);
    
    ezxml_free(root);
    ezxml_free(book0);
    ezxml_free(book1);

}



