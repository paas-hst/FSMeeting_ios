//
//  PermissionManager.h
//  IosSdk
//
//  Created by Tiger on 2021/8/13.
//

#import "BaseManager.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, kUserPermissionResult) {
    PER_DISABLE = 0,    //无权限
    PER_ENABLE = 1,     //有权限
    PER_APPLY = 2       //需申请
};

@interface PermissionManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<PermissionManagerDelegate>) listener;
/**
 * 查询用户权限
 *
 * @param permissonType    查询的权限类型
 * @param dwUserID    用户ID
 * @return BOOL     YES - 有权限，NO - 无权限
 */
-(kUserPermissionResult)checkPemission:(kUserPermissionType)permissonType dwUserID:(NSUInteger) dwUserID;


/**
 * 设置用户权限
 *
 * @param permissonType    设置的权限类型
 * @param dwUserID    用户ID
 * @return ReturnCode     返回错误码，详情请查看ReturnCode的定义
 */
-(ReturnCode)configPemission:(kUserPermissionType)permissonType dwUserID:(NSUInteger) dwUserID;
@end

NS_ASSUME_NONNULL_END
