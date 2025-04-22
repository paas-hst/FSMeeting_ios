//
//  ChatManager.h
//  IosSdk
//
//  Created by Tiger on 2021/7/26.
//

#import "BaseManager.h"
#import "ChatMessageInfo.h"

NS_ASSUME_NONNULL_BEGIN
@interface ChatManager : BaseManager
/**
 * 添加事件回调监听者
 *
 * @param listener    监听回调的对象
 */
-(void)addEventListener:(id<ChatManagerDelegte>) listener;
/**
 * 发送聊天消息
 *
 * @param chatMsgInfo      聊天消息对象
 * @return ReturnCode        返回错误码，详情请查看ReturnCode定义
 */
- (ReturnCode)sendChatMessage:(ChatMessageInfo *)chatMsgInfo;

@end

NS_ASSUME_NONNULL_END
