//
//  SDKDataType.h
//  IosSdk
//
//  Created by yanhd on 2021/8/26.
//

#ifndef SDKDataType_h
#define SDKDataType_h

typedef enum {
    ERR_UNKNOW, //未知错误
    ERR_SUCCESS,//成功
    ERR_CLIENTID_ERROR,//ClientID或ClientSecret信息错误"
    ERR_NETWORK,//网络错误
    ERR_CONNECT_FAILED,//网络链接失败
    ERR_INVALID_PARAM,//参数异常，用于登录参数验证
    ERR_IN_LOGINING,//正在登录会议室，防止多次调用登录会议室
    ERR_LOGIN_TIMEOUT,//登录超时
    ERR_ACCOUT_PWD, //账号名或密码错误
    ERR_LOGIN_SUCCESS,//登录成功
    ERR_LOGIN_FAILED,//登录失败
    ERR_LOGIN_CANCELED,//登录取消
    ERR_SERVER_UNAUTHORIZED, //服务器未授权
    ERR_ROOM_LOCKED, //会议室已锁定
    ERR_USER_REFUSED_ENTER, //锁定会议室后，用户被拒绝进入
    ERR_USER_FORBID_ENTER, // 锁定会议室后，用户被拉黑，
    ERR_NOT_PERMISSION_ENTER,//用户无权进入会议室
    ERR_ROOM_NOT_FOUND, //会议室未找到
    ERR_ROOM_FULL,//会议室已满
    ERR_HAS_LOGINED,//用户重复进入同一会议室
    ERR_PAAS_CONNECTING,//PASS重连
    ERR_VERIFY_ROOM, //会议室校验错误
    ERR_ROOM_PWD, //会议室密码错误
    ERR_NO_PERMISSION, //没有权限
    ERR_NEED_APPLY_PERMISSION, //音视频需要申请权限
    ERR_APPLY_SUCCESS,//申请成功
    ERR_APPLY_FAILED,  //申请失败
    ERR_INIT_FAILED, //SDK 未初始化
    ERR_ORGANIZATION_POIN_FULL, //组织授权点数已满，请联系售后客服热线400-1199-666
    ERR_ONLY_ACCOUNT_LOGIN,   //只允许以用户名密码方式登录
    ERR_APPLY_NOTPERSSIMON, // 不允许申请管理员
    ERR_FSP_LOGIN_FAILED,  //FSP登录失败
    ERR_USER_NOT_AUTHOR,    //会议室未授权该用户
    ERR_WHITEBOARD_COUNT_LIMIT, //白板个数超过5个
    ERR_VERIFY_FAILED, //验证失败
    ERR_ROOM_CLOSED, //会议室已关闭
    ERR_ROOM_EXPIRED, //会议室已过期
    ERR_NO_NETWORK, //无网络
    ERR_NOT_STAART, //未到开始时间
    ERR_NOT_INVITETOJOIM, //会议室不允许邀请码加入
    ERR_ENTER_ROOM_LIST, //进入会议室列表
    ERR_HAS_ANOTHER_LOGINED,//账号已被其他移动客户端登录
}ReturnCode;

typedef enum {
    Reconnecting =  0,
    ReconnectSuccess = 1,
    ReconnectFailed = 2,
}ReconnectState;

typedef enum
{
    _LAYOUT_MODE_NORMAL        = 1,//默认模式
    _LAYOUT_MODE_DATA        = 2,//数据模式
    _LAYOUT_MODE_VIDEO        = 3,//视频模式
    _LAYOUT_MODE_DATAFULL    = 4 //视频模式全屏，只有在本地asf录制的时候使用（为了兼容老功能）
}_LayoutMode;

//区域布局风格
typedef enum
{
    _AREA_LAYOUT_STYLE_TILED    = 0,    //平铺风格类型
    _AREA_LAYOUT_STYLE_TABLE    = 1,    //tab切换风格类型
    _AREA_LAYOUT_STYLE_SPLIT    = 2,    //分屏风格类型
    _AREA_LAYOUT_STYLE_POP    = 3        //弹出风格类型
}_AreaLayoutStyle;

//分屏风格
typedef enum
{
    _SPLIT_STYLE_AUTO    = 0,    //默认自动
    _SPLIT_STYLE_1        = 1,    //一分屏
    _SPLIT_STYLE_2        = 2,
    _SPLIT_STYLE_P_IN_P    = 3,    //画中画
    _SPLIT_STYLE_4        = 4,
    _SPLIT_STYLE_6        = 6,
    _SPLIT_STYLE_9        = 9,
    _SPLIT_STYLE_12        = 12,
    _SPLIT_STYLE_16        = 16,
    _SPLIT_STYLE_25        = 25,
    _SPLIT_STYLE_36        = 36,
    _SPLIT_STYLE_49        = 49,
    _SPLIT_STYLE_64        = 64,
    _SPLIT_STYLE_NO        = 50    //无分屏（如无视频/纯语音）
}_SplitStyle;


//数据类型
typedef enum
{
    _DATA_TYPE_NONE            = 0,    //默认,无类型，平面类型（如Windows端的会议室信息页面）
    _DATA_TYPE_WB            = 1,    //白板
    _DATA_TYPE_APPSHARE        = 2,    //屏幕共享
    _DATA_TYPE_WEB            = 3,    //Web协同浏览
    _DATA_TYPE_MEDIASHARE    = 4,    //媒体共享
    _DATA_TYPE_VOTE            = 5,    //电子投票
    _DATA_TYPE_VIDEO        = 6,    //视频
    _DATA_TYPE_ROUND        = 7     // 视频轮巡dataID为轮巡ID，userData为轮
                                    // 巡类型（本地 0，广播 1）；
}_DataType;

/// 会议类型
typedef NS_ENUM(NSUInteger, TagMeetingType) {
    MeetingTypeFixed = 0,            // 固定会议室
    MeetingTypeInvite = 1,           // 通讯录邀请入会
    MeetingTypeInstant,              // 主页立即开会
};

typedef NS_ENUM(NSUInteger, OnlineContactUserState) {
    USER_STATE_OFFLINE = 0,     //用户离线状态
    USER_STATE_MEETING,            //用户会议中状态
    USER_STATE_ONLINE            //用户在线状态
};

typedef NS_ENUM(NSUInteger, OnlineInviteRejectedReason) {
    IRR_BYUSER = 0, ///<用户操作拒绝
    IRR_REMOTE_TIMEOUT = 1, ///<远端用户超时未处理, 目前服务器定的是20s
    IRR_LOCAL_TIMEOUT = 2 ///<本地超时，90秒未收到任何回复就本地超时
};

typedef NS_ENUM(NSUInteger, OnlineInviteAbandonedReason) {
    IAR_BYUSER = 0, ///<邀请方手动取消
    IAR_CLEAR = 1,  ///<服务端发拆线,可能其他终端接收了
    IAR_LOCAL_TIMEOUT = 2, ///<本地超时，90秒为接受或拒绝就取消
    IAR_REJECT_INVITATION_REASON = 0x100, ///<起始值，具体的解析看RejectInvitationReason
};

@interface FullAreaObj : NSObject
@property (nonatomic, assign) _AreaLayoutStyle style;//全屏区域风格
@property (nonatomic, assign) int userData;          //自定义字段，暂时无用
@property (nonatomic, strong) NSMutableArray *idSet;
- (void) copy:(FullAreaObj*)object;
- (BOOL)isEqualTo:(FullAreaObj*)object;
@end

@interface DataBlockObj : NSObject
@property (nonatomic, assign) unsigned char pos;
@property (nonatomic, assign) _DataType dataType;
@property (nonatomic, assign) unsigned long dataID;
@property (nonatomic, assign) unsigned int userData;
- (BOOL)isEqualTo:(DataBlockObj*)object;
- (void)copy:(DataBlockObj*)object;
@end

@interface AreaDataObj : NSObject
@property (nonatomic, assign) unsigned char AreaDataid;
@property (nonatomic, assign) unsigned char screenID;//所属屏ID
@property (nonatomic, assign) _AreaLayoutStyle style;//区域布局样式
@property (nonatomic, assign) int userData;//自定义字段（tab风格中为当前选中的数据块pos；split分屏风格中为：分屏模式，多少分屏）
                                            //如果主持人是老版本，未使用新协议进行交互，则userData字段值为：对应的数据类型
                                            //所以需要应用层自己查找到对应pos,白板则需要继续以白板的active回调设置的当前激活白板
@property (nonatomic,strong) NSMutableArray *dataBlockList;//数据块列表
- (BOOL)isEqualTo:(AreaDataObj*)object;
- (void) copy:(AreaDataObj*)object;
+ (AreaDataObj*)newCopy:(AreaDataObj*)source;
@end

@interface FileListItemObj : NSObject
@property (nonatomic, strong) NSMutableString* guidFile;
@property (nonatomic, strong) NSMutableString* guidParent;
@property (nonatomic, strong) NSMutableString* strFileDisplayName;
@property (nonatomic, strong) NSMutableString* strFileName;
@property (nonatomic, strong) NSMutableString* strFileExName;
@property (nonatomic, assign) unsigned long dwFileSize;
@property (nonatomic, assign) unsigned long dwCheckCode;
@property (nonatomic, assign) unsigned long dwCreatorID;
@property (nonatomic, assign) unsigned short wFileType;
@property (nonatomic, assign) unsigned short wFileWidth;
@property (nonatomic, assign) unsigned short wFileHeight;
@property (nonatomic, assign) unsigned short wSubFileCount;
@property (nonatomic, strong) NSMutableString* strFileUrl;
@property (nonatomic, assign) unsigned short wFileServerAppID;
@property (nonatomic, strong) NSMutableString* strFileServerAddrLink;
@end

@interface MeetingRoomInfo : NSObject
@property (nonatomic, strong) NSMutableString* meetingSuject;
@property (nonatomic, strong) NSMutableString* inviteCode;
@property (nonatomic, strong) NSMutableString* roomID;
@property (nonatomic, strong) NSMutableString* maxCount;
@property (nonatomic, strong) NSMutableString* startTime;
@property (nonatomic, strong) NSMutableString* endTime;
@end

@interface TagRoomInfoObj : NSObject

@property (nonatomic, assign) NSInteger roomId;
@property (nonatomic, strong) NSMutableString *roomName;
@property (nonatomic, assign) NSInteger curUserCount;
@property (nonatomic, assign) NSInteger maxUserCount;
@property (nonatomic, strong) NSMutableString *nodeID;
@property (nonatomic, strong) NSMutableString *userRight;
@property (nonatomic, assign) NSInteger userId;
//add by hcb
@property (nonatomic, strong) NSMutableString *inviteCode;
//end
@end

@interface tagScheduleInfoObj : NSObject
@property (nonatomic,assign) NSInteger roomId; //    int    会议室ID
@property (nonatomic, assign) long hopeStartTime;  //  int 开始时间
@property (nonatomic, assign) long hopeEndTime;  //  int 结束时间
@property (nonatomic,strong) NSMutableString *roomName; //    String    会议室名称
@property (nonatomic,strong) NSMutableString *inviteCode; //    String    邀请码
@end

@interface tagInstantUserInfoObj : NSObject
@property (nonatomic,strong) NSMutableString *userName;
@property (nonatomic,strong) NSMutableString *nickName;
@end

@interface tagInstantRoomInfoObj : NSObject
@property (nonatomic,strong) NSMutableString *meetingName;
@property (nonatomic,assign) NSInteger creatorId;
@property (nonatomic,assign) NSInteger verifyMode;
@property (nonatomic,assign) NSInteger maxUserCount;
@property (nonatomic,assign) NSInteger meetingTemplate;
@property (nonatomic,assign) NSUInteger roomId;
@property (nonatomic,assign) NSInteger meetingCreateTime;
@property (nonatomic,strong) NSMutableString *inviteCode;
@property (nonatomic,strong) NSMutableArray <tagInstantUserInfoObj *>*userInfoList;
@end

@interface tagRespondInfoObj : NSObject
@property(nonatomic,assign) NSInteger nCode;
@property(nonatomic,strong) NSMutableString *strMessage;
@end

@interface tagOnlineUserInfoObj : NSObject
@property (nonatomic,strong) NSMutableString *name;
@property (nonatomic,strong) NSMutableString *nickname;
@property (nonatomic,strong) NSMutableString *depName;
@property (nonatomic,assign) NSInteger ID;
@property (nonatomic,assign) NSInteger deptId;
@property (nonatomic,assign) NSInteger sortId;
@property (nonatomic,assign) NSInteger typeFlag;
@property (nonatomic,assign) OnlineContactUserState status;
@end

@interface tagDeptInfoObj : NSObject
@property (nonatomic,assign) NSInteger ID;
@property (nonatomic,strong) NSMutableString *name;
@property (nonatomic,assign) NSInteger parent_id;
@end

@interface tagDeptNodeObj : NSObject
@property (nonatomic,strong) tagDeptInfoObj *data;
@property (nonatomic,strong) NSMutableArray <tagDeptNodeObj *>*children;
@end

@interface tagDeptListObj : NSObject
@property (nonatomic,strong) tagRespondInfoObj *rep;
@property (nonatomic,assign) NSInteger totalCount;
@property (nonatomic,assign) NSInteger totalUserCount;
@property (nonatomic,strong) tagDeptNodeObj *root;
@end

@interface tagPageUserListObj : NSObject
@property (nonatomic,strong) tagRespondInfoObj *rep;
@property (nonatomic,strong) NSMutableArray <tagOnlineUserInfoObj *>*userList;
@property (nonatomic,assign) NSInteger currentPage; // 当前页
@property (nonatomic,assign) NSInteger pageSize; // 每页大小
@property (nonatomic,assign) NSInteger totalRowsAmount; //    int    总数
@end

@interface InviterObj : NSObject

@property (nonatomic,assign) int userId;

@property (nonatomic,strong) NSMutableString *userName;

@property (nonatomic,strong) NSMutableString *terminal;
@end

@interface InviteDataObj : NSObject

@property (nonatomic,strong) InviterObj *inviter;

@property (nonatomic,assign) int inviteCode; // 邀请码

@property (nonatomic,assign) int roomCreateTime; // 会议室创建时间戳

@property (nonatomic,assign) int roomCompanyId; // 会议室所属企业ID

@property (nonatomic,assign) int calloutType; // 邀请会议模式 0. 音频 1. 视频

@property (nonatomic,assign) int isForce; // 强制邀请，预留后面会中也能接收邀请

@property (nonatomic,assign) int proxyUserId; // 代理人，预留后面web会控代理发起邀请

@end


@interface OnlineUserViewModel : NSObject

/// 用户信息
@property (nonatomic,strong) tagOnlineUserInfoObj *userInfo;

/// 是否被选中
@property (nonatomic,assign) BOOL isSelected;

- (instancetype)initWithUserInfo:(tagOnlineUserInfoObj *)userInfo;

/// 根据nickname排序
+ (NSMutableArray <OnlineUserViewModel *>*)sortedByNickname:(NSMutableArray <OnlineUserViewModel *>*)userList;

@end

@interface DeptNodeViewModel : NSObject

/// 部门信息
@property (nonatomic,strong) tagDeptInfoObj *deptInfo;

/// 子部门列表
@property (nonatomic,strong) NSMutableArray <DeptNodeViewModel *>* children;

/// 部门人员(当前部门)
@property (nonatomic,strong) NSMutableArray <OnlineUserViewModel *>* userList;

/// 该部门是否被选中
@property (nonatomic,assign) BOOL isSelected;

/// (当前部门+子部门)总人数
@property (nonatomic,strong,nullable) NSMutableArray <OnlineUserViewModel*>* deptAllUserList;

/// (当前部门+子部门)是否全部选中
- (BOOL)isAllUserSelected;

- (void)changeSubDeptSelectStatus:(BOOL)status;

- (instancetype)initWithDepthNodeInfo:(tagDeptNodeObj *)deptNodeInfo DeptUserDict:(NSDictionary <NSNumber *,NSMutableArray <OnlineUserViewModel *>*>*)deptUserDict;

/// 根据排序
+ (NSMutableArray <DeptNodeViewModel *>*)sortedByDeptName:(NSMutableArray <DeptNodeViewModel *>*)children;

- (void)updateWithData:(DeptNodeViewModel *)deptNodeViewModel;
@end

@interface ShareAppMsgDataObj : NSObject

@property (nonatomic, assign) int status;
@property (nonatomic, assign) int desktopWidth;
@property (nonatomic, assign) int desktopHeight;
@property (nonatomic, assign) int mobileHeight;
@property (nonatomic, assign) int mobileWidth;
@property (nonatomic, strong) NSMutableString* srcUserID;
// 接受者用户ID,0表示所有人
@property (nonatomic, strong) NSMutableString* dstUserID;
@property (nonatomic, strong) NSMutableString* url;
@property (nonatomic, strong) NSMutableString* appID;

@end
#endif /* SDKDataType_h */
