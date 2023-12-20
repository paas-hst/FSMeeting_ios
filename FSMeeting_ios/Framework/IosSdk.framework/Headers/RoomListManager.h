//
//  RoomListManager.h
//  IosSdk
//
//  Created by whyf on 2022/1/7.
//

#import "BaseManager.h"


NS_ASSUME_NONNULL_BEGIN

@interface RoomListManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<RoomListManagerDelegate>) listener;
/**
 * 获取固定会议室列表
 *
 * @param curPage   当前页码
 * @param pageSize  页大小
 * @return NSArray    返回即时会议列表
 */
-(ReturnCode)queryCommonMeeting:(NSString *)searchKey curPage:(NSInteger)curPage pageSize:(NSInteger)pageSize;

/**
 * 获取预约会议室列表
 *
 * @param curPage   白板文档名称
 * @param pageSize  页大小
 * @return  返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)querySchedulMeeting:(NSString *)searchKey nRecentDays:(NSInteger)nRecentDays curPage:(NSInteger)curPage pageSize:(NSInteger)pageSize;

/**
 * 获取即时会议室列表
 *
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)queryInstantMeeting;

/**
 * 创建即时会议（邀请入会）
 *
 * @param meetingName   会议名称
 * @param meetingType 会议类型
 * @param meetingPwd  会议密码
 * @param adminPwd  管理员密码
 * @param userList  授权用户数组
 * @return ReturnCode    返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)createInstantMeeting:(NSString *)meetingName meetingType:(TagMeetingType)meetingType meetingPwd:(NSString *)meetingPwd adminPwd:(NSString *)adminPwd userList:(NSArray *)userList;
@end

NS_ASSUME_NONNULL_END
