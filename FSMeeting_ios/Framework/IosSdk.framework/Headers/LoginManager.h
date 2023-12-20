//
//  LoginManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/26.
//

#import "BaseManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface LoginManager : BaseManager

//是否是邀请入会
@property (nonatomic, assign) BOOL isInviteJoin;

/// 会议室密码，用于账号登录入会
@property (nonatomic, copy) NSString *roomPwd;

//是否是登录后入会
@property (nonatomic, assign) BOOL isLoginedJoin;
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<LoginManageDelegate>) listener;
/**
 * 会议室号登录
 *
 * @param roomId                会议号
 * @param roomPwd              会议密码
 * @param nickName            用户昵称
 * @return ReturnCode        返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)loginRoomId:(NSString*)roomId pwd:(NSString*)roomPwd nickName:(NSString*)nickName;

/**
 * 会议室号登录
 *
 * @param account              用户名
 * @param usrPwd                用户密码
 * @param rid                       会议室号
 * @return ReturnCode        返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)loginAccount:(NSString*)account pwd:(NSString*)usrPwd roomId:(NSString*)rid;

/**
 * 退出登录
 *
 * @return ReturnCode        返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)logout;

/**
 * 获取账号登录后的昵称
 *
 * @return 登录后的昵称
 */
-(NSString *)getLoginUserNickName;

/**
 * 是否是正在登录中
 *
 * @return YES 正在登录  NO 不是正在登录
 */
-(BOOL)isInLoging;
@end

NS_ASSUME_NONNULL_END
