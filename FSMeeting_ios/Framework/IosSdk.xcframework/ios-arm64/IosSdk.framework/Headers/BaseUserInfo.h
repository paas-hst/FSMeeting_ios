//
//  BaseUserInfo.h
//  FSMeetingClient
//
//  Created by 钟勇 on 2018/8/23.
//

#import <Foundation/Foundation.h>

typedef enum {
    SCREEN_SHARE_STATE_NONE,  //音频 关闭状态
    SCREEN_SHARE_STATE_WAITTING, //申请发言中
    SCREEN_SHARE_STATE_DONE // 正在广播音频
}ScreenShareState;

typedef enum {
    AUDIO_STATE_NONE,  //音频 关闭状态
    AUDIO_STATE_WAITTING, //申请发言中
    AUDIO_STATE_DONE // 正在广播音频
}AudioState;

typedef enum {
    VIDEO_STATE_NONE,  //视频 关闭状态
    VIDEO_STATE_WAITTING, //正在申请广播中
    VIDEO_STATE_DONE // 正在广播视频
}VideoState;

typedef enum {
    VNC_STATE_NONE,  //屏幕共享关闭状态
    VNC_STATE_WAITTING, //屏幕共享申请中
    VNC_STATE_DONE // 屏幕共享正在共享
}UserVncState;

typedef enum {
    USER_STATE_NONE,  //参会人
    USER_STATE_WAITTING, //正在申主讲
    USER_STATE_DONE // 主讲
}UserState;

typedef enum {
    DESKTOP_CLIENT_INFO = 1,    // 桌面终端（win mac）
    DESKTOP_WIN = 21,    // 桌面终端（win）
    DESKTOP_MAC = 31,    // 桌面终端（mac）

    HARDWARE_CLIENT = 2,    // 硬件终端（x3 v5 ...)
    HARDWARE_X = 12,    // 硬件终端（x3 x...)
    HARDWARE_V = 22,    // 硬件终端（v5 v...)
    HARDWARE_X5 = 32,    // 硬件终端 x5 x
    HARDWARE_A3 = 42,    // 硬件终端 A3

    MOBILE_CLIENT = 3,    // 移动终端（ios android app tv a2 ...)
    MOBILE_IOS = 13,    // 移动终端（ios)
    MOBILE_ANDROID = 23,    // 移动终端（android app)
    MOBILE_ANDROID_TV = 33,    // 移动终端（android tv)
    MOBILE_ANDROID_MB = 43,    // 移动终端（android meetingbox)
    MOBILE_ANDROID_D1 = 53, // 移动终端（android d1)

    TELEPHONE_CLIENT = 4,    // 电话终端（呼入/呼出）
    H323_CLIENT = 14,   // H323网关终端

    VIRTUAL_RECORD = 5,    // 录制终端（录制服务器）
    VIRTUAL_H323 = 15,    // H323网关终端

    VIRTUAL_HH = 6,    // 虚拟终端（HardWareHelper硬件PC连接助手）不在用户列表显示
    VIRTUAL_SHARESCREEN = 16,    // 投屏用户,不在用户列表显示
    WEB_CTRL_PROXY = 26,   // 会控 不在用户列表显示
}SDKTERMINALTYPE;


@interface VideoChannelInfo : NSObject
@property (nonatomic, assign) int nCapDevIndex;
@property (nonatomic, assign) int nOperation;
@property (nonatomic, assign) NSUInteger bID;
@property (nonatomic, assign) VideoState bState;
@property (nonatomic, assign) BOOL bHasVideo;
@property (nonatomic, assign) BOOL bRecvVideo;
@property (nonatomic, strong) NSMutableString* strVideoName;
@end

@interface BaseUserInfo : NSObject

//初始化
+ (instancetype)baseUserWithUserInfo:(id)userInfo;

//用户id
-(unsigned long)userId;

//用户名
-(NSString*)userName;

//用户昵称
-(NSString*)nickName;

// 获取用户视频列表
- (NSDictionary *)videoChannelMap;

- (NSArray<VideoChannelInfo*>*)getVideoChannelInfos;

//dev id
- (int) nDefVideoDevID;

//音频SourceID
-(unsigned long) audioSourceID;

//音频状态
-(AudioState) audioState;

//音频id
-(unsigned int) audioId;

// 判断用户是否是参会人
- (BOOL)isListener;

// 判断用户是否是主席
- (BOOL)isChair;

// 判断用户是否是主持人
- (BOOL)isHost;

//是否正在申请主持人中
- (BOOL)isApplyingHost;

// 判断是否是本地用户
- (BOOL)isLocalUser;

// 判断用户是否打开视频
- (BOOL)isVideoOpen;

//是否正在申请广播视频
- (BOOL)isVideoStateWaiting;

/// 获取视频广播状态
- (VideoState)videoState;

//获取主讲状态
-(UserState)userDataState;

///是否是管理员
-(BOOL)isManager;

//本地录制开启状态<!--用户录制状态 0 未录制  1 录制中-->
-(unsigned char)localRecordState;

//终端类型
-(SDKTERMINALTYPE)terminaltype;

// 判断用户是否有麦克风权限
-(BOOL)isHaveMicrophone;

// 判断用户是否有摄像头权限
-(BOOL)isHaveCamera;
//获取屏幕共享状态
-(UserVncState)userVncState;
@end
