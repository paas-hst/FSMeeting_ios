//
//  ScreenShareManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/26.
//

#import "BaseManager.h"

typedef enum {
    ShareScreenStart = 0,
    ShareScreenLoadingFinish
}ShareScreenNotify;

typedef void(^ShareScreenNotifyBlock)(ShareScreenNotify status);

NS_ASSUME_NONNULL_BEGIN


@interface ScreenShareManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<ScreenShareManagerDelegate>) listener;
/**
 * 通知SDK屏幕旋转，刷新相关信息
 *
 * @return void     无返回值
 */
-(void)refreshWhenLayoutChanged;

/**
 * 开始接收远程屏幕共享数据
 *
 * @param preview                   屏幕共享渲染视图
 * @param dwStateUserID      屏幕共享者的用户ID
 * @param notify                     屏幕共享状态回调
 * @return ReturnCode        返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)startRemoteScreenShareView:(UIView*)preview userId:(NSInteger)dwStateUserID notify:(ShareScreenNotifyBlock)notify;

/**
 * 停止接收远程屏幕共享数据
 *
 * @return ReturnCode        返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)stopRemoteScreenShareView;

/**
 * 是否正在屏幕共享
 *
 * @return BOOL      YES- 是，NO -否
 */
-(BOOL)isScreenSharing;
@end

NS_ASSUME_NONNULL_END
