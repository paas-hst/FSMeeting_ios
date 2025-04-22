//
//  WhiteBoardView.h
//  FSMeetingClient
//
//  Created by jarvis on 2018/12/14.
//

#import <UIKit/UIKit.h>
#import <IosSdk/SDKDataType.h>

NS_ASSUME_NONNULL_BEGIN

@interface WhiteBoardView : UIView

/// 文档ID
@property (nonatomic, strong, readonly) NSString *mFileGuid;

/// 数据类型
@property (nonatomic, assign, readonly) _DataType dataType;

/// 白板类型为白板ID，VNC与媒体共享类型为其dataType
@property (nonatomic, assign, readonly) NSUInteger dataID;
/// 用户ID，判断关闭的是不是自己创建人共享
@property (nonatomic, assign) unsigned long userID;
/// 权限索引 , 关闭白板/文档共享的时候需要用到
@property (nonatomic, assign) int rightsIndex;
/// 白板类型固定为0，VNC与媒体共享类型为其用户ID
@property (nonatomic, assign) NSUInteger dwUserID;
/// 白板/文档名称
@property (nonatomic, copy, readonly) NSString *name;
/// 白板/文档名称(当前页数/总页数)
@property (nonatomic, copy, readonly) NSString *nameAndPage;

@property (nonatomic, strong, readonly) UIView *contentView;

- (instancetype)initWithContentView:(UIView *)contentView WithDataType:(_DataType)dataType;

- (void)destory:(BOOL)isCloseAll;

/// 关闭共享
- (void)destory:(BOOL)isCloseAll
         userID:(unsigned long)userID
    rightsIndex:(int)rightsIndex
       dwUserID:(NSUInteger)dwUserID
         dataID:(NSUInteger)dataID
       dataType:(_DataType)dataType;

/**
 创建电子投票

 @param contentView voteView
 @param voteID 投票ID
 @param voteName 投票主题名
 @return WhiteBoardView
 */
- (instancetype)initWithContentView:(UIView *)contentView
                             voteID:(NSUInteger)voteID
                           voteName:(NSString *)voteName;

///缩略图
@property (nonatomic, strong, nullable) UIImage *thumbnailImage;

- (UIView *)contentView;

- (BOOL)isFirstPage;

- (BOOL)isLastPage;


- (void)destoryWBIgnoreRight;

- (void)destoryRight;
@end

NS_ASSUME_NONNULL_END
