//
//  FSMeeting.h
//  FSMeeting
//
//  Created by whyf on 2021/11/4.
//

#import <UIKit/UIKit.h>
#import <IosSdk/IosSdk.h>

//! Project version number for FSMeeting.
FOUNDATION_EXPORT double FSMeetingVersionNumber;

//! Project version string for FSMeeting.
FOUNDATION_EXPORT const unsigned char FSMeetingVersionString[];

typedef enum : NSUInteger {
    /// 会议模式
    FSMeetingSceneTypeMeeting,
    /// 1对1纯音频模式
    FSMeetingSceneTypePureAudio,
    /// 1对多音视频模式
    FSMeetingSceneTypeAudioVideo,
} FSMeetingSceneType;

typedef enum : NSUInteger {
    /// 登录开始
    FSMeetingLoginTypeStart,
    /// 登录失败
    FSMeetingLoginTypeFail,
    /// 登录完成
    FSMeetingLoginTypeCompleted,
} FSMeetingLoginType;

typedef enum : NSUInteger {
    /// 等待超时
    FSMeetingLogoutTypeTimeout,
    /// 对方挂断
    FSMeetingLogoutTypeRemoteHangup,
    /// 通话结束
    FSMeetingLogoutTypeCallEnded,
    /// 本地挂断
    FSMeetingLogoutTypeLocalHangup,
    /// 网络异常
    FSMeetingLogoutTypeNetworkException,
    /// 被请出会议室
    FSMeetingLogoutTypeKickedOut,
    /// 会议结束
    FSMeetingLogoutTypeMeetingEnded,
    /// 使用接口退会
    FSMeetingLogoutTypeAPI,
} FSMeetingLogoutType;

@interface EnterMeetingBaseParam : NSObject

/// 入会后自动打开麦克风
@property (nonatomic, assign) BOOL microphoneEnabled;
/// 入会后自动打开摄像头
@property (nonatomic, assign) BOOL cameraEnabled;
/// 是否禁用挂断按钮
@property (nonatomic, assign) BOOL hangupButtonDisabled;
/// 是否禁用麦克风按钮
@property (nonatomic, assign) BOOL microphoneButtonDisabled;
/// 是否禁用摄像头按钮
@property (nonatomic, assign) BOOL cameraButtonDisabled;
/// 其他人员未入会前是否播放铃声，默认不播放
@property (nonatomic, assign) BOOL ringEnabled;
/// 30秒无人入会,则自动退会
@property (nonatomic, assign) BOOL timeoutEnabled;
/// 是否主动呼叫
@property (nonatomic, assign) BOOL calling;
/// 会议室ID
@property (nonatomic, copy) NSString *roomid;
/// 宿主UIViewController
@property (nonatomic, strong) UIViewController *fatherVc;
/// 0:扬声器[默认扬声器]   1:听筒
@property (nonatomic, assign) NSInteger audioMode;
/// 默认图片Url
@property (nonatomic, copy) NSString *imgUrl;
/// 被呼叫用户昵称
@property (nonatomic, copy) NSString *calledUserName;
@end

@interface EnterMeetingWithRoomidParam : EnterMeetingBaseParam

/// 会议室密码 ，若有则可填入
@property (nonatomic, copy) NSString *rpwd;
/// 昵称 可随意填，但不能为空 进入会议室后将显示
@property (nonatomic, strong) NSString *nickName;

@end

@interface EnterMeetingWithUserNameParam : EnterMeetingBaseParam

/// 会议室用户名
@property (nonatomic, copy) NSString *userName;
/// 密码
@property (nonatomic, copy) NSString *pwd;

@end

// In this header, you should import all the public headers of your framework using statements like #import <FSMeeting/PublicHeader.h>

@interface FSMeeting : NSObject

/// 单例初始化
+ (instancetype)shared;

/// 打印sdk 版本号 相关信息
- (void)printVersion;

/* 设置配置信息
 @param clientId      clientID
 @param clientSecret    secret
 @param fatherVc 宿主UIViewController
 @param ip      会议服务器ip
 @param port    会议服务端口
 @param fatherVc 宿主UIViewController
 @param isShowHud 是否显示loading
 */
-(void)setClientInfo:(NSString *)clientId secret:(NSString*)secret serverip:(NSString *)ip serverport:(NSString *)port viewCtrl:(UIViewController*)fatherVc isShowHud:(BOOL)isShowHud result:(void(^)(BOOL isSuccess)) result;

/* 通过RoomID 直接进入会议室
 @param roomid 会议室ID
 @param rpwd   会议室密码 ，若有则可填入
 @param nick   昵称 可随意填，但不能为空 进入会议室后将显示
 @param fatherVc 宿主UIViewController
 @param loginBlock 登录代码块
 @param logoutBlock 退会代码块
 @return void
 */
-(void)enterMeetingWithRoomIDParam:(EnterMeetingWithRoomidParam *)param loginBlock:(void(^)(FSMeetingLoginType type, ReturnCode code))loginBlock logoutBlock:(void(^)(FSMeetingLogoutType type))logoutBlock;

/* 直接进入视频会议界面,或者会议室列表界面
 @param usrname 会议室用户名
 @param pwd     密码
 @param rid     会议室号
 @param fatherVc 宿主UIViewController
 @param loginBlock 登录代码块
 @param logoutBlock 退会代码块
 @return void
 */
-(void)enterMeetingWithUserNameParam:(EnterMeetingWithUserNameParam *)param loginBlock:(void(^)(FSMeetingLoginType type, ReturnCode code))loginBlock logoutBlock:(void(^)(FSMeetingLogoutType type))logoutBlock;

/// 是否处于会议室中
-(BOOL)isFSMeetingActive;

/// 是否已最小化
- (BOOL)isFSMeetingMinimize;

/// 是否设置了IP，端口，clientID,secret
-(BOOL)hadSuccessConfigSdkInfo;

/// 设置会议室场景
/// - Parameter type: 纯音频/音视频/会议
- (void)setMeetingScene:(FSMeetingSceneType)type;

/// 设置窗口最小最小化回调
/// - Parameter minimizeBlock: 最小化回调
- (void)setMinimizeBlock:(void(^)(FSMeetingSceneType))minimizeBlock;

/// 设置挂断回调
/// - Parameter hangupBlock: 挂断回调
- (void)setHangupBlock:(void(^)(FSMeetingSceneType))hangupBlock;

/// 设置窗口最大化
- (void)maximizeWindow;

/// 退出会议室
- (void)exitMeetingRoom;

/* SDK 相关代理
 @return void
 */
- (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions  DEPRECATED_MSG_ATTRIBUTE("将在下个版本被取消");
- (void)applicationWillResignActive:(UIApplication *)application;
- (void)applicationDidEnterBackground:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application;
- (void)applicationWillTerminate:(UIApplication *)application;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (NSUInteger)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window ;

@end
