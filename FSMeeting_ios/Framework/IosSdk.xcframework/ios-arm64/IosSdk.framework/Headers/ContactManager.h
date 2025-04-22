//
//  ContactManager.h
//  IosSdk
//
//  Created by whyf on 2022/5/30.
//

#import "BaseManager.h"
#import "BaseUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@class InviteDataObj;
@class OnlineUserViewModel;

@interface ContactManager : BaseManager

@property (nonatomic, weak)id <ContactManagerDelegate>delegate;
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<ContactManagerDelegate>) listener;
/**
 * 是否支持邀请功能
 *
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(BOOL)isSupportInvite;

/**
 * 查询企业组织架构
 *
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)queryDeptInfo;

/**
 * 查询部门所有用户
 *
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)queryDeptUser:(NSInteger)deptID;

/**
 * 邀请用户
 *
 * @param userIdList   用户ID列表
 * @param inviteDataObj   邀请数据
 * @return BOOL    YES - 成功  NO - 失败
 */
-(BOOL)inviteUsers:(NSMutableArray <NSNumber *>*)userIdList inviteData:(InviteDataObj *)inviteDataObj;

/**
 * 接受/拒绝邀请
 *
 * @param inviterUserId   邀请人用户ID
 * @param inviteId   邀请ID
 * @param isAccept   YES - 接受 NO - 拒绝
 * @return BOOL    YES - 成功  NO - 失败
 */
-(BOOL)acceptRejectInvite:(NSUInteger)inviterUserId inviteId:(NSUInteger)inviteId isAccept:(BOOL)isAccept;

/**
 * 查询用户状态
 *
 * @param userList   用户ID列表
 * @return 无    YES - 成功  NO - 失败
 */
- (ReturnCode)queryOnlineStatusWithUserList:(NSArray <NSNumber *>*)userList;

/**
 * 根据昵称搜索用户
 *
 * @param nickName   用户昵称
 * @return NSArray<OnlineUserViewModel *>    返回用户列表
 */
-(NSArray<OnlineUserViewModel *>*)searchUserWithNickName:(NSString *)nickName;

/**
 * 根据昵称搜索用户
 *
 * @param userID   用户ID
 * @return BOOL    YES - 成功  NO - 失败
 */
-(BOOL)getOnlineDeviceInfo:(NSInteger)userID;
@end

NS_ASSUME_NONNULL_END
