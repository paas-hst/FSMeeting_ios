//
//  FMWebAppView.h
//  FSMeeting
//
//  Created by li on 31/08/2023.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FMWebAppViewDelegate <NSObject>

/// 接受 WebApp 发送的消息
/// - Parameter messageStr: json字符串
- (void)receiveMessageFromWeb:(NSString *)messageStr;

@end


@interface FMWebAppView : UIView

/// webApp 消息代理, 设置后 web 消息由 delegate 处理,不设置则 FMWebAppView 内部处理
@property (nonatomic, weak) id<FMWebAppViewDelegate> delegate;

/// 关闭 WebApp 页面
- (void)dismiss;

/// 关闭所有 WebApp 页面
+ (void)dismiss;

/// 设置关闭  WebApp 按钮图片
/// - Parameter image: 关闭按钮图片
- (void)setCloseButtonImage:(UIImage *)image;

/// 发生 json 消息给 WebApp
/// - Parameter messageStr: json 字符串
- (void)sendMessageToWeb:(NSString *)messageStr;

/// 显示 WebApp 页面
/// - Parameter data: WebApp 数据
+ (FMWebAppView *)showWepApp:(ShareAppMsgDataObj *)data;

@end

NS_ASSUME_NONNULL_END
