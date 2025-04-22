//
//  IMeetingManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/26.
//

#import "BaseManager.h"


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AVPermissionResult) {
    AV_DISABLE = 0,    //禁用
    AV_ENABLE = 1,     //可用
    AV_APPLY = 2       //需申请
};
@class LayoutEvent;
@class MeetingRoomInfo;
@interface IMeetingManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<IMeetingManagerDelegate>) listener;
/**
 * 获取会议名称
 *
 * @return NSString     返回会议室名称
 */
-(NSString *)getCurrentRoomName;

/**
 * 获取会议信息
 *
 * @return MeetingRoomInfo     返回会议信息对象
 */
-(MeetingRoomInfo *)getMeeetingRoomInfo;

/**
 * 广播自己的布局
 *
 * @param layoutEvent   布局信息对象
 * @return ReturnCode      返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)broadcastLayout:(LayoutEvent*)layoutEvent;
/**
 * 关闭会议
 *
 * @return ReturnCode         返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)closeMeeting;

@end

NS_ASSUME_NONNULL_END
