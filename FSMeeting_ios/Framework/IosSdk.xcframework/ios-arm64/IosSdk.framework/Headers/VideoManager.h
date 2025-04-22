//
//  VideoManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/26.
//

#import "BaseManager.h"
#import <UIKit/UIKit.h>
#import "BaseUserInfo.h"

typedef NSInteger RenderId;

typedef enum {
    FrontCamera,
    BackCamera
}CameraType;

NS_ASSUME_NONNULL_BEGIN

@interface VideoManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<VideoManagerDelegate>) listener;
/**
 * 通知SDK屏幕旋转，刷新相关信息
 *
 * @return void     无返回值
 */
-(void)refreshWhenOrientationChanged;

/**
 * 开始预览本地
 *
 * @param preview           本地视频渲染视图
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)startLocalVideoView:(UIView*)preview;

/**
 * 停止预览本地
 *
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)stopLocalVideoView;

/**
 * 判断是否是前置摄像头
 *
 * @return BOOL     YES - 前置， NO - 后置
 */
-(BOOL)isFrontCamera;

/**
 * 切换前后摄像头
 *
 * @param type           FrontCamera - 前置，BackCamera - 后置
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)switchCamera:(CameraType)type;

/**
 * 开始接收并显示视频
 *
 * @param user                用户信息
 * @param vid                  视频通道ID
 * @param render           渲染视频
 * @param mode               视频模式 2表示等比裁剪   3表示等比完整
 * @param target           监听回调的对象
 * @param action           回调方法
 * @return RenderId       返回渲染ID，停止接收时需要使用
 */
-(RenderId)startRemoteVideoView:(BaseUserInfo*) user
                   videoChannelId:(NSUInteger)vid
                       renderView:(UIView*)render
                        videoMode:(int)mode
                           target:(id)target
                           notify:(SEL)action;

/**
 * 停止接收和显示远端视频
 *
 * @param user                用户信息
 * @param vid                  视频通道ID
 * @param renderId       渲染ID
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)stopRemoteVideoView:(BaseUserInfo*) user
                    videoChannelId:(NSUInteger)vid
                          renderId:(RenderId)renderId;

/**
 * 暂停接收和显示远端视频
 *
 * @param user                用户信息
 * @param vid                  视频通道ID
 * @param renderId       渲染ID
 * @param isPause         YES - 暂停， NO- 继续接收
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)pauseRemoteVideoView:(BaseUserInfo*) user
                     videoChannelId:(NSUInteger)vid
                           renderId:(RenderId)renderId
                              pause:(BOOL)isPause;

/**
 * 申请/放弃广播视频
 *
 * @param apply              YES - 申请， NO- 放弃
 * @param vid                  视频通道ID
 * @param user                用户信息
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)applyBroadcastVideo:(BOOL) apply
                  videoChannelId:(NSUInteger)vid
                        withUser:(BaseUserInfo*)user ;

/**
 * 同意/拒绝申请广播视频
 *
 * @param agree              YES - 同意， NO- 拒绝
 * @param vid                  视频通道ID
 * @param user                用户信息
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)agreeApplyVideo:(BOOL) agree
              videoChannelId:(NSUInteger)vid
                    withUser:(BaseUserInfo*)user;

/**
 * 广播/关闭用户视频
 *
 * @param open                YES - 广播， NO- 关闭
 * @param vid                  视频通道ID
 * @param user                用户信息
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)broadcastVideo:(BOOL)open
             videoChannelId:(NSUInteger)vid
                   withUser:(BaseUserInfo*)user;

/**
 * 禁用/启用摄像头
 *
 * @param enable              YES - 启用， NO- 禁用
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setCameraEnable:(BOOL)enable;

/**
 * 查询摄像头是否是禁用状态
 *
 * @return BOOL    YES - 启用， NO- 禁用
 */
-(BOOL)isCameraEnable;

/**
 * 设置是否启用美颜功能
 *
 * @param enable             YES - 启用， NO- 不启用
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setBeautyEnable:(BOOL)enable;

/**
 * 设置是否启用视频镜像功能
 *
 * @param enable             YES - 启用， NO- 不启用
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setMirrorEnable:(BOOL)enable;

/**
 * 查询是否正在本地查看
 *
 * @return BOOL    YES - 是， NO- 否
 */
-(BOOL)isDisplayingLocalVideo;

/**
 * 设置视频显示模式
 *
 * @param userId             用户ID
 * @param vid                   视频通道ID
 * @param mode                  视频显示模式 2表示等比裁剪   3表示等比完整
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)setVideoDisplayMode:(unsigned long) userId videoChannelId:(NSUInteger)vid mode:(int)mode;
@end

NS_ASSUME_NONNULL_END
