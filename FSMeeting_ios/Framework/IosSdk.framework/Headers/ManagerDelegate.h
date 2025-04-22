//
//  ManagerDelegate.h
//  IosSdk
//
//  Created by hst on 2022/8/25.
//

#import <Foundation/Foundation.h>
#import <IosSdk/SDKDataType.h>
#import <IosSdk/BaseUserInfo.h>>

typedef enum{
    RegisteredUserLogin,  //注册用户登录   （用户名密码登录）
    UnRegisteredUserLogin  //非注册用户登录（会议室号登录）
}LoginType;

typedef NS_ENUM(NSInteger, kUserPermissionType) {
    //-----查询权限-----
    kUserPermissionTypeAudioEnable,              //拥有音频功能
    kUserPermissionTypeBroadCastOwnAudio,        //广播自己的音频权限
    kUserPermissionTypeStopBroadCastOwnAudio,    //关闭自己的音频权限
    kUserPermissionTypeBroadCastOthersAudio,     //广播他人的音频权限
    kUserPermissionTypeStopBroadCastOthersAudio, //关闭他人的音频权限
    kUserPermissionTypeBroadcastSpecifiedOtherAudio, //广播他人音频,需要判断otherUser是否有被广播的权限
    
    kUserPermissionTypeVideoEnable,              //拥有视频功能
    kUserPermissionTypeBroadCastOwnVideo,        //广播自己的视频权限
    kUserPermissionTypeStopBroadCastOwnVideo,    //关闭自己的视频权限
    kUserPermissionTypeBroadCastOthersVideo,     //广播他人的视频权限
    kUserPermissionTypeStopBroadCastOthersVideo, //关闭他人的视频权限
    kUserPermissionTypeBroadcastSpecifiedOtherVideo, //广播他人音频,需要判断otherUser是否有被广播的权限
    
    kUserPermissionTypePublicChat,               //群聊权限
    
    kUserPermissionTypeCloseMeeting,             //关闭会议室权限
    kUserPermissionTypeApplyAdmin,               //申请成为管理员权限
    
    kUserPermissionTypeViewUserInfo,             //显示自己的“查看个人信息”选项的权限
    kUserPermissionTypeModifyUserInfo,           //显示自己的“修改个人信息”选项的权限
    kUserPermissionTypeModifyOtherUserInfo,      //显示他人的“修改个人信息”选项的权限
    kUserPermissionTypeDisableModifySelfUserInfo,//禁止修改自己的信息的权限
    
    kUserPermissionTypeApplyPresenter,           //申请成为/放弃主讲人的权限
    kUserPermissionTypeKickUser,                 //踢人出会议室的权限
    kUserPermissionTypeBroadcastLayout,          //用户是否有同步布局权限
    
    kUserPermissionTypeConfigOtherPresenter,     //授予/审批他人成为主讲人
    
    kUserPermissionTypeCreateMeetingMute,        //全场静音权限
    
    kUserPermissionTypeWhiteBoardSave,           //保存白板权限
    kUserPermissionTypeWhiteBoardShare,           //白板共享权限
};

typedef NS_ENUM(NSInteger, kRoomPermissionType) {
    kRoomPermissionTypeRoomEnablePublicChat     //房间群里权限
};

typedef NS_ENUM(NSInteger, kUserGroupPermissionType) {
    kUserGroupPermissionTypeInvitation,    //允许[角色]拥有电话邀请功能+允许[角色]拥有在线邀请功能
    kUserGroupPermissionTypeChat,
    kUserGroupPermissionTypeUpdateWBAccessMode,
    kUserGroupPermissionTypeShareCloseOther,
    kUserGroupPermissionTypeShareDocumentPage,
    kUserGroupPermissionTypeShareSaveWhiteBoard,
    kUserGroupPermissionTypeShareMarkWhiteBoard,
    kUserGroupPermissionTypeMeetingServerRecord,
    kUserGroupPermissionTypeParticipantEnable,
    kUserGroupPermissionTypeShareToolBar,
    kUserGroupPermissionTypeAudio,
    kUserGroupPermissionTypeOwnApplyAudio,
    kUserGroupPermissionTypeVideo,
    kUserGroupPermissionTypeMainVCShare,
    kUserGroupPermissionTypeShareTool,
    kUserGroupShareMarkWhiteBoard    // 共享标注白板权限通知名称数组
};

/// 弹框类型
typedef NS_ENUM(NSUInteger, WhiteBoardMessageType) {
    WhiteBoardMessageTypeMessageBox = 0,     // dialog
    WhiteBoardMessageTypeMessageTips,        // tips
    WhiteBoardMessageTypeMessageHUD          // toast
};

typedef NS_ENUM(NSUInteger, WBErrorCodeType) {
    WBErrorCodeTypeFirstPage = 0,     // 已到第一页
    WBErrorCodeTypeLastPage,        // 已到最后一页
    WBErrorCodeTypeNotSuportPPT,    // 暂时不支持PPT动画电子白板
    WBErrorCodeTypeNotShareCanNotMark, //当前未共享白板或文档，标注功能不可用
    WBErrorCodeTypeNotRightContractAdmin, //您没有操作权限，请联系管理员
    WBErrorCodeTypeUserNotRight, //用户无权限
    WBErrorCodeTypeUploadDocErr, //上传文档时发生错误
    WBErrorCodeTypeDocPicTypeNotSupport,//主持人使用的文档转换格式不是图片格式，手机上无法显示
    WBErrorCodeTypeDownloadDocErr,//下载文档时发生错误
};

@class ChatMessageInfo;
@class TagRoomInfoObj;
@class LayoutEvent;
@class DataBlockObj;
@class tagDeptListObj;
@class InviteDataObj;
@class OnlineUserViewModel;

#ifndef ManagerDelegate_h
#define ManagerDelegate_h

@protocol SdkManagerDelegate <NSObject>

/// 设置服务器信息后的结果
/// @param isSuccess 是否设置成功
- (void)onSetServerResult:(BOOL)isSuccess;
/// 接收到其他人呼叫入会的回调
/// @param userID 呼叫人的userID
/// @param inviteId 呼叫ID
/// @param obj 呼叫的信息
- (void)onInviteIncome:(NSInteger)userID withinviteId:(NSInteger)inviteId withInviteDataObj:(InviteDataObj *)obj;

/// 拒接邀请后的回调
/// @param userID 拒接的成员ID
- (void)OnAbandonInvite:(NSInteger)userID;

@end

@protocol LoginManageDelegate <NSObject>

/// 登录、入会结果的回调
/// @param code 登录结果的错误码
/// @param message 登录结果的错误信息
/// @param type 登录的类型
- (void)onUserloginEventCallback:(ReturnCode)code withErrorMessage:(NSString *)message withLoginType:(LoginType)type;

@end

@protocol IMeetingManagerDelegate <NSObject>

///结束会议的回调
- (void)onEndMeeting;

/// Session重连状态的回调
/// @param state 重连状态
- (void)onSessionReconnect:(ReconnectState)state;

/// 同步布局
/// @param event  同步的布局信息
- (void)onRemoteLayout:(LayoutEvent *)event;

/// 同步会中WebApp
- (void)OnShareAppMsg:(ShareAppMsgDataObj*)dataObj;
@end

@protocol AudioManagerDelegate <NSObject>

/// 音频发生改变的回调
/// @param userID 发生改变的用户ID
- (void)onUserAudioStateChange:(NSInteger)userID withMediaID:(NSInteger) mediaID withAudioState:(AudioState)state;

@end

@protocol VideoManagerDelegate <NSObject>

/// 参会人视频状态改变的回调
/// @param userID 发生改变的参会人的用户ID
/// @param videoID 发生改变的视频ID
/// @param state 改变后的状态
- (void)onUserVideoStateChange:(NSInteger)userID withVideoID:(NSInteger)videoID withVideoState:(VideoState)state;

@end

@protocol ChatManagerDelegte <NSObject>

/// 接收到的聊天信息
/// @param info 聊天信息
- (void)onReceiveChatMessage:(ChatMessageInfo *)info;

@end

@protocol ScreenShareManagerDelegate <NSObject>

/// 共享屏幕状态发生改变
/// @param state 状态
/// @param userID 发生改变的参会人id
- (void)onScreenShareState:(ScreenShareState)state withUserID:(NSInteger)userID;

@end

@protocol IUserManagerDelegate <NSObject>

/// 参会人申请管理
/// @param code 申请返回的结果
- (void)onUserApplyManager:(ReturnCode)code;

/// 用户上线的回调
/// @param userInfo  上线参会人的信息
- (void)onUserOnline:(BaseUserInfo *)userInfo;

/// 用户进入会议室的回调
/// @param userInfo  进入会议室参会人的信息
- (void)onUserEnter:(BaseUserInfo *)userInfo;

/// 用户离开会议室
/// @param userID  离开参会人的用户ID
/// @param userInfo  离开参会人的用户信息
- (void)onUserLeave:(NSInteger)userID withUserInfo:(BaseUserInfo *)userInfo;

/// 用户信息更改
/// @param userInfo  被更改信息的参会人
- (void)onUserInfoUpdate:(BaseUserInfo *)userInfo;

/// 用户权限更改
/// @param userInfo 被修改权限的用户
- (void)onUserRightChanged:(NSInteger)userID;

/// 用户是否是主持人的状态更改
/// @param userID  被修改用户信息的用户ID
/// @param state 用户的状态
- (void)onUserDataStateChange:(NSInteger)userID withUserState:(UserState)state;

/// 被请出会议室
/// @param userInfo  被剔除参会人的信息
- (void)onUserKicked:(BaseUserInfo *)userInfo;

- (void)onUserAVInfoState:(NSInteger)userID;
@end

@protocol PermissionManagerDelegate <NSObject>

/// 成员组权限发生改变的回调
/// @param type 改变的权限类型
- (void)onUserGroupPermissionChanged:(kUserGroupPermissionType)type;

/// 会议室权限发生改变的回调
/// @param type 改变权限的类型
- (void)onRoomPermissionChanged:(kRoomPermissionType)type;

/// 参会人权限改变的回调
/// @param type 改变的权限类型
/// @param userID 改变权限参会人的ID
- (void)onUserPermissionChanged:(kUserPermissionType)type withUserID:(NSInteger)userID;

@end

@protocol WhiteBoardManagerDelegate <NSObject>

- (void)OnInitWB:(NSInteger)wbID withUserID:(NSInteger)wbUserId withDataBlack:(DataBlockObj *)datablock;

/// 接收共享白板时的错误
/// @param message 错误信息
/// @param type 错误类型
/// @param msgType 错误信息展示的方式
- (void)onReceiveWhiteBoardErrorMessage:(NSString *)message withCodeType:(WBErrorCodeType)type withMessageType:(WhiteBoardMessageType)msgType;

///白板数量改变
- (void)onWhiteBoardCountChange;

///放弃主持人并且无权限关闭自己创建的共享
- (void)onDataBlockCountOrThumingChange;

/// 被PC取消权限时需要关闭权限
- (void)onCancleWBRight;

/// 刷新当前活跃的白板
/// @param dataID 要刷新白板的ID
- (void)onRefreshWBViewByActiveWB:(NSInteger)dataID;

/// 移除单个的白板
/// @param dataID 要移除白板的ID
- (void)onRemoveSingleWBView:(NSInteger)dataID;

/// 刷新白板的标签昵称
/// @param title 刷新后的标签
- (void)onUpdateWBTitle:(NSString *)title;
@end

@protocol RoomListManagerDelegate <NSObject>
@optional
/// 查询云会议室的结果
/// @param isSuccess 是否查询成功
/// @param meetingList 查询到的会议列表
/// @param isLoadCloudMeetingAll 是否查询完毕
/// @param msg 查询失败后的错误信息
- (void)onQueryCommonMeeting:(BOOL)isSuccess withMeetingList:(NSArray <TagRoomInfoObj *> *)meetingList isLoadCloudMeetingAll:(BOOL)isLoadCloudMeetingAll witherrMessage:(NSString *)msg;

/// 查询预约会议室的结果
/// @param isSuccess 是否查询成功
/// @param meetingList 查询到的会议列表
/// @param isLoadSchedulMeetingAll 是否查询完毕
/// @param msg 查询失败后的错误信息
- (void)onQuerySchedulMeeting:(BOOL)isSuccess withMeetingList:(NSArray <tagScheduleInfoObj *> *)meetingList isLoadSchedulMeetingAll:(BOOL)isLoadSchedulMeetingAll witherrMessage:(NSString *)msg;

/// 查询即时会议的结果
/// @param meetingList 即时会议列表
/// @param isLoadInstantMeetingAll 是否查询完毕
- (void)onQueryInstantMeeting:(NSArray <tagInstantRoomInfoObj *> *)meetingList isLoadInstantMeetingAll:(BOOL)isLoadInstantMeetingAll;

/// 创建即时会议的结果
/// @param isSuccess 是否创建成功
/// @param code 创建失败的错误信息
/// @param roomInfo 创建完成的会议室
- (void)onCreateInstantMeeting:(BOOL)isSuccess withErrCode:(NSInteger)code withTagRoomInfoObj:(TagRoomInfoObj *)roomInfo;
@end

@protocol ContactManagerDelegate <NSObject>

/// 获取组织架构的回调
/// @param obj 组织架构列表信息
- (void)onQueryDept:(tagDeptListObj *)obj;

/// 获取某个组织下的所有人员和子组织信息列表
/// @param userList 组织下所有成员
/// @param children 子组织列表
/// @param allUserList 所有用户
- (void)onQueryDeptUser:(NSMutableArray <tagOnlineUserInfoObj *> *)userList withChildren:(NSMutableArray <DeptNodeViewModel *> *)children withAllUserList:(NSMutableArray <OnlineUserViewModel *> *)allUserList;

/// 成员在线状态改变的回调
/// @param model 改变的成员model
- (void)OnUserOnlineStateChange:(OnlineUserViewModel *)model;

@end
#endif /* ManagerDelegate_h */
