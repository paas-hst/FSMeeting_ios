//
//  IUserManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/26.
//

#import "BaseManager.h"
#import "BaseUserInfo.h"
//#import "EventListenerDelegate.h"
//#import "BaseEvent.h"
#import "BaseUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface IUserManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<IUserManagerDelegate>) listener;
/**
 * 添加事件回调监听者
 *
 * @return NSArray<BaseUserInfo*>     返回所有用户信息的数组
 */
-(NSArray<BaseUserInfo*>*)getAllUsers;

/**
 * 获取本地用户信息
 *
 * @return BaseUserInfo     返回本地用户信息对象
 */
-(BaseUserInfo*)getLocalUser;

/**
 * 授予主持人
 *
 * @param userInfo         被授权用户信息
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)grantBeHostForRemoteUser:(BaseUserInfo *)userInfo;

/**
 * 申请/取消主持人
 *
 * @param apply                 YES-申请，NO-取消
 * @param userInfo           申请用户信息
 * @return ReturnCode       返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)applyToBeHost:(BOOL) apply withUser:(BaseUserInfo *)userInfo;

/**
 * 放弃主持人
 *
 * @param userInfo           放弃用户信息
 * @return ReturnCode       返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)abandonTheHost:(BaseUserInfo *)userInfo;

/**
 * 更新用户昵称
 *
 * @param userInfo           用户信息
 * @param nickName           用户昵称
 * @return ReturnCode       返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)modifyUserNickname:(BaseUserInfo *)userInfo nickName:(NSString *)nickName;

/**
 * 根据用户ID查询用户信息
 *
 * @param userID                用户ID
 * @return BaseUserInfo      返回用户信息对象
 */
-(BaseUserInfo *)getUserInfo:(NSUInteger)userID;

/**
 * 会中踢出用户
 *
 * @param  userId                操作用户ID
 * @param  kickedUserId   被踢用户ID
 * @return ReturnCode         返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)kickUser:(NSInteger)userId kickedUserId:(NSInteger)kickedUserId;

/**
 * 获取会议室当前主持人
 *
 * @return BaseUserInfo      返回当前主持人用户信息对象
 */
- (BaseUserInfo*)getCurrentHost;

/**
 * 放弃管理员
 *
 * @param  userID                用户ID
 * @return ReturnCode         返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)abandonTheManager:(NSUInteger)userID;

/**
 * 请求管理员权限
 *
 * @param  hostPwd             主席密码
 * @return ReturnCode         返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)applyToBeManager:(NSString *)hostPwd;

/**
 * 判断会中是否有视频
 *
 * @return BOOL   YES-有 ， NO-无
 */
- (BOOL)getLocalVideoState;

/**
 * 判断会中是否支持线上邀请
 *
 * @return BOOL   YES-有 ， NO-无
 */
- (BOOL)isSupportOnlineInvite;
@end

NS_ASSUME_NONNULL_END
