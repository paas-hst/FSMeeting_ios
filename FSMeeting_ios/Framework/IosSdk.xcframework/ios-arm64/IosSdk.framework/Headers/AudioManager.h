//
//  AudioManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/26.
//

#import "BaseManager.h"
#import "BaseUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface AudioManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<AudioManagerDelegate>) listener;
/**
 * 申请/放弃申请发言
 *
 * @param apply    YES - 申请，NO - 放弃
 * @param user      用户信息
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)applyBroadcastAudio:(BOOL) apply withUser:(BaseUserInfo*)user;

/**
 * 同意/不同意申请发言
 *
 * @param agree    YES - 同意，NO - 不同意
 * @param user      用户信息
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)agreeApplyAudio:(BOOL) agree withUser:(BaseUserInfo*)user;

/**
 * 打开/关闭用户音频
 *
 * @param agree    YES - 打开，NO - 关闭
 * @param user      用户信息
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)broadcastAudio:(BOOL)open withUser:(BaseUserInfo*)user;

/**
 * 查询麦克风是否可用
 *
 * @return BOOL     YES - 可用，NO - 不可用
 */
-(BOOL)isMicrophoneEnable;

/**
 * 禁用/启用麦克风
 *
 * @param enable    YES - 启用，NO - 禁用
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
-(ReturnCode)setMicrophoneEnable:(BOOL)enable;

/**
 * 获取手机静音状态
 *
 * @return BOOL     YES - 静音，NO - 非静音
 */
-(BOOL)isAppMute;

/**
 * 设置当前APP静音
 *
 * @param mute    YES - 静音，NO - 非静音
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)setAppMute:(BOOL)mute;

/**
 * 设置全场静音
 *
 * @return ReturnCode     返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)setAllMute;

/**
 * 添加音频回路监听
 *
 * @return void    无返回值
 */
-(void)addAudioCaptureCallback;

/**
 * 删除音频回路监听
 *
 * @return (void)    无返回值
 */
-(void)removeAudioCaptureCallback;

/**
 * 获取音频能量值
 *
 * @param userID   用户ID
 * @return int    返回音频能量值
 */
-(int)getMicrophoneEnergy:(NSUInteger)userID;

/// 获取当前音频类型
-(int)getCurrentAudioMode;

/// 设置音频类型 0-扬声器 1-听筒
- (void)setCurrentAudioMode:(int)mode;

/// 开始播放音频文件
/// - Parameter filePath: 音频文件路径(只支持wav格式音频)
/// - return 音频播放ID(用于停止音频播放)
- (unsigned int)startPlaySoundWithFilePath:(NSString *)filePath;

/// 停止播放音频
/// - Parameter soundID: 音频播放ID
- (void)stopPlaySoundWithSoundID:(unsigned int)soundID;

@end

NS_ASSUME_NONNULL_END
