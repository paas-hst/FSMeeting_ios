//
//  SdkManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/24.
//

#import <Foundation/Foundation.h>
#import "BaseManager.h"
#import "IUserManager.h"
#import "LoginManager.h"
#import "IMeetingManager.h"
#import "ChatManager.h"
#import "VideoManager.h"
#import "AudioManager.h"
#import "ScreenShareManager.h"
#import "PermissionManager.h"
#import "WhiteBoardManager.h"
#import "RoomListManager.h"
#import "ContactManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface SdkManager : BaseManager
///代理
@property (nonatomic, weak)id<SdkManagerDelegate>delegate;
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<SdkManagerDelegate>) listener;

/**
 * 获取屏幕共享单列
 *
 * @return instancetype     sdk管理单列对象
 */
+ (instancetype)shareInstance;

/**
 * 初始化SDK
 *
 * @return void     无返回值
 */
-(void)initSdk;

/**
 * 释放SDK
 *
 * @return void     无返回值
 */
-(void)releaseSdk;

/**
 * 获取用户管理单列
 *
 * @return IUserManager     用户管理单列对象
 */
-(IUserManager*)getUserManager;

/**
 * 获取登录管理单列
 *
 * @return LoginManager     登录管理单列对象
 */
-(LoginManager*)getLoginManager;

/**
 * 获取会议管理单列
 *
 * @return IMeetingManager     会议管理单列对象
 */
-(IMeetingManager*)getMeetingManager;

/**
 * 获取聊天管理单列
 *
 * @return ChatManager     聊天管理单列对象
 */
-(ChatManager*)getChatManager;

/**
 * 获取视频管理单列
 *
 * @return VideoManager     视频管理单列对象
 */
-(VideoManager*)getVideoManager;

/**
 * 获取音频管理单列
 *
 * @return AudioManager     音频管理单列对象
 */
-(AudioManager*)getAudioManager;

/**
 * 获取屏幕共享单列
 *
 * @return ScreenShareManager     屏幕共享管理单列对象
 */
-(ScreenShareManager*)getScreenShareManager;

/**
 * 获取权限管理单列
 *
 * @return PermissionManager     权限管理单列对象
 */
-(PermissionManager*)getPermissionManager;

/**
 * 获取白板管理单列
 *
 * @return whiteBoardManager     白板管理单列对象
 */
-(WhiteBoardManager*)getWhiteBoardManager;

/**
 * 获取会议列表单列
 *
 * @return RoomListManager     会议列表单列对象
 */
-(RoomListManager*)getRoomListManager;

/**
 * 获取通讯录管理对象
 *
 * @return ContactManager     邀请通讯录对象
 */
-(ContactManager*)getContactManager;

/**
 * 设置ClientId和secret
 *
 * @param clientId     客户端Id
 * @param secret         秘钥
 * @return void             无返回值
 */
-(void)setClientIdInfo:(NSString*)clientId secret:(NSString*)clientSecret;

/**
 * 设置服务器
 *
 * @param host     域名或者ip地址，如果为null则重置为公有云
 * @param port     端口 0-65535
 * @return void     无返回值
 */
-(void)setServer:(NSString *)host port:(NSString *)port;

/**
 * 开始会议，即调用此方法后开始接收服务器消息
 *
 * @return void     无返回值
 */
-(void)startMeetingRoom;

/**
 * 退出会议，即调用此方法后停止接收服务器消息
 *
 * @return void     无返回值
 */
-(void)exitMeeting;

/**
 * 获取SDK版本号
 *
 * @return NSString     sdk版本号(V3.36.10.32)
 */
-(NSString*)getSdkVersion;

/**
 * App 进入到后台运行
 *
 * @return void     无返回值
 */
- (void)applicationDidEnterBackground;

/**
 * App 由后台进入前台运行
 *
 * @return void    无返回值
 */
- (void)applicationWillEnterForeground;

/**
 * App 进程结束
 *
 * @return void    无返回值
 */
- (void)applicationWillTerminate;
@end

NS_ASSUME_NONNULL_END
