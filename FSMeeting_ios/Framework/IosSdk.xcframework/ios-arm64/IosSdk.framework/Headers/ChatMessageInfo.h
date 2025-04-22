//
//  ChatMessageInfo.h
//  IosSdk
//
//  Created by whyf on 2021/8/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ChatMessageType) {
    ChatMessageISend,               // Message I sent.
    ChatMessageSendToMe             // Message sent to me.
};

@interface ChatMessageInfo : NSObject
/// User id to private chat to local users.
@property (nonatomic, assign) NSUInteger fromUserId;
/// User id that a local user initiated a private chat with a user. 0 - say to everyone.
@property (nonatomic, assign) NSUInteger toUserId;
/// The tableView shows the type of chat message.
@property (nonatomic, assign) ChatMessageType type;
/// Time to send a message.
@property (nonatomic, copy) NSString *time;
/// User name.
//@property (nonatomic, copy) NSAttributedString *title;
/// Chat Content.
@property (nonatomic, copy) NSMutableString *content;

/**
 *  Initialize the ChatMessageViewModel object based on the chat information sent by the remote.
 *
 *  @param chatMessageInfo Remote chat message
 */
- (instancetype)initWithChatMessageInfo:(id)chatMessageInfo;
/**
 *  Initialize the ChatMessageViewModel object based on the local chat information.
 */
- (instancetype)initWithLocalUserId:(NSUInteger)localUserId
                           toUserId:(NSUInteger)toUserId
                            content:(NSString *)content;

-(NSInteger)userType;

-(NSMutableString *)displayName;
@end

NS_ASSUME_NONNULL_END
